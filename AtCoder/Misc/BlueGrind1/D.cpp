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

ld max(ld x, ld y) {return x > y ? x : y;}

int main() {
    __;
    int n;
    ld maxSum, totalSum;
    cin >> n >> maxSum >> totalSum;
    vector<int> v(n);
    vector<ll> pref(n);
    for (auto &x : v)
        cin >> x;

    pref[0] = v[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + v[i];

    vector<ld> ans(n + 1);
    vector<ld> maxSumNode(n + 1);
    vector<ld> totalSumNode(n + 1);
    totalSumNode[n] = totalSum;
    maxSumNode[n] = maxSum;
    for (int i = n - 1; i >= 0; i--) {
        pair<ld, pair<ld, ld>> ansPair = {-1, {-1, -1}};
        for (int j = n; j > i; j--) {
            int currIndex = i, prevMaxIndex = j;
            int numsRightMax = prevMaxIndex - currIndex;
            ld currContribution = totalSumNode[j] / numsRightMax;
            if (currContribution > maxSumNode[j] + EPS) {
                currContribution = maxSumNode[j];
            }

            ll prefSum = pref[j - 1] - (( i == 0) ? 0 : pref[i - 1]);
            ld currTotal = totalSumNode[j] - numsRightMax * currContribution;
            ansPair = max(ansPair, {ans[j] + currContribution * prefSum, {currTotal, currContribution}});
        }
        ans[i] = ansPair.first, totalSumNode[i] = ansPair.second.first, maxSumNode[i] = ansPair.second.second;
    }

    // t(ans);
    // t(maxSumNode);
    // t(totalSumNode);
    cout << fixed << setprecision(12);
    cout << ans[0] << endl;
    return 0;
}
