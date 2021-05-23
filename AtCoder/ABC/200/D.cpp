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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

vector<int> getIndices(vector<int> &v, int n, int &index) {
    const int N = 200;
    vector<vector<int> > dp(n, vector<int>(N));
    vector<vector<int> > back(n, vector<int>(N, -1));

    dp[0][v[0] % N] = 1;
    // dp[0][0] = 1;

    for(int i = 1; i < n; i++) {
        dp[i][v[i] % N] = 1;
        for(int j = 0; j < N; j++) {
            if(index == -1) {
                if(dp[i-1][((j - v[i]%N) + N) % N] > 0) {
                    back[i][j] = ((j - v[i]%N) + N) % N;
                } 
                if(dp[i-1][j] > 0) {
                    back[i][j] = j;
                }
            } else {
                if(dp[i-1][j] > 0) {
                    back[i][j] = j;
                }
                if(dp[i-1][((j - v[i]%N) + N) % N] > 0) {
                    back[i][j] = ((j - v[i]%N) + N) % N;
                } 
            }

            dp[i][j] += dp[i-1][j] + dp[i-1][((j - v[i]%N) + N) % N];

            // dp[i][((j + v[i]) % N)] += dp[i-1][((j + v[i]) % N)] + dp[i-1][j];
        }
    }

    int backIndex = index;
    if(index == -1) {
        for(int j = 0; j < 200; j++) {
            if(dp[n-1][j] > 1) {
                backIndex = j;
                break;
            }
        }
    }

    index = backIndex;
    // t(dp);
    if(backIndex == -1) {
        vector<int> ansIndex;
        return ansIndex;
    } else {
        int currI = n-1;
        vector<int> ansIndex;
        while(backIndex != -1) {
            // t(backIndex, ansIndex, currI);
            int tempIndex = back[currI][backIndex];
            // t(tempIndex);
            if((tempIndex != backIndex && v[currI] != 0)) {
                ansIndex.pu(currI + 1);
                if(tempIndex == -1) break;
            }
            backIndex = tempIndex;
            currI--;
        }

        return ansIndex;

        // t(ansIndex);

        // cout << "Yes" << endl;
        // cout << 1 << " " << ansIndex.front() << endl;
        // cout << ansIndex.size() - 1 << " ";
        // for(int i = 1; i < ansIndex.size(); i++) cout << ansIndex[i] << " "; cout << endl;
    }
}

int main() {
    __;
    const int N = 200;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    {
        vector<vector<int> > easyAns(200);
        for(int i = 0; i < n; i++) {
            easyAns[v[i] % N].pu(i+1);
        }

        for(int j = 0; j < 200; j++) {
            if(easyAns[j].size() > 1) {
                cout << "Yes" << endl;
                cout << 1 << " " << easyAns[j].front() << endl;
                cout << 1 << " " << easyAns[j].back() << endl;
                return 0;
            }
        }
    }

    // vector<vector<int> > back(n, vector<int>(N, -1));

    int index = -1;
    vector<int> indices1 = getIndices(v, n, index);
    // t(index);
    if(index == -1) {
        cout << "No" << endl;
        return 0;
    }
    // set<int> s(indices1.begin(), indices1.end());
    // vector<int> w;
    // for(int i = 0; i < n; i++) {
    //     if(s.count(i+1)) {
    //         w.pu(0);
    //     } else {
    //         w.pu(v[i]);
    //     }
    // }
    vector<int> indices2 = getIndices(v, n, index);

    sort(indices1.begin(), indices1.end());
    sort(indices2.begin(), indices2.end());

    set<int> s1(indices1.begin(), indices1.end());
    set<int> s2(indices2.begin(), indices2.end());
    set<int> s3;
    for(auto it : s1) {
        if(s2.count(it)) s3.insert(it);
    }

    for(auto it : s3) {
        s1.erase(it);
        s2.erase(it);
    }

    cout << "Yes" << endl;
    cout << s1.size() << " ";
    for(auto it : s1) cout << it << " "; cout << endl;
    cout << s2.size() << " ";
    for(auto it : s2) cout << it << " "; cout << endl;
    return 0;
}
