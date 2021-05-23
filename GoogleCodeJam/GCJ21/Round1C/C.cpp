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

string getNot(string &s) {
    string t;
    int i = 0;
    while(s[i] == '1') i++;
    for(; i < s.size(); i++) {
        if(s[i] == '0') t += '1';
        else t += '0';
    }

    if(t.size() == 0) t += '0';

    return t;
}

bool isPrefix(string &s, string &t) {
    if(s.size() > t.size()) return false;
    if(s == t) return true;
    if(s.size() < t.size()) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) return false;
        }
        return true;
    }
    return false;
}

bool canChange(string &s, string &t, int i) {
    int start = i%2;
    int counter = 0;
    int j = s.size();
    for(; counter <= i && j < t.size(); counter++) {
        while(j < t.size() && t[j] == start + '0') {
            s += (start + '0');
            j++;
        }
        // t(s, t, start, counter, i);
        start ^= 1;
    }

    return s == t;
}

int getChanges(string s) {
    char prev = '$';
    int changes = 0;
    for(auto it : s) {
        if(it != prev) {
            prev = it;
            changes++;
        }
    }
    return changes;
}

int power2(string &s) {
    if(s[0] == '0') return false;
    int change = 0;
    char prev = '1';
    int changeIndex = -1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != prev) {
            changeIndex = i;
            prev = s[i];
            change++;
        }
    }

    if(change > 1) return -1;
    if(changeIndex + 1 > 1) {
        return s.size() + 1;
    } else {
        return s.size() - 1;
    }
}

void solve() {
    string s, t;
    cin >> s >> t;

    vector<string> notSeq;
    string temp = s;
    notSeq.push_back(temp);
    while(temp != "0") {
        string getNotS = getNot(temp);
        notSeq.push_back(getNotS);
        temp = getNotS;
    }

    // if(notSeq.back() != "1") notSeq.push_back("1");
    // t(notSeq);

    int ans = -1;
    for(int i = 0; i < notSeq.size(); i++) {
        string ele = notSeq[i];
        // t(i, ele);
        if(isPrefix(ele, t)) {
            if(canChange(ele, t, i)) {
                // t(ele, t, i, notSeq[i]);
                ans = t.size() - notSeq[i].size() + i;
                break;
            }
        }
    }

    if(ans == -1) {
        int c = power2(t);
        if(c != -1) {
            cout << notSeq.size() + c << endl;
            return;
        } 
    }

    if(ans == -1) {
        if(getChanges(t) <= notSeq.size()) {
            cout << notSeq.size() - 1 + t.size() << endl;
        }
    }

    if(ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;

}

int main() {
    __;
    int t;
    cin >> t;
    for(int h = 1; h <= t; h++) {
        cout << "Case #" << h << ": ";
        solve();
    }
    return 0;
}

/*
1
10001 111

1
1011 111

*/
