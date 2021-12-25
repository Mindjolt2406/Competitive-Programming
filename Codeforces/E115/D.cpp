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

ll getTripleCnt(vector<ll> &sizeArr) {
    ll tripleCnt = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < sizeArr.size(); i++) {
        tripleCnt += sizeArr[i] * sum2;
        sum2 += sum1 * sizeArr[i];
        sum1 += sizeArr[i];
    }

    return tripleCnt;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
        w[i] = mp(x, y);
    }

    vector<ll> sizeArr;
    for (auto it : v)
        if (it.size() != 0)
            sizeArr.push_back(it.size());

    ll tripleCnt = getTripleCnt(sizeArr);

    map<int, ll> totalFreq, currFreq, currFreqCnt;

    for (auto it : v) {
        for (auto x : it) {
            totalFreq[x]++;
        }
    }

    ll cnt2 = 0;
    ll eleLeft = n;
    for (auto it : v) {
        for (auto x : it) {
            if (currFreq.count(x)) {
                cnt2 += currFreq[x] - ((int)it.size() - 1);
            }
            currFreq[x] += (n - (int)it.size() - (totalFreq[x] - 1));
            currFreqCnt[x]++;
        }
    }

    ll cnt3 = 0;
    for (auto it : totalFreq) {
        ll val = it.se;
        cnt3 += (val * (val - 1) * (val - 2)) / 6;
    }

    // cnt2 -= 6 * cnt3;

    // for (auto it : currFreq) {
    //     ll val = it.se;
    //     ll val2 = (val * (val - 1)) / 2;
    //     cnt2 += (val2 * bagFreq[it.fi]);
    //     t(it.fi, it.se, bagFreq[it.fi]);
    // }

    // t(tripleCnt, cnt2, cnt3);

    // t(tripleCnt, cnt2, cnt3);
    ll bothConditions = tripleCnt - cnt2 - cnt3;

    map<int, int> firstDict, secondDict;
    for (auto it : w) {
        firstDict[it.fi]++;
        secondDict[it.se]++;
    }

    vector<ll> firstVecSize, secondVecSize;
    for (auto it : firstDict) {
        firstVecSize.push_back(it.se);
    }

    for (auto it : secondDict) {
        secondVecSize.push_back(it.se);
    }

    ll tripleCnt1 = getTripleCnt(firstVecSize);
    ll tripleCnt2 = getTripleCnt(secondVecSize);

    // t(tripleCnt1, tripleCnt2, bothConditions);
    cout << tripleCnt1 + tripleCnt2 - bothConditions << "\n";
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
