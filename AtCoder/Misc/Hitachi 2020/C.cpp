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

const int N = 2e5+10;
vector<int> adj[N] = {};
vector<int> ans(N);

vector<vector<int> > arr(6,vector<int>(6));
vector<vector<int> > counter(6,vector<int>(3));

void dfs(int u = 0, int p = -1,int depth = 0)
{
  for(auto v : adj[u])
  {
    if(v-p) dfs(v,u,depth+1);
  }
  for(int i=0;i<6;i++)
  {
    counter[i][(arr[i][depth%6])%3]++;
  }
}

void dfs2(int u = 0,int p = -1,int depth = 0,int k = 0)
{
  for(auto v : adj[u])
  {
    if(v-p) dfs2(v,u,depth+1,k);
  }
  
  ans[u] = arr[k][depth%6];
}

int main()
{
  __;
  arr[0] = {3,1,2,3,2,1};
  for(int i=1;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      arr[i][j] = arr[i-1][(j+1)%6];
    }
  }

  int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }
  // t(arr);
  dfs();
  vector<int> temp(3);
  for(int i=1;i<=n;i++)
  {
    temp[i%3]++;
  }

  int k = -1;
  for(int i=0;i<6;i++)
  {
    if(counter[i] == temp) 
    {
      k = i;
      break;
    }
  }

  if(k == -1) 
  {
    cout << -1 << endl;
    return 0;
  }

  dfs2(0,-1,0,k);
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for(int i=0;i<n;i++) 
  {
    if(ans[i] == 1)
    {
      cout << 3*cnt1+1 << " ";
      cnt1++;
    }
    else if(ans[i] == 2)
    {
      cout << 3*cnt2+2 << " ";
      cnt2++;
    }
    else
    {
      cout << 3*cnt3 + 3 << " ";
      cnt3++;
    }
    
    // cout << ans[i] << " "; cout << endl;
  }
  cout << endl;
  return 0;
}
