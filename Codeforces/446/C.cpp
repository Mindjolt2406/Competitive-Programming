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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  int count1 = 0;
  for(int i=0;i<n;i++) {sc(l[i]);if(l[i]==1) count1++;}
  if(count1!=0) {cout<<n-count1<<endl;return 0;}
  int boo = 1,min1 = INF;
  int g = l[0];
  // for(int i=0;i<n;i++)
  // {
  //   g = gcd(g,l[i]);
  // }
  // if(g!=1) {cout<<-1<<endl;return 0;}
  for(int i=0;i<n;i++) 
  {
    // int boo = 1;
    int g = l[i];
    for(int j=i+1;j<n;j++)
    {
      g = gcd(g,l[j]);
      // cout<<"i: "<<l[i]<<" j: "<<l[j]<<" g: "<<g<<endl;
      if(g==1) {boo = 0; min1 = min(min1,abs(i-j)); break;} 
    }
    // if(!boo) {boo1 = 0;break;}
  }
  // Take care of 1s
  if(boo) cout<<-1<<endl;
  else cout<<n-1+min1<<endl;
  return 0;
}

