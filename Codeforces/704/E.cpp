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

set<int> getIndexDiff(vector<int> &v, vector<int> &w) {
  set<int> ans;
  for(int i=0;i<v.size();i++)
  {
    if(v[i] != w[i]) ans.insert(i);
  }
  return ans;
}

set<int> compareAll(vector<int> &v, vector<int> &w, set<int> &diff) {
  set<int> diffAll;
  for(int i=0;i<v.size();i++) {
    if(diff.count(i)) continue;
    if(v[i] != w[i]) diffAll.insert(i);
  }

  return diffAll;
}

void enforceArr(vector<int> &v, vector<int> &w, int &leftMoves, set<int> diffs) {
  for(auto it : diffs) {
    w[it] = v[it];
    leftMoves--;
  }
}

bool processFinalArr(vector<int> &finalArr, vector<vector<int> > &v) {
  for(int i=0;i<v.size();i++) {
    if(getIndexDiff(v[i], finalArr).size() > 2) return false;
  }
  return true;
}

bool checkArr(vector<int> &finalArr, vector<vector<int> > &v, vector<int> &leftMoves) {
  for(int i=0;i<v.size();i++) {
    if(getIndexDiff(v[i], finalArr).size() > leftMoves[i]) return false;
  }
  return true;
}

void processAns(vector<int> &finalArr, vector<vector<int> > &v) {
  bool correct = processFinalArr(finalArr, v);
  if(!correct) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for(auto it : finalArr) cout << it << " "; cout << endl;
  } 
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(m));

  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
  
  /*
  2 3 4 5 6 7 8 1 1 1 1
                2 1 1 1
                1 2 1 1
                1 1 2 1
                1 1 1 2
  7 8 2 3 6 7 8 1 1 1 1
  Actual
  7 8 4 5 6 7 8 1 1 1 1
  */

  int maxDiffSize = 0;
  int otherArr = -1;
  set<int> maxDiffs;
  for(int i = 1;i < n; i++) {
    set<int> diff = getIndexDiff(v[0], v[i]);
    if(diff.size() > maxDiffSize) {
      maxDiffs = diff;
      maxDiffSize = diff.size();
      otherArr = i;
    }
  }

  if(maxDiffSize <= 2) { // Trivially covers n = 1 case
    cout << "Yes" << endl;
    for(auto it : v[0]) cout << it << " "; cout << endl;
    return;
  }
  
  if(maxDiffSize > 4) {
    cout << "No" << endl;
    return;
  }

  vector<int> leftMoves(n, 2);

  for(int i = 2; i < n; i++) {
    set<int> diffRest = compareAll(v[0], v[i], maxDiffs);
    if(diffRest.size() > 2) {
      cout << "No" << endl;
      return;
    }

    // Enforce the values of v[0] onto v[i] and reduce moves left accordingly
    enforceArr(v[0], v[i], leftMoves[i], diffRest);
  }

  // Now, take care of indices in maxDiffs
  int minMoves = INF, minIndex = -1;
  for(int i = 0;i < n; i++) {
    if(leftMoves[i] < minMoves) {
      minMoves = leftMoves[i];
      minIndex = i;
    }
  }

  // t(v, leftMoves);
  if(minMoves != 0) {
    bool flag = false;
    if(checkArr(v[0], v, leftMoves)) {processAns(v[0], v); return;}

    vector<int> diffList(maxDiffs.begin(), maxDiffs.end());
    // t(diffList, otherArr);
    for(int mask = 0; mask < (1 << diffList.size()); mask++) {
      if(__builtin_popcount(mask) > 2) continue;
      vector<int> tempListFirst, tempListSecond;
      for(int i=0;i<diffList.size();i++) {
        if(mask & (1 << i)) tempListFirst.pu(diffList[i]);
        else tempListSecond.pu(diffList[i]);
      }

      int thirdIndex = (otherArr == 1) ? 2 : 1;
      vector<int> w = v[0];
      for(auto it : tempListFirst) {
        w[it] = v[otherArr][it];
      }

      // if(mask == 4) t(mask, w);
      if(n > 2) {
        for(auto it : tempListSecond) {
          w[it] = v[thirdIndex][it];
        }
      }

      if(checkArr(w, v, leftMoves)) {processAns(w, v); return;}
    }

    for(int mask = 0; mask < (1 << diffList.size()); mask++) {
      if(__builtin_popcount(mask) > 2) continue;
      vector<int> tempListFirst, tempListSecond;
      for(int i=0;i<diffList.size();i++) {
        if(mask & (1 << i)) tempListFirst.pu(diffList[i]);
        else tempListSecond.pu(diffList[i]);
      }

      int thirdIndex = (otherArr == 1) ? 2 : 1;
      vector<int> w = v[0];
      for(auto it : tempListFirst) {
        w[it] = v[otherArr][it];
      }

      if(checkArr(w, v, leftMoves)) {processAns(w, v); return;}
    }

    cout << "No" << endl;
    return;
  }  else {
    if(checkArr(v[minIndex], v, leftMoves)) {processAns(v[minIndex], v); return;}
    return;
  }
}

int main()
{
  __;
  solve();
  return 0;
}
