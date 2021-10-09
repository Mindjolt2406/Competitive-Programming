#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
#define t1(x) cerr << #x << "=" << x << endl
#define t2(x, y) cerr << #x << "=" << x << " " << #y << "=" << y << endl
#define t3(x, y, z)                                                            \
    cerr << #x << "=" << x << " " << #y << "=" << y << " " << #z << "=" << z   \
         << endl
#define t4(a, b, c, d)                                                         \
    cerr << #a << "=" << a << " " << #b << "=" << b << " " << #c << "=" << c   \
         << " " << #d << "=" << d << endl
#define t5(a, b, c, d, e)                                                      \
    cerr << #a << "=" << a << " " << #b << "=" << b << " " << #c << "=" << c   \
         << " " << #d << "=" << d << " " << #e << "=" << e << endl
#define t6(a, b, c, d, e, f)                                                   \
    cerr << #a << "=" << a << " " << #b << "=" << b << " " << #c << "=" << c   \
         << " " << #d << "=" << d << " " << #e << "=" << e << " " << #f << "=" \
         << f << endl
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define tr(...) GET_MACRO(__VA_ARGS__, t6, t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __                                                                     \
    freopen("input.txt", "r", stdin);                                          \
    freopen("output.txt", "w", stdout);
#define fastio()                                                               \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(0)
#define MEMS(x, t) memset(x, t, sizeof(x));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
//#define MOD 1000000007
#define endl "\n"
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

int n;
string s;
const int N = 705;
int max_times_repeated[N][N];

int dp[N][N];

int rec(int l, int r) {
    if (l == r) {
        return 1;
    }
    int &ans = dp[l][r];
    if (ans >= 0)
        return ans;
    ans = inf;
    int totlen = r - l + 1;
    for (int i = l; i < r; i++) {
        int len = i - l + 1;
        ans = min(ans, rec(l, i) + rec(i + 1, r));
        if (totlen % len != 0)
            continue;
        int ns = totlen / len;
        if (max_times_repeated[l][i] >= ns) {
            ans = min(ans, rec(l, i));
        }
    }
    return ans;
}
int32_t main() {
    fastio();
    cin >> n;
    cin >> s;
    MEMS(dp, -1);
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int pt = l;

            for (int j = l; j < n; j++) {
                if (s[j] != s[pt])
                    break;
                if (pt == r) {
                    max_times_repeated[l][r]++;
                    pt = l;
                } else {
                    pt++;
                }
            }
        }
    }
    cout << rec(0, n - 1);
}
