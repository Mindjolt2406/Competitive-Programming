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

bool check(int n, int even, int odd)
{
  // t(n,even,odd);
  int cnt2 = 0, cnt3 = 0, cnt5 = 0, cnt7 = 0;
  while(n%2==0) { n/=2; cnt2++;}
  while(n%3==0) { n/=3; cnt3++;}
  while(n%5==0) { n/=5; cnt5++;}
  while(n%7==0) { n/=7; cnt7++;}
  if(n!=1) return false;

  odd -= cnt5; odd -= cnt7;
  if(odd < 0) return false;
  
  int temp2 = cnt2;
  if(temp2%3==0) temp2/=3;
  else temp2 = temp2/3+1;
  if(even < temp2) return false;

  vector<int> v(even);
  for(int i=0;i<even;i++) {cnt2--; v[i] = 1;}
  if(cnt2 < 0) return false;
  // What about 4?
  for(int i=0;i<v.size();i++)
  {
    if(cnt2>=2) {v[i] = 3; cnt2-=2;}
    else if(cnt2 == 1) {v[i]++; cnt2--;}
  }
  int count2 = 0;
  for(int i=0;i<v.size();i++) if(v[i]==1) count2++;

  int old = cnt3;
  cnt3 = max(0,cnt3-count2); // To make 6

  if(cnt3%2==0) cnt3/=2;
  else cnt3 = cnt3/2 +1;
  
  odd -= cnt3;
  if(odd < 0) return false;
  // t(n,even,odd);
  return true;   
}

bool check2(vector<ll> v, pair<ll,ll> w)
{
  ll prod = v[0], even  = v[1], odd = v[2], digit = v[3];
  ll a = w.fi, b = w.se;

  // Digit constraint
  if(digit!=b)
  {
    if(digit == 13579 && !(b == 1 || b == 3 || b == 5 || b == 7 || b == 9)) return false;
    else if(digit == 24680 && !(b== 0 || b == 2 || b == 4 || b == 6 || b == 8)) return false;
    else if(digit != 13579 && digit != 24680) return false;
  }

  // Frequency Constraint
  if(prod == 0) return false;
  if(a % prod != 0) return false;
  // t(a,prod);
  return check(a/prod,even,odd);
} 

int main()
{
  __;
  int t;
  cin >> t;
  vector<vector<int> > v; // {Product,Even,Odd,Digit}; // If odd store 13579
  map<string,int> d;

  d["one"] = 1;
  d["two"] = 2;
  d["three"] = 3;
  d["four"] = 4;
  d["five"] = 5;
  d["six"] = 6;
  d["seven"] = 7;
  d["eight"] = 8;
  d["nine"] = 9;
  d["zero"] = 0;

  for(int h=1;h<=t;h++)
  {
    string s;
    cin >> s;
    vector<vector<ll> > v;
    ll even = 0, odd = 0, prod = 1;
    while(true)
    {
      even = 0; odd = 0; prod = 1;
      while(s[s.size()-1] != ',' && s[s.size()-1] != '.')
      {
        if(s=="even") even++;
        else if(s=="odd") odd++;
        else prod*=d[s];
        // t(odd,even,prod);
        cin >> s;
      }
      bool boo = false;
      if(s[s.size()-1]=='.') boo = true;
      s = s.substr(0,s.size()-1);
      int a;
      if(s=="odd") a = 13579;
      else if(s=="even") a = 24680;
      else a = d[s];
      v.pu({prod,even,odd,a});
      if(boo) break;
      cin >> s;
    }
    
    // t(v);
    int n;
    cin >> n;
    vector<pair<ll,ll> > w;
    cin >> s;
    int prev = -1;
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
      if(prev == s[i]-'0') cnt++;
      else if(prev == -1) {prev = s[i]-'0'; cnt = 1;}
      else {w.pu(mp(cnt,prev)); prev = s[i]-'0'; cnt = 1;}
    }
    if(cnt!=0) w.pu(mp(cnt,prev));

    // t(w);


    int left = 0, right = 0;
    while(left < v.size())
    {
      if(check2(v[left],w[right])) 
      {
        // t(left,right);
        right++;
      }
      left++;
    }
    if(right == w.size()) cout << "Case " << h << ": MAY BE" << endl; 
    else cout << "Case " << h << ": NO" << endl;  
  }
  return 0;
}

