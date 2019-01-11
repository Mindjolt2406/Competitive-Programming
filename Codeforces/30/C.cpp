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

typedef struct
{
  ld x,y,t,p;

  void init(ld x1, ld y1, ld t1, ld p1)
  {
    x = x1;
    y = y1;
    t = t1;
    p = p1;
  }
}node;

bool comp(const node &node1, const node &node2)
{
  if(node1.t<node2.t) return true;
  return false;
}

ld dist(const node& n1, const node &n2)
{
  return sqrt(pow(abs(n1.x-n2.x),2) + pow(abs(n1.y-n2.y),2));
}

ld max(ld x, ld y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  vector<node> v;
  int n;
  sc(n);
  v.resize(n);
  for(int i=0;i<n;i++)
  {
    ld x,y,t,p;
    scld(x);
    scld(y);
    scld(t);
    scld(p);
    v[i].init(x,y,t,p);
  }
  sort(v.begin(),v.end(),comp);
  ld **dp = new ld*[n];
  for(int i=0;i<n;i++) dp[i] = new ld[2];
  for(int i=0;i<n;i++)  {dp[i][0] = dp[i][1] = -1;}
  dp[0][0] = 0;
  // dp[0][1] = v[0].p;
  for(int i=0;i<n;i++)
  {
    dp[i][1] = v[i].p;
    node n1 = v[i];
    dp[i][0] = 0;
    for(int j=0;j<i;j++)
    {
      node n2 = v[j];
      // From a certain j
      if(dist(n1,n2)<=abs(n1.t-n2.t))  dp[i][1] = max(dp[i][1],dp[j][1] + n1.p);
      dp[i][0] = max(dp[i][0],dp[j][1]);
    }
  }
  cout<<setprecision(10);
  cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
  return 0;
}

