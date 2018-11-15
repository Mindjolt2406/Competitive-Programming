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
  map<string,vector<int> > d;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    int k;
    cin>>k;
    d[s].pu(k);
  }
  int a=0,b=0,c=0,d1=0;
  if(d.find("11")!=d.end()) {a = d["11"].size();sort(d["11"].begin(),d["11"].end());reverse(d["11"].begin(),d["11"].end());}
  if(d.find("01")!=d.end()) {b = d["01"].size();sort(d["01"].begin(),d["01"].end());reverse(d["01"].begin(),d["01"].end());}
  if(d.find("10")!=d.end()) {c = d["10"].size();sort(d["10"].begin(),d["10"].end());reverse(d["10"].begin(),d["10"].end());}
  int c2 = min(b,c);
  for(int i=c2;i<d["01"].size();i++) d["00"].pu(d["01"][i]);
  for(int i=c2;i<d["10"].size();i++) d["00"].pu(d["10"][i]);
  if(d.find("00")!=d.end()) {d1 = d["00"].size();sort(d["00"].begin(),d["00"].end());reverse(d["00"].begin(),d["00"].end());}
  int c1 = a;
  ll sum1 = 0;
  if(a)
  {
    for(int i=0;i<d["11"].size();i++) sum1+=d["11"][i];
  }
  // cout<<sum1<<endl;
  if(b) for(int i=0;i<min(b,c);i++) sum1+=d["01"][i];
  // cout<<sum1<<endl;
  if(c) for(int i=0;i<min(b,c);i++) sum1+=d["10"][i];
  // cout<<sum1<<endl;
  if(d1) for(int i=0;i<min(c1,d1);i++) sum1+=d["00"][i];
  cout<<sum1<<endl;
  return 0;
}

