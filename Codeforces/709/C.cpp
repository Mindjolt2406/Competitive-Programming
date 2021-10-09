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
        int n, m;
        cin >> n >> m;
        vector<vector<int> > v(m);
        map<int, int> d;
        for(int i = 0; i < m; i++) {
            int kn;
            cin >> kn;
            v[i].resize(kn);
            for(int j = 0; j < kn; j++) {
                cin >> v[i][j];
                d[v[i][j]]++;
            }
        }

        for(auto it : d) d[it.fi] = min(it.se, (m+1)/2);

        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            if(v[i].size() == 1) {
                d[v[i][0]]--;
                ans[i] = v[i][0];
            }
        }

        bool flag = true;
        for(auto it : d) if(it.se < 0) flag = false;

        if(!flag) {
            cout << "NO" << endl;
            continue;
        }

        int max1 = -1, maxIndex = -1;
        for(auto it : d) {
            if(it.se > max1) {
                max1 = it.se;
                maxIndex = it.fi;
            }
        }

        if(max1 == -1) {
            cout << "NO" << endl;
            continue;
        }

        int left = min(max1, (m+1)/2);
        for(int i = 0; i < m; i++) {
            if(v[i].size() > 1) {
                for(int j = 0; j < v[i].size(); j++) {
                    if(v[i][j] == maxIndex && left) {
                        ans[i] = maxIndex;
                        left--;
                        break;
                    }
                }

                if(!ans[i]) {
                    for(int j = 0; j < v[i].size(); j++) {
                        if(v[i][j] != maxIndex && d[v[i][j]]) {
                            ans[i] = v[i][j];
                            d[v[i][j]]--;
                            break;
                        }
                    }
                }
            }
        }

        for(auto it : ans) if(it == 0) {cout << "NO" << endl; continue;}

        cout << "YES" << endl;
        for(auto it : ans) cout << it << " "; cout << endl;

    }
    return 0;
}