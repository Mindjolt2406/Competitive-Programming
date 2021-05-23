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

ld max(ld x, ld y) {return x > y ? x : y;}

int main() {
    __;
    int n, d;
    cin >> n >> d;

    vector<ll> v(n);
    vector<ld> w(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = log2(v[i]);
    }

    vector<vector<ld> > dp(n, vector<ld> (10, -1));
    vector<vector<bool> > taken(n, vector<bool> (10));
    vector<vector<pair<int, int> > > back(n, vector<pair<int, int> > (10, mp(-1, -1)));

    dp[0][v[0]%10] = w[0];
    taken[0][v[0]%10] = true;

    for(int i = 1; i < n; i++) {
        int digit = v[i]%10;
        dp[i][digit] = w[i];
        taken[i][digit] = true;

        // Don't take v[i] in the solution
        for(int j = 0; j < 10; j++) {
            if(dp[i-1][j] > dp[i][j]) {
                taken[i][j] = false;
                back[i][j] = (taken[i-1][j] ? mp(i-1, j) : back[i-1][j]);
                // dp[i][j] = dp[i-1][j];
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]); 
        }

        // Take v[i] in the solution
        for(int j = 0; j < 10; j++) {
            int newDigit = (j * digit) % 10;
            if(dp[i-1][j] != -1 && dp[i-1][j] + w[i] > dp[i][newDigit]) {
                dp[i][newDigit] = dp[i-1][j] + w[i];
                taken[i][newDigit] = true;
                back[i][newDigit] = (taken[i-1][j] ? mp(i-1, j) : back[i-1][j]);
            }
        }
    }

    // t(dp[n-1][d], pow(2, dp[n-1][d]));
    if(dp[n-1][d] == -1) {
        cout << -1 << endl;
    } else {
        // Write backtracking code
        pair<int, int> curr = (taken[n-1][d] ? mp(n-1, d) : back[n-1][d]);
        int currIndex = curr.fi, currDigit = curr.se;

        int value = dp[n-1][d];
        vector<int> ans;
        while(currIndex != -1) {
            ans.push_back(currIndex);
            curr = back[currIndex][currDigit]; 
            currIndex = curr.fi, currDigit = curr.se;
            // t(value, tempIndex);
        }

        cout << ans.size() << endl;
        for(auto it : ans) cout << v[it] << " "; cout << endl;
    }

    // t(dp);
    return 0;
}
