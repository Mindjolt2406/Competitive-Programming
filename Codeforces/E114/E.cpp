// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
// clang-format on

ll power(ll x, ll y, ll p) {
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

typedef struct Node {
    int zeroEvenNum = 0, zeroOddNum = 0, oneEvenNum = 0, oneOddNum = 0;
} Node;

int checkPossibility(Node &node) {
    if ((node.zeroEvenNum && node.zeroOddNum) ||
        (node.oneEvenNum && node.oneOddNum))
        return 0;

    if (node.zeroEvenNum || node.zeroOddNum || node.oneEvenNum ||
        node.oneOddNum)
        return 1;

    return 2;
}

pair<int, int> checkPatternPossibility(Node &node) {
    if (!checkPossibility(node))
        return make_pair(false, false);

    if (node.zeroEvenNum)
        return make_pair(true, false);
    else
        return make_pair(false, true);
}

void updateNode(int newPoss, int &oldPoss, int &numPoss, ll &numProd) {
    t(oldPoss, newPoss, numPoss, numProd);
    if (newPoss != oldPoss) {
        if (newPoss == 0) {
            numPoss--;
        } else if (newPoss == 1) {
            numProd = (power(2, MOD - 2, MOD) * numProd) % MOD;
            (oldPoss == 0 ? numPoss++ : 0);
        } else {
            numProd = (numProd * 2) % MOD;
        }
        // if (newPoss) {
        //     numProd = (power(2, MOD - 2, MOD) * numProd) % MOD;
        //     numPoss--;
        // } else {
        //     numProd = (numProd * 2) % MOD;
        //     numPoss++;
        // }

        oldPoss = newPoss;
    }
}

void updatePatNode(int newPoss, int &oldPoss, int &numPoss) {
    if (newPoss != oldPoss) {
        (newPoss ? numPoss++ : numPoss--);
    }
    oldPoss = newPoss;
}

void deleteNode(int ele, Node &node, int posNum) {
    if (posNum & 1)
        (ele == 0 ? node.zeroOddNum-- : node.oneOddNum--);
    else
        (ele == 1 ? node.zeroEvenNum-- : node.oneEvenNum--);
}

void insertNode(int ele, Node &node, int posNum) {
    if (posNum & 1)
        (ele == 0 ? node.zeroOddNum++ : node.oneOddNum++);
    else
        (ele == 1 ? node.zeroEvenNum++ : node.oneEvenNum++);
}

int main() {
    __;
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> rows(n), cols(m);
    vector<int> isRow(n, 2), isCol(m, 2);
    int numRowsPoss = n, numColsPoss = m;

    Node patNode;
    int isPatZero = true, isPatOne = true;

    ll rowProd = power(2, n, MOD), colProd = power(2, m, MOD);
    int patternOffset = 2;

    map<pair<int, int>, int> elePos;
    while (k--) {
        int x, y, type;
        cin >> x >> y >> type;
        x--;
        y--;
        pair<int, int> coord = make_pair(x, y);
        int rowNum = coord.first;
        int colNum = coord.second;
        if (type == -1) {
            // Deletion operation.
            if (elePos.count(coord)) {
                int ele = elePos[coord];

                // Delete from row, col and pattern node.
                deleteNode(ele, rows[rowNum], rowNum);
                deleteNode(ele, cols[colNum], colNum);
                deleteNode(ele, patNode, rowNum + colNum);

                // Update the row & col info.
                int newRowPoss = checkPossibility(rows[rowNum]);
                int newColPoss = checkPossibility(cols[colNum]);

                updateNode(newRowPoss, isRow[rowNum], numRowsPoss, rowProd);
                updateNode(newColPoss, isCol[colNum], numColsPoss, colProd);
                pair<int, int> isPat = checkPatternPossibility(patNode);
                updatePatNode(isPat.first, isPatZero, patternOffset);
                updatePatNode(isPat.second, isPatOne, patternOffset);

                elePos.erase(coord);
            } // Otherwise do nothing.
        } else {
            // Delete first, insert later.

            // Delete from row, col and pattern node.
            int oldEle = elePos[coord];
            deleteNode(oldEle, rows[rowNum], rowNum);
            deleteNode(oldEle, cols[colNum], colNum);
            deleteNode(oldEle, patNode, rowNum + colNum);

            // Insert to row, col and pattern node.
            int newEle = type;
            insertNode(newEle, rows[rowNum], rowNum);
            insertNode(newEle, cols[colNum], colNum);
            insertNode(newEle, patNode, rowNum + colNum);
            elePos[coord] = newEle;

            // Update the row & col info.
            int newRowPoss = checkPossibility(rows[rowNum]);
            int newColPoss = checkPossibility(cols[colNum]);

            updateNode(newRowPoss, isRow[rowNum], numRowsPoss, rowProd);
            updateNode(newColPoss, isCol[colNum], numColsPoss, colProd);

            pair<int, int> isPat = checkPatternPossibility(patNode);
            updatePatNode(isPat.first, isPatZero, patternOffset);
            updatePatNode(isPat.second, isPatOne, patternOffset);
        }

        t(rowProd, colProd);
        ll finalRowProd = rowProd * (numRowsPoss == n);
        ll finalColProd = colProd * (numColsPoss == m);
        t(finalRowProd, finalColProd, patternOffset, coord, type);
        t(numRowsPoss, numColsPoss);
        cout << ((finalRowProd + finalColProd) % MOD - patternOffset + MOD) %
                    MOD
             << "\n";
    }
    return 0;
}
