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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int n,t;
  sc(n);sc(t);
  vector<int> v(n);
  set<int> s;
  map<int,int> d;
  vector<int> x(n);
  int countarr[101] = {0};
  for(int i=0;i<n;i++) {sc(v[i]);s.insert(v[i]);}
  sort(x.begin(),x.end());
  int count = 1;
  for(auto it: s)
  {
    // if(d.find(x[i])==d.end()) d[x[i]] = 1;
    // else d[x[i]]++;
    if(d.find(it)==d.end()) {d[it] = count;count++;countarr[d[it]] = 1;}
    else countarr[d[it]]++;
  }
  for(int i=0;i<v.size();i++) v[i] = d[v[i]];

  int max1 = -1,max2 = -1;
  for(int i=0;i<=100;i++) {max1 = max(max1,countarr[i]);if(max1==countarr[i]) max2 = i;}
  t(countarr[16]);
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  count = 1;
  vi w;
  int counter2 = 0;
  while(count<=max2)
  {
    int counter = 0;
    for(int i=0;i<v.size();i++)
    {
      if(v[i]==count && countarr[v[i]]>1) {countarr[v[i]]--;counter++;}
      else if(v[i]==count && countarr[v[i]]==1) {count++;counter++;}
    }
    // t(count,counter,counter2);
    w.pu(counter);
    // counter2+=counter;
  }
  t(max1,max2);
  for(int i=0;i<w.size();i++) cout<<w[i]<<" ";cout<<endl;
  sort(w.begin(),w.end());
  reverse(w.begin(),w.end());
  ll sum1 = 0;
  if(t<=w.size())
  {
    for(int i=0;i<t;i++) sum1+=w[i];
    cout<<sum1<<endl;
  }
  else 
  {
    for(int i=0;i<w.size();i++) sum1+=w[i];
    sum1+=(t-w.size())*max1;
    cout<<sum1<<endl; 
  }
  return 0;
}

