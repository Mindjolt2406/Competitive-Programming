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
  int n,k;
  sc(n);sc(k);
  string s;
  scr(s);
  int* changed = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n/2;i++)
  {
    if(s[i]!=s[n-1-i])
    {
      k--;
      if(s[i]>s[n-1-i]) s[n-1-i] = s[i];
      else s[i] = s[n-1-i];
      changed[i] = 1;
      changed[n-1-i] = 1;
    }
  }
  // cout<<s<<endl;
  if(n%2==1) changed[(n-1)/2] = 1;
  if(k<0) {cout<<-1<<endl;return 0;}
  int i=0;
  while(k>=1 && i<=(n-1)/2)
  {
    // cout<<"i: "<<i<<" changed[i]: "<<changed[i]<<endl;
    if(s[i]=='9') {i++;continue;}
    else if(changed[i])k--;
    else if(k>=2) k-=2;
    else {i++;continue;}
    s[i] = '9';
    s[n-1-i] = '9';
    i++;
  }
  cout<<s<<endl;
  return 0;
}
