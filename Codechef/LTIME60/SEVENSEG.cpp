/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int t;
  cin>>t;
  // map<int,int> d;

  // d.insert(0,6);
  // d.insert(1,2);
  // d.insert(2,5);
  // d.insert(3,5);
  // d.insert(4,4);
  // d.insert(5,5);
  // d.insert(6,6);
  // d.insert(7,3);
  // d.insert(8,7);
  // d.insert(9,6);

  map<int,vector<int> > e;
  e[0] = vector<int>({1,1,0,1,1,1,1});
  e[1] = vector<int>({0,0,0,1,0,0,1});
  e[2] = vector<int>({1,0,1,1,1,1,0});
  e[3] = vector<int>({1,0,1,1,0,1,1});
  e[4] = vector<int>({0,1,0,1,1,0,1});
  e[5] = vector<int>({1,1,1,0,0,1,1});
  e[6] = vector<int>({1,1,1,0,1,1,1});
  e[7] = vector<int>({1,0,0,1,0,0,1});
  e[8] = vector<int>({1,1,1,1,1,1,1});
  e[9] = vector<int>({1,1,1,1,0,1,1});

  while(t--)
  {
    vector<int> counter1(7),counter2(7);
    vector<pair<int,int> > v,w;
    bool flag1[7],flag2[7];
    for(int i=0;i<7;i++) {flag1[i] = true;flag2[i] = true;}
    bool boo = true;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      vector<int > z = e[x];
      for(int i=0;i<7;i++)
      {
        if(z[i]) 
        {
          v.pu(mp(counter1[i],i));
          w.pu(mp(counter2[i],i));
        }
      }
      sort(v.begin(),v.end());
      sort(w.begin(),w.end());
      reverse(w.begin(),w.end());

      int j=0;
      for(int j=0;j<y;j++)
      {
        if(flag1[v[j].se] || flag2[w[j].se]) {boo = false;break;}
        counter1[v[j].se]++;
        counter2[w[j].se]++;
        j++;
      }
      while(j<v.size()) 
      {
        counter1[v[j].se] = -1;
        counter2[v[j].se] = -1;
        flag1[v[j].se] = false;
        flag2[w[j].se] = false;
        j++;
      }
    }
    int count1 = 0,count2 = 0;
    for(int i=0;i<7;i++)
    {
      if(!counter1[i]) count1++;
      if(!counter2[i]) count2++;
    }
    if(boo) cout<<count1<<" "<<count2<<endl;
    else cout<<"invalid"<<endl;
  }
  return 0;
}

