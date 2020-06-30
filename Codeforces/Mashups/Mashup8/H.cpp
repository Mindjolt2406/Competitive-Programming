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

void makeDigit(int n,vector<int> &v,int base)
{
  while(n)
  {
    v.pu(n%(base));
    n /= base;
  }
}

ll dp[10][20][1024];

ll solve(int pos, bool tight, int base, ll mask,bool leading, vector<int> &digit)
{
  if(pos == -1 && leading && mask == 0) return 0;
  if(pos == -1 && mask == 0) return 1;
  if(pos == -1) return 0;

  if(!tight && dp[base][pos][mask] != -1) return dp[base][pos][mask];

  int maxVal = (tight) ? digit[pos] : base-1;

  ll sum1 = 0;
  for(int i=0;i<=maxVal;i++)
  {
    bool newTight = (digit[pos] == i) ? tight : false;
    
    ll newMask = (leading && i==0) ? mask : mask ^ (1 << i);
    bool newLeading = (leading && i==0);
    sum1 += solve(pos-1,newTight,base,newMask,newLeading,digit);
  }

  if(!tight) dp[base][pos][mask] = sum1;

  return sum1;
}

int main()
{
  __;
  memset(dp,-1,sizeof(dp));

  int t;
  cin >> t;
  while(t--)
  {
    ll b,x,y;
    cin >> b >> x >> y;

    vector<int> rightDigit, leftDigit;
    makeDigit(y,rightDigit,b);
    makeDigit(x-1,leftDigit,b);

    ll rightAns = solve(rightDigit.size()-1,true,b,0,true,rightDigit);
    cout << endl;
    ll leftAns = solve(leftDigit.size()-1,true,b,0,true,leftDigit);

    t(rightAns,leftAns);
    cout << rightAns  - leftAns << endl;

    for(int i=0;i<=4;i++)
    {
      for(int j=0;j<=3;j++)
      {
        t(i,j,dp[2][i][j]);
      }
    }
  }
  return 0;
}
