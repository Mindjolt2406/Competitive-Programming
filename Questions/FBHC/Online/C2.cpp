#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define pr(v)                                                                  \
  {                                                                            \
    for (int i = 0; i < v.size(); i++) {                                       \
      v[i] == INF ? cout << "INF " : cout << v[i] << " ";                      \
    }                                                                          \
    cout << endl;                                                              \
  }
#define t1(x) cerr << #x << " : " << x << endl
#define t2(x, y) cerr << #x << " : " << x << " " << #y << " : " << y << endl
#define t3(x, y, z)                                                            \
  cerr << #x << " : " << x << " " << #y << " : " << y << " " << #z << " : "    \
       << z << endl
#define t4(a, b, c, d)                                                         \
  cerr << #a << " : " << a << " " << #b << " : " << b << " " << #c << " : "    \
       << c << " " << #d << " : " << d << endl
#define t5(a, b, c, d, e)                                                      \
  cerr << #a << " : " << a << " " << #b << " : " << b << " " << #c << " : "    \
       << c << " " << #d << " : " << d << " " << #e << " : " << e << endl
#define t6(a, b, c, d, e, f)                                                   \
  cerr << #a << " : " << a << " " << #b << " : " << b << " " << #c << " : "    \
       << c << " " << #d << " : " << d << " " << #e << " : " << e << " " << #f \
       << " : " << f << endl
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t6, t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr << "here" << endl;
#define __                                                                     \
  {                                                                            \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
  }

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <ll> ostream &operator<<(ostream &os, const vector<ll> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] != INF)
      os << v[i];
    else
      os << "INF";
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    ;
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  for (auto it : s) {
    if (it != *s.rbegin())
      os << it << ", ";
    else
      os << it;
  }
  os << "}";
  return os;
}
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << ", " << a.second << ")";
}

ll max(ll x, ll y) { return x > y ? x : y; }

void dfs(vector<vector<int>> &adj, vector<vector<vector<ll>>> &dp,
         vector<ll> &weight, int k, int u = 0, int p = -1) {
  bool isLeaf = true;
  // Process DP values for the children.
  for (auto v : adj[u]) {
    if (v - p) {
      dfs(adj, dp, weight, k, v, u);
      isLeaf = false;
    }
  }

  vector<bool> addRootContribution(k + 2, false);
  // Get DP values for root.
  for (auto v : adj[u]) {
    if (v == p)
      continue;

    vector<vector<ll>> dpNew = dp[u];
    for (int i = 0; i <= k + 1; i++) {
      for (int j = 0; j <= i; j++) {
        // Closed-closed
        if (dp[u][i - j][0] != -INF && dp[v][j][0] != -INF) {
          ll maxVal = max(dpNew[i][0], dp[u][i - j][0] + dp[v][j][0]);
          dpNew[i][0] = maxVal;
        }

        // Open-open
        if (j > 0 && dp[u][i - j][1] != -INF && dp[v][j - 1][1] != -INF) {
          ll maxVal = max(dpNew[i][0], dp[u][i - j][1] + dp[v][j - 1][1]);
          addRootContribution[i] =
              addRootContribution[i] || (maxVal != dpNew[i][0]);
          dpNew[i][0] = maxVal;
        }

        if (i - j <= k && dp[u][i - j + 1][1] != -INF && dp[v][j][1] != -INF) {
          ll maxVal = max(dpNew[i][0], dp[u][i - j + 1][1] + dp[v][j][1]);
          addRootContribution[i] =
              addRootContribution[i] || (maxVal != dpNew[i][0]);
          dpNew[i][0] = maxVal;
        }

        // Open-closed
        if (dp[u][i - j][0] != -INF && dp[v][j][1] != -INF)
          dpNew[i][1] = max(dpNew[i][1], dp[u][i - j][0] + dp[v][j][1]);

        // Closed-open
        if (dp[u][i - j][1] != -INF && dp[v][j][0] != -INF)
          dpNew[i][1] = max(dpNew[i][1], dp[u][i - j][1] + dp[v][j][0]);
      }
    }

    dp[u] = dpNew;
  }

  for (int i = 1; i <= k + 1; i++) {
    if (dp[u][i][1] != -INF)
      dp[u][i][1] += weight[u];
    if (addRootContribution[i] && dp[u][i][0] != -INF)
      dp[u][i][0] += weight[u];
  }

  if (isLeaf) {
    dp[u][1][0] = dp[u][1][1] = weight[u];
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  t(n, k);

  vector<ll> weight(n);
  for (int i = 0; i < n; i++)
    cin >> weight[i];

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].pu(y);
    adj[y].pu(x);
  }

  if (k == 0) {
    cout << weight[0] << endl;
    return;
  }

  /* K + 2 because we can take [0, k + 1] children from each subtree.
     dp[u][i][0] denotes the max weight given that we take i leaves from u's
     subtree. dp[u][i][1] denotes the same with a path that can be
     "continued". This weight is the sum of the nodes (without repetitions)
     from those leaves to the root.
  */
  vector<vector<vector<ll>>> dp(n,
                                vector<vector<ll>>(k + 2, vector<ll>(2, -INF)));
  for (int i = 0; i < n; i++)
    dp[i][0][0] = 0;

  dfs(adj, dp, weight, k);

  for (int i = 0; i < dp.size(); i++) {
    t(i, dp[i]);
  }

  /* It is not necessary to take k + 1 different leaves. In that case, we'll
     take max. We can always take whatever is stored in node 0, so that's the
     default value.
  */
  ll maxAns = weight[0];
  for (int i = 0; i <= k + 1; i++) {
    // maxAns = max(maxAns, dp[0][i][0]);
    maxAns = max(maxAns, dp[0][i][1]);
  }

  cout << maxAns << endl;
}

int main() {
  int t;
  cin >> t;
  for (int h = 1; h <= t; h++) {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}