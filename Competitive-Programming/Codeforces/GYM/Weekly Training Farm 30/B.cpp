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
  string s;
  scr(s);
  n= s.size();
  vector<int> v(n,0);
  // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  int k=n;
  for(int i=n-1;i>=0;i--)
  {
    if(s[i]=='>' && k>(i+1)) {v[i] = k;k--;}
  }
  int boo = 0;
  // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  for(int i=n-1;i>=0;i--)
  {
    if(s[i]=='<'&& k<(i+1)) {v[i] = k;k--;}
    else if(s[i]=='<') {boo = 1;break;}
  }
  // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++) if(v[i]==0) boo = 1;
  if(boo) cout<<"Impossible"<<endl;
  else 
  {
    cout<<"Possible\n";
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  }
  return 0;
}

