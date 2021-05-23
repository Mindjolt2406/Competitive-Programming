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


int main() {
    __;
    int n, kal;
    cin >> n >> kal;

    string s;
    cin >> s;

    vector<vector<int> > cost(kal, vector<int> (kal));

    for(int i = 1; i < s.size(); i++) {
        cost[s[i] - 'a'][s[i - 1] - 'a']++;
        cost[s[i - 1] - 'a'][s[i] - 'a']++;
    }

    vector<ll> dp(1 << kal, INF), inc(1 << kal);
    dp[0] = 0;



    for(int mask = 0; mask < (1 << kal); mask++) {
        int counter = 0;
        vector<int> set, unset;
        for(int i = 0; i < kal; i++) {
            if((mask & (1 << i))) {
                set.push_back(i);
            } else {
                unset.push_back(i);
            }
        }

        for(auto setIndex : set) {
            for(auto unsetIndex : unset) {
                counter += cost[setIndex][unsetIndex];
            }
        }

        for(auto unsetIndex : unset) {
            int tempCounter = counter;
            for(auto setIndex : set) {
                tempCounter -= cost[setIndex][unsetIndex];
            }
            for(auto unsetIndex2 : unset) {
                if(unsetIndex == unsetIndex2) continue;
                tempCounter += cost[unsetIndex][unsetIndex2];
            }

            int j = unsetIndex;
            if((mask & (1 << j)) == 0) {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + tempCounter);
                inc[mask | (1 << j)] = tempCounter;
            }            
        }
    }

    cout << dp[(1 << kal) - 1] << endl;

    // t(dp);
    return 0;
}

/*
6 - 427
7 - 540
8 - 925
9 - 876
10 - 1200
11 - 2280
12 - 840
13 - 1525
14 - 1853

*/