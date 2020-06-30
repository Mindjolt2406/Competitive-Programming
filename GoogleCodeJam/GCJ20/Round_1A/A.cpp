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

pair< bool, string>  compatible(vector<string> &v)
{
  string temp = "";
  for(int i=0;i<v.size();i++)
  {
    int j = 0;
    while(j < min(temp.size(),v[i].size()))
    {
      if(temp[j] != v[i][j]) return mp(false,"");
      j++;
    }
    while(j < v[i].size()) 
    {
      temp += v[i][j]; 
      j++;
    }
  }
  return mp(true,temp);
}

void solve()
{
  int n;
  cin >> n;
  vector<string> v(n);
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
  }
  vector<string> pref,suf;
  vector<string> rest;

  for(int i=0;i<n;i++)
  {
    int cnt = 0;
    int beg = 0, end = v[i].size()-1;
    string temp_pref,temp_suf,temp_rest;
    while(v[i][beg] != '*')
    {
      temp_pref += v[i][beg];
      beg++;
    } 
    while(v[i][end] != '*')
    {
      temp_suf += v[i][end];
      end--;
    }
    if(beg != end)
    {
      while(beg <= end)
      {
        if(v[i][beg] != '*') temp_rest += v[i][beg];
        beg++;
      }
    }
    if(temp_pref != "") pref.pu(temp_pref);
    if(temp_suf != "") 
    {
      // reverse(temp_suf.begin(),temp_suf.end());
      suf.pu(temp_suf);
    }
    if(temp_rest != "") rest.pu(temp_rest);
  }

  // t(suf);
  pair<bool,string> p1 = compatible(pref);
  pair<bool,string> p2 = compatible(suf);
  // t(p1,p2);
  string concat_rest;
  for(int i=0;i<rest.size();i++) concat_rest += rest[i];
  if(p1.fi && p2.fi) 
  {
    reverse(p2.se.begin(),p2.se.end());
    cout << p1.se << concat_rest << p2.se << endl;    
  }
  else cout << "*" << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

/*
4
4
H*O
HELLO*
*HELLO
HE*
2
CODE*
*JAM
2
A*C*E
*B*D
2
**Q**
*A*


1
2
**Q**
*A*

*/