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

class FixedNumberOfDigits
{
  public:
  vector<ll> first,last;

  FixedNumberOfDigits()
  {
    first.resize(17);
    last.resize(17);
  }

  void precompute(ll n, int step)
  {
    int mod = n%step;
    int len = to_string(n).size();
    ll prod = pow(10,len-1);
    for(int i=len;i<=16;i++)
    {
      ll end = ((prod*10)/step)*step;
      if(end + mod >= prod*10) end -= step;
      last[i] = end+mod;


      ll beg = (prod/step)*step;
      if(beg+mod < prod) beg += step;
      first[i] = beg+mod;

      prod *= 10;
    }
  }

  ll getCount(ll n, ll m,int step)
  {
    ll len_n = to_string(n).size(), len_m = to_string(m).size();
    if(len_n == len_m)
    {
      // t(n,m,step);
      return len_n * ((m-n)/step + 1);
    }

    ll cnt = 0;
    cnt += ((last[len_n]-n)/step + 1)*len_n;
    cnt += ((m-first[len_m])/step + 1)*len_m;

    for(ll i=len_n+1;i<len_m;i++)
    {
      cnt += ((last[i]-first[i])/step + 1) * i;
    }

    return cnt;
  }

  ll sum(int start, int step, ll numberOfDigits)
  {
    precompute(start,step);
    // t(first,last);
    ll n = start;
    ll beg = 0, end = 1e16, ans = 0;
    while(beg <= end)
    {
      ll mid = (beg+end) >> 1;
      ll temp = n + mid*step;
      ll numDigits = getCount(n,temp,step);
      // t(beg,end,mid,n,temp,numDigits);
      if(numDigits <= numberOfDigits)
      {
        ans =  mid;
        beg = mid+1;
      }
      else end = mid-1;
    }
    ll last = n + ans*step;
    ll numDigits = getCount(n,last,step);
    string lastStr =  to_string(last+step);

    // t(numDigits,numberOfDigits,lastStr);
    if(numDigits == numberOfDigits) return last;
    if(numDigits >= numberOfDigits) return stol(to_string(last).substr(0,numberOfDigits));
    else return stol(lastStr.substr(0,numberOfDigits - numDigits));
    
  }
};

// int main()
// {
//   __;
//   FixedNumberOfDigits f;
//   ll start,step,number;
//   cin >> start >> step >> number;
//   cout << f.sum(start,step,number) << endl;
//   return 0;
// }
