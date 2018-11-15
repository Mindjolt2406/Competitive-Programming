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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    string s;
    scr(s);
    int i=0;
    int count1 = 0;
    for(int i=0;i<s.size();i++) if(s[i]=='#') count1++;
    if(count1==s.size()) {printf("0\n");continue;}
    int counthash = 0,countdot = 0;
    while(s[i]=='#') i++;
    counthash = i;
    while(s[i]=='.') {i++;countdot++;}
    int c = i;
    string k;
    if(s[n-1]=='#') {printf("-1\n");continue;}
    int counter = 0;
    while(i<n-1)
    {
      // cout<<"i: "<<i;
      if(s[i]=='#' && s[i+1]=='.') {i+=2;k+="#.";}
      else if(s[i]=='#' && s[i+1]=='#') {i++;k+="#.";counter++;}
      else if(s[i]=='.' && s[i+1]=='#' && counter==0) {i++;k+='.';} 
      else {i++;counter--;}
      if(i==n-1) k+='.';  
      // cout<<" k: "<<k<<endl;
    }
    // cout<<"k: "<<k<<endl;
    string s1 = s.substr(c,n-c);
    // cout<<"s1: "<<s1<<endl;
    int c1 = 0,c2 = 0,c3 = 0,c4 = 0;
    vector<int> v1,v2;
    for(int i=0;i<k.size();i++)
    {
      if(k[i]=='.') c2++;
      else v2.pu(i);
      if(i<s1.size() && s1[i]=='.') c4++;
      else if(i<s1.size()) v1.pu(i);
    }
    i = k.size()-1;
    // cout<<"c2: "<<c2<<endl;
    while(k[i-1]=='.' && k[i]=='.') {c2--;i--;}
    // cout<<"k: "<<c2<<" s: "<<c4<<endl;
    if(c2<=c4)
    {
      ll cost = 0;
      for(int i=0;i<v1.size();i++) cost+=v2[i]-v1[i];
      // for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";cout<<endl;
      // for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";cout<<endl;
      // cout<<"cost: "<<cost<<endl;
      ll count = 0;
      for(int i=0;i<k.size();i++)
      {
        if(k[i]=='#') 
        {
          cost+=i-count;
          // cout<<"i: "<<i<<" count: "<<count<<" k[i]: "<<k[i]<<endl;
          count++;
        }
      }
      // cout<<"cost: "<<cost<<endl;
      cost+=count*countdot;
      printf("%lld\n",cost);
    } 
    else printf("-1\n");
  }
  return 0;
}

/*
1
8
#.##..#.

*/
