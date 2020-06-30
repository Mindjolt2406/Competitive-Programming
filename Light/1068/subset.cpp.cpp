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

bool dp[10001][805];
vector<vector<pair<int,int> > > back(10001,vector<pair<int,int> > (805,mp(-1,-1)));

int getLSB(int mask)
{
  int cnt = 0;
  while((mask&1) == 0)
  {
    mask >>= 1;
    cnt++;
  }
  return cnt;
}

string getFlag(int mask, vector<int> &m)
{
  int cnt = 0;
  string s = "zenseCTF{";
  while(mask)
  {
    if(mask&1) s+= (char)m[cnt];
    mask >>= 1;
    cnt++;
  }
  s+= "}";
  return s;
}

int main()
{
  __;
  memset(dp,false,sizeof(dp));
  vector<int> v(10001);
  for(int i=1;i<=10000;i++) cin >> v[i];

  int cnt = 0;
  vector<int> m;
  for(int i=1;i<=10000;i++)
  {
    if(v[i] == '_' || (v[i] >= 'a' && v[i] <= 'z') || (v[i] >= '0' && v[i] <= '9')) m.pu(v[i]);
    else v[i] = 0;
  }

  t(m.size());

  vector<int> dp((1<<24));
  vector<int> ans;
  for(int i=1;i<(1<<24);i++)
  {
    int lsb = getLSB(i);
    dp[i] = dp[i^(1<<lsb)]+m[lsb];
    if(dp[i] == 804) ans.pu(i);
  }

  t(ans.size());
  set<string> s;
  for(auto it : ans)
  {
    s.insert(getFlag(it,m));
  }

  t(s.size());;
  for(auto it : s)
  {
    cout << it << endl;
  }

  // vector<int> m2 = m;
  // m.clear();
  // set<int> s;
  // for(auto it : m2)
  // {
  //   if(!s.count(it))
  //   {
  //     s.insert(it);
  //     m.pu(it);
  //   }
  // }
  // t(m);

  // for(int )
//   int n = 1e4+1;


//   for(int i=0;i<=m.size();i++) dp[i][0] = true;
//   int MAX = 804;

//   for(int j=1;j<=MAX;j++) dp[j][0] = false;

//   for(int i=1;i<=m.size();i++)
//   {
//     // t(i);
//     for(int j=MAX;j>=1;j--)
//     {
//       // t(i,j);
//       if(dp[i-1][j] != false)
//       {
//         dp[i][j] = true;
//         back[i][j] = mp(i-1,j);
//       }
//       else if(m[i]>j)
//       {
//         dp[i][j] = false;
//         back[i][j] = mp(-1,-1);
//       }
//       else
//       {
//         // _;
//         dp[i][j] = dp[i-1][j-m[i]];
//         back[i][j] = mp(i-1,j-m[i]);
//       }
//     }
//   }

//   pair<int,int> p = mp(m.size(),MAX);
//   vector<pair<pair<int,int> ,int> > ans;

//   while(p != mp(-1,-1))
//   {
//     int i = p.fi, j = p.se;
//     pair<int,int> temp = back[i][j];
//     if(j != temp.se)
//     {
//       ans.pu(mp(mp(m[i],j),i));
//     }
//     p = temp;
//   }

//   reverse(ans.begin(),ans.end());
//   t(ans);

//   for(int i=1;i<ans.size();i++)
//   {
//     cout << (char)ans[i].fi.fi;
//   }
//   cout << endl;
//   return 0;
}

/*
5m4lly_k3
m4ly3yyy

*/