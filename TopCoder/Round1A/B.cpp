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

class EllysTwinLetters{
    public:
    int getMin(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(26, INF));
        vector<int> finalAns(n, INF);


        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                int currCost = abs(s[i] - 'A' - j) + abs(s[i-1] - 'A' - j);
                for(int k = i-2; k >= 0; k--) {
                    dp[i][j] = min(dp[i][j], currCost + finalAns[k]);
                    currCost += abs(s[k] - 'A' - j);
                }
                dp[i][j] = (dp[i][j] == INF) ? currCost : dp[i][j];
            }

            for(int j = 0; j < 26; j++) {
                finalAns[i] = min(finalAns[i], dp[i][j]);
            }
        }

        // t(dp);
        return finalAns[n-1];
        // for(int i = 0; i < 26; i++) {
        //     dp[0][i][0] = dp[0][i][1] = abs(s[0] - 'A' - i);
        // }

        // for(int i = 1; i < n; i++) {
        //     int currDiff = s[i] - 'A';
        //     for(int j = ; j < 26; j++) {
        //         if(i > 1 || currDiff == j) dp[i][currDiff][0] = min(dp[i][currDiff][0], dp[i-1][j][1]);
        //         dp[i][j][1] = min(dp[i][j][1], min(dp[i-1][j][1], dp[i-1][j][0]) + abs(s[i] - 'A' - j));
        //     }
        // }

        // int ans = INF;
        // for(int j = 0; j < 26; j++) ans = min(ans, dp[n-1][j][1]);

        // t(dp);
        // return ans;
    }
};

int main() {
    __;
    EllysTwinLetters e;
    string s;
    cin >> s;
    cout << e.getMin(s) << endl;
    return 0;
}
