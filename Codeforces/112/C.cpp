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
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int k;
  sc(k);
  ll count = 0;
  string s;
  scr(s);
  int n = s.size();
  vector<ll> v;
  v.pu(-1);
  for(int i=0;i<s.size();i++)
  {
    if(s[i]-'0'){count++;v.pu(i);}
  }
  v.pu(n);
  if(count<k) cout<<0<<endl;
  else
  {
    if(k==0)
    {
      ll count = 0;
      vector<ll> v;
      int i=0;
      int counter = 0;
      while(i<s.size())
      {
        // t(i,s[i]);
        if(s[i]=='0') counter++;
        else if(counter!=0) {v.pu(counter);counter = 0;}
        i++;
      }
      if(counter) v.pu(counter);
      // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
      for(int i=0;i<v.size();i++)
      {
        count+= (v[i]*(v[i]+1))/2;
      }
      cout<<count<<endl;
      return 0;
    }
    count = 0;
    int a = 1,b = k;
    int i=0;
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
    while(b+1<v.size())
    {
      count += (v[a]-v[a-1])*(v[b+1]-v[b]);
      a++;b++;
    }
    cout<<count<<endl;
  }
  return 0;
}

