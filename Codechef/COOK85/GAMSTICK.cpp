/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
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

ll sign(ll n,ll a)
{
  if(n<=a) return 1;
  return 0;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    ll n,x1,y1,x2,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    ll mid = (n+1)/2;
    if(n%2==1)
    {
      if(x1 == x2)
      {
        ll a = abs(y1-mid), b = abs(y2-mid);
        if(a<=b) cout << "Miron" << endl;
        else cout << "Slava" << endl;
      }
      else
      {
        ll a = abs(y1-mid), b = abs(y2-mid);
        // t(a,b);
        if(a<b) cout << "Miron" << endl;
        else if(a==b) cout << "Draw" << endl;
        else if(a==b+1) cout << "Draw" << endl;
        else cout << "Slava" << endl;
      }
    }
    else
    {
      ll mid1 = n/2, mid2 = mid1+1;
      if(x1 == x2)
      {
        // _;
        // t(y1,y2,mid1);
        if(sign(y1,mid1)==sign(y2,mid1))
        {
          ll a = abs(y1-mid1), b = abs(y2-mid1);
          if(a<=b) cout << "Miron" << endl;
          else cout << "Slava" << endl;
        }
        else
        {
          // _;
          if(y1>y2) swap(mid1,mid2);
          ll a = abs(y1-mid1), b = abs(y2-mid2);
          if(a<b) cout << "Miron" << endl;
          else if(a==b) cout << "Draw" << endl;
          else cout << "Slava" << endl;
        }
      }
      else
      {
        if(sign(y1,mid1)==sign(y2,mid1))
        {
          ll a = abs(y1-mid1), b = abs(y2-mid1);
          // t(a,b);
          if(a<b) cout << "Miron" << endl;
          else if(a==b) cout << "Draw" << endl;
          else if(a==b+1) cout << "Draw" << endl;
          else cout << "Slava" << endl;
        }
        else
        {
          if(y1>y2) swap(mid1,mid2);
          ll a = abs(y1-mid1), b = abs(y2-mid2);
          if(abs(a-b)<=1) cout << "Draw" << endl;
          else if(a<b) cout << "Miron" << endl;
          else cout << "Slava" << endl;
        }
      }
    }
  }
  return 0;
}

