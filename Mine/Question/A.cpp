/*
Name: Game on Tree
Author: Rathin Bhargava

Alice and Bob love playing games. Today, they invented a new one.  They took a rooted tree rooted at $1$. The took $K$ tokens and spread them across the tree at nodes $v_i$, $1 \leq i \leq k$. Both the players play the game in turns. Alice starts playing first. 
On each move, a player can take a token and move it to one of it's children. A player loses if they don't have any moves to play. Who wins the game? 

The input format 
The first line are two space separated integers N, K. 
The $i^{th}$ of the next $N-1$ lines comprise of two space separated integers $a_i$, $b_i$ giving the edges of the tree.
Finally, Tte last line has K space separated integers $v_j$, giving the nodes with the tokens. Note that a node may have more than one token. 

Output 
If Alice wins, output "Alice" (without quotes)
If Bob wins, output "Bob" (without quotes)

Constraints 
$ 1 \leq K \leq N \leq 10^5 $
$ 1 \leq a_i, b_i \leq N $
$ 1 \leq v_j \leq K$
*/
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 1e5+10;
vector<vector<int > > adj(N);
vector<int> mex(N);

int getMex(vector<int> &v)
{
  set<int> s;
  for(auto it : v) s.insert(it);
  for(int i=0;i<=v.size();i++) if(!s.count(i)) return i;
  return 0;
}

void dfs(int u = 0, int p = -1)
{
  vector<int> temp;
  bool isLeaf = true;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs(v,u);
      temp.pu(mex[v]);
      isLeaf = false;
    }
  }

  if(isLeaf) mex[u] = 0;
  else mex[u] = getMex(temp);
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs();

  int x = 0;
  for(int i=0;i<k;i++)
  {
    int a;
    cin >> a;
    a--;
    x ^= mex[a];
  }

  cout << ((x == 0) ? "Bob" : "Alice") << endl;

  return 0;
}

/*
3 1 
1 2 
1 3 
1 

3 2 
1 2 
1 3 
1 1 


*/