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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

pair<ll, ll> add(pair<ll, ll> p1, pair<ll, ll> p2) {
    pair<ll, ll> temp;
    temp.fi = p1.se * p2.fi + p1.fi * p2.se;
    temp.se = p1.se * p2.se;
    ll g = gcd(temp.fi, temp.se);
    temp.fi /= g;
    temp.se /= g;
    return temp;
}

pair<ll, ll> sub(pair<ll, ll> p1, pair<ll, ll> p2) {
    pair<ll, ll> temp;
    temp.fi = - p1.se * p2.fi + p1.fi * p2.se;
    temp.se = p1.se * p2.se;
    ll g = gcd(temp.fi, temp.se);
    temp.fi /= g;
    temp.se /= g;
    return temp;
}

pair<ll, ll> mul(pair<ll, ll> p1, pair<ll, ll> p2) {
    pair<ll, ll> temp;
    temp.fi = p1.fi * p2.fi;
    temp.se = p1.se * p2.se;
    ll g = gcd(temp.fi, temp.se);
    temp.fi /= g;
    temp.se /= g;
    return temp;
}

pair<ll, ll> div(pair<ll, ll> p1, pair<ll, ll> p2) {
    pair<ll, ll> temp;
    temp.fi = p1.fi * p2.se;
    temp.se = p1.se * p2.fi;
    ll g = gcd(temp.fi, temp.se);
    temp.fi /= g;
    temp.se /= g;
    return temp;
}

ll getNum(string &s) {
    ll cnt = 0;
    ll pow = 1;
    // reverse(s.begin(), s.end());
    for(auto it : s) {
        if(it == 'T') cnt += pow;
        pow <<= 1;
    }
    return cnt;
}

pair<ll, ll> max(pair<ll, ll> p1, pair<ll, ll> p2) {
    ll g1 = gcd(p1.fi, p1.se);
    p1.fi /= g1;
    p1.se /= g1;
    ll g2 = gcd(p2.fi, p2.se);
    p2.fi /= g2;
    p2.se /= g2;
    return ((p1.fi * 1.0) / p1.se) > ((p2.fi * 1.0) / p2.se) ? p1 : p2;
}

string switcher(string s) {
    string ans;
    for(auto it : s) {
        ans += (it == 'T') ? 'F' : 'T';
    }

    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> vs(n);
    vector<int> score(n);
    for(int i = 0; i < n; i++) cin >> vs[i] >> score[i];

    if(n == 1) {
        if(score[0] < max(score[0], q - score[0])) {
            vs[0] = switcher(vs[0]);
            score[0] = q - score[0];
        }
        cout << vs[0] << " " << score[0] << "/" << 1 << endl;
        return;
    } 

    for(int i = 0; i < 2; i++) {
        if(score[i] < max(score[i], q - score[i])) {
            vs[i] = switcher(vs[i]);
            score[i] = q - score[i]; 
        }
    }

    // if(score[0] > score[1]) {
    //     cout << vs[0] << " " << score[0] << "/" << 1 << endl;
    // } else {
    //     cout << vs[1] << " " << score[1] << "/" << 1 << endl;
    // }

    // return;



    vector<int> temp;
    for(int i = 0; i < (1<<q); i++) {
        int s1 = q - __builtin_popcountll(i ^ getNum(vs[0]));
        int s2 = q - __builtin_popcountll(i ^ getNum(vs[1]));
        // t(i, vs[0], s1, vs[1], s2);
        if(s1 == score[0] && s2 == score[1]) {
            temp.push_back(i);
        }
    }

    // t(temp);

    pair<ll, ll> ans = mp(0, 1);
    int ansString = 0;
    for(int i = 0; i < (1 << q); i++) {
        int temp1 = 0;
        for(auto it : temp) {
            int sc = q - __builtin_popcountll(i ^ it);
            temp1 += sc;
        }
        if(temp.size() == 0) continue;
        if(ans == max(ans, mp(temp1, temp.size()))) {
            continue;
        } else {
            if(temp.size() == 0) continue;
            ans = max(ans, mp(temp1, temp.size()));
            ansString = i;
        }
    }

    string finalAns;
    while(q--) {
        finalAns += (ansString&1) ? 'T' : 'F';
        ansString >>= 1;
    }

    cout << finalAns << " " << ans.fi << "/" << ans.se << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}
