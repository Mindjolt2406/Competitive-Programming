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

typedef struct Node {
    Node* next;
    Node* prev;
    int id;
    deque<pair<ll, ll> > queue;

    pair<ll, ll> getFront() {
        return queue.front();
    } 

    pair<ll, ll> getBack() {
        return queue.back();
    }
} Node;

Node* merge(Node* left, Node* right) {
    // t("merge", left -> getFront(), left -> getBack(), right -> getFront(), right -> getBack());
    if(left -> queue.size() < right -> queue.size()) { // Delete left
        while(!(left -> queue).empty()) {
            pair<ll, ll> temp = left -> getBack();
            (left -> queue).pop_back();
            (right -> queue).push_front(temp);
        }

        right -> prev = left -> prev;
        (left -> prev) -> next = right;
        free(left);
        // t(right -> getFront(), right -> getBack());
        return right;
    } else {
        while(!(right -> queue).empty()) { // Delete right
            pair<ll, ll> temp = right -> getFront();
            (right -> queue).pop_front();
            (left -> queue).push_back(temp);
        }

        left -> next = right -> next;
        (right -> next) -> prev = left;
        free(right);
        // t(left -> getFront(), left -> getBack());
        return left;
    }
}

Node* deleteRight(Node* left, Node* right) {
    // t("delete", left -> getFront(), left -> getBack(), right -> getFront(), right -> getBack());
    (right -> queue).pop_front();
    if((right -> queue).empty()) {
        left -> next = right -> next;
        (right -> next) -> prev = left;
        free(right);
    }
    return left;
}

bool checkMerge(Node* left, Node* right) {
    if(left -> id == right -> id) return false;
    int leftNum = left -> getBack().fi;
    int rightNum = right -> getFront().fi;
    // t(leftNum, rightNum);
    if(gcd(leftNum, rightNum) != 1) {
        return true;
    }
    return false;
}

void processOnlyNode(Node* node, vector<int> &ans) {
    while(!(node -> queue).empty()) {
        int leftNum = node -> getBack().fi;
        int rightNum = node -> getFront().fi;
        // t(leftNum, rightNum);
        if(gcd(leftNum, rightNum) == 1) {
            // t(node -> getFront());
            ans.push_back(node -> getFront().se);
            (node -> queue).pop_front();
        } else break;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    if(n == 1) {
        if(v[0] == 1) cout << "1 1" << endl; 
        else cout << 0 << endl;
        return;
    } 

    Node* head = new Node();
    head -> queue.push_back(mp(v[0], 0));
    head -> id = 0;

    // Make the circular linked list
    Node *curr = head;
    for(int i = 1; i < n; i++) {
        Node* temp = new Node();
        temp -> queue.push_back(mp(v[i], i));
        temp -> id = i;
        temp -> prev = curr;
        curr -> next = temp;
        curr = temp;

        if(i == n-1) {
            curr -> next = head;
            head -> prev = curr;
        }
    }

    // Merge stuff
    Node* temp = head;
    bool headDone = false;
    for(int i = 0; i < n; i++) {
        int leftNum = temp -> getBack().fi;
        int rightNum = temp -> next -> getFront().fi;
        bool isMerge = false;
        if(gcd(leftNum, rightNum) != 1) {
            if(checkMerge(temp, temp -> next)) {
                temp = merge(temp, temp -> next);
                isMerge = true;
            }
        }

        if(!isMerge) temp = temp -> next;
    }

    vector<int> ans;
    curr = temp;
    while(curr -> id != curr -> next -> id) {
        int leftNum = curr -> getBack().fi;
        int rightNum = curr -> next -> getFront().fi;
        bool isMerge = false;
        if(gcd(leftNum, rightNum) == 1) { // Delete and check if can be merged later
            ans.push_back(curr -> next -> getFront().se);
            curr = deleteRight(curr, curr -> next);
            if(checkMerge(curr, curr -> next)) {
                isMerge = true;
                curr = merge(curr, curr  -> next);
            }
        }

        if(!isMerge) curr = curr -> next;
    }

    processOnlyNode(curr, ans);

    cout << ans.size() << " "; 
    for(auto it : ans) cout << it + 1 << " "; cout << "\n";
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
