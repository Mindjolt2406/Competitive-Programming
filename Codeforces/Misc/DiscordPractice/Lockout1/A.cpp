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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > v, w;
    for(int i = 0; i < n; i++) {
        int type;
        cin >> type;
        int h, m;
        cin >> h >> m;
        if(type == 0) {
            v.pu(mp(h, m));
        } else {
            w.pu(mp(h, m));
        }
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    int i = 0, j = 0;

    int cnt1 = 0, cnt2 =0;
    {
        int currX = x;
        int i = 0;
        int prevI = -1;
        // t(v, w);
        for(; i < min((int)v.size(), (int)w.size()); i++) {
            // t(i, currX);
            if(currX >= v[i].fi) {
                cnt1++;
                currX += v[i].se;
                prevI = i;
            }  else break;

            // t(i, currX);

            if(currX >= w[i].fi) {
                cnt1++;
                currX += w[i].se;
            } else break;
        }

        // t(cnt1, prevI, i);
        if(i < v.size() && currX >= v[i].fi && i != prevI) {
            cnt1++;
            currX += v[i].se;
        }
        // t(cnt1);
    }

    {
        int currX = x;
        int i = 0;
        int prevI = -1;
        // t(v, w);
        for(; i < min((int)v.size(), (int)w.size()); i++) {
            // t(i, currX);
            if(currX >= w[i].fi) {
                cnt2++;
                currX += w[i].se;
                prevI = i;
            } else break;
            // t(i, currX);

            if(currX >= v[i].fi) {
                cnt2++;
                currX += v[i].se;
            }  else break;
        }
        // t(i, currX);
        if(i < w.size() && currX >= w[i].fi && i != prevI) {
            cnt2++;
            currX += w[i].se;
        }
    }

    cout << max(cnt1, cnt2) << endl;
    return 0;
}
