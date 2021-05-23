#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

bool check(vector<ll> &v, int k, ll mid) {
    int i = 0;
    int n = v.size();
    vector<vector<bool> > dp(n, vector<bool>(2));
    deque<int> dq;
    dq.push_back(0);
    dp[0][0] = true;
    dp[0][1] = (k <= 1);

    // dp[i][0] -> Can I open at i? 
    // dp[i][1] -> Can I close at i? 
    for(int i = 1; i < n; i++) {
        while(!dq.empty()) {
            int index = dq.front();
            if(v[i] - v[index] > mid) {
                dq.pop_front();
            } else break;
        }

        // t(i, dq.empty(), dq.front());

        // Open at i if you can close at i-1
        if(dp[i-1][1]) {
            dp[i][0] = 1;
            // Add i to list of possible openings
            dq.push_back(i);
        }

        if(!dq.empty()) {
            int index = dq.front();
            if(mid == 45) t(i, index, v);
            if(i - index + 1 >= k) dp[i][1] = true;
        }
    }

    return dp[n-1][1];
}

int main() {
    __;
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    ll beg = 0, end = v.back() - v.front(), ans = v.back() - v.front();
    while(beg <= end) {
        ll mid = (beg + end) >> 1;
        if(check(v, k, mid)) {
            end = mid-1;
            ans = mid;
        } else {
            beg = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
