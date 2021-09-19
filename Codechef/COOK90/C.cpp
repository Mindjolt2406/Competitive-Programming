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

bool check(vector<int> &v, int index, bool checkFlag, bool prevSwap, bool currSwap) {
    int n = v.size();
    int i = index;
    int a, b, c, d;
    // t(n, i-1, n-i);
    int lastIndex = (n+1)/2 - 1;

    a = v[i-1], b = v[i], c = v[n-1-i], d = v[n-i];
    if(prevSwap) swap(a, d);
    if(currSwap) swap(b, c);

    bool firstEven = ((i-1)%2 == 0);
    bool secondEven = ((n-i-1) % 2 == 0);

    bool firstFlag = false, secondFlag = false, thirdFlag = true;
    if(checkFlag) { // even > odd
        firstFlag = (firstEven ? (a > b) : (a < b));
        secondFlag = (secondEven ? (c > d) : (c < d));

        if(n%2 == 0 && lastIndex == i) {
            thirdFlag = (i % 2 == 0 ? b > c : b < c);
            t(thirdFlag, b, c, i);
        }
    } else {
        firstFlag = (firstEven ? (a < b) : (a > b));
        secondFlag = (secondEven ? (c < d) : (c > d));
        if(n%2 == 0 && lastIndex == i) {
            thirdFlag = (i % 2 == 0 ? b < c : b > c);
            t(thirdFlag, b, c, i);
        }
    }

    // t(prevSwap, currSwap);
    return firstFlag && secondFlag && thirdFlag;
}

void solver(vector<int> &v, bool flag, int &ans) {
    int n = v.size();
    vector<vector<int> > dp((n+1)/2, vector<int>(2, INF));

    dp[0][0] = 0;
    dp[0][1] = 1;

    int tempAns = INF;
    for(int i = 1; i < (n + 1) / 2; i++) {
        if(check(v, i, flag, false, false)) {
            // t(i, flag, 0, 0);
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        } 

        if(check(v, i, flag, true, false)) {
            // t(i, flag, 1, 0);
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }

        if(check(v, i, flag, false, true)) {
            // t(i, flag, 0, 1);
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
        }

        if(check(v, i, flag, true, true)) {
            // t(i, flag, 1, 1);
            dp[i][1] = min(dp[i][1], dp[i-1][1] + 1);
        }
    }

    // t(dp);

    ans = min(ans, dp[(n+1)/2 - 1][0]);
    ans = min(ans, dp[(n+1)/2 - 1][1]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    if(n == 2) {
        if(v[0] == v[1]) cout << -1 << endl;
        else cout << 0 << endl;
        return;
    }

    int ans = INF;
    solver(v, true, ans);
    solver(v, false, ans);

    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
