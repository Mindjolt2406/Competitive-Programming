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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

vector<int>*adj;

ll max(ll x, ll y)
{
  if(x<y) return y;
  return x;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    adj = new vector<int>[n+1];
    vector<int> col(n+1);
    vector<int> deg(n+1);

    ll count[2] = {1,0};
    ll sum1 = 0;
    for(int i=1;i<=n;i++)
    {
      int a;
      sc(a);
      a--;
      // i connects to a
      col[i] = col[a]^1;
      if(deg[a]==1) count[col[a]]--;
      deg[a]++; deg[i]++;
      count[col[i]]++;
      sum1+=max(count[0],count[1]);
    }
    cout<<sum1<<endl;
  }
  return 0;
}

