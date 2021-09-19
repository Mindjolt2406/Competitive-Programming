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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> minIndex(k + 1, INF), maxIndex(k+1, -1), prefMinIndex(k + 1, INF);

    for(int i = 0; i < n; i++) {
        minIndex[v[i]] = min(minIndex[v[i]], i);
        maxIndex[v[i]] = max(maxIndex[v[i]], i);
    }

    int prevMin = INF, prevMax = -1;

    // Fill up gaps
    for(int i = k - 1; i > 0; i--) {
        if(minIndex[i] == INF) {
            minIndex[i] = prevMin;
        } else {
            prevMin = minIndex[i];
        }
    }

    for(int i = 1; i <= k; i++) {
        if(maxIndex[i] == -1) {
            maxIndex[i] = prevMax;
        } else {
            prevMax = maxIndex[i];
        }
    }

    // Find right and left sorted limits
    int leftLimit = k+1, rightLimit = 0;
    int minSoFar = minIndex[k], maxSoFar = -1;
    for(int i = k - 1; i >= 0; i--) {
        if(maxIndex[i] > minSoFar) {
            rightLimit = i;
            break;
        } else {
            minSoFar = min(minSoFar, minIndex[i]);
        }
    }

    for(int i = 1; i <= k; i++) {
        if(minIndex[i] < maxSoFar) {
            leftLimit = i;
            break;
        } else {
            maxSoFar = max(maxSoFar, maxIndex[i]);
        }
    }

    prefMinIndex[k] = minIndex[k];
    for(int i = k - 1; i > 0; i--) {
        prefMinIndex[i] = min(prefMinIndex[i+1], prefMinIndex[i]);
    }

    t(leftLimit, rightLimit);
    ll finalAns = 0;
    for(int i = 0; i < min(leftLimit, k); i++) {
        // int rightMostLimit = max(i, rightLimit + 1);
        // finalAns += k - rightMostLimit + 1;
        // finalAns++;
        int beg = max(rightLimit + 1, i), end = k, ans = k;
        while(beg <= end) {
            int mid = (beg + end) >> 1;
            if(prefMinIndex[mid] >= maxIndex[i]) {
                ans = mid;
                end = beg - 1;
            } else {
                beg = mid + 1;
            }
        }

        t(k, ans, i);
        finalAns += k - ans + 1;
        // finalAns++;
        finalAns += (rightLimit == i);
        t(i, finalAns);
    }

    cout << finalAns << endl;
    
    return 0;
}
