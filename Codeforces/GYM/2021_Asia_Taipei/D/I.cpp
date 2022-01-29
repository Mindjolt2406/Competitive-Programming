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

#define N 11000
bool dpOdd[110][N] = {0};
bool dpEven[110][N] = {0};
// const int N = 13;

void solve() {
    int n;
    cin >> n;
    vector<int> oddNums(n), evenNums(n);
    int oddSum = 0, evenSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> oddNums[i];
        oddSum += oddNums[i] * (i + 1);
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> evenNums[i];
        evenSum += evenNums[i] * (i + 1);
    }
    
    if (oddSum > evenSum) {
        cout << -1 << endl;
        return ;
    } else if (oddSum == evenSum) {
        cout << 0 << endl;
        return ;
    }

    int diff = evenSum - oddSum;
    if (diff > N) {
        cout << -1 << endl;
        return ;
    }


    vector<int> ones, twos;
    for (int i = 0; i < n; ++i) {
        if (oddNums[i] == 1) 
            ones.push_back(i + 1);
        if (evenNums[i] == 2) 
            twos.push_back((i + 1));
    }

    int m = min((int) ones.size(), (int) twos.size());
    memset(dpOdd, 0, sizeof(dpOdd));
    memset(dpEven, 0, sizeof(dpEven));
    
    dpOdd[0][0] = dpEven[0][0] = true;

    // t(ones, twos, diff);
    // For each index
    for (int i = 0; i < ones.size(); ++i) {
        // For each "time"
        for (int j = m; j > 0; --j) {
            for (int k = 0; k < N; ++k) {
                // Take the number
                if (k >= ones[i])
                    dpOdd[j][k] = dpOdd[j - 1][k - ones[i]] || dpOdd[j][k];
            }
        }
    }

    // For each index
    for (int i = 0; i < twos.size(); ++i) {
        // For each "time"
        for (int j = m; j > 0; --j) {
            for (int k = 0; k < N; ++k) {
                // Take the number
                if (k >= twos[i])
                    dpEven[j][k] = dpEven[j - 1][k - twos[i]] || dpEven[j][k];
            }
        }
    }

    int currIndex = -1;
    // t(oddSum, evenSum, diff);
    for (int i = m; i > 0; --i) {
        for (int j = 0; j < N; ++j) {
            int rightWeight = (diff - j);
            if (rightWeight >= N || rightWeight < 0)
                break;
            
            if (dpOdd[i][j] && dpEven[i][rightWeight]) {
                currIndex = i;
                // t(i, j, rightWeight, ones, twos, diff);
            }
        }
    }

    // t(dpOdd, dpEven);
    // t(currIndex);
    cout << currIndex << endl;
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
