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

const int N = 2e5 + 10;

int main() {
    __;
    int n;
    cin >> n;
    vector<int> freq(N);
    vector<int> readCounts(n);
    vector<int> favMessage(n);
    int maxK = 0;
    for (int i = 0; i < n; ++i) {
        int m, r;
        cin >> m >> readCounts[i];
        freq[m]++;
        favMessage[i] = m;
        maxK = max(maxK, readCounts[i]);
    }

    vector<ld> bestExpectedValues(N);
    vector<pair<ld, int> > messageExpectedValues(N);
    ld bestExpectedValueSoFar = 0;
    int numBestToTake = 0;
    vector<int> bestMessages;
    for (int k = 1; k <= maxK; ++k) {
        messageExpectedValues.assign(N, mp(0, -1));
        for (int i = 0; i < n; ++i) {
            messageExpectedValues[favMessage[i]].se = favMessage[i];
            if (readCounts[i] >= k)
                messageExpectedValues[favMessage[i]].fi++;
            else
                messageExpectedValues[favMessage[i]].fi += ((ld) readCounts[i] / k);
        }

        sort(messageExpectedValues.begin(), messageExpectedValues.end());
        reverse(messageExpectedValues.begin(), messageExpectedValues.end());
        for (int i = 0; i < k; ++i) {
            bestExpectedValues[k] += messageExpectedValues[i].fi;
        }

        if (bestExpectedValues[k] > bestExpectedValueSoFar) {
            bestExpectedValueSoFar = bestExpectedValues[k];
            numBestToTake = k;
            bestMessages.clear();
            for (int i = 0; i < k; ++i) {
                bestMessages.push_back(messageExpectedValues[i].se);
            }
        }

        t(messageExpectedValues);
    }

    cout << numBestToTake << endl;
    for (auto it : bestMessages)
        cout << it << " ";
    cout << endl;

    return 0;
}

/*

x_1 + x_2 .. + x_n / n
x_{n+1}

(x_1 + x_2 .. + x_n + x_{n+1}) / n + 1 <?> (x_1 + x_2 .. + x_n) / n
n * (x_1 + ... x_n) + x_{n + 1} * n <?> (x_1 + x_2 + ... + x_n) * (n + 1)
x_{n+1} * n <?> x_1 + x_2 .. + x_n
Wkt x_i >= x_{n+1}, 1 <= i <= n
Hence, 
(x_1 + x_2 .. + x_n + x_{n+1}) / n + 1 < (x_1 + x_2 .. + x_n) / n
*/
