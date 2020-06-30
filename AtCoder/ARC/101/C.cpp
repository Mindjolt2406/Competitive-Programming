#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  vector<int> v(n+1);
  vector<ll> left(n+1,INF),right(n+1,INF);
  left[0] = 0;
  right[0] = 0;

  for(int i=1;i<=n;i++) cin >> v[i];

  int index = 0;
  for(int i=1;i<=n;i++)
  {
    if(v[i] > 0) break;
    else index = i;
  }

  for(int i = index;i>0;i--)
  {
    // left[index-i+1] = left[index-i];
    left[index-i+1] = abs(v[i]);
  }

  for(int i=index+1;i<=n;i++)
  {
    // right[i-index] = right[i-index-1];
    right[i-index] = v[i];
  }

  // t(left,right);

  ll min1 = INF;
  min1 = min(min1,left[k]);
  min1 = min(min1,right[k]);

  for(int i=1;i<k;i++)
  {
    min1 = min(min1,2*left[i]+right[k-i]);
    min1 = min(min1,2*right[i]+left[k-i]);
  }

  cout << min1 << endl;
  return 0;
}
