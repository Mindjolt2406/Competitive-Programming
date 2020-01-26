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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,k,x;
    ll sum1 = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {cin>>v[i];sum1+=v[i];}
    cin>>k>>x;
    vector<ll> w(n);
    for(int i=0;i<n;i++) w[i] = (v[i]^x) - v[i];
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());

    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++) pref[i]+=pref[i-1]+w[i-1];

    // t(w,pref);
    ll max1 = max(pref[k],pref[0]) ;
    if(k%2==0 && k!=n)
    {
      for(int i=0;i<=n;i+=2) max1 = max(max1,pref[i]);
    }
    else if(k!=n) // Odd case
    {
      for(int i=0;i<=n;i++) max1 = max(max1,pref[i]);
    }
    cout<<max1+sum1<<endl;
  }
  return 0;
}

/*
1
5
1 2 3 4 5
2 4

*/
