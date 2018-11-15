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

int check(string s,int k,int c,int n)
{
  int counta =0,countb = 0;
  for(int i=0;i<k;i++)
  {
    if(s[i]=='a') counta++;
    else countb++;
  }
  // cout<<"counta: "<<counta<<" countb: "<<countb<<endl;
  // if((abs(counta-countb)%2==0 && abs(counta-countb)/2<=c) || abs(counta-k)<=c || abs(countb-k)<=c) return 1;
  if(abs(counta-k)<=c || abs(countb-k)<=c) return 1;
  for(int i=k;i<n;i++)
  {
    char c1 = s[i-k];
    if(c1=='a') counta--;
    else countb--;
    if(s[i]=='a') counta++;
    else countb++;
    // cout<<"counta: "<<counta<<" countb: "<<countb<<endl;
    // if((abs(counta-countb)%2==0 && abs(counta-countb)/2<=c) || abs(counta-k)<=c || abs(countb-k)<=c) return 1;
    if(abs(counta-k)<=c || abs(countb-k)<=c) return 1;
  }
  return 0;
}

int bsearch2(string s,int n,int n1,int k)
{
  int beg = 1,end = n,max1 = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    mid*=2;
    // cout<<"mid: "<<mid<<endl;
    int c = check(s,mid,k,n1);
    // cout<<"c: "<<c<<" mid: "<<mid<<endl;
    if(c) {max1=max(max1,mid);beg = mid/2+1;}
    else end = mid/2-1;
  }
  return max1;
}

int bsearch(string s,int n,int k)
{
  int beg = 1,end = n,max1 = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    // cout<<"mid: "<<mid<<endl;
    int c = check(s,mid,k,n);
    // cout<<"c: "<<c<<" mid: "<<mid<<endl;
    if(c) {max1=max(max1,mid);beg = mid+1;}
    else end = mid-1;
  }
  return max1;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  string s;
  scr(s);
  int max1 = bsearch(s,n,k);
  // cout<<"max1: "<<max1<<endl;
  max1 = max(max1,bsearch2(s,n/2,n,k));
  int counta = 0,countb = 0;
  int i=0;
  while(i<n)
  {
    if(s[i]=='a')
    {
      while(s[i]=='a' && i<n) {counta++;i++;}
      max1 = max(max1,counta);
      counta = 0;
    }
    if(s[i]=='b')
    {
      while(s[i]=='b' && i<n) {countb++;i++;}
      max1 = max(max1,countb);
      countb = 0;
    }
  }
  cout<<max1<<endl;
  return 0;
}
