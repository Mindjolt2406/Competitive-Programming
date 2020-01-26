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
  vector<vector<int> > v2(n,vector<int>(m));
  vector<vector<int> > v(m,vector<int>(n));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> v2[i][j];
      v2[i][j]--;
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++) 
    {
      // t(i,j);
      v[j][i] = v2[i][j];
    }
  }

  ll cnt = 0;
  for(int j=0;j<m;j++)
  {
    vector<int> w = v[j];

    map<int,int> d;
    int temp_n = 0;
    for(int i=0;i<w.size();i++)
    {
      if(w[i]%m == j && w[i] < n*m)
      {
        int to_move = w[i]/m;
        int steps = 0;
        if(i >= to_move)
        {
          steps = i-to_move;
        }
        else
        {
          steps = i+n-to_move;
        }
        d[steps]++;
      }
    }

    int max1 = 0,min1 = 0;
    int min_final = INF;
    for(auto it : d) 
    {
      max1 =  it.se;
      min1 = it.fi;
      min_final = min(min_final,n-max1+min1);
      // if(it.se > max1)
      // {
      //   max1 =  it.se;
      //   min1 = it.fi;
      // }
      // else if(it.se == max1)
      // {
      //   min1 = min(min1,it.fi);
      // }
    }

    if(min_final != INF) cnt += min_final;
    // t(cnt);
  }

  cout << cnt << endl;
  return 0;
}
