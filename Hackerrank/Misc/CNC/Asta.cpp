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
  sort(v.begin(),v.end());

  if(n == 0) 
  {
    cout << "No" << endl;
  }
  else if(n == 1)
  {
    string s;
    cin >> s;
    set<char> set_char;
    for(int i=0;i<s.size();i++) set_char.insert(s[i]);
    // t(set_char.size(),s[0]-'0',v[0]);
    if(s[0] - '0' == v[0] && set_char.size() == 1) 
    {
      if(s[0] == '0' && s.size() > 1) cout << "Yes" << endl << 1 << endl;
      else cout << "Yes" << endl << s.size() << endl;
    }
    else cout << "No" << endl;
  }
  else
  {
    string s;
    cin >> s;
    set<char> set_char;
    for(int i=0;i<s.size();i++) set_char.insert(s[i]);
    bool boo = true;
    for(int i=0;i<s.size();i++)
    {
      int a = s[i]-'0';
      if(a != v[0] && a != v[1]) boo = false;
    }
    // _;
    if(set_char.size() <= 2 && boo)
    {
      cout << "Yes" << endl;
      if(v[0] == v[1]) 
      {
        if(v[0] == 0 ) cout << 1 << endl;
        else cout << s.size() << endl;
        return 0;
      }
      reverse(s.begin(), s.end());
      for(int i=0;i<s.size();i++)
      {
        if(s[i]-'0' == v[0]) s[i] = '0';
        else s[i] = '1';
      }
      ll prod = 0;
      if(v[0] == 0)
      {
        for(int i=0;i<s.size();i++)
        {
          if(s[i] == '1') prod += pow(2,i);
        }
        prod++;
      }
      else
      {
        for(int i=0;i<s.size();i++)
        {
          if(s[i] == '1') prod += 2*pow(2,i);
          else if(s[i] == '0') prod += pow(2,i);
        }
      }
      cout << prod << endl;
    }
    else cout << "No" << endl;
  }
  return 0;
}

