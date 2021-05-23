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
ld max(ld x, ld y) {return x > y ? x : y;}

void solve() {
    const int N = 100, Q = 1e4;
    vector<string> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    vector<ll> suspect(N);

    vector<int> qSum(Q);
    for(int j = 0; j < Q; j++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += v[i][j] - '0';
        }
        qSum[j] = cnt;
    }
    
    vector<pair<int, int> > qPair(Q);
    for(int i = 0; i < Q; i++) {
        qPair[i] = make_pair(qSum[i], i);
    }
    
    sort(qPair.begin(), qPair.end());

    int NUM = 4;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < Q; j++) {
            // if(i == 58 && v[i][j] == '0') t(j, qSum[j], v[i][j]);
            if(v[i][j] == '1' && j <= NUM) {
                suspect[i]+=pow(2, 50 - qPair[j].fi);
            } else if(v[i][j] == '0' && j >= 100-NUM) {
                suspect[i]+=pow(2, qPair[j].fi-50);
            }
        }
    }

    ld max1 = -1, maxIndex = -1;
    for(int i = 0; i < N; i++) {
        if(suspect[i] > max1) {
            max1 = suspect[i];
            maxIndex = i;
        }
    }
     
    cout << maxIndex + 1 << endl;
}


int main() {
    __;
    int t, p;
    cin >> t >> p;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
