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
  int t;
  sc(t);
  map<string,int> d;
  d["saturaday"] = 0;
  d["sunday"] = 1;
  d["monday"] = 2;
  d["tuesday"] = 3;
  d["wednesday"] = 4;
  d["thursday"] = 5;
  d["friday"] = 6;
  while(t--)
  {
    string s1,s2;
    cin>>s1>>s2;
    int a,b;
    sc(a);sc(b);
    int c = (d[s2]-d[s1] +1 + 7)%7;
    int count = 0,ans = 0;
    for(int i=a;i<=b;i++)
    {
      if(i%7==c) {count++;ans = i;}
    }
    if(count==0) cout<<"impossible"<<endl;
    else if(count==1) cout<<ans<<endl;
    else cout<<"many"<<endl;
  }
  return 0;
}

