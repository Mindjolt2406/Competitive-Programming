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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> mapper(n);

    stack<int> s1, s2, s3;
    bool flag = true;
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i] == 1) {
            s1.push(i);
        }
        else if(v[i] == 2) {
            if(s1.empty()) {
                flag = false;
                break;
            }
            int u = s1.top();
            s1.pop();
            mapper[i] = u;
            s2.push(i);
        } else if(v[i] == 3) {
            if(s2.empty() && s1.empty() && s3.empty()) {
                flag = false;
                break;
            }
            if(!s3.empty()) {
                int u = s3.top();
                s3.pop();
                mapper[i] = u;
            } else if(!s2.empty()) {
                int u = s2.top();
                s2.pop();
                mapper[i] = u;
            } else {
                int u = s1.top();
                s1.pop();
                mapper[i] = u;
            }
            s3.push(i);
        }
    }

    if(!flag) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int> > finalAns;
    for(int i = n-1; i>= 0; i--) {
        if(v[i] == 1) {
            finalAns.pu(mp(i, i));
        } else if(v[i] == 2) {
            finalAns.pu(mp(mapper[i], i));
        } else if(v[i] == 3) {
            finalAns.pu(mp(i, i));
            finalAns.pu(mp(i, mapper[i]));
        }
    }

    cout << finalAns.size() << endl;
    for(auto it : finalAns) {
        cout << it.fi + 1 << " " << it.se + 1 << endl;
    }


    return 0;
}
