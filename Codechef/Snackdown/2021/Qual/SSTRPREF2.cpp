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

void KMP(string &s, vector<int> &p) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int c = p[i - 1];
        while (c > 0 && s[c] != s[i])
            c = p[c - 1];
        if (s[c] == s[i])
            c++;
        p[i] = c;
    }
}

// Fills Z array for given string str[]
void getZarr(string str, vector<int> &Z) {
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void solve() {
    string suffS, prefS, X;
    cin >> suffS >> prefS >> X;

    int suffSize = suffS.size(), prefSize = prefS.size();
    string suffX = suffS + "$" + X;
    string prefX = prefS + "$" + X;

    vector<int> kmp(suffX.size()), zArrAfter(prefX.size());
    KMP(suffX, kmp);
    getZarr(prefX, zArrAfter);

    vector<int> afterX(X.size() + 1, 1);

    for (int i = prefSize + 1; i < prefX.size(); i++)
        afterX[i - prefSize - 1] = zArrAfter[i] + 1;

    // t(kmp, afterX);

    vector<pair<int, int>> sortZ;
    for (int i = 0; i < afterX.size(); i++)
        sortZ.push_back(make_pair(afterX[i], i));

    sort(sortZ.begin(), sortZ.end());
    reverse(sortZ.begin(), sortZ.end());
    // t(sortZ);

    vector<int> prefMax(suffS.size() + 1);
    vector<bool> prefDone(suffS.size() + 1);
    for (auto p : sortZ) {
        int currMax = p.first, currIndex = p.second;
        if (currIndex == 0) {
            prefMax[0] = max(currMax, max(prefMax[0], 1));
            // prefDone[0] = true;
            // t(prefMax[0]);
            continue;
        }

        // t(p);

        int currSize = kmp[currIndex + suffSize];
        while (!prefDone[currSize]) {
            // t(currSize, currMax);
            prefDone[currSize] = true;
            prefMax[currSize] = max(currMax, prefMax[currSize]);
            if (currSize)
                currSize = kmp[currSize - 1];
        }
    }

    // t(prefMax);

    ll finalCnt = 0;
    for (auto it : prefMax)
        finalCnt += it;

    cout << finalCnt << "\n";
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
