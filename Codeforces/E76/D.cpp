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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

int check(pair<int,int> p, int index,  vector<int> &mon)
{
  int pow = p.fi, en = p.se;
  int cnt = 0;
  for(int i=index;i<min(index+en,(int)mon.size());i++)
  {
    if(pow >= mon[i]) cnt++;
    else break;
  }
  return cnt;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> mon(n);
    int maxMon = -1;
    // vector<int> pow(n);
    for(int i=0;i<n;i++) cin >> mon[i];
    for(auto it : mon) maxMon = max(maxMon,it);
    // for(int i=0;i<n;i++) cin >> pow[i];

    int m;
    cin >> m;
    vector<pair<int,int> > v(m);
    int maxPow = -1;
    for(int i=0;i<m;i++)
    {
      cin >> v[i].fi >> v[i].se;
      maxPow = max(maxPow,v[i].fi);
    }

    if(maxPow < maxMon) 
    {
      cout << -1 << endl;
      continue;
    }

    sort(v.begin(),v.end());
    vector<pair<int,int> > pep;
    int min1 = -INF;
    for(int i=v.size()-1;i>=0;i--)
    {
      if(v[i].se > min1)
      {
        min1 = v[i].se;
        pep.pu(v[i]);
      }
    }

    int index = 0,ans = 0;
    while(index < n)
    {
      int beg = 0, end = pep.size()-1;
      while(end-beg > 3)
      {
        int mid1 = beg + (end-beg)/3;
        int mid2 = end - (end-beg)/3;
        int ans1 = check(pep[mid1],index,mon);
        int ans2 = check(pep[mid2],index,mon);
        if(ans1 < ans2)
        {
          beg = mid1;
        }
        else end = mid2;
      }

      int max1 = 0;
      for(int i=beg;i<=end;i++)
      {
        max1 = max(max1,check(pep[i],index,mon));
      }
      index += max1;
      ans++;
    }

    cout << ans << endl;

  }
  return 0;
}

/*
1
5
78 22 90 12 42
5
51 1
87 3
48 2
13 1
98 5

*/