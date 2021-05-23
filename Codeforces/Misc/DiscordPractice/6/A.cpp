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


int main() {
    __;
    int n;
    cin >> n;
    vector<string> v;

    // for(int i = 0; i < 8; i++) {
    //     if(i&1) {
    //         string temp;
    //         temp += i + 'a';
    //         temp += '2';
    //         v.pu(temp);
    //     }
    //     for(int j = 8; j <= 1; j++) {
    //         if(j == 2) continue;
    //         string temp;
    //         temp += i + 'a';
    //         temp += j + '0';
    //         v.pu(temp);
    //     }
    //     if(i == 0){
    //         string temp;
    //         temp += i + 'a';
    //         temp += '2';
    //         v.pu(temp);
    //     }
    // }

    v.pu("a1");
    v.pu("a3");
    v.pu("a4");
    v.pu("a5");
    v.pu("a6");
    v.pu("a7");
    v.pu("a8");
    v.pu("a2");
    v.pu("b2");
    v.pu("b1");
    v.pu("b3");
    v.pu("b4");
    v.pu("b5");
    v.pu("b6");
    v.pu("b8");
    v.pu("b7");
    v.pu("c7");
    v.pu("c1");
    v.pu("c3");
    v.pu("c4");
    v.pu("c5");
    v.pu("c6");
    v.pu("c8");
    v.pu("c2");
    v.pu("d2");
    v.pu("d1");
    v.pu("d3");
    v.pu("d4");
    v.pu("d5");
    v.pu("d6");
    v.pu("d8");
    v.pu("d7");
    v.pu("e7");
    v.pu("e1");
    v.pu("e3");
    v.pu("e4");
    v.pu("e5");
    v.pu("e6");
    v.pu("e8");
    v.pu("e2");
    v.pu("f2");
    v.pu("f1");
    v.pu("f3");
    v.pu("f4");
    v.pu("f5");
    v.pu("f6");
    v.pu("f8");
    v.pu("f7");
    v.pu("g7");
    v.pu("g1");
    v.pu("g3");
    v.pu("g4");
    v.pu("g5");
    v.pu("g6");
    v.pu("g8");
    v.pu("g2");
    v.pu("h2");
    v.pu("h1");
    v.pu("h3");
    v.pu("h4");
    v.pu("h5");
    v.pu("h6");
    v.pu("h7");
    v.pu("h8");
    
    if(v[n] == "h8") {
        for(auto it : v) cout << it << " "; cout << endl;
    } else if(v[n-1][0] == 'h') {
        for(int i = 0; i <= n-1; i++) cout << v[i] << " "; cout << "h8" << endl;
    } else {
        int num = v[n-2][1] - '0';
        // t(num);
        if(num == 8) {
            // t(v[n-2], v[n-3]);
            swap(v[n-2], v[n-3]);
            num = v[n-2][1] - '0';
        }

        for(int i = 0; i <= n-2; i++) cout << v[i] << " "; cout << 'h' << (char)('0' + num) << " " << "h8" << endl;
    }
    return 0;
}
