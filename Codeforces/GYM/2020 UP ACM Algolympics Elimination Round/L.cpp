#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000000
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


int main()
{
  __;

  vector<ll> look(1e5+10);
  look[0] = 1;
  for(int i=1;i<1e5+7;i++) look[i] = ((2*look[i-1])%MOD+1) % MOD;

  int n,k;
  cin >> n >> k;

  vector<int> v(n);
  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    if(s == "MEEK") v[i] = 1;
  }

  if(v.size() == 2 && v[0] != v[1])
  {
    k %= 2;
    if(k) swap(v[0],v[1]);
    if(v[0]) cout << 2 << endl;
    else cout << 1 << endl;
    return 0;
  }

  int left = 0, right = n-1;
  while(k--)
  {
    while(left<n && v[left] != 1) left++;
    while(right> 0 && v[right] != 0) right--;
    if(left>=right) break;
    swap(v[left],v[right]);
  }

  // t(v);
  ll cnt = 0;
  for(int i=0;i<n;i++)
  {
    if(v[i] == 0) 
    {
      cnt++;
      if(i>0) cnt += look[i-1];
      cnt %= MOD;
    }
  }

  cout << cnt << endl;
  return 0;
}
