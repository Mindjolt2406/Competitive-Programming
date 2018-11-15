#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

pair<ld,ld> change(pair<ld,ld> p,int a)
{
  ld sin1 = (ld)a/sqrt(a*a+1);
  ld cos1 = (ld)1/sqrt(a*a+1);
  sin1*=-1;
  pair<ld,ld> p1;
  ld x = p.first,y = p.second;
  p1.first = x*cos1 - y*sin1;
  p1.second = x*sin1 + y*cos1;
  p1.first = round(10000000*p1.first)/10000000;
  p1.second = round(10000000*p1.second)/10000000;
  return p1;
}

int main()
{
  cout<<setprecision(20);
  int n,a,b;
  sc(n);sc(a);sc(b);
  vector<pair<ld,ld> > v;
  map<ld,ld > d1;
  map<ld,ld> :: iterator it1;
  map < pair<ld,ld> ,ld> :: iterator it2;
  map <pair<ld,ld>,ld> d2;
  set<pair<ld,ld> > s;
  for(int i=0;i<n;i++)
  {
    ld x,vx,vy;
    scld(x);scld(vx);scld(vy);
    ld y = a*x + b;
    pair<ld,ld> p1,p2;
    p1 = mp(x,y);
    p2 = mp(vx,vy);
    p1 = change(p1,a);
    p2 = change(p2,a);
    // d1 is the x counter
    if(s.find(p2)!=s.end())
    {
      if(d2.find(p2)!=d2.end()) d2[p2]++;
      else d2[p2] =  2;
    }
    else s.insert(p2);

    if(d1.find(p2.second)!=d1.end()) d1[p2.second]++;
    else d1[p2.second] = 1;
  }
  ll count=  0;
  for(it1 = d1.begin();it1!=d1.end();it1++)
  {
    // cout<<it1->first<<endl;
    ll c = it1->second;
    // cout<<"c: "<<c<<endl;
    c = c*(c-1);
    count+=c;
  }
  for(it2 = d2.begin();it2!=d2.end();it2++)
  {
    // cout<<"here"<<endl;
    // cout<<(it2->first).first<<" "<<(it2->first).second<<endl;
    ll c = it2->second;
    c = c*(c-1);
    count-=c;
  }
  cout<<count<<endl;
  return 0;
}
