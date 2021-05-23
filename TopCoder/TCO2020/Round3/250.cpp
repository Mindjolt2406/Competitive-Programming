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

class RectangularObstacle
{
  public:
  ll min(ll x, ll y) {return x<y?x:y;}
  ll max(ll x, ll y) {return x>y?x:y;}

  long long countReachable(int x1, int x2, int y1, int y2, int s)
  {
    ll ans = 0;
    ll k = s;
    ans += k*k;
    vector<ll> v(2e6+1),w(2e6+1);
    int orig = 1e6;

    // Rectangle and below
    for(int i=min(orig+s,orig+1e6);i>=max(orig-s,orig-1e6);i--)
    {
      if(i > orig+x2) v[i] += k-abs(i-orig)+1;
      else if(i < orig+x1) v[i] += k-abs(i-orig)+1;
      else v[i] += min(y1,k-abs(i-orig)+1);
    }

    if(k>(ll)1e6)
    {
      ans += (k-(ll)1e6)*(k-(ll)1e6+1);
    }

    // Right rectangle point
    ll work2 = y2+1 + abs(x2)+1;
    ll work1 = y1+1 + abs(x1)+1;

    // t(work1,work2);

    work2 = k-work2;
    work1 = k-work1;

    work2 = max(work2,0);
    work1 = max(work1,0);

    // t(work1,work2);

    for(int i=orig+x1;i<=orig+x2;i++)
    {
      w[i] = max(w[i],work1);
      work1--;
    }

    for(int i=orig+x2;i>=orig+x1;i--)
    {
      w[i] = max(w[i],work2);
      work2--;
    }

    for(auto it : v) ans += it;
    for(auto it : w) ans += it;

    // cout << v << endl;
    // cout << w << endl;
    // ans--; // Origin
    return ans;
  }
};

int main()
{
  __;
  RectangularObstacle r;
  int x1,x2,y1,y2,s;
  cin >> x1 >> x2 >> y1 >> y2 >> s;
  cout << r.countReachable(x1,x2,y1,y2,s) << endl;
  return 0;
}
