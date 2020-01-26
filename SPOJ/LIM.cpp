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

ld max(ld x, ld y)
{
  if(x>y) return x;
  return y;
}

int gauss(vector<vector<ld> > &v, vector<ld> &ans, int &rank)
{
  int n = v.size(), m = v[0].size()-1;
  rank = 0;
  int row = 0;
  vector<bool> check(m);

  for(int col = 0;row<n && col<m;col++)
  {
    // For each row check if v[i][i] = 0. If it is, swap with a non-zero element
    if(abs(v[row][col]) < EPS) 
    {
      // Curing cuarable breakdowns by taking the max pivot
      // This is called partial pivoting, it's a stable algorithm, i.e. the error doesn't blow up
      bool boo = false;
      ld max1 = v[row][col];
      int index = row;
      for(int i=row+1;i<n;i++)
      {
        if(abs(v[i][col]) > EPS)
        {
          max1 = max(max1,v[i][col]);
          if(max1 == v[i][col]) index = i;
        } 
      }

      // Case where it's a non-curable breakdown. Ignore and move on
      if(!boo) continue;
      swap(v[index],v[row]);
    }

    // This col is independent
    check[col] = true;
    ld pivot = v[row][col];
    for(int i=row+1;i<n;i++)
    {
      ld temp = v[i][col]/pivot;
      for(int j=0;j<=m;j++)
      {
        v[i][j] -= v[row][j]*temp;
      }
    }

    row++;
  }

  rank = row;
  // Back propagation
  for(int i=row-1;i>=0;i--)
  {
    ld sum1 = 0;
    for(int j=n-1;j>i;j--)
    {
      sum1 += ans[j]*v[i][j];
    }

    ld temp = v[i][m] - sum1;
    temp /= v[i][i];

    ans[i] = temp;
  }

  for(int i=0;i<m;i++) if(check[i]) rank++;
  // Checking whether we have no wrong solutions
  // If we do, there's no solution
  for(int i=n-1;i>=0;i--)
  {
    ld sum1 = 0;
    for(int j=m-1;j>=0;j--)
    {
      sum1 += ans[j]*v[i][j];
    }

    if((sum1 - v[i][m]) > EPS) return 0;
  }

  // If any of the columns have not been independent, then there are more variables than needed
  // Thus there are infinite number of solutions
  for(int i=0;i<m;i++) if(!check[i]) return INF;
  
  // Everything's okay. The answers have been stored in the ans array
  return 1;
}

int main()
{
  __;
  int n;
  cin >> n;
  while(n)
  {
    vector<vector<int> > adj(301);
    vector<vector<ld> > v(301,vector<ld>(302,0));
    vector<vector<ld> > prob(301,vector<ld>(301,0));

    for(int i=0;i<n;i++)
    {
      int a,b;
      cin >> a >> b;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    for(int i=0;i<301;i++)
    {
      ld tot = adj[i].size();

      for(auto j : adj[i])
      {
        prob[i][j] = 1/tot;
      }
    }

    for(int i=291;i<=300;i++)
    {
      for(int j=0;j<=300;j++) prob[i][j] = 0;
    }

    for(int i=0;i<301;i++)
    {
      for(int j=0;j<301;j++)
      {
        v[i][j] = -prob[j][i];
      }
    }

    for(int i=0;i<301;i++) v[i][i]++;
    v[0][301] = 1;

    // for(int i=0;i<301;i++)
    // {
    //   for(int j=0;j<302;j++) cout << v[i][j] << " ";
    //   cout << endl;
    // }

    vector<ld> ans(301);
    int rank = 0;
    gauss(v,ans,rank);

    // cout << endl;

    // for(int i=0;i<301;i++)
    // {
    //   for(int j=0;j<302;j++) cout << v[i][j] << " ";
    //   cout << endl;
    // }



    cout << fixed << setprecision(3);
    cout << abs(ans[300]) << endl;

    // t(ans);

    cin >> n;
  }
  return 0;
}

