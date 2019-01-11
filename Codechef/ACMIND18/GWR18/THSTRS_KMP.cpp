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
#define scr(s) {char temp[200010];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

void get(string &s1,string &t,int boo,set<int> &v) // t is the prefix
{
  int n = s1.size(), m = t.size();
  string s = t+"$"+s1;
  vector<int> p(n+m+1); // the pi array (dp array)
  // t(s,boo);
  for(int i=1;i<n+m+1;i++)
  {
    int c = p[i-1];
    while(c>0 && s[c]!=s[i]) c = p[c-1];
    if(s[c]==s[i]) c++;
    p[i] = c;
  }

  for(int i=m+1;i<n+m+1;i++)
  {
    int j = p[i];
    // t(i,j);
    while(j>0)
    {
      // t(i,j,n+m-j);
      if(i+j>n+m) j = p[j-1];
      else if(i+j==n+m) 
      {
        // _;
        if(boo) v.insert(j);
        else v.insert(i-j-m);
        break;
      }
      else break;
    }
    if(t[0]==s[s.size()-1] && boo) v.insert(0);
    if(t[0]==s[s.size()-1] && !boo) v.insert(s1.size()-1);
  }
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    string a,b,c;
    scr(a);scr(b);scr(c);
    set<int> a1,b1;
    get(a,c,1,a1);
    get(c,b,0,b1);

    // for(auto it : a1) cout<<it<<" ";cout<<endl;
    // for(auto it : b1) cout<<it<<" ";cout<<endl;
    b1.insert(c.size());
    set<int> :: iterator it;
    int min1 = INF;
    a1.insert(-1);
    for(it=a1.begin();it!=a1.end();it++)
    {

      int a = *b1.upper_bound(*it);
      min1 = min(a-*it-1,min1);
    }

    if(a==c || b==c) cout<<a.size()+b.size()<<endl;
    else if(min1==INF) cout<<a.size()+b.size()+c.size()<<endl;
    else cout<<min1+a.size()+b.size()<<endl;
  }
  return 0;
}

/*
1
abc
cde
cec

*/
