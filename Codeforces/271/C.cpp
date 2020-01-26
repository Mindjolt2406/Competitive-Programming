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
#define EPS 1e-3
// #define ll long long int
#define ld long double
#define fi first
#define se second
#define int long long int
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

int get_co(pair<int,int> p)
{
  if(p.fi < 0) 
  {
    if(p.se < 0) return 3;
    else return 2;
  }
  else
  {
    if(p.se < 0) return 4;
    else return 1;
  }
}

pair<int,int> rotate(pair<int,int> &a, pair<int,int> &b,int k)
{
  int ox = b.fi, oy = b.se;
  int nx = a.fi - ox, ny = a.se - oy;
  pair<int,int> p = mp(nx,ny);
  vector<pair<int,int> > v(4);
  v[0] = mp(abs(nx),abs(ny));
  v[1] = mp(-1*v[0].se, v[0].fi);
  v[2] = mp(-1*v[0].fi,-1*v[0].se);
  v[3] = mp(v[0].se,-1*v[0].fi);
  if(k==0) return a;
  else 
  {
    pair<int,int> temp = v[(get_co(p) - 1 + k)%4];
    temp.fi += ox;
    temp.se += oy;
    return temp;
  }
}

ld get_dist(pair<int,int> p, pair<int,int> q)
{
  return sqrt((ld)pow(p.fi-q.fi,2) + (ld)pow(p.se-q.se,2));
}

bool check_sq(vector<pair<int,int> > &v)
{
  for(int i=0;i<4;i++)
  {
    for(int j = i+1;j<4;j++)
    {
      if(v[i]==v[j]) return false;
    }
  }

  vector<ld> w;
  w.pu(get_dist(v[0],v[1]));
  w.pu(get_dist(v[0],v[2]));
  w.pu(get_dist(v[0],v[3]));

  sort(w.begin(),w.end());

  if(abs(w[0]-w[1]) < EPS)
  {
    if(abs(w[0]*sqrt(2) - w[2]) < EPS) 
    {
      return true;
    }
    return false;
  } 
  else return false;
}

int32_t main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    vector<pair<int,int> > v(4); //Actual
    vector<pair<int,int> > w(4); //Home

    for(int i=0;i<4;i++)
    {
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      v[i] = mp(a,b);
      w[i] = mp(c,d);
    }

    int min1 = INF;
    for(int i1 = 0;i1 < 4;i1++)
    {
      for(int i2 = 0;i2 < 4;i2++)
      {
        for(int i3 = 0;i3 < 4;i3++)
        {
          for(int i4 = 0;i4 < 4;i4++)
          {
            pair<int,int> p1,p2,p3,p4;
            p1 = rotate(v[0],w[0],i1);
            p2 = rotate(v[1],w[1],i2);
            p3 = rotate(v[2],w[2],i3);
            p4 = rotate(v[3],w[3],i4);

            vector<pair<int,int> > temp = {p1,p2,p3,p4};
            if(check_sq(temp)) min1 = min(min1,i1+i2+i3+i4);
          }
        }
      }
    }

    if(min1 == INF) {cout<<-1<<endl; continue;}
    else cout << min1 << endl;
  }

  return 0;
}

/*
1
2 2 0 1
-1 0 0 -2
3 0 0 -2
-1 1 -2 0

 */