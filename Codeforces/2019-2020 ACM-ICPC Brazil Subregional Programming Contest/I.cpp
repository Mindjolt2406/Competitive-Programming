#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

void addNode(vector<vector<ll> > &mat, int node)
{
  for(int i=0;i<mat.size();i++)
  {
    for(int j=0;j<mat.size();j++)
    {
      mat[i][j] = min(mat[i][node] + mat[node][j],mat[i][j]);
    }
  }
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<pair<int,int> > temp(n);


  for(int i=0;i<n;i++) 
  {
    temp[i].se = i;
    cin >> temp[i].fi;
  }

  sort(temp.begin(),temp.end());

  vector<vector<ll> > mat1(n,vector<ll> (n,INF));
  vector<vector<ll> > mat2(n,vector<ll> (n,INF));
  vector<pair<ll, pair<int,int>  > > edges;
  map<pair<int,int> , ll> weight;

  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    ll c;
    cin >> c;
    edges.pu(mp(c,mp(a,b)));
    weight[mp(a,b)] = weight[mp(b,a)] = c;
  }

  sort(edges.begin(),edges.end());

  int q;
  cin >> q;
  map<int,vector<int> > i_q1;
  map<vector<int> , int> q_i1;

  map<int,vector<int> > i_q2;
  map<vector<int> , int> q_i2;

  for(int i=0;i<q;i++)
  {
    t(i);
    int a,b,k,c;
    cin >> a >> b >> k >> c;
    a--; b--;
    if(c == 0)
    {
      i_q1[i] = {k,a,b};
      q_i1[{k,a,b}] = i;
    }
    else
    {
      i_q2[i] = {k,a,b};
      q_i2[{k,a,b}] = i;
    }
  }

  vector<ll> ans(q);

  // Coldest temp

  int ptr = 0;
  set<int> nodes1,nodes2;

  for(auto it : q_i1)
  {
    vector<int> v = it.fi;
    int k = v[0],a = v[1], b = v[2];
    while(ptr < n && ptr <= k)
    { 
      int temp_node = temp[ptr].se;

      nodes1.insert(temp_node);
      for(auto it2 : nodes1)
      {
        mat1[temp_node][it2] = mat1[it2][temp_node] = weight[mp(temp_node,it2)];
      }
      addNode(mat1,temp_node);
      ptr++;
      t(mat1);
    }

    if(mat1[a][b] == INF) ans[it.se] = -1;
    else ans[it.se] = mat1[a][b];
  }

  // Hottest
  reverse(temp.begin(),temp.end());
  ptr = 0;

  for(auto it : q_i2)
  {
    vector<int> v = it.fi;
    int k = v[0],a = v[1], b = v[2];

    while(ptr < n && ptr <= k)
    { 
      int temp_node = temp[ptr].se;
      nodes2.insert(temp_node);
      for(auto it2 : nodes2)
      {
        if(weight.find(mp(temp_node,it2))!=weight.end()) mat2[temp_node][it2] = mat2[it2][temp_node] = weight[mp(temp_node,it2)];
      }
      addNode(mat2,temp_node);
      ptr++;
    }

    if(mat2[a][b] == INF) ans[it.se] = -1;
    else ans[it.se] = mat2[a][b];
  }
  
  for(int i=0;i<q;i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}

/*
7 9
-53 -180 456 420 -210 15 150
1 2 2
1 3 1
2 3 4
2 4 2
2 5 5
3 4 6
6 4 10
4 5 4
3 7 2
4 
1 5 2 1
1 2 1 1
5 6 1 0
1 7 2 1

*/