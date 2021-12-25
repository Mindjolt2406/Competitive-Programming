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

pair<int, int> getCounter(int a, int b) {
    int counter = 0 ,total = 0;
    while (a != 0 || b != 1) {
        // t(a, b, counter);
        if (a == b && a != 1)
            return {INF, -1};
        if (a == 1) {
            counter += max(b - 2, 0);
            total += b;
            break;
        }
        
        if (a >= b) {
            counter += (a - a % b) / b - 1;
            total += (a - a % b) / b;
            a %= b;
        } else {
            counter += (b - b % a) / a - 1;
            total += (b - b % a) / a;
            b %= a;
        }
    }

    // t(counter);
    return {counter, total};
}

int main() {
    __;
    int n, r;
    cin >> n >> r;
    pair<int, pair<int, int>> min1 = {INF, {-1, -1}};
    for (int i = 1; i <= r; ++i) {
        if (__gcd(i, r) == 1) {
            auto p = getCounter(i, r);
            if (p.se != n)
                continue;
            min1 = min(min1, mp(p.fi, mp(i, 0)));
            p = getCounter(r, i);
            if (p.se != n)
                continue;
            min1 = min(min1, mp(p.fi, mp(i, 1)));
        }
    }

    if (min1.fi == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Some processing with min1.se.
        string ans;
        int a = min1.se.fi, b = r;
        if (min1.se.se)
            swap(a, b);
        while (a != 0) {
            if (a >= b) {
                a -= b;
                ans += 'T';
            } else {
                b -= a;
                ans += 'B';
            }
        }

        reverse(ans.begin(), ans.end());
        cout << min1.fi << "\n";
        cout << ans << endl;
    }
    return 0;   
}
