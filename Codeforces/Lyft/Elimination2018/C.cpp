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
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  vector<int>* m = new vector<int>[n+1];
  for(int i=0;i<n;i++)
  {
    int k = i;
    k-=l[i];
    // cout<<"i: "<<i<<endl;
    while(k>=0)
    {
      if(l[k]>l[i]) m[l[i]].pu(l[k]);
      k-=l[i];
    }
    k = i+l[i];
    while(k<n)
    {
      if(l[k]>l[i]) m[l[i]].pu(l[k]);
      k+=l[i];
    }
  }
  // cout<<"here"<<endl;
  int*check = (int*)calloc(n+1,sizeof(int));
  string k;
  for(int i=n;i>=1;i--)
  {
    for(auto j : m[i])
    {
      if(check[j]==0) check[i] = 1;
    }
  }
  for(int i=0;i<n;i++)
  {
    if(check[l[i]]==1) k+='A';
    else k+='B';
  }
  cout<<k<<endl;
  return 0;
}

