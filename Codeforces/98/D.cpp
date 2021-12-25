// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

// isPalindrome(i .. j) - O(1)
//

int minCharsToMakePalindrome(string &s, int i, int j) {
    if (j < i)
        return INF;

    int beg = i, end = j;
    int counter = 0;
    while (beg <= end) {
        counter += !(s[beg] == s[end]);
        beg++;
        end--;
    }

    return counter;
}

string convertToPalindrome(string s) {
    int beg = 0, end = (int)s.size() - 1;
    while (beg <= end) {
        if (s[beg] != s[end]) {
            s[beg] = s[end];
        }
        beg++;
        end--;
    }
    return s;
}

void solve() {
    string s;
    cin >> s;
    int n, K;
    n = s.size();
    cin >> K;

    vector<vector<int>> getMinChars(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            getMinChars[i][j] = minCharsToMakePalindrome(s, i, j);
        }
    }

    vector<vector<int>> dp(n, vector<int>(K, INF));
    vector<vector<int>> back(n, vector<int>(K, -1));
    for (int j = 0; j < K; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n; ++i) {
        // Make first palindrome
        dp[i][0] = getMinChars[0][i];
        for (int j = 0; j < i; ++j) {
            for (int k = 1; k < K; ++k) {
                int currDp = dp[j][k - 1] + getMinChars[j + 1][i];
                if (currDp < dp[i][k]) {
                    dp[i][k] = currDp;
                    back[i][k] = j;
                }
            }
        }
    }

    pair<int, int> minValue = {INF, -1};
    for (int j = 0; j < K; ++j) {
        minValue = min(minValue, {dp[n - 1][j], j});
    }

    // Construct the palindromes
    int numPalindromes = minValue.second + 1;
    vector<int> startIndices;
    int currPalinIndex = minValue.second;
    int tempStart = back[n - 1][currPalinIndex];
    currPalinIndex--;
    while (tempStart != -1) {
        startIndices.push_back(tempStart + 1);
        tempStart = back[tempStart][currPalinIndex];
        currPalinIndex--;
    }
    startIndices.push_back(0);
    sort(startIndices.begin(), startIndices.end());

    cout << minValue.first << "\n";
    for (int i = 0; i < (int)startIndices.size() - 1; i++) {
        int currIndex = startIndices[i], nextIndex = startIndices[i + 1];
        cout << convertToPalindrome(s.substr(currIndex, nextIndex - currIndex))
             << "+";
    }

    cout << convertToPalindrome(
                s.substr(startIndices.back(), n - startIndices.back() + 1))
         << "\n";
}

int main() {
    __;
    solve();
    return 0;
}
