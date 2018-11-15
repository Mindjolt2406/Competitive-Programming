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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n,a,b;
  sc(n);sc(a);sc(b);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int count = 0,boo = 0;
  for(int i=0;i<n/2;i++)
  {
    if(l[i]==l[n-1-i] && l[i]==2)
    {
      count+=2*min(a,b);
    }
    else if(l[i]==l[n-1-i]) continue;
    else if(l[i]!=l[n-1-i])
    {
      if((l[i]==0 && l[n-1-i]==1) || (l[n-1-i]==0 && l[i]==1)) {boo = 1;break;}
      else if(l[i]==0 || l[n-1-i]==0) count+=a;
      else if(l[i]==1 || l[n-1-i]==1) count+=b;
    }
  }
  if(n%2==1)
  {
    if(l[n/2]==2) count+=min(a,b);
  }
  if(boo) cout<<-1<<endl;
  else cout<<count<<endl;
  return 0;
}
