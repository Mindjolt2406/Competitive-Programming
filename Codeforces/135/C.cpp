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
  int n,k;
  sc(n);sc(k);
  string s;
  scr(s);
  if(k==2)
  {
    string k1,k2;
    for(int i=0;i<n/2;i++) {k1+="AB";k2+="BA";}
    if(n%2)
    {
      k1+="A";
      k2+="B";
    }
    int count1 = 0,count2 = 0;
    for(int i=0;i<n;i++)
    {
      if(s[i]!=k1[i]) count1++;
      if(s[i]!=k2[i]) count2++;
    }
    if(count1<count2) {cout<<count1<<"\n";cout<<k1<<"\n";}
    else cout<<count2<<"\n"<<k2<<"\n";
    return 0;
  }
  int count = 0;
  for(int i=1;i<s.size();i++)
  {
    if(s[i]==s[i-1])
    {
      count++;
      int boo = 1;
      char c1,c2;
      c1 = s[i-1];
      if(i+1<n) c2 = s[i+1];
      else c2 = 'A'-1;
      char c = 'A'+k-1;
      if(c==c1 || c==c2)
      {
        c--;
        if(c==c1 || c==c2)
        {
          c--;
          s[i] = c;
        }
        else s[i] = c;
      }
      else s[i] = c;
    }
  }
  cout<<count<<endl;
  cout<<s<<endl;
  return 0;
}

