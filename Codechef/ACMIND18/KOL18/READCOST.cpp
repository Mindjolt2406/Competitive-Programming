#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,m,x,ans;
  while(true)
  {
    scanf("%lld %lld %lld",&n,&m,&x);
    // cin>>n>>m>>x;
    ans=0;
    if(!n && !m && !x) break;
    if(n>=m)
    {
      for(int i=1;i<=m;i++)
      ans+=(x+(i-1)*n)/m;
    }
    else
    {
      int k=2,l=(m-x)/n+1,r;
      while(true)
      {
        r=(k*m-x)/n+1;
        if(r>m)
        {
          ans+=m-l+1;
          break;
        }
        ans+=r-l+1;
        l=r+1;
        k++;
        cout<<"k: "<<k<<" r: "<<r<<endl;
      }
    }
    printf("%lld\n",ans);
    // cout<<ans<<endl;
  }
  return 0;
}