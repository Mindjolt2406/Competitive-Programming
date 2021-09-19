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

bool query(vector<int> &indices, int mid, int i) {
    cout << "? ";
    for(int i = 0; i < mid; i++) {
        cout << indices[i] << " ";
    }
    cout << i << endl;

    int ans;
    cin >> ans;
    if (ans == -1) exit(0);
    
    return (ans > 1);
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> indices;
    indices.pu(1);
    vector<int> finalAns(n);
    finalAns[0] = 1;

    for (int i = 2; i <= n; i++) {
        int beg = 1, end = indices.size(), ans = -1;
        while (beg <= end) {
            int mid = (beg + end) >> 1;
            bool freqTwo = query(indices, mid, i);
            if (freqTwo) {
                ans = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        if (ans == -1) {
            indices.pu(i);
            finalAns[i - 1] = i;
        } else {
            finalAns[i - 1] = finalAns[indices[ans - 1] - 1];
        }
    }

    cout << "! ";
    for(auto it : finalAns) {
        cout << it << " ";
    }
    cout << endl;

    int check;
    cin >> check;
    if (check == -1) exit(0);
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