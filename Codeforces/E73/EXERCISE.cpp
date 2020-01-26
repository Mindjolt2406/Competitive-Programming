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


bool check(int idx,int n,vector<int> &v, string &s) // Check no value becomes invalid
{
  int a = v[idx];
  
  // Forward
  int i = idx;
  char sign = s[idx];
  bool boo = true;
  int kf = a;
  while(i<n-1)
  {
    if(s[i] != '=' && sign == '=') sign = s[i];
    if(s[i]!= '=' && s[i]!=sign) break;

    if(v[i+1] == -1)
    { 
      if(s[i] == '<')
      {
        kf++;
        // if(kf>1e6) {boo = false; break;}
      }
      else if(s[i] == '>')
      {
        kf--;
        if(kf<0) {boo =false; break;}
      }
    }
    else
    {
      if(s[i] == '<')
      {
        if(kf >= v[i+1]) boo = false; 
      }
      else if(s[i] == '=')
      {
        if(sign == '<' && kf > v[i+1]) boo = false; 
        else if(sign == '>' && kf < v[i+1]) boo = false; 
        else if(sign == '=' && kf != v[i+1]) boo = false;
      }
      else if(s[i] == '>')
      {
        if(kf <= v[i+1]) boo = false;
      }
      break;
    }
    i++;
  }

  if(!boo) return false;

  i = idx;
  int kr = a;
  sign = s[i-1];
  while(i>0)
  {
    if(s[i] != '=' && sign == '=') sign = s[i];
    if(s[i] != '=' && s[i-1]!=sign) break;

    if(v[i-1] == -1)
    {
      if(s[i-1] == '<')
      {
        kr--;
        if(kr<0) {boo = false; break;}
      }
      else if(s[i-1]== '>')
      {
        kr++;
        // if(kr > 1e6) {boo = false; break;}
      }
    }
    else
    {
      if(s[i-1] == '<')
      {
        if(v[i-1] >= kr) boo = false;
      }
      else if(s[i-1] == '=')
      {
        // t(sign,v[i-1],kr);
        if(sign == '<' && v[i-1] > kr) boo = false;
        else if(sign == '>' && v[i-1] < kr) boo = false;
        else if(sign == '=' && v[i-1] != kr) boo = false;
      }
      else if(s[i-1] == '>')
      {
        if(v[i-1] <= kr) boo = false;
      }
      break;
    }
    i--;
  }

  return boo;
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
    string s;
    cin >> s;

    bool boo = true;
    for(int i=0;i<n;i++)
    {
      if(v[i] != -1) 
      {
        if(check(i,n,v,s)) continue;
        else {boo = false; break;}
      }
    }

    if(boo) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

/*
1
6
7 5 -1 -1 -1 10
>>=>>

1
6
7 5 -1 -1 -1 10
>>=<>

1
4
999998 -1 -1 -1
===

1
5
0 -1 0 -1 -1
===<

*/