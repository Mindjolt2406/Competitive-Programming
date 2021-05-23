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

void printABSame(int a, int b) {
  string s = "";
  for(int i=0;i<b;i++) s += '1';
  for(int i=0;i<a;i++) s += '0';
  cout << s << endl;
  cout << s << endl;
}

void caseOnes(string &s, string &t, int k, int b) {
  for(int i=0;i<=b;i++) {
    if(i == 0) {
      s += '1';
      t += '0';
    }
    else if(i == k) {
      s += '0';
      t += '1';
    }
    else {
      s += '1';
      t += '1';
    }
  }
}

void caseZeroes(string &s, string &t, int k, int a) {
  string revS = "", revT = ""; 
  for(int j=0;j<=a;j++) {
    if(j==0) {
      revS += '0';
      revT += '1';
    }
    else if(j == k) {
      revS += '1';
      revT += '0';
    }
    else {
      revS += '0';
      revT += '0';
    }
  }

  reverse(revS.begin(), revS.end());
  reverse(revT.begin(), revT.end());

  s += revS;
  t += revT;
}

void caseOnlyZeroes(string &s, string &t, int k, int a) {
  for(int i=0;i<a;i++) {
    s += '0';
    t += '0';
  }
}

void solve() {
  int a, b, k;
  cin >> a >> b >> k;

  if(a == 0 || b == 1) {
    if(k == 0) {
      cout << "Yes" << endl;
      printABSame(a, b);
    }
    else {
      cout << "No" << endl;
    }
    return;
  }

  if(k == 0) {
    cout << "Yes" << endl;
    printABSame(a, b);
    return;
  }


  int maxK = max(a+b-3, max(a*(b==2), (b-1)*(a == 1)));
  if(k == a + b - 2 && a > 1 && b > 2) {
    cout << "Yes" << endl;
    string s = "11";
    string t = "10";
    int c = a+b-2;
    for(int i=0;i<b-2;i++) {
      s += '1';
      t += '1';
    }
    for(int i=0;i<a-1;i++) {
      s += '0';
      t += '0';
    }
    s += '0';
    t += '1';
    cout << s << endl;
    cout << t << endl;
    return;
  }
  if(k > maxK) {
    cout << "No" << endl;
    return;
  }

  string s = "1", t = "1";
  if(a == 1) {
    caseOnes(s, t, k, b-1);
  }
  else if(b == 2) {
    caseZeroes(s, t, k, a);
  }
  else {
    if(k <= b-1) {
      caseOnlyZeroes(s, t, 0, a-1);
      caseOnes(s, t, k, b-1);
    }
    else {
      int leftOver = k-(b-2);
      caseZeroes(s, t, leftOver, a-1);
      caseOnes(s, t, b-2, b-2);
    }
  }

  cout << "Yes" << endl;
  cout << s << endl;
  cout << t << endl;
}

int main()
{
  __;
  solve();
  return 0;
}
