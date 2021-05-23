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

int merge(int left, int right, vector<deque<pair<int, int> > > &cells, set<int> &s, vector<int> &getID) {
    if(cells[right].size() < cells[left].size()) {
        s.erase(right);
        while(!cells[right].empty()) {
            pair<int, int> p = cells[right].front();
            cells[right].pop_front();
            cells[left].push_back(p);
            getID[p.se] = left;
        }
        return left;
    } else {
        s.erase(left);
        while(!cells[left].empty()) {
            pair<int, int> p = cells[left].back();
            cells[left].pop_back();
            cells[right].push_front(p);
            getID[p.se] = right;
        }
        return right;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    // Create everything
    set<int> s;
    vector<deque<pair<int, int> > > cells(n);
    vector<int> getID(n);
    for(int i = 0; i < n; i++) {
        s.insert(i);
        cells[i].push_back(mp(v[i], i));
        getID[i] = i;
    }

    // Merge stuff
    for(int i = 0; i < n; i++) {
        if(gcd(v[i], v[(i+1)%n]) != 1 && n > 1) {
            int left = getID[i], right = getID[(i+1)%n];
            merge(left, right, cells, s, getID);
        }
    }

    // Kill stuff
    int currID = getID[0];
    vector<int> ans;
    while(s.size() > 1) {
        int nextID;
        if(s.upper_bound(currID) == s.end()) nextID = *s.begin();
        else nextID = *s.upper_bound(currID);

        if(currID == nextID) break;

        pair<int, int> leftNode = cells[currID].back();
        pair<int, int> rightNode = cells[nextID].front();
        int leftNum = leftNode.fi, leftID = getID[leftNode.se];
        int rightNum = rightNode.fi, rightID = getID[rightNode.se];
        int newID = -1;

        if(gcd(leftNum, rightNum) != 1) {
            newID = merge(leftID, rightID, cells, s, getID);
        } else {
            // Delete the next node since GCD  = 1
            pair<int, int> p = cells[nextID].front();
            cells[nextID].pop_front();
            ans.push_back(p.se + 1);
            if(cells[nextID].empty()) s.erase(nextID);
            else { // Try merging if gcd is not 1
                pair<int, int> leftNode = cells[currID].back();
                pair<int, int> rightNode = cells[nextID].front();
                int leftNum = leftNode.fi, leftID = getID[leftNode.se];
                int rightNum = rightNode.fi, rightID = getID[rightNode.se];
                if(gcd(leftNum, rightNum) != 1) {
                    newID = merge(leftID, rightID, cells, s, getID);
                }
            }   
        }

        if(newID == -1) {
            if(s.count(nextID)) currID = nextID;
            else {
                int nextNextID;
                if(s.upper_bound(nextID) == s.end()) nextNextID = *s.begin();
                else nextNextID = *s.upper_bound(nextID);

                currID = nextNextID;
            }
        } else {
            int nextNextID;
            if(s.upper_bound(newID) == s.end()) nextNextID = *s.begin();
            else nextNextID = *s.upper_bound(newID);

            currID = nextNextID;
        }
    }

    // t(ans);
    currID = *s.begin();

    while(!cells[currID].empty()) {
        pair<int, int> leftNode = cells[currID].back();
        pair<int, int> rightNode = cells[currID].front();
        // t(leftNode, rightNode, cells[currID].size());
        int leftNum = leftNode.fi, leftID = getID[leftNode.se];
        int rightNum = rightNode.fi, rightID = getID[rightNode.se];
        if(gcd(leftNum, rightNum) == 1) {
            ans.push_back(rightNode.se + 1);
            cells[currID].pop_front();
        } else break;
    }

    // t(ans);

    cout << ans.size() << " ";
    for(auto it : ans) cout << it << " "; cout << endl;
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
