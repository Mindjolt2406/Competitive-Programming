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

void prettyPrint(vector<int> &indices, int n) {
    string s;
    for (int i = 0; i < n; i++)
        s += '1';

    t(s);
    for (int i = 0; i < indices.size(); i++) {
        int numTimes = (1 << i);
        int currIndex = indices[i];
        currIndex--;
        for (int i = currIndex; i < currIndex + numTimes; i++)
            s[i] = (s[i] == '1' ? '0' : '1');
        t(s);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << "YES\n";
        cout << 0 << "\n";
        return;
    } else if (k % 2 == 0) {
        cout << "NO\n";
    } else {
        n = k;
        vector<int> numBits;
        int tempN = n;
        while (tempN) {
            numBits.push_back((tempN & 1));
            tempN >>= 1;
        }

        int currIndex = n + 1;
        int i = 0;
        vector<int> ansIndex;
        while (i < numBits.size()) {
            int lastZeroIndex = -1;
            for (int j = i + 1; j < numBits.size(); j++) {
                if (numBits[j])
                    break;
                lastZeroIndex = j;
            }

            if (lastZeroIndex + 1) {
                int tempIndex = currIndex;
                tempIndex -= (1 << lastZeroIndex);

                currIndex = tempIndex;
                for (int j = i; j < lastZeroIndex; j++) {
                    ansIndex.push_back(tempIndex);
                    tempIndex += (1 << j);
                }

                ansIndex.push_back(currIndex); // Starting tempIndex.
                currIndex = tempIndex;         // Make it out of bounds.
                i = lastZeroIndex + 1;
            } else {
                currIndex -= (1 << i);
                ansIndex.push_back(currIndex);
                i++;
            }
        }

        cout << "YES\n";
        cout << ansIndex.size() << "\n";
        for (auto index : ansIndex)
            cout << index << "\n";

        // prettyPrint(ansIndex, n);
    }
}

int main() {
    // __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
111011111

*/