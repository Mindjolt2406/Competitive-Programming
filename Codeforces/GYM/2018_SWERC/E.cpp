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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}

ld max(ld x, ld y) {return x > y ? x : y;}
ld min(ld x, ld y) {return x < y ? x : y;}

int main() {
    __;
    int n;
    cin >> n;
    vector<string> cities(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i] >> v[i];
    
    int sumPercent = 0;
    for (auto x : v)
        sumPercent += x;

    sumPercent -= v[0];

    ld minPercent = INF;
    ld maxPercent = -INF;
    bool isImpossible = true;
    for (ld i = -0.50; i < 0.49 + EPS; i+= 0.01) {
        ld maxLimit = sumPercent + ((n - 1) * 0.49);
        ld minLimit = sumPercent - ((n - 1) * 0.50);
        ld currLeftPercent = 100 - (v[0] + i);
        if (currLeftPercent > minLimit - EPS && currLeftPercent < maxLimit + EPS) {
            // t(currLeftPercent, minLimit, maxLimit, i);
            isImpossible = false;
            minPercent = min(minPercent, i);
            maxPercent = max(maxPercent, i);
        }
    }

    if (isImpossible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) 
        cout << cities[i] << " " << min(max(v[i] + minPercent, 0), 100) << " " << min(max(v[i] + maxPercent, 0), 100)<< "\n";
    
    return 0;
}

/*
7
Aqueduc_Medicis 11
Parc_Montsouris 40
Place_Denfert 10
Hopital_Sainte_Anne 4
Butte_aux_cailles 20
Cite_florale 12
Prison_de_la_Sante 0

*/