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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int k,n;
  cin >> k >> n;

  vector<vector< pair<bool,pair<ll,ll> >  > >v(n+1); // For each column
  vector<multiset<ll> > w(k);
  for(int i=0;i<k;i++) w[i].insert(0);

  vector<int> check(n+1);

  for(int h=0;h<k;h++)
  {
    // [i,i+k-n];
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
      int a;
      cin >> a;
      int left = i, right = i+n-m;
      v[left].pu(mp(1,mp(a,h)));
      v[right+1].pu(mp(0,mp(a,h)));

    }
    
    if(m!=n)  
    {
      int left = 0, right = n-1;
      int right1 = n-m-1, left2 = m+1;
      
      v[left].pu(mp(1,mp(0,h)));
      v[right+1].pu(mp(0,mp(0,h)));
      v[left2].pu(mp(1,mp(0,h)));
      v[right+1].pu(mp(0,mp(0,h)));
    }
  }

  // Insert 0s for places which can get 0s
  int temp = 0;
  for(int i=0;i<n;i++)
  {
    temp += check[i];
    if(temp > 0) w[i].insert(0);
  }

  ll sum1 = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<v[i].size();j++) // The ith column
    {
      pair<bool,pair<int,int> > p = v[i][j];
      // t(i,j,sum1,p.fi,p.se);
      if(p.fi)
      {
        ll old = *w[p.se.se].rbegin();
        w[p.se.se].insert(p.se.fi);
        ll max1 = *w[p.se.se].rbegin();
        sum1 -= old;
        sum1 += max1;
      }
      else
      {
        ll old = *w[p.se.se].rbegin();
        w[p.se.se].erase(w[p.se.se].find(p.se.fi));
        ll max1 = *w[p.se.se].rbegin();
        sum1 -= old;
        sum1 += max1;
      }
      // t(i,j,sum1,p.fi,p.se);
    }
    cout << sum1 << " ";
  }
  cout << endl;
  return 0;
}

/*
1 3
3 2 4 8
 
*/
