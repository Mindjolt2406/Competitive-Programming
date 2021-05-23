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

const int N = 1e6+10;
// const int BASE = 253;
const int BASE = 100;
vector<ll> prefHash(N);
vector<ll> powB(N), invB(N);

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
            if (y & 1)
                    res = (res*x) % p;
            y = y>>1; // y = y/2
            x = (x*x) % p;
    }
    return res;
}

ll getHash(int l, int r) {
    if(l == 0) return prefHash[r];

    ll powHash = (prefHash[r] - prefHash[l-1] + MOD) % MOD;
    return (powHash * invB[l]) % MOD;
}

void precompute() {
    powB[0] = 1;
    for(int i = 1; i < N; i++) {
        powB[i] = (powB[i-1] * BASE) % MOD;
        invB[i] = power(powB[i], MOD-2, MOD);
    }
}

void precomputeHash(string &s) {
    prefHash[0] = s[0] - 'a' + 1;
    for(int i = 1; i < s.size(); i++) {
        prefHash[i] = prefHash[i-1] + (powB[i] * (s[i] - 'a' + 1)) % MOD;
        prefHash[i] %= MOD;
    }
}

int main() {
    __;
    precompute();
    string binStr;
    string s;
    cin >> binStr >> s;

    prefHash.resize(s.size());

    vector<int> binAhead(binStr.size());
    vector<int> binAhead0(binStr.size());
    vector<int> binAhead1(binStr.size());
    int cnt0 = 0, cnt1 = 0;
    int minIndex0 = INF, minIndex1 = INF;
    for(int i = 0 ; i < binAhead.size(); i++) {
        binAhead[i] = cnt0 + cnt1;
        (binStr[i] == '0' ? cnt0++ : cnt1++);

        if(binStr[i] == '0') minIndex0 = min(minIndex0, i);
        else minIndex1 = min(minIndex1, i);

        if(i > 0) {
            binAhead0[i] = binAhead0[i-1] + (binStr[i-1] == '0');
            binAhead1[i] = binAhead1[i-1] + (binStr[i-1] == '1');
            t(i, binAhead1);
        }
    }

    int n = s.size();
    _;

    precomputeHash(s);
    t(prefHash);
    _;
    ll totalHash = prefHash[n - 1];
    t(totalHash);

    int ans = 0;

    for(ll sz0 = 1; sz0 < n; sz0++) {
        // sz0 is size of t_0
        int m = n - sz0 * cnt0;
        if(m < 0) continue;
        if(m % cnt1 != 0) continue;

        int sz1 = m / cnt1;
        // t(n, sz0, cnt0, cnt1, m, sz1);

        // t(minIndex0, minIndex1, binAhead1[minIndex0], binAhead0[minIndex1], sz0, sz1);
        pair<int, int> pair0 = mp(minIndex0 * binAhead1[minIndex0] * sz1, minIndex0 * binAhead1[minIndex0] * sz1 + sz0 - 1);
        pair<int, int> pair1 = mp(minIndex1 * binAhead0[minIndex1] * sz0, minIndex1 * binAhead0[minIndex1] * sz0 + sz1 - 1);
        if(pair0.fi >= n || pair0.se >= n || pair1.fi >= n || pair1.se >= n) continue;
        // t(pair0, pair1);

        ll hash0 = getHash(pair0.fi, pair0.se);
        ll hash1 = getHash(pair1.fi, pair1.se);

        t(hash0, hash1);

        if(hash0 == hash1) continue;

        ll currHash = 0;
        for(int i = 0; i < binAhead.size(); i++) {
            ll offset = binAhead1[i] * sz1 + binAhead0[i] * sz0;
            if(binStr[i] == '0') {
                currHash += (hash0 * power(BASE, offset, MOD)) % MOD;
                currHash %= MOD;
            } else {
                currHash += (hash1 * power(BASE, offset, MOD)) % MOD;
                currHash %= MOD;
            }
        }

        t(currHash);
        if(currHash == totalHash) ans++;
    }

    cout << ans << endl;
    return 0;
}
