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

const int N = 2e5+10;
vector<int> spf(N, INF);
 
void sieve() {
  spf[0] = spf[1] = -1;
  for(ll i = 2; i < N; i++) {
    if(spf[i] == INF) {
      spf[i] = i;
      for(ll j = i*i; j < N; j+= i) spf[j] = min(spf[j], (int)i);
    }
  }
}

bool query(int val, int n, int m, bool height = true) {
  int i1, j1, i2, j2, h, w;
  if(height) {
    i1 = 1, j1 = 1, i2 = val + 1, j2 = 1, h = val, w = m;
  } else {
    i1 = 1, j1 = 1, i2 = 1, j2 = val + 1, h = n, w = val;
  }
  cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
  int a;
  cin >> a;
  if(a == 1) {
    return true;
  } else if(a == 0) {
    return false;
  } else exit(0);
}

bool lastQuery(int val, int n, int m, bool height = true) {
  int i1, j1, i2, j2, h, w;
  if(height) {
    i1 = 1, j1 = 1, i2 = n - val + 1, j2 = 1, h = val, w = m;
  } else {
    i1 = 1, j1 = 1, i2 = 1, j2 = m - val + 1, h = n, w = val;
  }
  cout << "? " << h << " " << w << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
  int a;
  cin >> a;
  if(a == 1) {
    return true;
  } else if(a == 0) {
    return false;
  } else exit(0);
}

int checkNum(int n, int it, int n1, int m1, bool height = true) {
  int last = 0;
  // t(n, it, n1, m1, height);
  for(int i = 1; i * (n/it) * 2 <= n; i <<= 1) {
    // t(i);
    bool val = query(i * (n/it), n1, m1, height); // When called with m, n is m
    if(!val) {
      return 0;
    }
    last = (n/it) * i * 2;
  }

  if(n != last) {
    // t(n - last);
    bool val = lastQuery(n - last, n1, m1, height);
    if(!val) {
      return 0;
    }
  }

  if((n/it)%it == 0) {
    if(height) n1 /= it;
    else m1 /= it;
    int x = checkNum(n/it, it, n1, m1, height);
    return x + 1;
  } else {
    return 1;
  }
}

int main()
{
  __;
  sieve();
  int n, m;
  cin >> n >> m;

  vector<int> primeN, primeM;

  for(int i = 2; i <= n; i++) {
    if(spf[i] == i) primeN.push_back(i);
  }

  for(int i = 2; i <= m; i++) {
    if(spf[i] == i) primeM.push_back(i);
  }

  int primeIterN = 0, primeIterM = 0;
  bool iterPrimeN = true, iterPrimeM = true;

  vector<pair<int, int> > possN, possM;
  for(auto it : primeN) {
    bool flag = true;
    if(n % it == 0) {
      int resNum = checkNum(n, it, n, m);
      if(!resNum) {
        flag = false;
        continue;
      }
      possN.push_back(mp(it, resNum));
    }
  }

  for(auto it : primeM) {
    bool flag = true;
    if(m % it == 0) {
      int resNum = checkNum(m, it, n, m, false);
      // t(it, resNum);
      if(!resNum) {
        flag = false;
        continue;
      }
      possM.push_back(mp(it, resNum));
    }
  }

  int ansN = 1, ansM = 1;
  for(auto it : possN) ansN *= (it.se + 1);
  for(auto it : possM) ansM *= (it.se + 1);

  // t(possN, possM);

  cout << "! " << ansN * ansM << endl;
  return 0;
}
