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

void solve(int n, int b) {
    
    vector<vector<int> > v;
    v.resize(n);

    for(int i = 0; i < n*b; i++) {
        int d;
        cin >> d;
        if(d == -1) exit(0);
        // t(i, d, n*b);
        bool flag = false;
        if(d < 9) {
            // Insert in the smallest tower seen
            int min1 = INF, minT = INF;
            for(int j = 0; j < n; j++) {
                if(v[j].size() < min1) {
                    min1 = v[j].size();
                    minT = j;
                }
            }

            v[minT].push_back(d);
            // t(minT + 1);
            cout << minT + 1 << endl;
        } else {
            // Put it in the highest tower seen which is not full
            int max1 = -1, maxT = -1;
            for(int j = 0; j < n; j++) {
                if(v[j].size() == b) continue;
                if((int) v[j].size() > max1) {
                    max1 = v[j].size();
                    maxT = j;
                }
            }

            v[maxT].push_back(d);
            // t(maxT + 1);
            cout << maxT + 1 << endl;
        }
    }
}

int main() {
    __;
    int t;
    cin >> t;
    int n, b;
    ll p;
    cin >> n >> b >> p;
    t(t, n, b, p);
    for(int h = 1; h <= t; h++) {
        solve(n, b);
    }

    int correct;
    cin >> correct;
    t(correct);
    if(correct == -1) exit(0);
    return 0;
}
