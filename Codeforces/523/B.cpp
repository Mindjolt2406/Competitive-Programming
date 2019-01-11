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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  int*l = new int[n];
  int max1 = -1,k1;
  ll count = 0,sum1 = 0;
  for(int i=0;i<n;i++) {sc(l[i]);max1 = max(max1,l[i]);sum1+=l[i];}
  k1 = max1;
  map<int,int> d;
  map<int,int> :: iterator it;
  for(int i=0;i<n;i++)
  {
    if(d.find(l[i])==d.end()) d[l[i]] = 1;
    else d[l[i]]++;
  }
  for(auto it=d.rbegin();it!=d.rend();it++)
  {
    if(it->fi>=max1)
    {
      count+=min(it->se,max1);
      max1-=min(it->se,max1);
    }
    else
    {
      max1 = it->fi;
      count+=min(it->se,max1);
      max1-=min(it->se,max1);
    }
  }
  ll c = k1-count;
  cout<<sum1-n-c<<endl;
  // cout<<count<<endl;
  return 0;
}

