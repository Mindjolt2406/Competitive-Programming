#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
#define MOD 1000000007
#define EPS 1e-10
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

void solve() {
    int m, n;
    cin >> m >> n;
    set<int> checkPoints;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        checkPoints.insert(a);
    }

    vector<pair<int, int> > car(n);
    for(int i = 0; i < n; i++) cin >> car[i].fi;
    for(int i = 0; i < n; i++) cin >> car[i].se;

    map<int, vector<pair<int, int> > > checkCarRight;
    map<int, vector<pair<int, int> > > checkCarLeft;
    map<int, vector<pair<int, int> > > intervals;
    for(int i = 0; i < n; i++) {
        auto it = checkPoints.lower_bound(car[i].fi);
        if(*it != car[i].fi) {
            intervals[*it].pu(car[i]);
        }

        if(car[i].se > 0) {
            // Get checkpoint to the right of car[i].fi
            int checkPoint = *checkPoints.lower_bound(car[i].fi);
            checkCarRight[checkPoint].pu(car[i]);
        } else {
            auto it = checkPoints.lower_bound(car[i].fi);
            if(it != checkPoints.begin()) {
                it--;
                checkCarLeft[(*it)].pu(car[i]);
            }
        }
    }

    for(auto it : intervals) {
        vector<pair<int, int> > v = it.se;
        sort(v.begin(), v.end());
        bool isPos = false;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].se > 0) {
                isPos = true;
            } else {
                if(isPos) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    for(auto it : checkCarLeft) {
        ld maxTime = -INF;
        vector<pair<int, int> > v = it.se;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            ld currTime = abs(v[i].fi - it.fi) / abs((ld)v[i].se);
            if(currTime > maxTime - EPS) {
                maxTime = currTime;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for(auto it : checkCarRight) {
        ld maxTime = -INF;
        vector<pair<int, int> > v = it.se;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            ld currTime = abs(v[i].fi - it.fi) / abs((ld)v[i].se);
            if(currTime > maxTime - EPS) {
                maxTime = currTime;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
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
