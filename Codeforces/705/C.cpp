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

bool isZeroFreq(vector<int> &freq) {
  for(auto it : freq) if(it) return false;
  return true;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if(n%k != 0) {cout << "-1" << endl; return;}

  vector<int> freq(26);

  for(auto it : s) freq[it - 'a']++;
  for(int i = 0; i < 26; i++) freq[i] %= k;

  if(isZeroFreq(freq)) {
    cout << s << endl;
    return;
  }

  for(int i = n-1; i >= 0; i--) {
    for(int j = s[i] + 1; j <= 'z'; j++) {
      
      vector<int> tempFreq = freq;
      tempFreq[s[i] - 'a'] = (tempFreq[s[i] - 'a'] - 1 + k) % k;
      vector<int> d(26);
      tempFreq[j-'a'] ++; tempFreq[j-'a'] %= k;


      int leftOver = n - i - 1;

      for(int k1=0;k1<26;k1++) {
        if(tempFreq[k1]) {
          int left = k - tempFreq[k1];
          leftOver -= left;
          d[k1] += left;
          tempFreq[k1] = 0;
        }
      }

      if(leftOver < 0) continue;
      if(leftOver > 0) d['a'-'a'] += leftOver;

      { // Leftover should be 0 if it comes here
        string t;
        for(int k=0;k<i;k++) {
          t += s[k];
        }
        t += j;

        for(int i=0;i<26;i++) {
          for(int k=0;k<d[i];k++) t += ('a'+i);
        }

        cout << t << endl;
        return;
      }
    }
    freq[s[i]-'a'] = (freq[s[i]-'a'] - 1 + k) % k;
  }
  cout << -1 << endl;
}
int main()
{
  __;
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
