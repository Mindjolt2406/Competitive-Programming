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
  int n;
  cin >> n;
  vector<int> v(n);

  for(int i=0;i<n;i++) cin >> v[i];

  set<int> s,s_odd,s_even;
  for(int i=1;i<=n;i++) s.insert(i);

  for(int i=0;i<n;i++) if(v[i]) s.erase(v[i]);

  int even = 0, odd = 0;
  for(auto it : s) 
  {
    if(it&1) 
    {
      odd++;
      s_odd.insert(it);
    }
    else 
    {
      s_even.insert(it);
      even++;
    }
  }

  for(int i=0;i<n;i++)
  {
    if(v[i]) continue;
    bool par_odd = false, par_even = false;
    if(i>0 && v[i-1]) 
    {
      if(v[i-1]&1) par_odd = true;
      else par_even = true;
    }
    if(i<n-1 && v[i+1])
    {
      if(v[i+1]&1) par_odd = true;
      else par_even = true;
    }

    if(par_odd && par_even)
    {
      continue;
    }
    else if(par_odd)
    {
      if(odd)
      {
        odd--;
        v[i] = *s_odd.begin();
        s_odd.erase(v[i]);
      }
      else
      {
        even--;
        v[i] = *s_even.begin();
        s_even.erase(v[i]);
      }
    }
    else if(par_even)
    {
      if(even)
      {
        even--;
        v[i] = *s_even.begin();
        s_even.erase(v[i]);
      }
      else
      {
        odd--;
        v[i] = *s_odd.begin();
        s_odd.erase(v[i]);
      }
    }
  } 

  vector<int> w = v;
  set<int> w_even = s_even, w_odd = s_odd;

  for(int i=0;i<n;i++)
  {
    if(!v[i])
    {
      if(odd)
      {
        odd--;
        v[i] = *s_odd.begin();
        s_odd.erase(v[i]);
      }
      else
      {
        even--;
        v[i] = *s_even.begin();
        s_even.erase(v[i]);
      }
    }

    if(!w[i])
    {
      if(even)
      {
        even--;
        w[i] = *w_even.begin();
        w_even.erase(w[i]);
      }
      else
      {
        odd--;
        w[i] = *w_odd.begin();
        w_odd.erase(w[i]);
      }
    }
  }

  int cnt1 = 0,cnt2 = 0;
  for(int i=0;i<n-1;i++) if((v[i]&1) != (v[i+1]&1)) cnt1++;
  for(int i=0;i<n-1;i++) if((w[i]&1) != (w[i+1]&1)) cnt2++;

  cout << min(cnt1,cnt2) << endl;
  return 0;
}
