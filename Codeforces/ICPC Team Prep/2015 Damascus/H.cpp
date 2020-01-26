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
#define EPS 1e-2
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

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main()
{
  __;
  int n;
  cin >> n;
  while(n!=0)
  {
    ll c1,a,c2,b;
    cin >> c1 >> a >> c2 >> b;

    cerr<<fixed<<setprecision(5);
    ll x0,y0,g;
    bool boo = find_any_solution(a,b,n,x0,y0,g);
    if(boo) 
    {
      // t(y0,b,x0,a);
      ld temp1 = ((ld)y0)/a, temp2 = -((ld)x0)/b;
      // t(temp1,temp2,temp1-temp2);
      if(abs(temp1 - temp2) > EPS && temp1<temp2) {cout << "failed" << endl; cin >> n;continue;}
      // _;
      ll k;

      
      ld k1 = ceil(temp2*g);
      // if(x0*g % b == 0) k1 = (-x0*g)/b;
      // else k1 = (-x0*g)/b + 1;

      ld k2 = floor(temp1*g);

      if((ld)c1/a > (ld)c2/b)
      // if(c1*b > c2*a)
      { 
        // k >= -x0*g / b;
        k = k1;
      }
      else
      {
        // k <= y0*g/a
        k = k2;
      }

      // t(k1,k2);
      if(k1>k2) {cout << "failed" << endl; cin >> n;continue;}
  
      ll x1 = x0 + (k*b)/g;
      ll y1 = y0 - (k*a)/g;

      cout << x1 << " " << y1 << endl;
    }
    else cout<<"failed"<<endl;
    cin >> n;
  }
  return 0;
}

/*

40
5 9
5 12
43
1 3
2 4
0

 */
