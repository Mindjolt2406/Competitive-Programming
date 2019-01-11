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
#define scr(s) {char temp[1000010];scanf("%s",temp);s = temp;}
#define pr(v,n) { for(int i=0;i<n;i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

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

// vector>\<l
vector<ll> power10(1000010);

void computePower(int mod,int n)
{
  ll prod = 1;
  for(int i=0;i<n;i++)
  {
    power10[i] = prod;
    prod*=10;
    prod%=mod;
  }
}

void computePref(vector<ll> &num,vector<ll> &pref,int n,int mod)
{
  ll prod = 0;
  for(int i=0;i<num.size();i++)
  {
    prod*=10;
    prod+=num[i];
    prod%=mod;
    pref[i] = prod;
  }
}

ll computeSuf(int i,int mod,vector<ll> &pref,int n)
{
  
  if(i>0) return (pref[n-1] - pref[i-1] + mod)%mod;
  else return pref[n-1];
}

// void computeSuf(vector<ll> &num, vector<ll> &suf,int n)
// {
//   ll prod = 0;
//   for(int i=n-1;i>=0;i--)
//   {
//     prod+=num[i]*power10[n-1-i];
//     prod%=mod;
//     suf[i] = mod;
//   }
// }


void computeMod(vector<ll> &pref, vector<ll>&modvec, int n,int mod)
{
  for(int i=0;i<n;i++) // Skipping i
  {
    ll sum1 = 0;
    if(i>0) sum1+=pref[i-1]*power10[n-i];
    sum1%=mod;
    if(i<n-1) sum1+=computeSuf(i+1,mod,pref,n);
    sum1%=mod;
    modvec[i] = sum1;
  }
}

void dfs(vector<int>*adj,vector<bool> &vis,int u)
{
  if(vis[u]) return;
  vis[u] = true;
  for(int i=0;i<adj[u].size();i++) dfs(adj,vis,adj[u][i]);
}

void bfs(vector<ll> &modvec,int root, vector<bool> &vis,int mod,int n)
{
  queue<int> q;
  q.push(root);
  ll a = power(10,n-1,mod);

  vector<int> *adj = new vector<int>[mod];
  while(!q.empty())
  {
    int u = q.front();
    // t(u);
    q.pop();
    vis[u] = true;
    for(int i=0;i<mod;i++)
    {
      int c = (u*a + modvec[i])%mod;
      if(modvec[i]>0 && vis[c]==false) {q.push(c); adj[c].pu(u);}
    }
  }

  vis.clear();
  dfs(adj,vis,0);
}

int main()
{
  int t;
  sc(t);
  vector<ll> num(1000010),pref(1000010),modvec(1000010);
  while(t--)
  {
    string s;
    int mod;
    scr(s);
    sc(mod);
    int n = s.size();
    computePower(mod,n);

    for(int i=0;i<n;i++) num[i] = s[i]-'0';
    computePref(num,pref,n,mod);
    pr(pref,n);
    computeMod(pref,modvec,n,mod);

    pr(modvec,n);
    vector<ll> modvis(1001);
    for(int i=0;i<n;i++) modvis[modvec[i]]++;
    
    vector<bool> vis(1001);
    bfs(modvis,modvec[0],vis,mod,n); 

    int count = 0;
    for(int i=0;i<mod;i++)
    {
      if(vis[i]) count+=modvis[i];
    }

    printf("%d\n",count);
    pref.clear();
    modvec.clear();
  }
  return 0;
}

