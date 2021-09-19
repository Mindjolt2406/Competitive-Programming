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

map<ll, int> dp;

int recur(ll n) {
    if(dp.count(n)) {
        return dp[n];
    }

    if(n == 0) return dp[0] = 0;
    if(n <= 3) return dp[n] = 1;

    bool flag_3 = true, flag_0 = false;
    int index_0 = 0;
    string s = to_string(n);
    for(auto it : s) {
        if(it == '0') {
            flag_0 = true;
            break;
        }
        if(it > '3') {
            flag_3 = false;
            break;
        }
        index_0++;
    }

    // t(n, flag_0, flag_3);

    if(flag_0) {
        string temp = s.substr(0, index_0);
        ll templl = stoll(temp);
        templl--;
        string t = to_string(templl);
        for(int i = index_0; i < s.size(); i++) {
            t += '3';
        }

        ll subNum = stoll(t);
        // t(n, subNum);
        return dp[n] = 1 + recur(n - subNum);
    }
    
    if(flag_3) {
        // t(n, 1);
        return dp[n] = 1;
    }

    // Get biggest base 3 number below n (1 indexed)
    string t;
    bool flag = true;
    for(auto it : s) {
        if(!flag) {
            t += '3';
            continue;
        }
        if(it > '3') {
            t += '3';
            flag = false;
        } else { // no '0'
            t += it;
        }
    }

    ll subNum = stoll(t);
    // t(n, subNum);
    return dp[n] = 1 + recur(n - subNum);
}

int main() {
    __;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << recur(n) << endl;
    }
    int max1 = 0;
    for(int i = 1; i <= 100000; i++) {
        ll tmp = recur(i);
        if(tmp > max1) t(i, tmp);
        max1 = max(max1, (int)tmp);
    }

    t(max1);
    return 0;
}
