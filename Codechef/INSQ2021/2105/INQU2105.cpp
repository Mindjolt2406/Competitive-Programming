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
template <class A, class B> ostream& operator<<(ostream& os, const map<A, B>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on


typedef struct Med {
    ll p = 0, q = 0, cost = 0;
} Med;

ll min(ll x, ll y) {return x < y ? x : y;}

int main() {
    __;
    int p, q, N;
    cin >> p >> q >> N;

    int gp = __gcd(p, q);
    p /= gp;
    q /= gp;
    
    vector<Med> meds(N);
    for (int i = 0; i < N; ++i) {
        cin >> meds[i].p >> meds[i].q >> meds[i].cost;
    }

    int midPoint = (N + 1) / 2;
    map<pair<int, int>, int> medsFirst, medsSecond;
    for (int i = 0; i < (1 << midPoint); ++i) {
        Med med;
        for (int j = 0; j < midPoint; ++j) {
            if ((i >> j) & 1) {
                med.p += meds[j].p;
                med.q += meds[j].q;
                med.cost += meds[j].cost;
            }
        }

        if (medsFirst.count({med.p, med.q})) {
            if (med.cost < medsFirst[{med.p, med.q}]) {
                medsFirst[{med.p, med.q}] = med.cost;
            }
        } else {
            medsFirst[{med.p, med.q}] = med.cost;
        }
    }

    for (int i = 0; i < (1 << (N - midPoint)); ++i) {
        Med med;
        for (int j = 0; j < (N - midPoint); ++j) {
            if ((i >> j) & 1) {
                med.p += meds[j + midPoint].p;
                med.q += meds[j + midPoint].q;
                med.cost += meds[j + midPoint].cost;
            }
        }

        if (medsSecond.count({med.p, med.q})) {
            if (med.cost < medsSecond[{med.p, med.q}]) {
                medsSecond[{med.p, med.q}] = med.cost;
            }
        } else {
            medsSecond[{med.p, med.q}] = med.cost;
        }
    }

    ll totalCost = INF;
    for (auto med1 : medsFirst) {
        for (auto med2 : medsSecond) {
            Med med;
            med.p = med1.fi.fi + med2.fi.fi;
            med.q = med1.fi.se + med2.fi.se;
            med.cost = med1.se + med2.se; 
            if (med.p != 0 || med.q != 0) {
                int g = __gcd(med.p, med.q);
                if (med.p / g == p && med.q / g == q) 
                    totalCost = min(totalCost, med.cost);
            }
        }
    }

    // t(medsSecond, medsFirst);

    cout << ((totalCost == INF) ? -1 : totalCost) << endl;
    return 0;
}
