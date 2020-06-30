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

bool eq(char a, char b)
{
  if(a == '?' || b == '?' || a == b) return true;
  return false;
}

bool eq2(char a, char b)
{
  if(a == b) return true;
  return false;
}

// bool cmp2(string &s1, string &t)
// {
//   // t is inside
//   string s = s1;
//   // reverse(s.begin(),s.end());
//   int n = s.size(), m = t.size();
//   s = t+"$"+s;
//   // t(s);
//   vector<int> p(n+m+1); // the pi array (dp array)
//   // t(s,m);
//   for(int i=1;i<n+m+1;i++)
//   {
//     int c = p[i-1];
//     while(c>0 && !eq2(s[c],s[i])) c = p[c-1];
//     if(eq2(s[c],s[i])) c++;
//     p[i] = c;
//   }

//   // t(p);
//   // return p[p.size()-1];

// }

int cmp(string s, string t)
{
  int cnt = 0;
  for(int i=s.size()-1;i>=0 && s.size()-1-i < t.size();i--)
  {
    bool boo = true;
    for(int j=i;j<s.size();j++)
    {
      if(!eq(s[j],t[j-i])) boo = false;
    }
    if(boo) cnt = s.size()-i;
  }
  return cnt;
}

int cmp2(string s, string t)
{
  for(int i=0;i<t.size();i++)
  {
    if(i>=s.size()) break;
    bool boo = true;
    for(int j=0;j<s.size();j++)
    {
      if(i+j>=t.size()) 
      {
        boo = false;
        break;
      }
      if(!(s[j] == t[i+j])) boo = false;
    }
    if(boo) return true;
  }
  return false;
}


int check(string a, string b, string c)
{
  if(cmp2(a,b))
  {
    if(cmp2(b,c))
    {
      return c.size();
    }
    else if(cmp2(c,b))
    {
      return b.size();
    }
    else
    {
      int y = cmp(b,c);
      return b.size() + c.size() - y;
    }
  }
  else if(cmp2(b,a))
  {
    if(cmp2(a,c))
    {
      return c.size();
    }
    else if(cmp2(c,a))
    {
      return a.size();
    }
    else
    {
      int x = cmp(a,c);
      return a.size() + c.size() - x;
    }
  }
  else
  {
    if(cmp2(b,c))
    {
      int x = cmp(a,c);
      return a.size() + c.size() - x;
    }
    else if(cmp2(c,b))
    {
      int x = cmp(a,b);
      return a.size() + b.size() - x; 
    }
    int tot = a.size() + b.size() + c.size();
    int x = cmp(a,b);
    a = a.substr(0,a.size()-x);
    string temp = a+b;
    int y = cmp(temp,c);
    int ans = tot - x - y;
    return ans;
  }
}

int main()
{
  __;
  string a,b,c;
  cin >> a >> b >> c;
  int min1 = INF;
  min1 = min(min1,check(a,b,c));
  min1 = min(min1,check(a,c,b));
  min1 = min(min1,check(b,a,c));
  min1 = min(min1,check(b,c,a));
  min1 = min(min1,check(c,a,b));
  min1 = min(min1,check(c,b,a));
  // 
  cout << min1 << endl;
  return 0;
}
