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

string getNot(string s) {
    string t;
    int i = 0;
    while(s[i] == '1') i++;
    for(; i < s.size(); i++) {
        if(s[i] == '0') t += '1';
        else t += '0';
    }

    if(t.size() == 0) t += '0';

    return t;
}

string getBin(ll a) {
    string t;
    if(a == 0) return "0";

    while(a) {
        if(a&1) t += '1';
        else t += '0';
        a >>= 1;
    }

    reverse(t.begin(), t.end());
    return t;
}

ll getNum(string a) {
    reverse(a.begin(), a.end());
    ll prod = 1;
    ll cnt = 0;
    for(auto it : a) {
        if(it == '1') cnt += prod;
        prod <<= 1;
    }
    return cnt;
}

int bfs(ll root, ll target) {
    queue<ll> q;
    q.push(root);
    set<ll> visited;
    visited.insert(root);
    q.push(-1);
    int dist = 0;

    bool flag = false;

    while(!q.empty() && visited.size() < 1e6) {
        ll u = q.front();
        q.pop();
        // t(u);
        if(u == -1) {
            if(!q.empty() && q.front() != -1) {
                q.push(-1);
                dist++;
            }
            continue;
        }

        if(u == target) {
            flag = true;
            return dist;
        }

        if(u * 2 <= 1e17) {
            if(!visited.count(u * 2)) {
                visited.insert(u*2);
                q.push(u*2);
            }
        }

        ll c = getNum(getNot(getBin(u)));

        if(!visited.count(c)) {
            visited.insert(c);
            q.push(c);
        }
    }

    return -1;
}

void solve() {
    string a, b;
    cin >> a >> b;


    ll c, d;
    c = getNum(a), d = getNum(b);

    int x = bfs(c, d);
    if(x == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else cout << bfs(c, d) << endl;
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
