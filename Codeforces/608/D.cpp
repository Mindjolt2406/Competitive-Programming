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
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cout<<#x<<" : "<<x<<endl
#define t2(x, y)             cout<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cout<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cout<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cout<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cout<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 5100;
vector<int> a(N), b(N), c(N);
vector<pair<int,int> > adj[N];
vector<int> ex(N),cum(N);

int main()
{
  __;
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<n;i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin >> x >> y;
    x--; y--;
    adj[x].pu(mp(c[y],y));
  }

  for(int i=0;i<n;i++) sort(adj[i].begin(),adj[i].end());

  for(int i=0;i<n;i++)
  {
    if(k >= a[i])
    {
      ex[i] = k-a[i];
      k += b[i];
    }
    else 
    {
      cout << -1 << endl;
      return 0;
    }
  }


  for(int i=0;i<n;i++) cout << ex[i] << " "; cout << endl;
  int min1 = INF;
  for(int i=n-1;i>=0;i--)
  {
    cum[i] = min1;
    min1 = min(min1,ex[i]);
  }

  for(int i=0;i<n;i++) cout << cum[i] << " "; cout << endl;
  multiset<pair<int,int> > s;
  for(int i=0;i<n;i++) 
  {
    for(auto v : adj[i])
    {
      s.insert(v);
    }
    s.insert(mp(c[i],i));
  }

  int ans = 0;

  b[n-1] += a[n-1];
  set<pair<int,int> > edge;
  t(adj[n-1]);
  for(auto v : adj[n-1]) edge.insert(v);
  edge.insert(mp(c[n-1],n-1));

  while(b[n-1]-- && !edge.empty())
  {
    pair<int,int> p = *edge.rbegin();
    ans += p.fi;
    t(p);
    edge.erase(p);
    s.erase(p);
    for(auto it : s) t(it,cum[it.se]);
  }

  for(auto it : s) t(it,cum[it.se]);
  
  int left = 0;
  int used = 0;

  while(left != n)
  {
    // t(left,used);
    while(left!=n && cum[left] <= used) 
    {
      cout << "Deleting..." << endl;
      // t(left,cum[left]);
      if(s.count(mp(c[left],left))) s.erase(s.find(mp(c[left],left)));
      
      for(auto v : adj[left])
      {
        if(s.count(v)) s.erase(s.find(v));
      }
      // for(auto it : s) t(it,cum[it.se]);
      left++;
    }

    if(!s.empty())
    {
      pair<int,int> p = *s.rbegin();
      ans += p.fi;
      used++;
      t(left,p,used);

      // Delete anything to do with this vertex
      s.erase(p);
      // for(auto it : s) t(it,cum[it.se]);
      // for(auto v : adj[p.se])
      // {
      //   if(s.count(v)) s.erase(s.find(v));
      // }
    }
    else break;
  }

  cout << ans << endl;
  return 0;
}

/*
4 3 7
7 4 17
3 0 8
10 2 0
12 3 5
3 1
2 1
4 3


*/
