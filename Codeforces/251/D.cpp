/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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

int bsearch1(vector<ll> &v,int key)
{
  int beg = 0, end = (int)v.size()-1;
  int ans = -1;
  while(beg<=end)
  {
    int mid = (beg+end)>>1;
    if(v[mid]<=key) {ans = mid; beg = mid+1;}
    else end = mid-1;
  }
  return ans;
}

int bsearch2(vector<ll> &v,int key)
{
  int beg = 0, end = (int)v.size()-1; 
  int ans = v.size();
  while(beg<=end)
  {
    int mid = (beg+end)>>1;
    if(v[mid]>=key) {ans = mid; end = mid-1;}
    else beg = mid+1;
  }
  return ans;
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<ll> v(n),w(m),prefv(n),prefw(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<m;i++) cin>>w[i];

  sort(all(v));
  sort(all(w));

  prefv[0] = v[0];
  prefw[0] = w[0];
  
  for(int i=1;i<v.size();i++) prefv[i] += v[i] + prefv[i-1];
  for(int i=1;i<w.size();i++) prefw[i] += w[i] + prefw[i-1];


  ll min1 = INF;
  swap(n,m);
  swap(v,w);
  swap(prefv,prefw);

  for(int i=0;i<n;i++)
  {
    int index = bsearch1(w,v[i]);
    ll cost1,cost2;
    if(index!=-1)  cost2 = prefw[w.size()-1] - prefw[index] - (w.size()-1-index)*v[i];
    else cost2 = prefw[w.size()-1] - (w.size()-1-index)*v[i];
    
    cost1 = v[i]*(i+1) - prefv[i];

    t(i,v[i],cost1,cost2);
    min1 = min(min1,cost1+cost2);
  }

  for(int i = 0;i<m;i++)
  {
    int index = bsearch2(v,w[i]);
    ll cost1,cost2;
    cost2 = prefw[w.size()-1] - prefw[i] - (w.size()-1-i)*w[i];
    if(index==v.size()) cost1 = w[i]*n - prefv[n-1];
    else cost1 = w[i]*(index+1) - prefv[i];
    
    t(i,w[i],cost1,cost2);
    min1 = min(min1,cost1+cost2);
  }

  cout<<min1<<endl;
  return 0;
}

/*

1 2 3 4 5 

 */
