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

int main() {
    __;
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> hp(n), dmg(n);
    for(int i = 0; i < n; i++) cin >> hp[i] >> dmg[i];

    ll maxIndex = -1, maxDiff = 0;

    if(a) {
        for(int i = 0; i < n; i++) {
            if(hp[i] * (1LL << a) - dmg[i] > maxDiff) {
                maxDiff = hp[i] * (1LL << a);
                maxIndex = i;
            }
        }
    }

    // t(maxIndex, maxDiff);

    vector<pair<ll, int> > v;
    for(int i = 0; i < n; i++) {
        v.pu(mp(hp[i] - dmg[i], i));
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    bool flagExists = false;
    for(int i = 0; i < min(n, b); i++) {
        if(v[i].se == maxIndex) flagExists = true;
    }

    // t(v);
    // t(flagExists);

    ll cnt = 0;

    for(int i = 0; i < n; i++) cnt += dmg[i];

    cnt += (flagExists ? 0 : maxDiff - v[maxIndex].fi);

    for(int i = 0; i < min(b - 1 + flagExists, n); i++) {
        int currIndex = v[i].se;
        if(currIndex == maxIndex) {
            cnt += maxDiff;
        } else {
            cnt += max(0, hp[currIndex] - dmg[currIndex]);
        }
    }

    // for(int i = b - 1 + flagExists; i < n; i++) {
    //     int currIndex = v[i].se;
    //     cnt += dmg[currIndex];
    // }

    cout << cnt << endl;

    return 0;
}
