/*
Rathin Bhargava
IIIT Bangalore

*/
// Missed the corner case where n = 1. I actualy didn't add that in the array, so it never shows up in the final dp like matrix
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

bitset<100010> bs;
const int N = 1e5+10;
vector<int> adj[N] = {};

void sieve(ll size)
{
  bs.set();
  bs[0] = bs[1] = false;
  adj[1].pu(1);
  for(ll i = 2;i<size;i++)
  {
    if(bs[i])
    {
      adj[i].pu(i);
      for(ll j = 2*i;j<size;j+=i) 
      {
        bs[j] = false;
        adj[j].pu(i);
      }
    }
  }
}

int main()
{
  __;
  int n;
  cin>>n;
  sieve(1e5+1);
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int> refer(N),dp(n);

  for(int i=0;i<n;i++)
  {
    // refer[v[i]] = 1;
    int max1 = -1;
    for(auto j : adj[v[i]]) {refer[j]++;max1 = max(max1,refer[j]);}
    for(auto j : adj[v[i]]) {refer[j] = max1;}
    // for(int i=0;i<n;i++) cout<<refer[i]<<" "; cout<<endl;
  }

  int max1 = -1;
  for(int i=0;i<N;i++) max1 = max(max1,refer[i]);
  cout<<max1<<endl;
  return 0;
}

