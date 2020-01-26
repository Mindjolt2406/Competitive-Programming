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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 3e5+10, BLOCK = 510;
int arr[BLOCK][N] = {0};
int dp[N][BLOCK] = {0};
int counter[N] = {0},counter2[N] = {0};
int get_index[N] = {0};
vector<ll> fact(N),inv(N);

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
  // __;
  // Input
  int n,q;
  // cin>>n>>q;
  scanf("%d %d",&n,&q);
  vector<int> v(n);
  set<int> s;
  for(int i=0;i<n;i++) scanf("%d",&v[i]);
  int block = (int)sqrt(n);
  // int block = 0;

  // Precomputing factorial
  fact[0] = 1;
  inv[0] = 1;
  for(int i=1;i<fact.size();i++)
  {
    fact[i] = (fact[i-1]*i)%MOD;
    inv[i] = power(fact[i],MOD-2,MOD);
  }

  // Compressing v
  for(int i=0;i<n;i++) s.insert(v[i]);
  int count = 0;
  unordered_map<int,int> d;
  for(auto it : s) 
  {
    d[it] = count;
    count++;
  }
  for(int i=0;i<n;i++) v[i] = d[v[i]];

  // Precomputing arr and dp
  // arr is for elements where count > block, and dp for all others

  for(int i=0;i<n;i++) counter[v[i]]++;
  int cntx = 0, cnty = 0;
  int max1 = 0;
  for(int i=0;i<n;i++) 
  {
    if(counter[v[i]]>block && !get_index[v[i]]) 
    {
      cntx++;
      // t(v[i],cntx);
      get_index[v[i]] = cntx;
    }
  }

  for(int i=0;i<v.size();i++)
  {
    // t(i,v[i],counter[v[i]],get_index[v[i]]);
    if(i>0) for(int j=0;j<=block;j++) dp[i][j] = dp[i-1][j];
    if(counter[v[i]]>block) 
    {
      // t(v[i],get_index[v[i]]);
      arr[get_index[v[i]]][i]++; 
      continue;
    }
    if(i==0) 
    {
      counter2[v[i]]++;
      dp[0][counter2[v[i]]]++;
      continue;
    }
    if(counter[v[i]]<=block)
    {
      // if(counter2[v[i]]) dp[i][counter2[v[i]]]--;
      counter2[v[i]]++;
      dp[i][counter2[v[i]]]++;
    }
  }

  for(int i=1;i<=cntx;i++)
  {
    for(int j=1;j<n;j++)
    {
      arr[i][j]+=arr[i][j-1];
    }
  }

  t(block);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<4;j++) cout<<dp[i][j]<<" "; cout<<endl;
  }
  ll ans = 0;
  while(q--)
  {
    ll l1,l2,r1,r2;
    scanf("%lld %lld %lld %lld",&l1,&l2,&r1,&r2);
    ll l = (l1*ans+ l2)%n , r = (r1*ans + r2)%n;
    if(l>r) swap(l,r);

    ans = fact[r-l+1];
    // DP
    for(int j=0;j<=block;j++) 
    {
      ll a;
      if(l>0) 
      {
        a = dp[r][j] - dp[l-1][j];
        if(a<0) a = dp[r][j];
      }
      a = dp[r][j];

      // a is the number of numbers with frequency j
      ll b = fact[j];
      ll c = inv[j];
      ll d = power(c,a,MOD);

      t(j,a,b,c,d);
      ans *= d;
      ans%=MOD;
    }

    t(ans);
    for(int j=1;j<=cntx;j++)
    {
      ll a;
      if(l>0) a = arr[j][r] - arr[j][l-1];
      else a = arr[j][r];

      // t(a,j);
      ans*= inv[a];
      ans%=MOD;
    }

    printf("%lld\n",ans);
  }
  return 0;
}

