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

ll max(ll x, ll y) {return x>y?x:y;}

void solve()
{
  ll n,m,q,k;
  cin >> n >> m >> q >> k;
  vector<ll> e(n),w(n),x(n),y(n);

  for(int i=0;i<k;i++) cin >> w[i];

  for(int i=0;i<k;i++) cin >> x[i];
  ll ax,bx,cx;
  cin >> ax >> bx >> cx;
  for(int i=k;i<n;i++) x[i] = ((((ax*x[i-2]) % m) + ((bx*x[i-1]) % m) + cx) % m);

  for(int i=0;i<k;i++) cin >> y[i];
  ll ay,by,cy;
  cin >> ay >> by >> cy;
  for(int i=k;i<n;i++) y[i] = ((ay*y[i-2] % m) + (by*y[i-1]) % m + cy) % m + x[i];

  for(int i=0;i<k;i++) cin >> e[i];
  ll ae,be,ce;
  cin >> ae >> be >> ce;
  for(int i=k;i<q;i++) e[i] = ((((ae*e[i-2]) % (n*m+n)) + ((be*e[i-1]) % (n*m+n)) + ce) % (n*m+n));

  for(int i=0;i<k;i++) cin >> w[i];
  ll aw,bw,cw;
  cin >> aw >> bw >> cw;
  for(int i=k;i<q;i++) w[i] = ((((aw*w[i-2]) % (INF-1)) + ((bw*w[i-1]) % (INF-1)) + cw) % (INF-1));

  vector<vector<multiset<ll> > > v(n,vector<multiset<ll> > (2));
  set<ll> outside,circle; 
  vector<int> which(n);
  vector<ll> weights(n*m+n,1);
  int maxIndex = n*m;

  ll prod = 1;
  ll currSum = (n-1) + n*(m-1);

  for(int i=0;i<n;i++)
  {
    int beg = m*i, end = m*i + (m-1);
    int low = x[i], high = y[i];
    for(int i=low;i<high;i++) v[i][0].insert(1);
    for(int i=beg;i<low;i++) v[i][1].insert(1);
    for(int i=high;i<=end;i++) v[i][1].insert(1);
  }

  for(int i=n*m;i<n*m+n;i++) outside.insert(1);

  for(int i=0;i<n;i++)
  {
    ll temp0 = (v[i][0].empty()) ? -1 : *v[i][0].rbegin();
    ll temp1 = (v[i][1].empty()) ? -1 : *v[i][1].rbegin();

    if(temp0 > temp1) 
    {
      which[i] = 1;
      if(temp1 != -1) circle.insert(temp1);

    }
    else
    {
      which[i] = 0;
      if(temp0 != -1) circle.insert(temp0);
    }
  }

  for(int i=0;i<q;i++)
  {
    int edge = e[i];
    int weight = w[i];

    if(edge >= n*m) // Outside edge
    {
      outside.erase(outside.find(weights[edge]));
      outside.insert(weight);
      if(weights[maxIndex] < weight)
      {
        currSum += weights[maxIndex];
        currSum -= weight;
        maxIndex = edge;
      }
    }
    else
    {
      int origIndex = edge/m;
      int tempPar = 1;
      if(x[origIndex] <= edge && edge < y[origIndex])
      {
        tempPar = 0;
      }

      if(tempPar == which[origIndex])
      {
        if(!v[origIndex][tempPar^1].empty())
        {
          if(weight > *v[origIndex][tempPar^1].rbegin())
          {
            which[origIndex] ^= 1;
            v[origIndex][tempPar].erase(v[origIndex][tempPar].find(weights[edge]));
            v[origIndex][tempPar].insert(weight);


            ll oldMax = *v[origIndex][tempPar^1].rbegin();
            currSum += oldMax;
            currSum -= weight;

            if(oldMax) // ARGHHHHHHHH I need to store indices also . SO fucking close


            circle.erase(circle.find(oldMax));
            
            circle.insert(*v[origIndex][tempPar^1].rbegin());
          }
        }
        else
        {
          if(weight > weights[maxIndex])
          {
            maxIndex = edge;
            currSum += weights[maxIndex];
            currSum -= weight;
          }
          circle.erase(circle.find(weights[edge]));
          circle.insert(weight);
        }
      }
      else
      {
        if(weight > *v[origIndex][tempPar].rbegin())
        {
          currSum -= *v[origIndex][tempPar].rbegin();
          currSum += weight;
        }
        v[origIndex][tempPar].erase(v[origIndex][tempPar].find(weights[edge]));
        v[origIndex][tempPar].insert(weight);
      }
    }

    weights[edge] = weight;
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}
