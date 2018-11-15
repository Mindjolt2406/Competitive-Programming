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
  string s1,s2;
  scr(s1);scr(s2);
  int* l1 = (int*)calloc(26,sizeof(int));
  int* l2 = (int*)calloc(26,sizeof(int));
  for(int i=0;i<n;i++)l1[s1[i]-'a']++;
  for(int i=0;i<n;i++)l2[s2[i]-'a']++;
  for(int i=0;i<26;i++)
  {
    if(l1[i]!=l2[i]) {cout<<-1<<endl;return 0;}
  }
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    // char c = s2[i];
    for(int j=i;j<n;j++)
    {
      if(s2[i]==s1[j])
      {
        s1.erase(j,1);
        // cout<<s1<<endl;
        // string s3 = (string)s2[i];
        // cout<<i<<s2[i]<<endl;
        s1.insert(i,1,s2[i]);
        // cout<<s1<<endl;
        // cout<<"here"<<endl;
        for(int k=j-1;k>=i;k--) v.pu(k);
        break;
      }
    }
  }
  cout<<v.size()<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]+1<<" ";cout<<endl;
  return 0;
}
