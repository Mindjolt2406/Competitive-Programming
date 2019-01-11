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
  int n;
  sc(n);
  int*l = new int[n];
  int*visited = (int*)calloc(1000001,sizeof(int));
  int max1 = -1;
  for(int i=0;i<n;i++) {sc(l[i]);visited[l[i]]++;max1 = max(max1,l[i]);}
  t(visited[1],visited[2]);
  vector<vector<int> > v(max1+1);
  map<int,int> d;
  map<int,int> :: iterator it;
  for(int i=1;i<=max1;i++)
  {
    for(int j=i;j<=max1;j+=i)
    {
      t(i,j);
      if(visited[j])
      {
        _;
        for(int k=0;k<visited[j];k++) v[i].pu(j);
      }
      if(d.find(j)==d.end()) d[j] = 1;
      else d[j]++;
    }
  }
  for(int i=1;i<=max1;i++)
  {
    for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";cout<<endl;
  }
  ll prod = 1;
  int counter = 0;
  for(int i=1;i<=n && v[i].size();i++) {prod*=v[i].size();counter++;}
  // t(prod);
  // for(it=d.begin();it!=d.end();it++)
  // {
  //   ll k = it->second;
  //   t(k);
  //   for(int j=0;j<visited[k];j++)
  //   {
  //     ll c = (power(2,k,MOD) - k + MOD)%MOD;
  //     prod*=power(c,MOD-2,MOD);
  //     prod%=MOD;
  //   }
  // }
  cout<<prod<<endl;
  return 0;
}

