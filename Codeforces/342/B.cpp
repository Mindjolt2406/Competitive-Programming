#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  string s,t;
  scr(s);scr(t);
  int n = s.size(), m = t.size();
  s = t+"$"+s;
  vector<int> p(n+m+1); // the pi array (dp array)
  // t(s,m);
  for(int i=1;i<n+m+1;i++)
  {
    int c = p[i-1];
    while(c>0 && s[c]!=s[i]) c = p[c-1];
    if(s[c]==s[i]) c++;
    p[i] = c;
  }

  int i = m+1;
  int count = 0;
  // for(int i=m+1;i<n+m+1;i++) cout<<p[i]<<" ";cout<<endl;
  while(i<n+m+1)
  {
    if(p[i]==m) {count++;i+=m-1;}
    i++;
  }
  cout<<count<<endl;
  return 0;
}

