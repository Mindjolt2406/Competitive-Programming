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

vector<ll> pow2;
// ll max(ll x, ll y)
// {
//   if(x>y) return x;
//   return y;
// }

// ll biand(ll x, ll y)
// {
//   string s,t;
  
//   while(x)
//   {
//     s += '0' + (x&1);
//     x >>= 1;
//   }

//   while(y)
//   {
//     t += '0' + (y&1);
//     y >>= 1;
//   }

//   while(s.size() != t.size())
//   {
//     if(s.size() < t.size()) s += '0';
//     else t += '0';
//   }

//   reverse(s.begin(),s.end());
//   reverse(t.begin(),t.end());

//   string ans_str;

//   for(int i=0;i<s.size();i++)
//   {
//     if(s[i] == t[i]) ans_str += s[i];
//     else break;
//   }

//   while(ans_str.size() != s.size())
//   {
//     ans_str += '0';
//   }

//   reverse(ans_str.begin(),ans_str.end());

//   ll ans = 0;
//   for(int i=0;i<ans_str.size();i++)
//   {
//     if(ans_str[i] == '1') ans += (1LL<<i);
//   }

//   return ans;
// }


ll biand(ll x, ll y)
{
  if(x==y) return (x&y);
  ll xr = x^y;

  // t(xr);
  // while(xr) 
  // {
  //   xr >>=1;
  //   cnt++;
  // }

  ll cnt = (ll)log2(xr);

  // if(!(cnt+1)) return x&y;

  return ((x&y) & (~(unsigned ll)((pow2[cnt+1])-1))   );
}

int main()
{
  __;
  for(int i=0;i<=60;i++) pow2.pu((1LL<<i));
  int t;
  cin >> t;
  while(t--)
  {
    ll a,b,k;
    cin >> a >> b >> k;

    // First do nothing and check
    ll max1 = -1;


    // Raghavan
    // ll mask = 0;
    // for(int i=60;i>=0;i--)
    // {
    //   ll temp = mask | (1LL<<i);
    //   if(temp >= a && temp + k-1 <= b)
    //   {
    //     mask = temp;
    //   }
    // }

    // cout << biand(mask,mask+k-1) << endl;

    max1 = max(max1,biand(b,b-k+1));
    // Otherwise, for b, iterate through each set bit and reset it. Make everything in front 1s, subtract k, take the and and compare
    for(int i=0;i<=60;i++)
    {
      if(!(b&(pow2[i]))) continue;
      else
      {
        ll temp = b;
        temp -= (pow2[i]);
        temp |= ((pow2[i])-1);
        ll temp2 = temp-k+1;
        if(temp2<a) break;
        max1 = max(max1,biand(temp,temp2));
      }
    }

    cout << max1 << endl;
  }
  
  return 0;
}

