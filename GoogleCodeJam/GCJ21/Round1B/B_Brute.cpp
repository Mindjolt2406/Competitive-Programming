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

const int N = 2e5+10;
vector<int> spf(N, INF);
 
void sieve() {
  spf[0] = spf[1] = -1;
  for(ll i = 2; i < N; i++) {
    if(spf[i] == INF) {
      spf[i] = i;
      for(ll j = i*i; j < N; j+= i) spf[j] = min(spf[j], (int)i);
    }
  }
}

vector<int> getPrimes(int n) {
    vector<int> temp;
    int i = n;
    while(i != 1) {
        temp.push_back(spf[i]);
        i /= spf[i];
    } 
    return temp;
}

void solve() {
    vector<int> d(50000);
    ll sum1 = 0;
    int m;
    cin >> m;
    while(m--) {
        ll n, p;
        cin >> p >> n;
        d[p] = n;
        sum1 += n * p;
    }

    ll ans = 0;
    for(int i = 2; i <= 50000; i++) {
        vector<int> primes = getPrimes(i);
        bool flag = true;
        for(auto it : primes) {
            // t(it, d.count(it), );
            if(d[it] > 0) {
            }
            else flag = false;
            d[it]--;
            sum1 -= it;
        }

        // if(i == 25) {
        //     t(primes, sum1, flag);
        //     for(auto it : d) t(it);
        // }
        if(sum1 == i && flag) ans = i;

        for(auto it : primes) {
            d[it]++;
            sum1 += it;
        }
    }

    cout << ans << endl;
}

int main() {
    __;
    sieve();
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
