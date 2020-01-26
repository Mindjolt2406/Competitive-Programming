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

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    string s;
    cin >> s;
    int n_orig = s.size();

    char check = s[0];
    bool same = true;
    for(int i=0;i<s.size();i++)
    {
      if(s[i] != check) 
      {
        same = false;
        break;
      }
    }

    if(same) 
    {
      cout << "Case " << h << ": " << s.size()-1 << endl;
      continue;
    }

    s = s+s+s;

    int n = s.size();
    int ans;

    // Check if all As or all Rs

    vector<int> left(n),right(n);
    char prev = '$';
    int a,r;

    for(int i=0;i<n;i++)
    {
      if(s[i] != prev)
      {
        prev = s[i];
        if(s[i] == 'A') a = i;
        else r = i;
      }

      if(s[i] == 'A')  left[i] = a;
      else left[i] = r;
    }

    prev = '$';
    for(int i=n-1;i>=0;i--)
    {
      if(s[i] != prev)
      {
        prev = s[i];
        if(s[i] == 'A') a = i;
        else r = i;
      }

      if(s[i] == 'A')  right[i] = a;
      else right[i] = r;
    }

    int max1 = -1;
    int index = -1;
    int cnt_max = 0;
    int max_left = -1, max_right = -1;
    set<int> set_max;
    for(int i=n_orig;i<2*n_orig;i++)
    {
      t(i,right[i]-left[i]+1,left[i],right[i]);
      set_max.insert(right[i]-left[i]+1);

      if(max1 < right[i]-left[i]+1)
      {
        max1 = right[i]-left[i]+1;
        index = i;
        cnt_max = 1;
        max_left = left[i];
        max_right = right[i];
      }
      else if(max1 == right[i]-left[i]+1 && max_left != left[i] && max_right != right[i])
      {
        cnt_max++;
      }
    }

    // t(cnt_max);
    if(cnt_max > 1)
    {
      ans = max1;
    }
    else
    {
      auto it = set_max.end();
      it--; it--;

      if(max1%2==1) ans = max(max1/2,*it);
      else ans = max(max1/2 + 1,*it);
    }

    cout << "Case " << h << ": " << ans << endl;
  }
  return 0;
}

