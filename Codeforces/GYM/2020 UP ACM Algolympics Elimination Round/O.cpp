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


int dx[3] = {0,0,1};
int dy[3] = {-1,1,0};

bool check(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return true;
}

void move(vector<string> &v,vector<vector<int> > &w, vector<vector<int> > &state,vector<vector<bool> > &stateful,pair<int,int> start,queue<pair<int,int> > &q,int k,int n,int m)
{
  // t(start,dx[k],dy[k]);
  vector<int> score(3);
  score = {1,2,4};
  int i = start.fi, j = start.se;
  while(check(i,j,n,m) && v[i][j] != '#')
  {
    t(i,j);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++) cout << state[i][j]%10 << " "; cout << endl;
    }
    state[i][j] |= score[k];
    if(state[i][j] == 7 && !stateful[i][j])
    {
      stateful[i][j] = true;
      if(mp(i,j) == mp(8,8)) 
      {
        t(w[i][j],start);
      }
      if(check(i-1,j,n,m))
      {
        if((v[i-1][j] == '.' && w[i-1][j] == -1)) 
        {
          q.push(mp(i-1,j));
          w[i-1][j] = w[start.fi][start.se]+1;
        }
        else if(v[i-1][j] != '#') 
        {
          if(check(i-1,j+1,n,m) && w[i-1][j+1] == -1 && v[i-1][j+1] == '.' && check(i,j+1,n,m) && v[i][j+1] == '#') 
          {
            q.push(mp(i-1,j+1));
            w[i-1][j+1] = w[start.fi][start.se]+1;
            // t(i-1,j+1,w[i-1][j+1]);
          }
          if(check(i-1,j-1,n,m) && w[i-1][j-1] == -1 && v[i-1][j-1] == '.' && check(i,j-1,n,m) && v[i][j-1] == '#') 
          {
            q.push(mp(i-1,j-1));
            w[i-1][j-1] = w[start.fi][start.se]+1;
            // t(i-1,j-1,w[i-1][j-1]);
          }

        }
      }
    }
    i -= dx[k];
    j -= dy[k];
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    queue<pair<int,int> > q;
    vector<vector<int> > w(n,vector<int>(m,-1)); // Time at which each state was taken
    vector<vector<int> > state(n,vector<int>(m)); // Is it surrounded by everyone?
    vector<vector<bool> > stateful(n,vector<bool>(m));
    // vector<vector<bool> > run(n,vector<bool> (m));

    for(int j=0;j<m;j++)
    {
      if(v[0][j] == 'W') 
      {
        q.push(mp(0,j));
        w[0][j] = 0;
      }
    }

    pair<int,int> breaker = mp(-1,-1);
    q.push(breaker);
    int timer = 0;

    while(!q.empty())
    {
      pair<int,int> p = q.front();
      q.pop();
      if(p == breaker)
      {
        timer++;
        if(q.empty()) break;
        q.push(breaker);
        continue;
      }

      int i = p.fi, j = p.se;
      v[i][j] = '0'+timer%10;
      // if(w[i][j] == -1)
      // {
      //   if(v[i][j] == '.') v[i][j] = '0'+timer%10;
      // }
      // else v[i][j] = '0' + w[i][j]%10;

      // Check for supports on 3 sides
      vector<int> score(3);
      score = {1,2,4};


      for(int k=0;k<3;k++)
      {
        int x = dx[k]+i;
        int y = dy[k]+j;
        if(check(x,y,n,m) && (v[x][y] == '#' || state[x][y] == 7))
        {
          move(v,w,state,stateful,mp(i,j),q,k,n,m);
        }
        else if(check(x,y,n,m) && w[x][y] == -1 && v[x][y] == '.' && k == 2)
        {
          w[x][y] = timer+1;
          q.push(mp(x,y));
        }
        else if(check(x,y,n,m) && w[x][y] == -1 && v[x][y] == '.' && k < 2)
        {
          if(check(i+1,j,n,m) && (state[i+1][j] == 7 || v[i+1][j] == '#')) 
          {
            w[x][y] = timer+1;
            q.push(mp(x,y));
          }
        }
      }

      if(check(i+1,j,n,m) && (state[i+1][j] == 7 || v[i+1][j] == '#'))
      {
        // t(i,j,w[i][j],w[i][j-1]);
        if(check(i,j-1,n,m) && w[i][j-1] == -1 && v[i][j-1] == '.') 
        {
          // _;
          q.push(mp(i,j-1));
          w[i][j-1] = timer+1;
          // t(w[i][j-1]);
        }
        if(check(i,j+1,n,m) && w[i][j+1] == -1 && v[i][j+1] == '.') 
        {
          q.push(mp(i,j+1));
          w[i][j+1] = timer+1;
        }
      }
    }


    int max1 = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) max1 = max(max1,w[i][j]);

    //cout << max1 << endl;
    //for(int i=0;i<n;i++)
    //{
    //  cout << v[i] << endl;
    //}

    cout << endl;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++) 
      {
        if(w[i][j] != -1)cout << w[i][j]%10 << " "; 
        else cout << "- ";
      }
      cout << endl;
    }
    
  }
  return 0;
}

/*
2
6 7
...W...
.......
..#.#..
..#.#..
..#.#..
..###..
6 9
....W....
.........
..#...#..
..#...#..
..#...#..
..#####..


1
6 9
....W....
.........
..#...#..
..#...#..
..#...#..
..#####..

1
6 7
...W...
.......
..#.#..
..#.#..
..#.#..
..###..


*/
