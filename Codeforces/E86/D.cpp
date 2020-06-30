#include<bits/stdc++.h>
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

typedef struct BIT //int
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size()+10);
    for(int i=0;i<v.size();i++) 
    {
      inc(i,v[i]);
      inc(i+1,-v[i]);
    }
  }
} BIT;

void print(BIT &bit)
{
  for(int i=0;i<=5;i++) cout << bit.sum(i) << " "; cout << endl;
}

int bsearch1(BIT &bit)
{
  int beg = 1, end = bit.n-1,ans = 0;
  while(beg <= end)
  {
    int mid = (beg+end) >> 1;
    if(bit.sum(mid)>0)
    {
      ans = mid;
      beg = mid+1;
    }
    else end = mid-1;
  }
  return ans;
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  vector<int> v(n),w(k+1);
  multiset<int,greater<int> > s,s2;
  BIT bit,bit2;
  bit2.init(3e5);
  bit2.inc(0,1);

  for(int i=0;i<n;i++) 
  {
    cin >> v[i];
    s.insert(v[i]);
    s2.insert(v[i]);
    bit2.inc(v[i],1);
  }
  for(int i=1;i<=k;i++) cin >> w[i];

  bit.init(w);
  // print(bit);


  vector<vector<int> > ans;

  
  while(!s.empty())
  {
    // _;
    vector<pair<int,int> > inv;
    vector<int> temp_ans;
    auto it = s.begin();
    while(it != s.end())
    {
      if(bit.sum(*it) && s2.count(*it))
      {
        bit.inc(1,-1);
        inv.pu(mp(1,1));
        bit.inc(bit.n,1);
        inv.pu(mp(bit.n,-1));
        temp_ans.pu(*it);
        s.erase(s.find(*it));
        bit2.inc(*it,-1);
      }
      else if(bit.sum(*it)) break;
      int a = bsearch1(bit);
      // t(a);
      // for(auto it : s) t(it);
      it = s.lower_bound(a);
      if(it == s.end()) 
      {
        it = s.upper_bound(a);
      }
    }

    // _;
    // for(auto it : temp_ans) s.erase(s.find(it));
    for(auto p : inv) bit.inc(p.fi,p.se);
    ans.pu(temp_ans);
  }

  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++)
  {
    cout << ans[i].size() << " ";
    for(auto it : ans[i]) cout << it << " "; cout << "\n";
  }
  return 0;
}
