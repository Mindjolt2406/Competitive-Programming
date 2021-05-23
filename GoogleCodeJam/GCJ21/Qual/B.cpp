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

// X *** X -> (j - i)/2; of each
// X ** Y  ->  (j - i)/2 of each + XY
// ** X -> 

void solve3(int a, int b, string &s) {
    int n = s.size();
    int i = 0;

    vector<pair<int, int> > edges;
    while(i < n) {
        if(s[i] == '?') {
            int first = i;
            while(i < n && s[i] == '?') i++;
            int second = i;
            edges.push_back(make_pair(first - 1, second));
        }
        i++;
    }

    ll cnt = 0;
    for(auto it : edges) {
        ll tempCnt = INF;
        int sz = (it.se - it.fi - 1);
        
        int cj = 0, cc = 0, jc = 0, jj = 0;

        if(sz % 2 == 0) {
            // CJCJ
            cj = a * (sz/2) + b * (sz/2 - 1);
            // JCJC
            jc = a * (sz/2 - 1) + b * (sz/2);

        } else {
            // CJCJC
            cj = a * (sz/2) + b * (sz/2);
            // JCJCJ
            jc = a * (sz/2) + b * (sz/2);
        }

        if(it.fi != -1) {
            cj += (s[it.fi] == 'C') ? 0 : b;
            cc += (s[it.fi] == 'C') ? 0 : b;
            jc += (s[it.fi] == 'J') ? 0 : a;
            jj += (s[it.fi] == 'J') ? 0 : a;
        } 

        if(it.se != n) {
            cc += (s[it.se] == 'C') ? 0 : a;
            jc += (s[it.se] == 'C') ? 0 : a;
            cj += (s[it.se] == 'J') ? 0 : b;
            jj += (s[it.se] == 'J') ? 0 : b;
        }


        tempCnt = min(cj, min(cc, min(jc, jj)));

        cnt += tempCnt;
    }

    cout << cnt << endl;
}  

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    if(a < 0 || b < 0) {
        solve3(a, b, s);
        return;
    } 

    string t;
    for(auto it : s) {
        if(it != '?') t += it;
    }

    ll cnt = 0;
    for(int i = 0; i < (int) t.size() - 1; i++) {
        if(t[i] == 'C' && t[i+1] == 'J') cnt += a;
        else if(t[i] == 'J' && t[i+1] == 'C') cnt += b;
    }

    cout << cnt << endl;
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


/*
if(it.fi == -1 || it.se == n) {
        if(a + b >= 0) {
            if(it.fi == -1 && it.se == n) {
                cnt += min(a, b);
            } else if(it.fi == -1) {
                if(s[it.se] == 'C') {
                    if(b < a) cnt += b;
                } else {
                    if(a < b) cnt += a;
                }
            } else { // it.se == n
                if(s[it.fi] == 'C') {
                    if(a < b) cnt += a;
                } else {
                    if(b < a) cnt += b;
                }
            }
        } else {

        }
    } else {
        if(a + b >= 0) {
            if(s[it.fi] != s[it.se]) {
                cnt += (s[it.fi] == 'C') ? a : b;
            }
        } else {
            if(s[it.fi] == s[it.se]) cnt += (a+b) * ((it.se - it.fi)/2);
            else {
                cnt += (a+b) * ((it.se - it.fi)/2);
                cnt += (s[it.fi] == 'C') ? a : b;
            }
        }
    }
*/