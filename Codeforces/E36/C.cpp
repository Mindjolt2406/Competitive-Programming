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
  string s1,s2;
  scr(s1);scr(s2);
  if(s1.size()<s2.size())
  {
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;
  }
  else
  {
    int*l = (int*)calloc(10,sizeof(int));
    for(int i=0;i<s1.size();i++)
    {
      l[s1[i]-'0']++;
    }
    string k;
    int i=0;
    int n = s1.size();
    while(i<n && l[s2[i]-'0']>0)
    {
      k+=s2[i];
      l[s2[i]-'0']--;
      i++;
    }
    // cout<<"k: "<<k<<endl;
    if(i==n) {cout<<k<<endl;return 0;}
    int a=0;
    if(i!=n) a = s2[i]-'0';
    // cout<<"a: "<<a<<endl;
    int boo = 0;
    while(a>=0)
    {
      if(l[a]) {l[a]--;k+='0'+a;boo = 1;break;}
      a--;
    }
    // cout<<"k: "<<k<<endl;
    while(!boo && !k.empty())
    {
      int a = k.back()-'0';
      k.pop_back();
      l[a]++;
      a--;
      while(a>=0)
      {
        if(l[a]) {l[a]--;k+='0'+a;boo = 1;break;}
        a--;
      }
    }
    // cout<<"k: "<<k<<endl;
    // for(int i=0;i<10;i++) cout<<l[i]<<" ";cout<<endl;
    for(int i=9;i>=0;i--)
    {
      while(l[i]>0) 
      {
        k+=i+'0';
        l[i]--;
      }
    }
    cout<<k<<endl;
    trace1(k);
  }
  return 0;
}
