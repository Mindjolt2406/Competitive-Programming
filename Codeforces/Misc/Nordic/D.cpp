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

const int N = (1<<20) + 100;
// vector<int> adj[N];
vector<int> dist(N);
vector<int> vis(N);

int main()
{
  __;
  int n,k;
  cin >> n >> k;


  queue<int> q;
  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    int cnt = 0;
    int prod = 1;
    reverse(s.begin(),s.end());
    for(int j=0;j<s.size();j++) 
    {
      if(s[j]-'0') cnt += prod;
      prod <<= 1;
    }

    q.push(cnt);
    vis[cnt] = 1;
  }

  int cnt = 0;
  q.push(-1);
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u==-1 && !q.empty()) {cnt++;q.push(-1);continue;}
    else if(u==-1) break;

    dist[u] = cnt;
    // t(u,dist[u]);
    for(int j=0;j<k;j++)
    {
      // Change the jth bit
      int v = (1<<j)^u;
      if(!vis[v]) {q.push(v);vis[v] = 1;}
    }
  }
  int max1 = -1, max2 = -1;
  for(int i=0;i<(1<<k);i++)
  {
    if(dist[i]>max1)
    {
      max1 = dist[i];
      max2 = i;
    }
  }

  string s = "";
  for(int i=0;i<k;i++)
  {
    if((max2/(1<<i))&1) s+='1';
    else s+='0';
  }
  // t(max2);
  reverse(s.begin(),s.end());
  cout << s << endl;
  return 0;
}

