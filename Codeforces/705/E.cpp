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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

string maxXor(string &a, string &b) {
  string ans = "";
  int n = a.size();
  bool diffDone = false;
  for(int i=0;i<n;i++) {
    if(!diffDone) {
      if(a[i] == b[i]) ans += '0';
      else {
        ans += '1';
        diffDone = true;
      }
    } else {
      ans += '1';
    }
  }

  return ans;
}

string addBinary(string s) {
  for(int i=s.size() - 1; i>= 0; i--) {
    if(s[i] == '0') {
      s[i] = '1';
      for(int j=i+1;j<s.size();j++) s[j] = '0';
      return s;
    }
  }
}

int main()
{
  __; 
  // *** 00 -> 0
  // *** 01 -> 1
  // *** 10 -> 2
  // *** 11 -> 3

  // 30 -? a^b | 11
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  if(t.size() == 1) {
    if(t == "0") cout << "0" << endl;
    else cout << "1" << endl;
    return 0;
  }

  string a = s.substr(0, n-2), b = t.substr(0, n-2);
  string ans;
  if(a == b) {
    // t or b || 3
    string a2 = s.substr(n-2, 2);
    string b2 = t.substr(n-2, 2);

    if(b2 != "10") ans = t;
    else {
      if(b == "") ans = (a2 == b2) ? t : b + "11";
      else ans = (a2 != "00") ? t : b + "11";
    }

  } else {
    // Take max xor and concatenate 3 or just take t
    string a2 = s.substr(n-2, 2);
    string b2 = t.substr(n-2, 2);
    string temp = maxXor(a, b) + "11";
    // t(temp, t);
    ans = (temp > t) ? temp : b + ((b2 == "10") ? "11" : ((b2 == "00" && ((addBinary(a) == b && a2 != "11") || (addBinary(a) < b))) ? "01" : b2));
    // ans = (temp > t) ? temp : b + ((b2 == "10") ? "11" : ((b2 == "00" && (a2 != "11")) ? "01" : b2));
    
  }

  cout << ans << endl;
  return 0;
}
