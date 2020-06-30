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

set<ll> counter;

void answer(string &s, string &t,int n,int m)
{
  // n is EW
  // t(s,t);
  string ans;
  for(int i=0;i<s.size();i++)
  {
    if(s[i] != '*')
    {
      if(n < 0) ans += (s[i] == '+') ? 'E' : 'W';
      else ans += (s[i] == '+') ? 'W' : 'E';
    }
    else
    {
      if(m < 0) ans += (t[i] == '+') ? 'N' : 'S';
      else ans += (t[i] == '+') ? 'S' : 'N';
    }
  }
  cout << ans << endl;
}

void solve()
{
  int n,m;
  cin >> n >> m;
  if((n&1) == (m&1)) cout << "IMPOSSIBLE" << endl;
  else
  {
    int a = n, b = m;
    n = abs(n), m = abs(m);
    string s,t;
    while(n || m)
    {
      // t(n,m);
      if(n == 0 && m == 1)
      {
        t += '-';
        s += '*';
        break;
      }
      else if(m == 0 && n == 1)
      {
        s += '-';
        t += '*';
        break;  
      }
      else
      {
        // Look at the second bit
        if(((n>>1)&1) == ((m>>1)&1))
        {
          // Push the bit forward
          if(n&1)
          {
            n++;
            s += '+';
            t += '*';
          }
          else
          {
            m++;
            t += '+';
            s += '*';
          }
        }
        else
        {
          // Remove the bit
          if(n&1)
          {
            s += '-';
            t += '*';
          }
          else
          {
            t += '-';
            s += '*';
          }
        }
      }
      n >>= 1;
      m >>= 1;
    }
    answer(s,t,a,b);
  }
}

int main()
{
  __;
  ll prod = 2;
  for(int i=0;i<50;i++)
  {
    counter.insert(prod-1);
    prod <<= 1;
  }
  // for(auto it : counter) t(it);
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  // solve();
  return 0;
}