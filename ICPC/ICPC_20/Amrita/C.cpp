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

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;


int pow2[N];

vector<int> in, out;
int ic, oc;
map<int, int> incnt;

int get(int l, int r) {
  int ans = 0;
  for (int i = l; i <= r; i++) {
    ans += incnt[i];
  }
  return ans;
}

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  out.clear();
  in.clear();
  for (int i = 0; i < n; i++) {
    if ((arr[i] >= -d) && (arr[i] <= d)) {
      in.push_back(arr[i]);
    } else {
      out.push_back(arr[i]);
    }
  }
  ic = in.size();
  oc = out.size();
  sort(out.begin(), out.end());
  sort(in.begin(), in.end());

  incnt.clear();
  for (auto i : in) {
    incnt[i]++;
  }

  // tr(ic, oc);

  map<int, int> cnt;
  for (auto i : out) {
    cnt[i]++;
  }
  int ans = 0;
  ans = (pow2[ic] * (oc + 1)) % MOD; // no element case is counted here;
  ans = ((ans -oc -ic -1) % MOD + MOD) % MOD;
  // tr(ans);
  for (auto i : out) {
    if (i > 0) {
      // tr(i);
      for (int j = -1 * (i + d + d); j <= min(-d-1, -1 * (i - d -d)); j++) {
        // tr(j);
        if (cnt.find(j) != cnt.end()) {
          // fixing i, j
          int t = i + j;
          int mi = max(-d, t - d);
          int mx = min(d, t + d);

          int c1 = get(mi, mx);
          int c2 = get(-d, mi - 1);
          int c3 = get(mx + 1, d);

          int temp = ((pow2[ic] - pow2[c2] - pow2[c3] + 1) % MOD + MOD) % MOD;
          temp = (temp * (cnt[j])) % MOD;
          // tr(i, j, mi, mx, c1, c2, c3, cnt[j], temp);
          ans = (ans + temp) % MOD;
          // tr(ans);

        }
      }
    }
  }

  cout << ans << endl;

}

int32_t main() {

  _
  pow2[0] = 1;
  for (int i = 1; i < N; i++) {
    pow2[i] = (pow2[i - 1] * 2) % MOD;
  }
  int t;
  cin >> t;
  // t = 1;
  while (t--) {
    solve();
  }
}