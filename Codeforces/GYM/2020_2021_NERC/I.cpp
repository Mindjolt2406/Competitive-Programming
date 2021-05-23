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

ld min(ld x, ld y) {return x < y ? x : y;}
ld max(ld x, ld y) {return x < y ? x : y;}

int main() {
    __;
    int n, m;
    cin >> n >> m;

    vector<int> score(n);
    for(int i = 0; i < n; i++) score[i] = 0;

    int beg = 0, end = 1;
    ld mid = (beg + end) >> 1;
    int myScore = 0;
    ld thresh = n/2;
    for(int h = 0; h < m; h++) {

        vector<pair<int, int> > scores;
        for(int i = 0; i < n; i++) {
            scores.push_back(mp(score[i], i));
        }

        sort(scores.begin(), scores.end());
        reverse(scores.begin(), scores.end());

        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < n; i++) {
            // if(scores[i].se > myScore * 1.3 && h > min(100, 0.05*m))(s[scores[i].se] == '0' ? cnt0++ : cnt1++);
            if(myScore > scores[0].fi * 1.3 - 0.3 * h && h > min(200, 0.26 * m))
            (s[scores[i].se] == '0' ? cnt0++ : cnt1++);
            else if(i > thresh) (s[scores[i].se] == '0' ? cnt0++ : cnt1++);
        }


        // int myAns;
        // if(myScore + 100 > scores[0].fi * 1.3 - 0.3 * h && h > min(100, 0.26 * m)) {
        //     myAns = s[scores[0].se] - '0';
        //     cout << myAns << endl;
        // } else {
        //     myAns = ((cnt0 > cnt1) ? 0 : 1);
        //     cout << myAns << endl;
        // }

        int myAns = ((cnt0 > cnt1) ? 0 : 1);
        cout << myAns << endl;
        int ans;
        cin >> ans;

        for(int i = 0; i < n; i++) {
            if(s[i] - '0' == ans) {
                score[i]++;
            }
        }

        if(myAns == ans) myScore++;

        if(myAns == ans) { // Doing good
            thresh =  max(0.01 * n + thresh, n);
        } else {
            thresh = min(thresh - 0.01 * n, 1);
        }

        // if(myScore + 100 >= scores[0].fi * 1.3 - h * 0.3) { // Doing good
        //     thresh =  max(0.01 * n + thresh, n);
        // } else {
        //     thresh = min(thresh - 0.01 * n, 1);
        // }
        // if(beg <= end) {
        //     if(myAns == ans) {
        //         beg = mid+0.0001;
        //     } else {
        //         end = mid-0.0001;
        //     }
        //     mid = (beg + end) >> 1;
        // }
    }
    return 0;
}
