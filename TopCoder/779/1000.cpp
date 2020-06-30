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

class ArraySorting
{
  public:
    vector <int> arraySort(vector <int> v)
    {
      int n = v.size();
      vector<int> dp(n);
      vector<int> back(n);

      for(int i=0;i<n;i++) dp[i] = 1;
      for(int i=0;i<n;i++) back[i] = -1;

      for(int i=1;i<n;i++)
      {
        int max1 = 1;
        int index = -1;
        for(int j=0;j<i;j++)
        { 
          if(v[i] >= v[j])
          {
            // if(i==2) t(j,dp[j],max1);
            if(dp[j] >= max1)
            {
              max1 = dp[j];
              index = j;
            }
          }
        }
        // if(i==2) t(index,max1,dp[i]);
        back[i] = index;
        if(index != -1) dp[i] = max1+1;
        // if(i==2) t(i,dp[i]);
      }

      int index = -1;
      int max1 = -1;
      for(int i=0;i<n;i++)
      {
        if(dp[i] >= max1)
        {
          max1 = dp[i];
          index = i;
        }
      }

      // t(v);
      // t(max1);
      // t(back);
      // t(dp);
      // t(index);
      vector<int> taken(n);
      taken[index] = 1;
      index = back[index];
      while(index != -1)
      {
        taken[index] = 1;
        index = back[index];
      }



      vector<int> ans(n);
      int prev = 1;
      for(int i=0;i<n;i++)
      {
        if(taken[i]) prev = v[i];
        ans[i] = prev;
      }

      return ans;
    }
};

int main()
{
  __;
  ArraySorting a;
  cout << a.arraySort({2000,2000,1}) << endl;
  return 0;
}
