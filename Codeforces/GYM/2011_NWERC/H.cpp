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

typedef struct Card {
    int num;
    char numChar;
    char type;
    string cardString;
} Card;

int recur(vector<int> &dp, vector<int> &back, vector<Card> &v, int mask);

void updateDP(vector<int> &dp, vector<int> &back, int currMask, int oldMask, vector<Card> &v) {
    int dpOldMask = recur(dp, back, v, oldMask);
    int currCost = dpOldMask + 1;
    if(dp[currMask] > currCost) {
        dp[currMask] = currCost;
        back[currMask] = oldMask;
    }
}

void updateMaskMulti(vector<vector<int> > &keepIndex, int currMask, int index, vector<int> &dp, vector<int> &back, vector<Card> &v) {
    int changeMask = 0;
    if(keepIndex[index].size() >= 1) {
        for(int i = 0; i < keepIndex[index].size(); i++) {
            changeMask ^= (1 << keepIndex[index][i]);
            updateDP(dp, back, currMask, changeMask ^ currMask, v);
        }
    }
}

void updateMask32(vector<vector<int> > &keepIndex, int currMask, int index, vector<int> &dp, vector<int> &back, vector<Card> &v) {
    int changeMask = 0;
    if(keepIndex[index].size() >= 3) {
        changeMask ^= (1 << keepIndex[index][0]);
        changeMask ^= (1 << keepIndex[index][1]);
        changeMask ^= (1 << keepIndex[index][2]);

        for(int i = 0; i < 15; i++) {
            if(i == index) continue;
            if(keepIndex[i].size() >= 2) {
                int tempChangeMask = changeMask;
                tempChangeMask ^= (1 << keepIndex[i][0]);
                tempChangeMask ^= (1 << keepIndex[i][1]);
                updateDP(dp, back, currMask, tempChangeMask ^ currMask, v);
            }
        }
    }
}

void updateMaskStraight(vector<vector<int> > &keepIndex, int currMask, int index, vector<int> &dp, vector<int> &back, vector<Card> &v) {
    int changeMask = 0;
    if(index <= 5) return;
    for(int i = 0; i < 5; i++) {
        if(keepIndex[index - i].size() == 0) return;
    }

    changeMask ^= (1 << keepIndex[index][0]);
    changeMask ^= (1 << keepIndex[index - 1][0]);
    changeMask ^= (1 << keepIndex[index - 2][0]);
    changeMask ^= (1 << keepIndex[index - 3][0]);

    for(int i = 4; index - i >= 2; i++) {
        if(keepIndex[index - i].size() == 0) return;
        changeMask ^= (1 << keepIndex[index - i][0]);
        updateDP(dp, back, currMask, changeMask ^ currMask, v);
    }
}

int recur(vector<int> &dp, vector<int> &back, vector<Card> &v, int mask) {
    if(dp[mask] != INF) return dp[mask];
    
    vector<vector<int> > keepIndex(15);
    for(int i = 0; i <13; i++) {
        if((mask & (1 << i))) {
            keepIndex[v[i].num].pu(i);
        }
    }

    for(int i = 0; i < 13; i++) {
        if((mask & (1 << i))) {
            updateMaskMulti(keepIndex, mask, v[i].num, dp, back, v);
            updateMask32(keepIndex, mask, v[i].num, dp, back, v);
            updateMaskStraight(keepIndex, mask, v[i].num, dp, back, v);
        }
    }

    if(dp[mask] == INF) dp[mask]++;

    return dp[mask];
}

void solve() {
    vector<Card> v(13);
    for(int i = 0; i < 13; i++) {
        string s;
        cin >> s;
        v[i].cardString = s;
        v[i].type = s[1];
        v[i].numChar = s[0];
        if(s[0] <= '9') v[i].num = s[0] - '0';
        else if(s[0] == 'T') v[i].num = 10;
        else if(s[0] == 'J') v[i].num = 11;
        else if(s[0] == 'Q') v[i].num = 12;
        else if(s[0] == 'K') v[i].num = 13;
        else v[i].num = 14;
    }

    int N = 13;
    vector<int> dp((1 << 13), INF), back((1 << 13), -1);

    dp[0] = 0;

    recur(dp, back, v, (1 << N) - 1);

    cout << dp[(1 << N) - 1] << endl;

    int currMask = (1 << N) - 1;
    vector<int> masks;
    while(back[currMask] != -1) {
        int tempMask = currMask ^ back[currMask];
        masks.pu(tempMask);
        currMask = back[currMask];
    }
    masks.pu(currMask);

    for(auto mask : masks) {
        if(mask == 0) continue;
        for(int i = 0; i < 13; i++) {
            if(mask & (1 << i)) {
                cout << v[i].cardString << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    __;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
