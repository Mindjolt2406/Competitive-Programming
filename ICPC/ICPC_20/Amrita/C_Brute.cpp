#include "bits/stdc++.h"

typedef long long ll;
typedef long double lld;
using namespace std;

#define endl "\n"
#define fi first
#define se second
#define MEMS(a, b) memset(a, b, sizeof(a))
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define __                          \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout);
#define all(c) c.begin(), c.end()
#define pii pair<int, int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

#define tr(...)                                     \
  cout << __FUNCTION__ << ' ' << __LINE__ << " = "; \
  trace(#__VA_ARGS__, __VA_ARGS__)
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.fi << ", " << p.se << ')';
  return out;
}

template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  ll l = v.size();
  for (ll i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}

template <typename T>
ostream& operator<<(ostream& out, set<T> const& v) {
  for (auto i = v.begin(); i != v.end(); i++) out << (*i) << ' ';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, multiset<T> const& v) {
  for (auto i = v.begin(); i != v.end(); i++) out << (*i) << ' ';
  return out;
}
template <typename T, typename V>
ostream& operator<<(ostream& out, map<T, V> const& v) {
  for (auto i = v.begin(); i != v.end(); i++)
    out << "\n" << (i->first) << ":" << (i->second);
  return out;
}

template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}

template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}

#define int ll
void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
cin >> arr[i];
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) >= 2) {
      vector<int> possible;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          possible.push_back(arr[j]);
        }
      }
      set<int> avai(possible.begin(), possible.end());
      int nn = possible.size();
      int no = 0;
      for (int j = 0; j < nn; j++) {
        for (int k = j + 1; k < nn; k++) {
          int temp = possible[j] + possible[k];
          int par = 0;
          for (int q = -d; q <= d; q++) {
             if (avai.count(temp + q)) {
               par = 1;
               break;
             }
          }
          if (par == 0) {
            no = 1;
            break;
          }
        }
        if(no == 1) break;
      }
      if (no == 0) ans++;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  _ int t;
  cin >> t;
  // t = 1;
  while (t--) {
    solve();
  }
}