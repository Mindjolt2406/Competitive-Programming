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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 5000;
int p[N] = {0}, sz[N] = {0};

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) create(i);
    // set<int> sep;

    while(m--)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;

      int len = b-a+1;
      for(int i=0;i<(len+1)/2;i++)
      {
        // t(a+i,b-i);
        merge(a+i,b-i);
      }
    }

    map<int,int> d;

    for(int i=0;i<n;i++)
    {
      d[find(i)] = sz[i];
    }

    // for(auto it : d) t(it);


    // DP

    vector<vector<int> > dp(n,vector<int>(n));
    vector<vector<int> > keep(n,vector<int>(n));
    vector<vector<pair<int,int> > > back(n,vector<pair<int,int> >(n,mp(-1,-1)));

    vector<pair<int,int>  > w;
    for(auto it : d)
    {
      w.pu(mp(it.se,it.fi));
    }

    int cnt1 = 0,cnt0 = 0;
    string s = "";
    for(int i=0;i<n;i++) s+='-';


    dp[0][w[0].fi] = w[0].fi;
    keep[0][w[0].fi] = 1;

    for(int i=1;i<min(n,n);i++)
    {
      for(int j=0;j<n;j++)
      {
        if(j>=w[i].fi && i<(int)w.size())
        { 
          if(dp[i-1][j] > dp[i-1][j-w[i].fi]) 
          {
            back[i][j] = mp(i-1,j);
            dp[i][j] = dp[i-1][j];
            keep[i][j] = 0;
          }
          else
          {
            back[i][j] = mp(i-1,j-w[i].fi);
            dp[i][j] = dp[i-1][j-w[i].fi] + w[i].fi;
            keep[i][j] = 1;
          }
        }
        else 
        {
          dp[i][j] = dp[i-1][j];
          back[i][j] = mp(i-1,j);
          keep[i][j] = 0;
        }
      }
    }

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }
    set<int> x;

    int index = 0;

    for(int i=n/2;i>=0;i--)
    {
      if(dp[((int)w.size())-1][i]!=0)
      {
        index = i;
        break;
      }
    }
    
    t(index);
    {
      pair<int,int> p = mp(n-1,index);
      if(keep[p.fi][p.se]) x.insert(w[index].se);
      while(p!=mp(-1,-1))
      {
        t(p,keep[p.fi][p.se],w[p.fi].se);
        p = back[p.fi][p.se];
        if(p==mp(-1,-1)) break;
        if(keep[p.fi][p.se]) x.insert(w[p.fi].se);
        // t(p);
      }
    }

    // _;
    for(auto it: x) t(it);
    for(int i=0;i<n;i++)
    {
      if(x.find(find(i)) != x.end()) {s[i] = '1';cnt1++;}
      else {s[i] = '0';cnt0++;}
    }

    cout<<"Case #"<<h<<": "<<s<<endl;
    memset(p,0,sizeof(p));
    memset(sz,0,sizeof(sz));
  }
  return 0;
}

/*
1
4 2
1 2
2 4

 */