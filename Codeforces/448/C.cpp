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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

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

int gauss(vector<vector<ll> > &v,int k)
{
  int n = v.size(), m = v[0].size()-1;
  int row = 0;

  for(int col = 0;row<n && col<m;col++)
  {
    // For each row check if v[i][i] = 0. If it is, swap with a non-zero element

    // Curing cuarable breakdowns by taking the max pivot
    // This is called partial pivoting, it's a stable algorithm, i.e. the error doesn't blow up
    bool boo = false;
    ll max1 = v[row][col];
    int index = row;
    for(int i=row;i<n;i++)
    {
      if(v[i][col])
      {
        boo = true;
        max1 = max(max1,v[i][col]);
        if(max1 == v[i][col]) index = i;
      } 
    }

    // Case where it's a non-curable breakdown. Ignore and move on
    if(!boo) continue;

    // Otherwise swap and go ahead
    swap(v[index],v[row]);

    // The variable assosciated with this pivot is a pivoted one, and thus it counts in the rank
    ll pivot = v[row][col];
    for(int i=row+1;i<n;i++)
    {
      // ld temp = v[i][col]/pivot;
      ll temp = ( v[i][col] * power(pivot,k-2,k) ) % k;
      for(int j=0;j<=m;j++)
      {
        v[i][j] = (v[i][j] - (v[row][j]*temp) % k + k) % k;
      }
    }

    row++;
  }

  return row;
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
  // Check1 checks whether a prime existed before doing the operations
  // Check2 tells what columns are pivoted

  vector<vector<ll> > w(n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<19;j++)
    {
      int cnt = 0;
      while(v[i]%prime[j] == 0) {cnt++; v[i]/=prime[j];}
      w[i].pu(cnt%2);
    }
  }

  for(int i=0;i<n;i++) w[i].pu(0);

  int rank = gauss(w,2);

  // t(rank);
  cout << (power(2,n-rank,MOD) - 1 + MOD)%MOD << endl;
  return 0;
}

