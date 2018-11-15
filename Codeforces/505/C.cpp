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
  string s;
  scr(s);
  int n = s.size();
  if(n==1) {cout<<1<<endl;return 0;}
  int max1 = -1;
  int boo;
  if(s[0]=='b') boo = 1;
  else boo = 0;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='b' && boo == 1) {boo++;boo%=2;count++;max1 = max(max1,count);}
    else if(s[i]=='b') {count = 1;max1 = max(max1,count);}
    else if(s[i]=='w' && boo==0) {boo++;boo%=2;count++;max1 = max(max1,count);}
    else if(s[i]=='w') {count = 1;max1 = max(max1,count);}
    // cout<<"s[i]: "<<s[i]<<" i: "<<i<<" count: "<<count<<endl;
  }
  if(s[0]!=s[n-1])
  {
    int max1 = -1,max2 = -1;
    int boo;
    if(s[0]=='b') boo = 1;
    else boo = 0;
    int count1 = 0,count2 = 0;
    s = s+s;
    for(int i=0;i<2*n;i++)
    {
      if(s[i]=='b' && boo == 1) {boo++;boo%=2;count1++;max1 = max(max1,count1);}
      else if(s[i]=='b') {count1 = 1;max1 = max(max1,count1);}
      else if(s[i]=='w' && boo==0) {boo++;boo%=2;count1++;max1 = max(max1,count1);}
      else if(s[i]=='w') {count1 = 1;max1 = max(max1,count1);}
    }
    if(max1==2*n) max1/=2;
    cout<<max1<<endl;
    return 0;
    // for(int i=0;i<n;i++)
    // {
    //   if(s[i]=='b' && boo == 1) {boo++;boo%=2;count1++;max1 = max(max1,count1);}
    //   // else if(s[i]=='b') {count = 1;max1 = max(max1,count1);}
    //   else if(s[i]=='w' && boo==0) {boo++;boo%=2;count1++;max1 = max(max1,count1);}
    //   // else if(s[i]=='w') {count = 1;max1 = max(max1,count1);}
    //   else break;
    // }
    // if(s[n-1]=='b') boo = 1;
    // else boo = 0;
    // for(int i=n-1;i>=0;i--)
    // {
    //   if(s[i]=='b' && boo == 1) {boo++;boo%=2;count2++;max2 = max(max2,count2);}
    //   // else if(s[i]=='b') {count = 1;max1 = max(max1,count1);}
    //   else if(s[i]=='w' && boo==0) {boo++;boo%=2;count2++;max2 = max(max2,count2);}
    //   // else if(s[i]=='w') {count = 1;max1 = max(max1,count1);}
    //   else break;
    // }
    // if(max1==n) cout<<n<<endl;
    // else cout<<max1+max2<<endl;
    // return 0;
  }
  cout<<max1<<endl;
  return 0;
}
