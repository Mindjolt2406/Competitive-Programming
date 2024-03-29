// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1e18
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
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

void solve() {
    ll n, k, x, y;
    cin >> n >> k >> x >> y;
    multiset<ll> scoresA, scoresB;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        ll value;
        cin >> value;
        if (type == 'A')
            scoresA.insert(value);
        else 
            scoresB.insert(value);
    }

    int counter = 2 * k;
    ll finalScore = 0;
    int leftA = k, leftB = k;
    // t(scoresA, scoresB);
    while (counter--) {
        ll bestA = (scoresA.empty() ? -INF : *scoresA.rbegin());
        ll bestB = (scoresB.empty() ? -INF : *scoresB.rbegin());
        if (bestA > bestB) {
            if (leftA) {
                leftA--;
                finalScore +=  bestA;
                scoresA.erase(scoresA.find(bestA));   
            } else {
                leftB--;
                ll bestScoreForAInB = bestA - x;
                if (bestScoreForAInB > bestB) {
                    finalScore += bestScoreForAInB;
                    scoresA.erase(scoresA.find(bestA));
                } else {
                    finalScore += bestB;
                    scoresB.erase(scoresB.find(bestB));
                }
            }
        } else {
            if (leftB) {
                leftB--;
                finalScore += bestB;
                scoresB.erase(scoresB.find(bestB));
            } else {
                leftA--;
                ll bestScoreForBInA = bestB - y;
                if (bestScoreForBInA > bestA) {
                    finalScore += bestScoreForBInA;
                    scoresB.erase(scoresB.find(bestB));
                } else {
                    finalScore += bestA;
                    scoresA.erase(scoresA.find(bestA));
                }
            }
        }
    } 

    cout << finalScore << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
