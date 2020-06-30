#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
// #define MOD 1000000007
#define EPS 1e-6
#define ll long long 
#define int long long int
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

int dp[10][350][350];

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

int getAns(int pos, bool tight, int divMOD,int digMOD,vector<int> &digit,int MOD)
{
  if(pos == -1 && divMOD == 0 && digMOD == 0) return 1;
  if(pos == -1) return 0;

  if(dp[pos][divMOD][digMOD] != -1 && !tight) return dp[pos][divMOD][digMOD];


  int maxVal = (tight) ? digit[pos] : 9;
  // t(pos,maxVal,divMOD,digMOD);

  int sum1 = 0;

  for(int i=0;i<=maxVal;i++)
  {
    bool newTight = (digit[pos] == i) ? tight : 0;
    int newMOD = (power(10,pos,MOD)*i) % MOD;
    int tempDivMOD = (divMOD - newMOD + MOD) % MOD;
    int tempDigMOD = (digMOD - (i%MOD) + MOD) % MOD;
    sum1 += getAns(pos-1,newTight,tempDivMOD,tempDigMOD,digit,MOD);
  }

  if(!tight) dp[pos][divMOD][digMOD] = sum1;

  // t(pos,maxVal,divMOD,digMOD,sum1);
  return sum1;
}

void makeDigit(int n,vector<int> &v)
{
  while(n)
  {
    v.pu(n%10);
    n /= 10;
  }
}



void solve(int a, int b,int k)
{
  if(k > 100)
  {
    cout << 0 << endl;
    return;
  }

  vector<int> digitRight,digitLeft;
  makeDigit(b,digitRight);
  makeDigit(a-1,digitLeft);

  memset(dp,-1,sizeof(dp));
  int rightAns = getAns(digitRight.size()-1,true,0,0,digitRight,k);
  int leftAns = getAns(digitLeft.size()-1,true,0,0,digitLeft,k);

  // t(rightAns,leftAns);
  cout << rightAns - leftAns << endl;

}

int32_t main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    int a,b,k;
    cin >> a >> b >> k;
    cout << "Case " << h << ": ";
    solve(a,b,k);
  }
  return 0;
}

/*
3
1 20 1
1 20 2
1 1000 4

1
1 20 2

*/