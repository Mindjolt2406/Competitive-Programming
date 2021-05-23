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


int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<string> v(n);
  vector<pair<int,int> > orig(26,mp(-2,-2));

  for(int i=0;i<n;i++) cin >> v[i];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j] != '.') orig[v[i][j]-'A'] = mp(i,j);
    }
  }

  vector<int> up(27),down(27),left(27),right(27);
  for(int i=0;i<26;i++)
  {
    up[i] = down[i] = orig[i].fi;
    left[i] = right[i] = orig[i].se;
  }

  up[27] = left[27] = -1;
  down[27] = n;
  right[27] = m;

  queue<int> q;
  q.push(1);
  vector<bool> done(26);
  while(!q.empty())
  {
    int a = q.front();
    q.pop();

    // Construct up down left and right arrays
    vector<pair<int,int> > local_up, local_down, local_left,local_right; // Has coordinate and the corresponding letter
    for(int i=0;i<26;i++)
    {
      if(orig[i] != mp(-1,-1));
      for(int j=0;j<26;j++)
      {
        if(i==j) continue;
        if(up[j]+2 && up[j] < down[i]) local_down.pu(mp(up[j],j));
        if(down[j]+2 && down[j] > up[i]) local_up.pu(mp(down[j],j));
        if(left[j]+2 && left[j] > right[i]) local_right.pu(mp(left[j],j));
        if(right[j]+2 && right[j] < left[i]) local_left.pu(mp(right[j],j));
      }

      for(auto it1 : local_down)
      {
        for(auto it2 : local_up)
        {
          for(auto i3 : local_left)
          {
            for(auto i4 : local_right)
            {
              // Check if i1, i2, i3 and i4 can create a proper rectangle
              
            }
          }
        }
      }
    }

  }
  return 0;
}
