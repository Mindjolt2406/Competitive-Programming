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
  string s;
  scr(s);
  string s1;
  for(int i=0;i<n;i++) s1+='0';
  if(s1==s) {cout<<"YES"<<endl;return 0;} 
  string s2;
  for(int i=0;i<s.size();i++) if(s[i]!='0') s2+=s[i];
  n = s2.size();
  s = s2;
  vector<int> v;
  vector<int> pref;
  for(int i=0;i<s.size();i++) v.pu(s[i]-'0');
  pref.pu(v[0]);
  for(int i=1;i<v.size();i++) pref.pu(v[i]+pref[i-1]);
  // for(int i=0;i<pref.size();i++) cout<<pref[i]<<" ";cout<<endl;
  for(int i=0;i<n-1;i++)
  {
    int sum1 = pref[i];
    int j = i+1,boo = 0;
    while(j<n)
    {
      // if(v[j]==0){j++;continue;}
      int k = sum1;
      if(k==0) {j++;continue;}
      while(k>0 && j<n)
      {
        // cout<<"j: "<<j<<" k: "<<k<<endl;
        k-=v[j];
        j++;
      }
      // cout<<"j: "<<j<<" k: "<<k<<endl;
      if(k==0) 
      {
        continue;
      }
      else {boo = 1;break;}
    }
    if(boo==0) {cout<<"YES"<<endl;return 0;}
  }
  cout<<"NO"<<endl;
  return 0;
}

