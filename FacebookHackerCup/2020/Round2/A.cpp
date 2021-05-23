#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll max(ll x, ll y) {return x>y?x:y;}
ll min(ll x, ll y) {return x<y?x:y;}

void solve()
{
  int n,k;
  cin >> n >> k;
  vector<ll> s(n),x(n),y(n);

  for(int i=0;i<k;i++) cin >> s[i];
  ll as,bs,cs,ds;
  cin >> as >> bs >> cs >> ds;
  for(int i=k;i<n;i++) s[i] = ((((as*s[i-2]) % ds) + ((bs*s[i-1]) % ds) + cs) % ds);


  for(int i=0;i<k;i++) cin >> x[i];
  ll ax,bx,cx,dx;
  cin >> ax >> bx >> cx >> dx;
  for(int i=k;i<n;i++) x[i] = ((((ax*x[i-2]) % dx) + ((bx*x[i-1]) % dx) + cx) % dx);

  for(int i=0;i<k;i++) cin >> y[i];
  ll ay,by,cy,dy;
  cin >> ay >> by >> cy >> dy;
  for(int i=k;i<n;i++) y[i] = ((ay*y[i-2] % dy) + (by*y[i-1]) % dy + cy) % dy + x[i];

  for(int i=0;i<k;i++) y[i] += x[i];


  ll lowerSum = 0, upperSum = 0, sum1 = 0;
  for(auto it : s) sum1 += it;
  for(auto it : x) lowerSum += it;
  for(auto it : y) upperSum += it;

  // t(sum1,lowerSum,upperSum);
  // t(s,x,y);
  if(sum1 < lowerSum || sum1 > upperSum) 
  {
    cout << -1 << endl;
    return;
  }

  ll below = 0, above = 0;
  for(int i=0;i<n;i++)
  {
    if(x[i] <= s[i] && s[i] <= y[i]) 
    {
      
    }
    else if(s[i] < x[i])
    {
      below += x[i]-s[i];
    }
    else above += s[i]-y[i];
  }

  // t(above,below);

  cout << max(above,below) << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

