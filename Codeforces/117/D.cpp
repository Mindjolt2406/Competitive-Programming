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

// long long int size;
// bitset<10000010> bs;
// vector<int> prime;

// void sieve(ll upperbound)
// {
//   size = upperbound + 1;
//   bs.set();
//   bs[0] = bs[1] = false;
//   for(ll i = 2;i< size;i++)
//   {
//     if(bs[i])
//     {
//       for(ll j = i*i;j<size;j+=i) bs[j] = false;
//     }
//     prime.pu((int)i);
//   }
// }

bool check(string &s,int k)
{
  int n = s.size();
  if(n%k!=0) return false;
  for(int i=0;i<n;i++)
  {
    if(s[i]!=s[i%k]) return false;
  }
  return true;
}

bool check2(string &s,string &t, int k)
{
  for(int i=0;i<k;i++)
  {
    if(s[i]!=t[i]) return false;
  }
  return true;
}

int main()
{
  __;
  string s,t;
  cin>>s>>t;
  int n = s.size(),m = t.size();

  vector<int> counter(1e5+10);

  for(int i=1;i<=n;i++)
  {
    if(check(s,i)) counter[i]++;
  }

  int count = 0;
  for(int i=1;i<=m;i++)
  {
    if(check(t,i) && counter[i])
    {
      count+=check2(s,t,i);
    } 
  }

  cout<<count<<endl;
  return 0;
}

