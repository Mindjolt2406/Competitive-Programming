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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}


vector<vector<vector<int> > > allPartitions(15);
map<vector<int>, vector<ll> > digitNums;
set<ll> allNums;

void getPartitions(int n) {
    if (n < 10) {
        vector<int> onePartition = {n};
        allPartitions[n].push_back(onePartition);
    }
    
    for (int i = 1; i < min(10, n); i++) {
        // i is the largest number in the partition amonst all partitions of n-i
        for (auto partition : allPartitions[n-i]) {
            int maxEle = *max_element(partition.begin(), partition.end());
            if (maxEle < i) {
                partition.push_back(i);
                allPartitions[n].push_back(partition);
            }
        }
    }
}

vector<int> generateBlockFromPartition(vector<int> &partition) {
    vector<int> block(10);
    for(auto num : partition) {
        block[num] += num;
    }

    return block;
}

void generateNumsFromPartitionBlock(vector<int> &block) {
    if (digitNums.count(block)) {
       return ; 
    }

    if (*max_element(block.begin(), block.end()) == 0) {
        digitNums[block] = {0};   
        return;
    }

    for (int i = 1; i < block.size() /* 10 */; i++) {
        vector<int> tempBlock = block;
        if (tempBlock[i]) {
            tempBlock[i]--;
            generateNumsFromPartitionBlock(tempBlock);
            for (auto num : digitNums[tempBlock]) {
                digitNums[block].push_back(num * 10 + i);
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 12; i++) {
        getPartitions(i);
        t(i, allPartitions[i]);
    }

    for (int digits = 1; digits <= 12; digits++) {
        for (auto partition : allPartitions[digits]) {
            vector<int> block = generateBlockFromPartition(partition);
            generateNumsFromPartitionBlock(block);
            t(block, digits);
            for (auto num : digitNums[block]) {
                allNums.insert(num);
            }
        }
    }
}