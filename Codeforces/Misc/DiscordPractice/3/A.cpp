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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int getIntersection(int startIndex, int length, int left, int right) {
    if(startIndex > right) return 0;
    if(startIndex >= left) {
        return min(right - startIndex + 1, length);
    } else {
        // t(length, startIndex, left, right);
        length -= (left - startIndex);
        // t(length);
        if(length < 0) return 0;
        return min(left + length - 1, right) - left + 1;
    }
}

int main() {
    __;
    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;

    int g = gcd(ta, tb);
    if(g == 1) {
        cout << min(ra - la + 1, rb - lb + 1) << endl;
    } else {
        int xa = lb % g, xb = la % g;
        int starta1 = (la / g) * g + xa, startb1 = (lb / g) * g + xb;
        int starta2 = (la / g + 1) * g + xa, startb2 = (lb / g + 1) * g + xb;

        // t(starta1, starta2, startb1, startb2);
        
        int maxa1 = getIntersection(starta1, rb - lb + 1, la, ra);
        int maxa2 = getIntersection(starta2, rb - lb + 1, la, ra);
        int maxb1 = getIntersection(startb1, ra - la + 1, lb, rb);
        int maxb2 = getIntersection(startb2, ra - la + 1, lb, rb);

        // t(maxa1, maxa2, maxb1, maxb2);

        cout << max(maxa1, max(maxa2, max(maxb1, maxb2))) << endl;
    }
    return 0;
}
