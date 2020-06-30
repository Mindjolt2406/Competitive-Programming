#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 78294349
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

void right(vector<vector<pair<int,int > > >&v)
{
  int n = v.size(), m = v[0].size();
  vector<vector<pair<int,int> > > w(n,vector<pair<int,int> > (m,mp(-1,-1)));
  for(int i=0;i<n;i++)
  {
    int left = m-1, right = m-1;
    while(left >= 0 && right >= 0)
    {
      if(v[i][left] != mp(-1,-1))
      {
        w[i][right] = v[i][left];
        right--;
      }
      left--;
    }
  }

  v = w;
}

void left(vector<vector<pair<int,int > > >&v)
{
  int n = v.size(), m = v[0].size();
  vector<vector<pair<int,int> > > w(n,vector<pair<int,int> > (m,mp(-1,-1)));
  for(int i=0;i<n;i++)
  {
    int left = 0, right = 0;
    while(left <= m-1 && right <= m-1)
    {
      if(v[i][left] != mp(-1,-1))
      {
        w[i][right] = v[i][left];
        right++;
      }
      left++;
    }
  }

  v = w;
}

void down(vector<vector<pair<int,int > > >&v)
{
  int n = v.size(), m = v[0].size();
  vector<vector<pair<int,int> > > w(n,vector<pair<int,int> > (m,mp(-1,-1)));
  for(int j=0;j<m;j++)
  {
    int left = n-1, right = n-1;
    while(left >= 0 && right >= 0)
    {
      if(v[left][j] != mp(-1,-1))
      {
        w[right][j] = v[left][j];
        right--;
      }
      left--;
    }
  }

  v = w;
}

void up(vector<vector<pair<int,int > > >&v)
{
  int n = v.size(), m = v[0].size();
  vector<vector<pair<int,int> > > w(n,vector<pair<int,int> > (m,mp(-1,-1)));
  for(int j=0;j<m;j++)
  {
    int left = 0, right = 0;
    while(left < n && right < n)
    {
      if(v[left][j] != mp(-1,-1))
      {
        w[right][j] = v[left][j];
        right++;
      }
      left++;
    }
  }

  v = w;
}

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

long long mod_of_lcm(vector<long long> &a){
  int n = a.size();
	long long ans=1;
	for(long long i=0;i<n;i++){
 		if(a[i]!=1){
 			for(long long j=i+1;j<n;j++){
 				a[j]/=gcd(a[i],a[j]);
			}
			ans=(ans*a[i])%MOD;//mod
		}
	}
	return ans;}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<pair<int,int> > > w(n,vector<pair<int,int> > (m,mp(-1,-1)));
    vector<vector<bool> > vis(n,vector<bool>(m));
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(v[i][j] == '#') 
        {
          w[i][j] = mp(i,j);
        }
      }
    }


    // t(w);
    right(w);
    // t(w);
    up(w);
    // t(w);
    left(w);
    // t(w);
    down(w);
    // t(w);

    vector<ll> x;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(w[i][j] == mp(-1,-1)) continue;

        if(!vis[i][j]) vis[i][j] = true;
        else continue;

        pair<int,int> p = mp(i,j);
        pair<int,int> temp = w[i][j];
        int cnt = 0;
        while(true)
        {
          cnt++;
          if(temp == p) break;
          temp = w[temp.fi][temp.se]; 
        }
        x.pu(cnt);
      }
    }

    // t(x);
    cout << "Case " << h << ": " << mod_of_lcm(x) << endl;

  }
  return 0;
}


/*
3
2 2
..
#.
2 2
#.
#.
18 13 
............. 
##........... 
##........... 
####......... 
####......... 
#####........ 
#####........ 
#######...... 
#######...... 
#########.... 
#########.... 
##########... 
###########.. 
###########.. 
###########.. 
############. 
############# 
#############

*/