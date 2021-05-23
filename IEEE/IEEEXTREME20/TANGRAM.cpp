#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "\n["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

bool check(int i, int j,int n)
{
  if(i < 0 || j < 0 || i >= n || j >= n) return false;
  return true;
}

int main()
{
  __;
  int t;
  cin >> t;

  string text;
  for(int i=0;i<26;i++) text += ('a' + i);
  for(int i=0;i<26;i++) text += ('A' + i);
  for(int i=0;i<9;i++) text += ('0' + i);
  // cout << text << endl;

  while(t--)
  {
    int n;
    cin >> n;
    if(n <= 3) 
    {
      cout << "impossible" << endl;
      continue;
    }

    vector<vector<char> > mat(n, vector<char>(n,'9'));

    int textChar = 0;
    for(int j=0;j<n;j++) mat[n-1][j] = text[textChar];
    textChar++;

    int lim = (((n/2) % 2) ? (n/2) : (n-1)/2);
    // if(n%4 == 3) lim = (n)/2;
    for(;textChar <= lim;textChar++)
    {
      int j = textChar-1;
      for(int i=j;i<n-1;i++)
      {
        mat[i][j] = text[textChar];
      }

      for(int i=0;i<=j;i++)
      {
        mat[i][j+1] = text[textChar];
      }
    }

    int state = 0;
    for(;textChar < n-1;textChar++)
    {
      int j = textChar-1;
      int curr = n-1-j;
      int next = j+1;

      if(!state) // Start at i=j and go down
      {
        for(int i=j;i<n-1;i++)
        {
          mat[i][j] = text[textChar];
        }

        int currIndex = n-2;
        while(next--)
        {
          mat[currIndex][j+1] = text[textChar];
          currIndex--;
        }
      }
      else
      {
        // Start at i=0 and go down curr places
        for(int i=0;i<curr;i++)
        {
          mat[i][j] = text[textChar];
        }

        for(int i=0;i<next;i++)
        {
          mat[i][j+1] = text[textChar];
        }
      }
      state ^= 1;
    }

    if(n%4 == 3)
    {
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(mat[i][j] == text[textChar-1]) mat[i][j] = '9';
        }
      }

      int temp = 3, next = n-3;
      int i = n-2;
      while(next--)
      {
        mat[i][n-2] = text[textChar-1];
        i--;
      }
      i = n-2;
      while(temp--)
      {
        mat[i][n-1] = text[textChar-1];
        i--;
      }
    }

    // vector<vector<int> > vis(n,vector<int>(n,-1));
    // pair<int,int> start = mp(0,0);
    // // 0 ->right
    // // 1 -> down
    // // 2 -> left
    // // 3 -> up

    // int dir = 0; 
    // int cnt = 1;
    // vis[0][0] = 0;
    // while(cnt < n*n)
    // {
    //   int i = start.fi, j = start.se;
    //   if(dir == 0 && check(i,j+1,n) && vis[i][j+1] == -1)
    //   {
    //     start = mp(i,j+1);
    //     vis[i][j+1] = cnt;
    //     cnt++;
    //   }
    //   else if(dir == 0) dir++;

    //   else if(dir == 1 && check(i+1,j,n) && vis[i+1][j] == -1)
    //   {
    //     start = mp(i+1,j);
    //     vis[i+1][j] = cnt;
    //     cnt++;
    //   }
    //   else if(dir == 1) dir++;


    //   else if(dir == 2 && check(i,j-1,n) && vis[i][j-1] == -1)
    //   {
    //     start =  mp(i,j-1);
    //     vis[i][j-1] = cnt;
    //     cnt++;
    //   }
    //   else if(dir == 2) dir++;

    //   else if(dir == 3 && check(i-1,j,n) && vis[i-1][j] == -1)
    //   {
    //     start = mp(i-1,j);
    //     vis[i-1][j] = cnt;
    //     cnt++;
    //   } 
    //   else dir++;

    //   dir %= 4;
    // }

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++) cout << mat[i][j];
      cout << endl;
    }
  }
  return 0;
}


// "

// bbcd999
// bccd999
// bcdde99
// bcdee99
// bcdee99
// bcdee99
// aaaaaaa


// "
