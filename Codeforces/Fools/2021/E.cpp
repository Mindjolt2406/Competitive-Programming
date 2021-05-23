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

int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool check(int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    return true;
}

int main() {
    __;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int> > vis(n, vector<int>(m));
    vector<vector<int> > counter(n, vector<int>(m));
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<pair<int, int> > food;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '*') food.push_back(mp(i, j));
        }
    }


    int i = 0, j = 0, cnt = 0;
    while(i !=  n-1 || j != m-1) {
        // t(i, j);
        cnt += (v[i][j] == '*');
        vector<pair<int, int> > temp;
        int min1 = INF;
        for(auto it : food) {
            if(it.fi >= i && it.se >= j && it != mp(i, j)) {
                temp.push_back(it);
                min1 = min(min1, it.se - j + it.fi - i);
            }
        }

        // t(temp, min1);

        int maxJ = -1;
        pair<int,int> next = mp(-1, -1);
        for(auto it : temp) {
            if(it.fi >= i && it.se >= j && it != mp(i, j)) {
                if(min1 == it.se - j + it.fi - i) {
                    if(it.se > maxJ) {
                        maxJ = it.se;
                        next = it;
                    }
                }
            }
        }

        if(next == mp(-1, -1)) next = mp(n-1, m-1);

        // t(next);

        if(next.se != j) j++;
        else i++;
    }

    cout << cnt << endl;
    return 0;
}
