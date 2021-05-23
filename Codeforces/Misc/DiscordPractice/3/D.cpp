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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll max(ll x, ll y) {return x > y ? x : y;}

void addToQueue(deque<ll> &dq, ll x) {
    while(!dq.empty() && x > dq.back()) {
        dq.pop_back();
    }

    dq.push_back(x);
}

ll getMaxFromQueue(deque<ll> &dq) {
    return dq.front();
}

void removeFromQueue(deque<ll> &dq, ll x) {
    if(!dq.empty() && dq.front() == x) {
        dq.pop_front();
    }
}

int main() {
    __;
    ll n, k, x;
    cin >> n >> k >> x;
    vector<deque<ll> > getMax(x + 1);
    vector<vector<ll> > dp(n, vector<ll>(x + 1, -1));

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // Initialise DP
    for(int i = 0; i < k; i++) {
        dp[i][1] = v[i];
    }

    for(int i = 0; i <= x; i++) addToQueue(getMax[i], -1);

    dp[0][1] = v[0];
    addToQueue(getMax[1], dp[0][1]);

    for(int i = 1; i < n; i++) {
        for(int j = 2; j <= x; j++) {
            ll maxSoFar = getMaxFromQueue(getMax[j-1]);

            if(maxSoFar != -1) {
                dp[i][j] = maxSoFar + v[i];
            }
        }

        for(int j = 1; j <= x; j++) {
            if(i - k >= 0) {
                removeFromQueue(getMax[j], dp[i-k][j]);
            }
            addToQueue(getMax[j], dp[i][j]);
        }
    }

    // t(dp);

    ll finalAns = -1;
    for(int i = max(n-k, 0); i < n; i++) {
        for(int j = 1; j <= x; j++) {
            finalAns = max(finalAns, dp[i][j]);
        }
    }

    cout << finalAns << endl;
    return 0;
}
