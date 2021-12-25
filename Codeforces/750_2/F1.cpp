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

typedef struct BIT // int
{
    vector<int> bit;
    int n;

    void init(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) {
            res += bit[i];
        }
        return res;
    }

    void inc(int i, int delta) {
        for (; i < n; i = i | (i + 1)) {
            bit[i] += delta;
        }
    }

    int getsum(int l, int r) {
        // If l==0, sum(-1) automatically returns the default calue of res, 0
        return sum(r) - sum(l - 1);
    }

    void init(vector<int> v) {
        init(v.size());
        for (int i = 0; i < v.size(); i++)
            inc(i, v[i]);
    }
} BIT;

const int N = 1030;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    vector<BIT> bits(N);
    for (auto &bit : bits) {
        bit.init(N);
    }

    bits[v[0]].inc(v[0], 1);
    bits[0].inc(0, 1);

    for (int i = 1; i < n; i++) {
        int val = v[i];
        for (int j = 0; j < N; j++) {
            if ((j ^ val) < N) {
                int newVal = (j ^ val);
                if (bits[newVal].sum(val))
                    bits[j].inc(val, 1);
            }
        }
    }

    vector<int> ans;
    for (int j = 0; j < N; j++) {
        if (bits[j].sum(N - 1))
            ans.push_back(j);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}

int main() {
    __;
    solve();
    return 0;
}
