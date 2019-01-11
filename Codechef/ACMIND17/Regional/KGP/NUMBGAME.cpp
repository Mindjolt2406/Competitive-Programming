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
#define _ cerr<<"here"<<endl;


using namespace std;

int num[1000010],pref[1000010],suf[1000010];
bool vis[1011];
int modvis[1011];
unordered_set<int> setmod;
vector<vector<int> > adj;
// map<ll,ll> modvis;
int a;
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
ll power10[1000010];

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

void computePref(int n,int mod)
{
  ll prod1 = 0;
  for(int i=0;i<n;i++)
  {
    prod1*=10;
    prod1+=num[i];
    prod1%=mod;
    pref[i] = prod1;

    // prod2+=num[i]*power10[n-1-i];
    // prod2%=mod;
    // suf[i] = prod2;
  }
}

void computeSuf(int n,int mod)
{
  ll prod2 = 0;
  for(int i=n-1;i>=0;i--)
  {
    prod2+=num[i]*power10[n-1-i];
    prod2%=mod;
    suf[i] = prod2;
    // t(prod2,i);
  }
}
// ll computeSuf(int i,int mod,vector<ll> &pref,int n)
// {
  
//   if(i>0) return (pref[n-1] - pref[i-1] + mod)%mod;
//   else return pref[n-1];
// }



void computeMod(int n,int mod)
{
  for(int i=0;i<n;i++) // Skipping i
  {
    ll sum1 = 0;
    int boo = 0;
    if(i>0) {sum1+=(pref[i-1]*power10[n-i-1])%mod;boo = 1;}
    sum1%=mod;
    if(i<n-1) {sum1+=suf[i+1];boo = 1;}
    sum1%=mod;
    if(boo==1) 
    {
      a = sum1;
      modvis[sum1]++;
      setmod.insert(sum1);
    }
  }
}

void dfs(int u)
{
  if(vis[u]) return;
  // t(u);
  vis[u] = true;
  for(auto it: adj[u]) dfs(it);
}

void bfs(int root,int mod,int n)
{
  queue<int> q;
  q.push(root);
  ll a = power(10,n-1,mod);

  // vector<int> *adj = new vector<int>[mod];
  for(int i=0;i<mod;i++) {vis[i] = false;adj.pu({});}
  int count = 0;
  while(!q.empty())
  {
    // count++;
    int u = q.front();
    // t(u,a);
    q.pop();
    vis[u] = true;
    for(auto it: setmod)
    {
      // count++;
      // t(u,a,it);
      int c = (u*a + it)%mod;
      // if(count%100000==0) t(u,c,vis[c],count);
      if(c!=u) adj[c].pu(u);
      if(vis[c]==false) {vis[c] = true;q.push(c);}
    }
  }

  for(int i=0;i<mod;i++) vis[i] = false;
  dfs(0);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int t;
  // sc(t);
  cin>>t;
    
  // vector<unordered_set<int> >adj(1010);
  while(t--)
  {
    // t(t);
    // memset(suf,0,sizeof(suf));
    // memset(pref,0,sizeof(pref));
    // memset(num,0,sizeof(num));
    memset(modvis,0,sizeof(modvis));
    // memset(vis,false,sizeof(vis));
    // memset(power10,0,sizeof(power10));
    // modvis.clear();
    string s;
    int mod;
    // scr(s);sc(mod);
    cin>>s>>mod;
    // adj ={};
    // for(int f = 0;f<=mod;f++) adj.push_back({});
    // t(s,mod);
    int n = s.size();
    computePower(mod,n);
    for(int i=0;i<n;i++) num[i] = s[i]-'0';
    computePref(n,mod);
    computeSuf(n,mod);
    // pr(pref,n);
    // pr(suf,n)
    computeMod(n,mod);

    // for(int i=0;i<n;i++) modvis[modvec[i]]++;
    
    bfs(a,mod,n); 

    int count = 0;
    for(int i=0;i<mod;i++)
    {
      if(vis[i]) count+=modvis[i];
    }

    printf("%d\n",count);
    // setmod.clear();
    setmod = {};
    adj = {};
    // adj.clear();
    // for(int i=0;i<mod;i++) adj[i].clear();
  }
  return 0;
}

/*
5
1611531 100
1750331 100
1590001 100
1321051 100
1088691 100


*/