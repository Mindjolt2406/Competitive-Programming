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
#define pn(v,n) { for(int i=0;i<n;i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
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


int block;
const int N = 3e5+10, BLOCK = 510;
// int arr1[100010][BLOCK] = {0};
vector<int> v(N), counter(N);
vector<ll> fact(N);
ll cnt = 1;

typedef struct node
{
  int first,second,i;
}node;

bool sorter(const node &a, const node &b) 
{ 
  if(a.fi/block < b.fi/block) return true;
  else if(a.fi/block> b.fi/block) return false;
  else
  {
    if(a.se<b.se) return true;
    return false;
  }
} 

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void add(int pos)
{
  counter[v[pos]]++;
  cnt*= counter[v[pos]];
  cnt%=MOD;
}

void remove(int pos)
{
  cnt*=power(counter[v[pos]],MOD-2,MOD);
  cnt%=MOD;
  counter[v[pos]]--;
}

int main()
{
  __;
  fact[0] = 1;
  for(int i=1;i<=3e5;i++)
  {
    fact[i] = (fact[i-1]*i)%MOD;
  }
  int n;
  cin>>n;
  int q;
  cin>>q;
  set<int> s;
  unordered_map<int,int> d;
  int rank = 0;
  for(int i=0;i<n;i++) 
  {
    cin>>v[i];
    s.insert(v[i]);
  }
  
  for(auto it : s)
  {
    d[it] = rank;
    rank++;
  }
  for(int i=0;i<n;i++) v[i] = d[v[i]];

  vector<int> ans(q);
  vector<node> arr(q);

  for(int i=0;i<q;i++)
  {
    int e,f;
    // cin>>e>>f; // l1 and ri. We don't need this at all
    cin>>e>>arr[i].fi>>f>>arr[i].se;
    if(arr[i].fi > arr[i].se) swap(arr[i].fi,arr[i].se);
    arr[i].i = i;
  }
  // t(v);
  block = int(sqrt(n));
  sort(arr.begin(),arr.end(),sorter);
  
  int left = 0,right = -1,count = 0;
  for(int i=0;i<q;i++)
  {
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(right<b)
    {
      right++;
      add(right);
    }
    while(right>b)
    {
      remove(right);
      right--;
    }
    while(left>a)
    {
      left--;
      add(left);
    }
    while(left<a)
    {
      remove(left);
      left++;
    }
    ans[p.i] = (fact[b-a+1]*power(cnt,MOD-2,MOD))%MOD;
    // ans[p.i] = count;
  }

  for(int i=0;i<q;i++)
  {
    cout<<ans[i]<<endl;
  }
  return 0;
}  

/*
20 
5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
0 0 0 19
0 0 0 1
0 0 5 5
0 0 3 4
0 0 2 5

*/