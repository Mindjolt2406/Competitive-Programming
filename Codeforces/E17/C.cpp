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
  string s,t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  
  vector<int> pref(m,INF),suf(m,-1);
  int left = 0,right = 0;
  while(left < n)
  {
    if(s[left] == t[right])
    {
      pref[right] = left;
      left++;
      right++;
    }
    else left++;
  }

  left = n-1, right = m-1;
  while(left >= 0)
  {
    if(s[left] == t[right])
    {
      suf[right] = left;
      left--;
      right--;
    }
    else left--;
  }

  ll min1 = INF, left_index = -1,right_index = -1;

  t(pref,suf);

  for(int i=0;i<n;i++)
  {
    int index = pref[i];
    if(index == INF) break; 
    int beg = i+1, end = m-1, ans = m;
    while(beg <= end)
    {
      int mid = (beg+end) >> 1;
      if(suf[mid] > index)
      {
        ans = mid;
        end = mid-1;
      }
      else beg = mid+1;
    }
    
    if(ans-index-1 < min1)
    {
      min1 = ans-i-1;
      left_index = i;
      right_index = ans;
    }
  }

  if(min1 == INF) cout << "-" << endl;
  else
  {
    for(int i=0;i<suf.size();i++) 
    {
      if(suf[i] != -1)
      {
        if(i < min1)
        {
          left_index = -1;
          right_index = i;
          break;
        }
      }
    }
    for(int i=0;i<=left_index;i++) cout << t[i];
    for(int i=right_index;i<m;i++) cout << t[i];
    cout << endl;
  }
  return 0;
}
