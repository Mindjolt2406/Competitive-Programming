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

void check(vector<int> &ans,int n)
{
  bool flag1 = (ans.size() >= n/2 && ans.size() <= n);
  int odd = 0, even = 0;
  for(int i=0;i<ans.size();i++)
  {
    if(ans[i])
    {
      (i&1) ? even++ : odd++;
    }
  }
  
  // t(flag1,even,odd);
  cout << ((flag1 && (even == odd)) ? "Success" : "Failure") << endl;
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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    if(n == 2)
    {
      if(v[0] != v[1])
      {
        cout << 1 << endl;
        cout << 0 << endl;
      }
      else 
      {
        cout << v.size() << endl;
        for(auto it : v) cout << it << " "; cout << endl;
      }
      continue;
    }

    int odd = 0, even = 0;
    for(int i=0;i<n;i++)
    {
      if(v[i])
      {
        // (i&1) ? even++ : odd++;
        if(i%2 == 1) even++;
        else odd++;
      }
    }

    t(odd,even);
    int diff = abs(odd-even);
    bool diffOdd = diff&1;

    if(odd == even)
    {
      cout << v.size() << endl;
      for(auto it : v) cout << it << " "; cout << endl;
      check(v,n);
    }
    else 
    {
      vector<int> ans;

      for(int i=n-2;i>=0;i--)
      {
        t(i,even,odd);
        if(diff && (odd>even) && v[i] == 1 && v[i+1] == 0) 
        {
          // ans.pu(v[i+1]);
          odd--;
          swap(even,odd);
          diff--;
          i--;
        }
        else if(diff && (even > odd) && v[i] == 0 && v[i+1] == 1) 
        {
          // t(i);
          ans.pu(v[i]);
          even--;
          swap(even,odd);
          diff--;
        }
        else 
        {
          // t(i,i+1);
          ans.pu(v[i]);
          if(i+1 != n) ans.pu(v[i+1]);
        }
      }

      cout << ans.size() << endl;
      for(auto it : ans) cout << it << " "; cout << endl;
      cout << v.size() << endl;
      for(auto it : v) cout << it << " "; cout << endl;
      check(ans,n);
    }
    // else
    // {
    //   vector<int> ans;
    //   for(int i=0;i<n;i+=2)
    //   {
    //     if(diff && v[i] == 0 && v[i+1] == 1) 
    //     {
    //       if(!diffOdd) ans.pu(v[i]);
    //       else if(diffOdd && diff != 1) ans.pu(v[i]);
    //       diff--;
    //     }
    //     else 
    //     {
    //       ans.pu(v[i]);
    //       ans.pu(v[i+1]);
    //     }
    //   }

    //   cout << ans.size() << endl;
    //   for(auto it : ans) cout << it << " "; cout << endl;
    //   cout << v.size() << endl;
    //   for(auto it : v) cout << it << " "; cout << endl;
    //   check(ans,n);
    // }
  }
  return 0;
}
