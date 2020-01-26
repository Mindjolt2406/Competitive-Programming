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

ld area(pair<ld,ld> p1, pair<ld,ld> p2, pair<ld,ld> p3)
{
  ld x1 = p1.fi, y1 = p1.se;
  ld x2 = p2.fi, y2 = p2.se;
  ld x3 = p3.fi, y3 = p3.se;

  return abs(((x2*y3 - y2*x3) - (x1*y3 - y1*x3) + (x1*y2 - x2*y1)) / 2);
}

ld dist(pair<ld,ld> p1, pair<ld,ld> p2)
{
  return sqrt(abs((p1.fi - p2.fi)*(p1.fi - p2.fi) + (p1.se - p2.se)*(p1.se - p2.se)));
}

ld min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

ld max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

pair<ld,ld> nearest(pair<ld,ld> p, vector<pair<ld,ld> > &v)
{
  ld ans = 1e18;
  pair<ld,ld> ansp = mp(-1,-1);
  for(int i=0;i<v.size();i++)
  {
    ld temp = dist(p,v[i]);
    if(temp < ans)
    {
      ans = temp;
      ansp = v[i];
    }
  }

  return ansp;
} 

int main()
{
  __;
  pair<ld,ld> A,B,C;
  
  
  cin >> A.fi >> A.se;
  cin >> B.fi >> B.se;
  cin >> C.fi >> C.se;

  int n_ab,n_bc,n_ca;
  cin >> n_ab;
  vector<pair<ld,ld> > v_ab(n_ab);
  vector<pair<ld,ld> > all;

  ld dist_ab = dist(A,B);
  ld dist_bc = dist(B,C);
  ld dist_ca = dist(C,A);
  // t(dist_bc,dist_ca);

  for(int i=0;i<n_ab;i++) 
  {
    ld distance;
    cin >> distance;

    ld x = (B.fi * distance + A.fi*(dist_ab - distance)) / dist_ab;
    ld y = (B.se * distance + A.se*(dist_ab - distance)) / dist_ab;

    v_ab[i] = mp(x,y);
    all.pu(mp(x,y));
  }

  cin >> n_bc;
  vector<pair<ld,ld> > v_bc(n_bc);
  for(int i=0;i<n_bc;i++) 
  {
    ld distance;
    cin >> distance;

    ld x = (C.fi * distance + B.fi*(dist_bc - distance)) / dist_bc;
    ld y = (C.se * distance + B.se*(dist_bc - distance)) / dist_bc;

    v_bc[i] = mp(x,y);
    all.pu(mp(x,y));
  }

  cin >> n_ca;
  vector<pair<ld,ld> > v_ca(n_ca);
  for(int i=0;i<n_ca;i++)
  {
    ld distance;
    cin >> distance;

    ld x = (A.fi * distance + C.fi*(dist_ca - distance)) / dist_ca;
    ld y = (A.se * distance + C.se*(dist_ca - distance)) / dist_ca;

    v_ca[i] = mp(x,y);
    all.pu(mp(x,y));
  }

  // t(v_ab);
  // t(v_bc);
  // t(v_ca);

  vector<pair<ld,ld> > near;

  near.pu(nearest(A,v_ab));
  near.pu(nearest(A,v_ca));

  near.pu(nearest(B,v_bc));
  near.pu(nearest(B,v_ab));

  near.pu(nearest(C,v_ca));
  near.pu(nearest(C,v_bc));


  ld max1 = -1;
  vector<pair<ld,ld> > w;

  for(int i=0;i<near.size();i++)
  {
    for(int j=0;j<near.size();j++)
    {
      for(int k=0;k<all.size();k++)
      {
        ld ar = area(near[i],near[j],all[k]);
        if(ar > max1)
        {
          max1 = ar;
          w = {near[i],near[j],all[k]};
        }
        // max1 = max(max1,ar);
      }
    }
  }

  cout << fixed << setprecision(12);
  cout << max1 << endl;
  // t(w);

  return 0;
}

/*
0 0
2 0
0 2
1
1
5
0.1 0.2 1.414 1.8 1.9
1
1

*/