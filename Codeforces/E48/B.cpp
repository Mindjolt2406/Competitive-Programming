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
  int n1,n2,q;
  sc(n1);sc(n2);sc(q);
  string s1,s2;
  scr(s1);scr(s2);
  int*l = (int*)calloc(n1+1,sizeof(int));
  for(int i=0;i<n1-n2+1;i++)
  {
    if(s1.substr(i,n2)==s2) l[i]++;
  }
  // for(int i=0;i<n1;i++) cout<<l[i]<<" ";cout<<endl;
  for(int i=1;i<n1;i++) l[i]+=l[i-1];
  for(int h=0;h<q;h++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    if(b-a+1>=n2)
    {
      if(a!=0)printf("%d\n",l[b-n2+1]-l[a-1]);
      else printf("%d\n",l[b-n2+1]);
    }
    else printf("0\n");
  }
  return 0;
}
