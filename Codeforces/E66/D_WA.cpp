/*
Rathin Bhargava
IIIT Bangalore

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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  // Input
  int n,k;
  cin>>n>>k;
  vector<ll> pref(n+1),v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  
  // Construct reverse prefix sum
  pref[n-1] = v[n-1];
  for(int i=n-2;i>=0;i--) pref[i] = pref[i+1]+v[i];

  // The kth interval can have its left only from k-1 to n-1
  int left = k-1, right = n-1;
  set <pair<ll, int > > s;
  for(int i=right;i>=left;i--) s.insert(mp(pref[i],i));

  ll count = 0, sofar = 0;  
  while(left>0) // Don't consider the first interval for now
  {
    // For each left'th interval, the right has been determined earlier, get the left point. 
    // p should be the prefix sum in the allowed range with the max sum
    pair<ll,int> p = *s.rbegin();
    int index = p.se; 

    // The best prefix sum contains sums from index to n-1
    // The right+1 to n-1 should be subtracted. Also, left is 0 based, but f(i) is 1-based
    ll sum1 = p.fi;
    ll a = (sum1 - pref[right+1])*(left+1);
    count+=a;
    t(left,right,index,sum1-pref[right+1],a);
    // for(auto p : s) t(p);
    for(int i=index;i<=right;i++) s.erase(mp(pref[i],i));
    
    // For the left-1 'th interval, its right point is just before index
    // It's lower bound on left decreases by 1. So consider that prefix sum as well
    right = index-1;
    left--;
    s.insert(mp(pref[left],left));
  }

  // We force the first interval to take the first element. 
  count+=pref[0]-pref[right+1];
  cout<<count<<endl;
  return 0;
}

