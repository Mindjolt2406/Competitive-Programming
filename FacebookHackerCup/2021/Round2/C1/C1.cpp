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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

void calculatePref(vector<string> &v, vector<vector<int>> &prefSum) {
    int m = prefSum[0].size(), n = prefSum.size();
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            prefSum[i][j] = (v[i][j]  == 'X');
            if (i > 0) 
                prefSum[i][j] += prefSum[i-1][j];
        }
    }
}

int query(int j, int i1, int i2, vector<vector<int>> &prefSum) {
    if (i1 > i2) swap(i1, i2);
    i1 = max(i1, 0);
    i2 = min(i2, (int)prefSum.size() - 1);

    return prefSum[i2][j] - (i1 == 0 ? 0 : prefSum[i1-1][j]);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k--;
    vector<string> v(n);
    for (auto &s : v)
        cin >> s;
    
    vector<vector<int>> prefSum(n, vector<int>(m));
    calculatePref(v, prefSum);

    // Calculating min by moving down.
    int minAns = INF;
    for (int movesDown = 0; movesDown < n; movesDown++) {
        int currAns = movesDown;
        for (int j = 0; j < m; j++) {
            // Levitate car if after moving down, the car exists on the mat[k][j]th position.
            int carNum = query(j, k-movesDown, n-1, prefSum);
            int currEmpty = ((movesDown <= k) ? v[k-movesDown][j] != 'X' : true);
            currEmpty = currEmpty && (carNum < n - k);
            currAns += !currEmpty;
        }
        // t(movesDown, currAns);
        minAns = min(minAns, currAns);
    }

    for (int movesUp = 0; movesUp < n; movesUp++) {
        int currAns = movesUp;
        for (int j = 0; j < m; j++) {
            // Levitate car if after moving up, the car exists on the mat[k][j]th position.
            int carNum = query(j, 0, k + movesUp, prefSum);
            int currEmpty = ((movesUp < n - k) ? v[k+movesUp][j] != 'X' : true);
            currEmpty = currEmpty && (carNum <= k);
            currAns += !currEmpty;
        }
        // t(movesUp, currAns);
        minAns = min(minAns, currAns);
    }

    cout << minAns << "\n";
}

int main() {
    __;
    int t;
    cin >> t;
    for (int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
