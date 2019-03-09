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
#define vi vector<int>
#define vll vector<long long int>
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

vector<ld> fin(1e6);

ld min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

void getPos(vector<ld> &bound, vector<ld> &pos, vector<ld> &vel, ld t, int n)
{
  for(int i=0;i<n;i++) fin[i] = pos[i]+vel[i]*t;
}

ld getMinT(vector<ld> &bound, vector<ld> &pos, vector<ld> &vel, int n)
{
  ld min1 = 1e18;
  for(int i=0;i<n;i++)
  {
    if(vel[i]==0) continue;
    ld t = (bound[i]-pos[i])/vel[i];
    if(t<0) t = abs((pos[i]/vel[i]));
    min1 = min(min1,t);
  } 
  return min1;
}

ld distance(vector<ld> &a, vector<ld>&b, int n)
{
  ld sum1 = 0;
  for(int i=0;i<n;i++)
  {
    sum1+=(a[i]-b[i])*(a[i]-b[i]);
  }
  sum1 = sqrt(sum1);
  return sum1;
}

ld getSpeed(ld t,vector<ld> &cur, int n)
{
  ld dist = distance(fin,cur,n);
  return dist/t;
}

ld checker(vector<ld> &bound, vector<ld> &pos, vector<ld> &vel, vector<ld> &cur, ld t, int n)
{
  getPos(bound, pos, vel, t, n);
  // pr(fin);
  return getSpeed(t,cur, n);
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<ld> bound(n),pos(n), vel(n), cur(n);
    for(int i=0;i<n;i++) cin>>bound[i];
    for(int i=0;i<n;i++) cin>>pos[i];
    for(int i=0;i<n;i++) cin>>vel[i];
    for(int i=0;i<n;i++) cin>>cur[i];
    // pr(bound);
    // pr(pos);
    // pr(vel);
    // pr(cur);
    ld t = getMinT(bound, pos, vel, n);
    // t(t);
    ld min1 = 1e18;
    ld beg = 0, end = t;
    ld ans = 0;
    ld a,b,c;
    cout<<setprecision(10);
    while(beg<=end)
    {
      ld mid = (beg+end)/2;
      // t(mid,beg,end);
      ld mid1 = mid+0.0000000001, mid2 = mid-0.0000000001;
      a = checker(bound, pos, vel, cur, mid2, n);
      b = checker(bound, pos, vel, cur, mid, n);
      c = checker(bound, pos, vel, cur, mid1, n);
      // t(a,b,c);
      ans = b;
      if(a>=b && b>=c) beg = mid+0.0000000001;
      else if(a<=b && b<=c) end = mid-0.0000000001;
      else {ans = b;break;}
    }
    cout<<setprecision(10);
    cout<<ans<<endl;
    for(int i=0;i<n;i++) fin[i] = 0;
  }
  return 0;
}

