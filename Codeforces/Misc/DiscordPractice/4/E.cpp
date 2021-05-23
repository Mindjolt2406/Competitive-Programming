#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
#define MOD 1000000007
#define EPS 1e-15
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
ld min(ld x, ld y) {return x < y ? x : y;}

bool getIntersection(pair<ld, ld> &p1, pair<ld, ld> &p2, pair<ld, ld> &finalAns) {
    ld first = max(p1.fi, p2.fi);
    ld second = min(p1.se, p2.se);

    if(first > second + EPS) {
        return false;
    }
    finalAns = make_pair(first, second);
    return true;
}

bool check(vector<pair<ll, ll> > &v, ld mid) {

    pair<ld, ld> temp = mp(-INF, INF);
    for(auto pair2 : v) {
        ll y = pair2.se, x = pair2.fi;
        if(abs(y-mid) > mid) return false;
        ld c = mid * cos(asin(abs(y - mid) / mid));
        // t(c, x, y, mid);
        pair<ld, ld> it = make_pair(-c + x, c + x);
        if(!getIntersection(temp, it, temp)) {
            return false;
        }
    }
    return true;
}

int main() {
    __;
    cerr << fixed << setprecision(12);
    int n;
    cin >> n;
    vector<pair<ll, ll> > v(n);

    bool isPos = false, isNeg = false;
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        if(v[i].se < 0) isNeg = true;
        else isPos = true;
        v[i].se = abs(v[i].se);
    }

    if(isPos && isNeg) cout << -1 << endl;
    else {
        ld beg = 0, end = 1e18, ans = 1e18;
        for(int i = 0; i < 100; i++) {
            ld mid = (beg + end) / 2;
            bool checkFlag = check(v, mid);
            // t(checkFlag, mid);
            if(check(v, mid)) {
                end = mid - EPS;
                ans = mid;
            } else {
                beg = mid + EPS;
            }
        }

        cout << fixed << setprecision(12);
        cout << ans << endl;
    }
    return 0;
}
