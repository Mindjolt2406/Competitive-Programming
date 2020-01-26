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

int dp[10][10][10][10] = {0};
int dp2[10][10][201] = {0};

void comp()
{
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      for(int k=0;k<=200;k++) dp2[i][j][k] = INF;

      for(int k1=0;k1<=10;k1++)
      {
        for(int k2=0;k2<=10;k2++)
        {
          if(k1==0 && k2==0) continue;
          int a = k1*i + k2*j;
          dp2[i][j][a] = min(dp2[i][j][a],k1+k2);
        }
      }
    }
  }
}

int find(int a, int b,int dif)
{
  int min1 = INF;
  for(int i=dif;i<=100;i+=10)
  {
    int c = dp2[a][b][i];
    if(c == INF) continue;
    min1 = min(min1,c);
  }

  if(min1 == INF) return -1;
  return min1;
}

int main()
{
  __;
  comp();
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      for(int k1 = 0;k1<10;k1++)
      {
        for(int k2 = 0;k2<10;k2++)
        {
          dp[i][j][k1][k2] = -1;
          int a = k1, b = k2;
          int c = find(i,j,(b-a+10)%10);
          dp[i][j][k1][k2] = c;
          if(c!=-1) dp[i][j][k1][k2]--;
        }
      }
    }
  }

  string s;
  cin >> s;
  int n = s.size();
  int ans[10][10] = {0};

  for(int i=0;i<10;i++)
  {
    for(int j=i;j<10;j++)
    {
      int cnt = 0;
      for(int ind = 1;ind < n;ind++)
      {
        int b = s[ind]-'0',a =  s[ind-1]-'0';
        cnt += dp[i][j][a][b];
        if(dp[i][j][a][b] == -1) {cnt = -1; break;}
      }
      ans[i][j] = ans[j][i] = cnt;
    }
  }

  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++) 
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  // for(int i=0;i<10;i++)
  // {
  //   for(int j=0;j<10;j++) 
  //   {
  //     if(ans[i][j]!=-1) cout << ans[i][j] - (int)s.size() + 1  << " ";
  //     else cout << -1 << " ";
  //   }
  //   cout << endl;
  // }


  // for(int i=0;i<3;i++)
  // {
  //   for(int j=0;j<3;j++)
  //   {
  //     for(int k=0;k<30;k++) t(i,j,k,dp2[i][j][k]);
  //   }
  // }

  // for(int i=0;i<10;i++) for(int j=0;j<10;j++) t(i,j,dp[i][j][0][0],dp2[i][j][0]);
  return 0;
}


/*
-1 17 7 7 7 -1 2 17 2 7 
17 17 7 5 5 5 2 7 2 7 
7 7 7 4 3 7 1 7 2 5 
7 5 4 7 3 3 2 5 2 3 
7 5 3 3 7 7 1 7 2 7 
-1 5 7 3 7 -1 2 9 2 7 
2 2 1 2 1 2 2 2 0 1 
17 7 7 5 7 9 2 17 2 3 
2 2 2 2 2 2 0 2 2 2 
7 7 5 3 7 7 1 3 2 7 

-1 17 7 7 7 -1 2 17 2 7 
17 17 7 5 5 5 2 7 2 7 
7 7 7 4 3 7 1 7 2 5 
7 5 4 7 3 3 2 5 2 3 
7 5 3 3 7 7 1 7 2 7 
-1 5 7 3 7 -1 2 9 2 7 
2 2 1 2 1 2 2 2 0 1 
17 7 7 5 7 9 2 17 2 3 
2 2 2 2 2 2 0 2 2 2 
7 7 5 3 7 7 1 3 2 7 

 */
