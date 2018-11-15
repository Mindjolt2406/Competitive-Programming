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

int compare(int**l1,int**l2,int a,int b,int k)
{
  int boo = 1;
  for(int i=0;i<26;i++)
  {
    int a1,a2;
    if(a!=0) a1 = l1[a+k-1][i]-l1[a-1][i];
    else a1 = l1[a+k-1][i];
    if(b!=0) a2 = l2[b+k-1][i]-l2[b-1][i];
    else a2 = l2[b+k-1][i];
    
    if(a1!=a2) {boo = 0;break;}
  }
  return boo;
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n;
    sc(n);
    string s1,s2;
    scr(s1);scr(s2);
    int**l1 = (int**)calloc(n,sizeof(int*));
    int**l2 = (int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++) {l1[i] = (int*)calloc(26,sizeof(int));l2[i] = (int*)calloc(26,sizeof(int));}
    for(int i=0;i<n;i++)
    {
      // cout<<"i: "<<i<<" s1: "<<s1[i]-'a'<<" s2: "<<s2[i]-'a'<<endl;
      l1[i][s1[i]-'A']++;
      l2[i][s2[i]-'A']++;
    }
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<26;j++)
      {
        l1[i][j]+=l1[i-1][j];
        l2[i][j]+=l2[i-1][j];
      }
    }
    // for(int i=0;i<n;i++) {for(int j=0;j<26;j++) cout<<l1[i][j]<<" "; cout<<endl;}
    // for(int i=0;i<n;i++) {for(int j=0;j<26;j++) cout<<l2[i][j]<<" "; cout<<endl;}
    // set<string> s;
    int count = 0;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<n-i+1;j++)
      {
        for(int k=0;k<n-i+1;k++)
        {
          if(compare(l1,l2,j,k,i)) 
          {
            count++; 
            break;
          }
        }
      }
    }
    printf("Case #%d: %d\n",h,count);
  }
  return 0;
}

