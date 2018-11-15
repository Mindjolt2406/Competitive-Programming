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
  int count0 = 0;
  int*l = (int*)calloc(4,sizeof(int));
  string k;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(s[i]-'0'==1 && l[0]==0) l[0] = 1;
    else if(s[i]-'0'==6 && l[1]==0) l[1] = 1;
    else if(s[i]-'0'==8 && l[2]==0) l[2] = 1;
    else if(s[i]-'0'==9 && l[3]==0) l[3] = 1;
    else if(s[i]=='0') count0++;
    else
    {
      int a = s[i]-'0';
      k+=s[i];
      count+=a;
      count%=7;
      count*=10;
    }
  }
  map<int,string> d;
  d[0] = "1869";
  d[1] = "1968";
  d[2] = "9816";
  d[3] = "6198";
  d[4] = "1698";
  d[5] = "1986";
  d[6] = "1896";
  count/=10;
  for(int i=0;i<4;i++) {count*=10;count%=7;}
  int b = (7-count)%7;
  k+=d[b];
  for(int i=0;i<count0;i++) k+='0';
  cout<<k<<endl;
  return 0;
}

