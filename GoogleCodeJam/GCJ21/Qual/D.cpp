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

int query(int left, int mid, int right) {
    cout << left + 1 << " " << mid + 1 << " " << right + 1 << endl; 
    int ansIndex;
    cin >> ansIndex;
    if(ansIndex == -1) exit(0);

    return ansIndex - 1;
}

void submitAnswer(vector<int> &v) {
    for(auto it : v) cout << it + 1 << " "; cout << endl;

    int ansIndex;
    cin >> ansIndex;
    if(ansIndex == -1) exit(0);
}

vector<int> sortMedian(vector<int> v, int vMin = -1, int vMax = -1) {
    // t(v, vMin, vMax);
    int n = v.size();

    // n is guaranteed to be greater than 2
    int leftIndex;
    int rightIndex = leftIndex = rng() % n;
    while(leftIndex == rightIndex) rightIndex = rng() % n;

    // if(leftIndex > rightIndex) swap(leftIndex, rightIndex);
    if(vMin != -1 || vMax != -1) {
        if(vMin != -1) {
            int ansIndex = query(v[leftIndex], v[rightIndex], vMin);
            if(ansIndex == v[rightIndex]) swap(v[leftIndex], v[rightIndex]);
        } else {
            int ansIndex = query(v[leftIndex], v[rightIndex], vMax);
            if(ansIndex == v[leftIndex]) swap(v[leftIndex], v[rightIndex]);
        }
    }

    // t(v[leftIndex], v[rightIndex]);
    vector<int> left, mid, right;
    for(int i = 0; i < n; i++) {   
        // t(i, v[i]); 
        if(v[i] == v[leftIndex] || v[i] == v[rightIndex]) continue;
        int ansIndex = query(v[leftIndex], v[i], v[rightIndex]);

        if(ansIndex == v[leftIndex]) {
            left.push_back(v[i]);
        } else if(ansIndex == v[i]) {
            mid.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }

    if(left.size() <= 2) {
        if(left.size() == 2) {
            int ansIndex = query(left[0], left[1], v[leftIndex]);
            if(ansIndex == left[0]) swap(left[0], left[1]);
        }
    } else {
        left = sortMedian(left, -1, v[leftIndex]);
    }

    if(mid.size() <= 2) {
        if(mid.size() == 2) {
            int ansIndex = query(mid[0], mid[1], v[leftIndex]);
            if(ansIndex == mid[1]) swap(mid[0], mid[1]);
        }
    } else {
        mid = sortMedian(mid, v[leftIndex], v[rightIndex]);
    }

    if(right.size() <= 2) {
        if(right.size() == 2) {
            int ansIndex = query(right[0], right[1], v[leftIndex]);
            if(ansIndex == right[1]) swap(right[0], right[1]);
        }
    } else {
        right = sortMedian(right, v[rightIndex]);
    }

    vector<int> ans = left;
    ans.push_back(v[leftIndex]);
    for(auto it : mid) ans.push_back(it);
    ans.push_back(v[rightIndex]);
    for(auto it : right) ans.push_back(it);

    return ans;
}

void solve(int n, int q) {
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i;

    vector<int> ans = sortMedian(v);

    submitAnswer(ans);
}

int main() {
    __;
    int t, n, q;
    cin >> t >> n >> q;
    while(t--) {
        solve(n, q);
    }
    return 0;
}
