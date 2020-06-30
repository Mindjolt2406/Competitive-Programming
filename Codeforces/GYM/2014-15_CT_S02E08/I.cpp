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

pair<int,int> getter(int n, int x)
{
  int y = n-x;
  int temp_y = y, temp_x = x;
  while(y >= x && x > 0)
  {
    temp_y = y, temp_x = x;
    pair<int,int> p = mp(x,y-x);
    y = p.fi, x = p.se;
  }

  if(temp_y < temp_x) return mp(temp_x,temp_y);
  return mp(temp_y,temp_x);
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
    int orig_beg = (n%3 == 0) ? n/3 : n/3 + 1;
    int orig_end = (n%2 == 0) ? n/2 : n/2 - 1;
    int beg = 1, end = n-1;
    // int orig_beg = beg, orig_end = end;
    pair<int,int> ans = mp(n-1,1);
    // t(beg,end);
    // while(beg <= end)
    while(end-beg > 5)
    {
      int mid = (beg + end) >> 1;
      // t(beg,end,mid);
      if(n-mid < mid)
      {
        end = mid-1;
        continue;
      }
      pair<int,int> p1,p2,p3;
      p1 = getter(n,mid-1);
      p3 = getter(n,mid+1);

      // if(mid < orig_beg || mid > orig_end)
      // {
      //   p2 = mp(n-mid,mid);
      // }
      // else p2 = getter(n,mid);

      p2 = getter(n,mid);
      // t(mid-1,p1,mid,p2,mid+1,p3);
      if(p1 >= p2 && p3 >= p2)
      {
        ans = p2;
        break;
      } 
      else if(p1 <= p2)
      {
        end = mid-1;
      }
      else
      {
        beg = mid+1;
      }
    }

    for(int i=beg;i<=end;i++) ans = min(ans,getter(n,i));
    cout << ans.se << " " << ans.fi << endl; 
  }
  return 0;
}

/*
5
89
123
1000
1573655
842831057

*/