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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        vector<pair<ll, ll> > dec;
        int inc = 0;
        int diff = -1;
        bool flag = true;
        for(int i = 0; i < n - 1; i++) {
            if(v[i] <= v[i+1]) {
                inc++;
                if(diff == -1) diff = v[i+1] - v[i];
                else {
                    if(diff != v[i+1] - v[i]) {
                        flag = false;
                        break;
                    }
                }
            } else {
                dec.push_back(make_pair(v[i], v[i+1]));
            }
        }

        if(inc == 0 || dec.size() == 0) {
            int diff = 0;
            bool flag = true;
            if(v.size() == 1) cout << 0 << endl;
            else {
                diff = v[1] - v[0];
                for(int i = 1; i < n; i++) {
                    if(diff != v[i] - v[i-1]) flag = false;
                }

                cout << (flag ? 0 : -1) << endl;
            }
            continue;
        }
        if(flag) {
            bool flag2 = true;
            pair<ll, ll> temp = dec[0];
            ll m = temp.fi + diff - temp.se;
            if(m <= 0) flag2 = false;
            else {
                for(auto it : dec) {
                    if((it.fi + diff) % m != it.se) flag2 = false;
                }
            }

            for(auto it : v) if(it >= m) flag2 = false;

            if(flag2) {
                cout << m << " " << diff << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
