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
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}

// const int MAXN = 1e6 + 10;
const int MAXN = 1e6 + 10;
// stores smallest prime factor for every number
ll spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<vector<int> > primeFactors(MAXN);

vector<int> getFactorization(int x)
{
    // t(x);
    vector<int> ret;
    for(ll i = 2; i * i <= x; i++) {
        if(x%i == 0) {
            ret.pu(i);
            if(i != x/i) ret.pu(x/i);
        }
    }

    return ret;
}


void precompute() {
    sieve();
    for(int i = 3; i < MAXN; i++) {
        // t(i);
        primeFactors[i] = getFactorization(i);
    }
}

vector<vector<pair<int, int> > > mapper(MAXN);
vector<int> invMapper(MAXN);

void precompute2() {
    int N = MAXN;
    // int N = 20;
    for(int i = 3; i < N; i++) {
        for(auto factor : primeFactors[i]) {
            if(factor == 1 || factor == i) continue;
            for(auto it : mapper[factor]) {
                int val = it.fi, depth = it.se;
                if(val + i < N) {
                    mapper[i].pu(mp(val + i, depth + 1));
                    invMapper[val + i] = max(invMapper[val + i], depth + 1);
                    // if(it + i == 12) t(i, depth[i], 12);
                }
            }
        }

        // depth[i] = max(depth[i], 1);
        mapper[i].pu(mp(i, 1));
        invMapper[i] = max(invMapper[i], 1);
    }

    // t(primeFactors[12]);

    // for(int i = 3; i < 20; i++) {
    //     t(i, mapper[i]);
    // }

    // for(int i = 3; i < 20; i++) {
    //     t(i, invMapper[i]);
    //     t(i, mapper[i]);
    // }
}

void solve() {
    int n;
    cin >> n;
    cout << invMapper[n] << endl;
}

int main() {
    precompute();
    precompute2();
    __;
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
