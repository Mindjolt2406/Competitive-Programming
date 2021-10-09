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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}

ll min(ll x, ll y) {return x < y ? x : y;}

int main() {
    __;
    int m, n;
    cin >> m >> n;
    vector<int> maxSoFar(m, -1), minSoFar(m, INF);
    int q;
    cin >> q;
    while (q--) {
        int j, i;
        cin >> j >> i;
        maxSoFar[j] = max(maxSoFar[j], i);
        minSoFar[j] = min(minSoFar[j], i);
    }

    vector<pair<int, int> > v;
    for (int j = 0; j < m; j++) {
        if (maxSoFar[j] + 1) {
            v.push_back(mp(maxSoFar[j], 1));
            v.push_back(mp(minSoFar[j], 0));
        }
    }

    sort(v.begin(), v.end());
    
    ll currAns = 0;
    int minLeft = v[0].fi;
    // t(v, minLeft);
    ll numLeft = 0, numRight = 0;
    for (int j = 0; j < m; j++) {
        if (maxSoFar[j] + 1) {
            numRight++;
            currAns += (maxSoFar[j] - minLeft) * 2;
        }
    }

    ll minAns = currAns;
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            currAns += (numLeft * (v[i].fi - v[i-1].fi)) * 2;
            currAns -= (numRight * (v[i].fi - v[i-1].fi)) * 2;
            minAns = min(minAns, currAns);
        }
        // t(i, v[i].fi, numLeft, numRight, currAns, minAns);
        if (v[i].se) 
            numRight--;
        else 
            numLeft++;
    }

    cout << minAns + (m - 1) << "\n";
    return 0;
}
