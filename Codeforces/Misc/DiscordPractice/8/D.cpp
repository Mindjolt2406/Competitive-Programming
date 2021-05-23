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

ld max(ld x, ld y) {return x > y ? x : y;}

int main() {
    __;
    int n;
    ld x1, x2;
    cin >> n >> x1 >> x2;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].fi;
        v[i].se = i;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 1; i < n; i++) {
        int beg = 1, end = i;
        int total = i + 1;
        while(end - beg > 3) {
            t(beg, end);
            int m1 = beg + (end - beg) / 3;
            int m2 = end - (end - beg) / 3;
            ld f1 = max(x1 / m1, x2 / (total - m1));
            ld f2 = max(x2 / m2, x2 / (total - m2));

            t(f1, f2);

            if(f1 > f2) {
                beg = m1;
            } else {
                end = m2;
            }
        }

        int ans = -1;
        ld max1 = -1;
        for(int j = beg; j <= end; j++) {
            ld temp1 = min(x1 / j, x2 / (total - j));
            ld f1 = x1 / j, f2 = x2 / (total - j);

            if(f1 < f2) {
                if(f2 <= v[j-1].fi && f1 <= v[i].fi) {
                    cout << "Yes" << endl;
                    cout << i + 1 - j << " " << j << endl;
                    for(int k = j; k <= i; k++) {
                        cout << v[k].se + 1 << " ";
                    }
                    cout << endl;
                    for(int k = 0; k < j; k++) {
                        cout << v[k].se + 1 << " ";
                    } 
                    cout << endl;
                    return 0;
                }
            } else {
                if(f1 <= v[j-1].fi && f2 <= v[i].fi) {
                    cout << "Yes" << endl;
                    cout << j << " " << i + 1 - j << endl;
                    for(int k = 0; k < j; k++) {
                        cout << v[k].se + 1 << " ";
                    } 
                    cout << endl;
                    for(int k = j; k <= i; k++) {
                        cout << v[k].se + 1 << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
        }

        if(ans != -1) {
            cout << "Yes" << endl;
            ld f1 = x1 / ans, f2 = x2 / (total - ans);
            vector<int> ans1, ans2;
            for(int j = 0; j < ans; j++) 
            cout << ans << " " << i + 1 - ans << endl;
            for(int j = 0; j < ans; j++) {
                cout << v[j].se + 1 << " ";
            } 
            cout << endl;
            for(int j = ans; j <= i; j++) {
                cout << v[j].se + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
