/*
Rathin Bhargava
IIIT Bangalore
Div2D
Div1C

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

const int N = 3e5+10;
vector<int> adj[N] = {};
unordered_map<pair<int,int> ,int, pair_hash> d;
vector<int> weight(N);


void add(int a,int b)
{
  if(d.find(mp(a,b))==d.end()) d[mp(a,b)] = 1;
  else d[mp(a,b)]++;
}

int bsearch1(vector<int> &v, int val)
{
  int beg = 0, end = v.size()-1, ans = v.size();
  while(beg<=end)
  {
    int mid = (beg+end)>>1;
    if(v[mid]>=val) {end = mid-1; ans = mid;}
    else beg = mid+1;
  }
  
  return ans;
}

int main()
{
  __;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    a--; b--;
    add(a,b);
  }

  vector<int> v;

  for(auto it : d)
  {
    weight[it.fi.fi] += it.se;
    weight[it.fi.se] += it.se;
  }

  for(int i=0;i<n;i++) v.pu(weight[i]);

  sort(v.begin(),v.end());

  ll cnt = 0;

  for(int i=0;i<n;i++)
  {
    int a = weight[i];
    if(a>=k)
    {
      cnt += n-1;
      // t(cnt,i);
      continue;
    }
    else
    {
      int b = k-a;
      // Get the number of numbers greater than or equal to b
      int index = bsearch1(v,b);
      // Get the sum of all their weights
      int val = v.size() - index;
      // Subtract all the neighbour's whos weight is >= b, since you've already counted them
      for(auto v : adj[i]) 
      {
        if(weight[v] < b) continue;
        if(weight[v] - d[mp(i,v)] < b) val--;
      }
      if(weight[i]>=b) val --;
      // What's left is the number of pairs compatible with i
      cnt += val;
    }
    // t(cnt,i);
  }

  cout<<cnt/2<<endl;

  return 0;
}

