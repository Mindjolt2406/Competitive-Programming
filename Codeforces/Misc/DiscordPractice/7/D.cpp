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

bool query(int l1, int r1, int l2, int r2, int n) {
    if(l1 > l2) swap(l1, l2);
    if(r1 > r2) swap(r1, r2);

    if(l1 <= 0 || l2 > n || r1 <= 0 || r2 > n) return false;

    cout << "? " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    string s;
    cin >> s;
    if(s == "BAD") exit(0);
    else if(s == "YES") return true;
    else return false;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    __;
    int n;
    cin >> n;
    vector<pair<int, int> > ans;

    ans.pu(mp(n, n));
    for(int i = 0; i < n - 1; i++) {
        pair<int, int> left = mp(ans.back().fi + dx[1], ans.back().se + dy[1]);
        pair<int, int> up = mp(ans.back().fi + dx[3], ans.back().se + dy[3]);

        if(query(left.fi, left.se, 1, 1, n)) {
            ans.pu(left);
        } else {
            ans.pu(up);
        }
    }

    vector<pair<int, int> > frontAns;
    frontAns.pu(mp(1, 1));
    for(int i = ans.size() - 2; i > 0; i--) {
        pair<int, int> p = frontAns.back();
        pair<int, int> right = mp(p.fi + dx[0], p.se + dy[0]);
        pair<int, int> down = mp(p.fi + dx[2], p.se + dy[2]);

        if(query(ans[i].fi, ans[i].se, down.fi, down.se, n)) {
            frontAns.pu(down);
        } else {
            frontAns.pu(right);
        }
        // t(frontAns.back());
    }

    reverse(ans.begin(), ans.end());
    for(auto it : ans) frontAns.pu(it);

    string finalAns;
    for(int i = 1; i < frontAns.size(); i++) {
        if(frontAns[i].fi == frontAns[i-1].fi) finalAns += 'R';
        else finalAns += 'D';
    }

    cout << "! " << finalAns << endl;
    return 0;
}

/*
YES
NO
YES
YES
YES
YES
NO
NO
NO
NO

*/