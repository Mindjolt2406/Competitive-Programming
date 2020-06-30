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


int get(int i1,int i2,int j1,int j2,vector<vector<int> > &pref)
{
  int x = pref[i2][j2];
  if(i1 > 0) x -= pref[i1-1][j2];
  if(j1 > 0) x -= pref[i2][j1-1];
  if(i1 > 0 && j1 > 0) x += pref[i1-1][j1-1];
  return x;
}

int main()
{
  __;
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int> > v(n,vector<int> (m));
  vector<vector<int> > pref(n,vector<int> (m));
  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++) v[i][j] = s[j] - '0';
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      pref[i][j] += v[i][j];
      if(i>0) pref[i][j] += pref[i-1][j];
      if(j>0) pref[i][j] += pref[i][j-1];

      if(i>0 && j>0) pref[i][j] -= pref[i-1][j-1];
    }
  }

  // t(pref);
  // _;
  int min1 = INF;
  for(int i=0;i<pow(2,n-1);i++)
  {
    // line is before index
    // t(i);
    vector<int> w;
    w.pu(0);
    int temp = i;
    int index = 1;
    while(temp)
    {
      if(temp&1) w.pu(index);
      temp >>= 1;
      index++;
    }
    w.pu(n);
    // t(w);
    int prev = 0;
    bool boo = true;
    int cnt = 0;
    for(int j=0;j<m;j++) 
    {
      for(int y = 0;y<w.size()-1;y++)
      {
        int y1 = w[y], y2 = w[y+1]-1;
        int x1 = prev, x2 = j;
        swap(x1,y1);
        swap(x2,y2);
        // t(x1,x2,y1,y2);
        int getter = get(x1,x2,y1,y2,pref);
        // t(j,getter,k);
        // if(w.size() == 3 && w[1] == 2) 
        // {
        //   t(y,w);
        //   t(x1,x2,y1,y2,getter);
        // }
        if( getter > k)
        {
          if(prev == j) 
          {
            boo = false;
            break;
          }
          prev = j;
          cnt++;
          getter = get(x1,x2,j,j,pref);

          if( getter > k) boo = false;
        }
      }
      if(!boo) break;
    }
    // t(i,boo);
    if(boo) min1 = min(min1,(int)w.size()-2+cnt);
    // t(min1);
  }

  if(min1 == INF) cout << 0 << endl;
  else cout << min1 << endl;
  return 0;
}
