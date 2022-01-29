// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    if (((n + a - 1) / a) > b || a + b > n + 1) {
        cout << -1 << endl;
        return ;
    }

    int blockSize = (n - a + b - 1) / b;
    int numWritten = 0;
    int numBlocksLeft = b;
    vector<int> ans(n);
    for (int i = n - a; i < n; ++i) {
        ans[i - (n - a)] = i + 1;
    }

    numWritten += a;
    int startBlockNum = n - a;
    numBlocksLeft--;
    bool writeOne = false;
    for (int i = a; i < n;) {
        int currNum = n - numWritten;
        if (writeOne) {
            while (i < n) {
                ans[i++] = currNum--;
            }
            break;
        } else if (currNum - a < numBlocksLeft - 1) {
            int numsToWrite = currNum - numBlocksLeft + 1;
            int startNum = numBlocksLeft;
            while (numsToWrite--) {
                ans[i++] = startNum++;
                numWritten++;
            }
            writeOne = true;
        } else {
            int startNum = currNum - a + 1;
            for (int j = 0; j < a; ++j) {
                ans[i++] = startNum++;
                numWritten++;
            }
            numBlocksLeft--;
        }
    }

    for (auto it : ans)
        cout << it << " " ;
    cout << endl;

    // int lisForward = lis(ans);
    // reverse(ans.begin(), ans.end());
    // int lisBackward = lis(ans);

    // set<int> s(ans.begin(), ans.end());
    // assert(lisForward == a);
    // assert(lisBackward == b);
    // assert(s.size() == n);
    // t("assertion true");
}

int main() {
    __;
    // const int N = 8;
    // vector<int> v(N);
    // for (int i = 0; i < N; ++i)
    //     v[i] = i + 1;
    

    // set<int> s;
    // set<pair<int, int>> sp;
    // do {
    //     vector<int> w = v;
    //     int lisForward = lis(w);
    //     reverse(w.begin(), w.end());
    //     int lisBackward = lis(w);
    //     int sumLis = lisForward + lisBackward;
    //     s.insert(sumLis);
    //     sp.insert({lisForward, lisBackward});
    //     // if (max(lisForward, lisBackward) < N / 2)
    //     //     t(v, lisForward, lisBackward);
    //     assert(max(lisForward, lisBackward) >= sqrt(N));
    // } while (next_permutation(v.begin(), v.end()));

    // t(sp);
    // while (100) {
    //     solve();
    // }

    solve();
    return 0;
}

/*
sp : {(1, 8), (2, 4), (2, 5), (2, 6), (2, 7), (3, 3), (3, 4), (3, 5), (3, 6), (4, 2), 
(4, 3), (4, 4), (4, 5), (5, 2), (5, 3), (5, 4), (6, 2), (6, 3), (7, 2), (8, 1)}
*/