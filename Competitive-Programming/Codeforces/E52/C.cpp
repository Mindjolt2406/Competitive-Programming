#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000000000000001
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

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  ll*l = (ll*)calloc(200001,sizeof(ll));
  ll min1 = INF,min2 = -1;
  for(int i=0;i<n;i++)
  {
    int a;
    sc(a);
    l[a]++;
    min1 = min(min1,a);
    min2 = i;
  }

  for(int i=199999;i>=0;i--) l[i]+=l[i+1];
  int count = 0;
  int c = k;
  // for(int i=0;i<10;i++) cout<<l[i]<<" ";cout<<endl;
  for(int i=0;i>min1;i--)
  {
    c-=l[i];
    // if(i<6) cout<<"c: "<<c<<" l[i]: "<<l[i]<<endl;
    if(c==0) {count++;c = k;}
    else if(c<0) 
    {
      count++;
      c = k-l[i];
      // cout<<"c: "<<c<<" l[i]: "<<l[i]<<endl;
      if(c==0) {count++;c = k;}
    }
  }
  if(c>0 && c!=k) count++;
  cout<<count<<endl;
  return  0;
}

