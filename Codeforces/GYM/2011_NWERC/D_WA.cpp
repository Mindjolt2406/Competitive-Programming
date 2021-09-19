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

bool check(int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true; 
}

bool checkUp(int i, int j, int n, int m, vector<string> &v) {
    return check(i-1, j, n, m) && v[i-1][j] == 'W';
}

bool checkLeft(int i, int j, int n, int m, vector<string> &v) {
    return check(i, j-1, n, m) && v[i][j-1] == 'W';
}

bool checkRight(int i, int j, int n, int m, vector<string> &v) {
    return check(i, j+1, n, m) && v[i][j+1] == 'W';
}

bool checkDown(int i, int j, int n, int m, vector<string> &v) {
    return check(i+1, j, n, m) && v[i+1][j] == 'W';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'B') {
                if(checkUp(i, j, n, m, v) && checkLeft(i, j, n, m, v)) {
                    v[i-1][j] = '$';
                    v[i][j-1] = '$';
                    v[i][j] = '$';
                } else if(checkLeft(i, j, n, m, v) && checkDown(i, j, n, m, v)) {
                    v[i][j-1] = '$';
                    v[i+1][j] = '$';
                    v[i][j] = '$';
                } else if(checkUp(i, j, n, m, v) && checkRight(i, j, n, m, v)) {
                    v[i-1][j] = '$';
                    v[i][j+1] = '$';
                    v[i][j] = '$';
                } else if(checkDown(i, j, n, m, v) && checkRight(i, j, n, m, v)) {
                    v[i+1][j] = '$';
                    v[i][j+1] = '$';
                    v[i][j] = '$';
                }
            }
        }
    }

    bool isPoss = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            isPoss = isPoss && (v[i][j] == '.' || v[i][j] == '$');
        }
    } 

    cout << (isPoss ? "YES" : "NO") << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
