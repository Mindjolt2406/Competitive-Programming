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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
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
  ll t,n,k;
  scll(t);
  while(t--)
  {
    scll(n);scll(k);
    if(n==1&&k==0)
    {
      //cout<<1<<endl;
      printf("1\n");
      continue;
    }
    ll mi = (n*(n+1))/2 - 1;
    ll mx = mi; 
    ll j=0;
    ll res = mi;
    for(int i = n-2;i>0;i-=2)
    {
      mx+=i;
      if(mx<=k) 
      {
        res+=i;
        j = (n-i)/2;

      }
    }  
    if(k<mi||k>mx) 
    {
      //cout<<-1<<endl;
      printf("-1\n");
      continue;
    }
//    t2(mi,mx);
    res = max({k-res,0ll});
  //  t(res);
    int cnt = n;
    vector<int> ans(n+1,-1);
    int i;
    for( i = 1;i<=2*j ;i++)
    {
      if(i%2==0) 
       ans[i] = cnt--;
      //j++;
    }  
    //t(j);
    if(res)
    ans[n-res] = cnt;
    j=1;
    for(i=1;i<=n;i++)
    {
      if(ans[i]==-1)
      {
      ans[i] = j++;

      }
      
      //else
      //ans[i] = cnt;

    }
    /*
    ans[n-res] = cnt;
    for(;i<=n;i++)
    {
      ans[i] = ++j;
    }
    */

    //t2(mi,mx);
    for(int i =1;i<=n;i++)
    printf("%d ",ans[i]);
    printf("\n");

  } 
  return 0;
}
/*
10
100000 50000000000
*/
