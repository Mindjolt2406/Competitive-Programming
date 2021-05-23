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
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
        v[i].se += v[i].fi;
    }

    vector<pair<int, int> > interPair;
    interPair.pu(v[0]);
    bool possFlag = true;
    for(int i = 1; i < n; i++) {
        pair<int, int> p1 = interPair.back();
        pair<int, int> p2 = v[i];

        // Adjust +-1
        p1.fi--;
        p1.se++;

        // Find intersection
        pair<int, int> p;
        p.fi = max(p1.fi, p2.fi);
        p.se = min(p1.se, p2.se);
        if(p.fi > p.se){
            possFlag = false;
            break;
        }
        interPair.pu(p);
    }

    if(!possFlag) {
        cout << -1 << endl;
    } else {
        reverse(interPair.begin(), interPair.end());
        int beg = -1;
        vector<int> ans;
        for(auto it : interPair) {
            if(beg == -1) {
                beg = it.se;
                ans.pu(beg);
            } else {
                int sec;
                if(beg + 1 <= it.se) beg = beg + 1;
                else if(beg <= it.se) beg = beg;
                else beg--;
                ans.pu(beg);
            }
        }

        reverse(ans.begin(), ans.end());
        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            int diff = ans[i] - v[i].fi;
            if(diff < 0) {
                possFlag = false;
                break;
            } else {
                cnt += diff;
            }
        }

        if(!possFlag) cout << -1 << endl;
        else {
            cout << cnt << endl;
            for(auto it : ans) cout << it << " "; cout << endl;
        }
    }   
    return 0;
}
