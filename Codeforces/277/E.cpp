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

int computeLIS(vector<int> &v, vector<int> &lis)
{
  int n = v.size();
  // vector<int> lis(n);
  vector<int> I(n+1);

  I[0] = -INF;
  for(int i=1;i<=n;i++) I[i] = INF;

  int lenLIS = 0;

  for(int i=0;i<n;i++)
  {
    int beg = 0, end = n;
    while(beg <= end)
    {
      int mid = (beg+end) >> 1;
      if(I[mid] < v[i])
      {
        beg = mid+1;
      }
      else end = mid-1;
    }

    I[beg] = v[i];
    lis[i] = beg;
    if(beg > lenLIS) lenLIS = beg;
  }

  return lenLIS;
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n), lis(n);
  for(int i=0;i<n;i++) cin >> v[i];

  int lenLIS = computeLIS(v,lis);
  
  vector<set<int> > adj(n+1);
  vector<bool> marked(n);
  for(int i=n-1;i>=0;i--)
  {
    if(lis[i] == lenLIS) 
    {
      marked[i] = true;
      adj[lenLIS].insert(v[i]);
    }
    else
    {
      if(!adj[lis[i]+1].empty())
      {
        int highest = *adj[lis[i]+1].rbegin();
        if(highest > v[i])
        {
          adj[lis[i]].insert(v[i]);
          marked[i] = true;
        }
      }
    }
  }

  vector<int> freq(n+1);
  for(int i=0;i<n;i++)
  {
    if(marked[i]) freq[lis[i]]++;
  }

  string ans;
  for(int i=0;i<n;i++) ans += '1';
  for(int i=0;i<n;i++)
  {
    if(marked[i])
    {
      if(freq[lis[i]] == 1) ans[i] = '3';
      else ans[i] = '2';
    }
  }

  cout << ans << endl;
  return 0;
}
