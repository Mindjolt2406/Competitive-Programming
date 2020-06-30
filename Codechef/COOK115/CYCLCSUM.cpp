#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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
  if(x > y) return x;
  return y;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<ll> v(2*n);
    vector<int> back(2*n);
    vector<ll> dp(2*n);
    multiset<ll> s;
    for(int i=0;i<n;i++) 
    {
      cin >> v[i];
      v[i+n] = v[i]; 
    }
    dp[0] = v[0];
    s.insert(dp[0]);
    for(int i=1;i<n;i++)
    {
      dp[i] = max(v[i],dp[i-1]+v[i]);
      if(dp[i] == v[i]) back[i] = i;
      else back[i] = back[i-1];
      s.insert(dp[i]);
    }

    cout << *s.rbegin() << " ";
       
    ll remover = 0;
    int remove_index = -1;
    multiset<ll> s_remove;
    for(int i=n;i<2*n-1;i++)
    {
      // i-n is being removed
      if(back[i-n] == i-n)
      {
        s.erase(s.find(dp[i-n]));
        remover = -v[i-n];
        remove_index = i-n;
        for(int j=i-n+1;j<i;j++)
        {
          if(back[j] == remove_index)
          {
            s.erase(s.find(dp[j]));
            s_remove.insert(dp[j]);
          }
        }
      }
      else
      {
        remover -= v[i-n];
        s_remove.erase(s_remove.find(dp[i-n]));
      }

      // i is being added
      if(back[i-1] == remove_index) dp[i] = max(v[i],dp[i-1]+remover+v[i]);
      else dp[i] = max(v[i],dp[i-1]+v[i]);

      if(dp[i] == v[i]) back[i] = i;
      else back[i] = back[i-1];

      if(back[i] == remove_index)
      {
        s_remove.insert(dp[i]);
      }
      else s.insert(dp[i]);

      ll max1 = -INF;
      if(!s_remove.empty()) max1 = max(max1,*s.rbegin() + remover);
      if(!s.empty()) max1 = max(max1,*s.rbegin());

      cout << max1 << " ";
    }
    cout << endl;
  }
  return 0;
}
