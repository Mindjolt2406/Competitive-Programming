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

bitset<10000001> bs;
int size = 10000001;

void sieve()
{
  bs.set();
  bs[0] = false;bs[1] = false;
  for(ll i=2;i<size;i++)
  {
    if(bs[i])
    {
      for(ll j=i*i;j<size;j+=i) bs[j] = false;
    }
  }
}

int add(vector<int> &v)
{
  int i=v.size()-1;
  while(i>=0)
  {
    if(v[i]!=3) {v[i]++;return 1;}
    else {v[i] = 0;i--;}
  }
  return 0;
}

int check(vector<int> v,int n)
{
  string k;
  while(v[3]--) k+='9';
  while(v[2]--) k+='7';
  while(v[1]--) k+='3';
  while(v[0]--) k+='1';
  int c = stoi(k);
  if(c>=n) return 1;
  return 0;
}

int main()
{
  sieve();
  int n;
  sc(n);
  while(n)
  {
    string s = to_string(n);
    int c = s.size();
    if(c==1)
    {
      int l[10] = {2,2,3,5,5,7,7,0,0,0};
      printf("%d\n",l[n]);
      // sc(n);
      // continue;
      // printf("0\n");
      sc(n);
      continue;
    }
    map<vector<int>,int >d;
    map<vector<int>,int > :: iterator it;
    vector<int> v;
    for(int i=0;i<c;i++) v.pu(0);
    v[v.size()-1] = -1;
    while(add(v))
    {
      // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
      string k;
      vector<int> v1;
      v1.resize(4);
      for(int i=0;i<4;i++) v1[i] = 0;
      for(int i=0;i<c;i++)
      {
        if(v[i]==0) {k+='1';v1[v[i]]++;}
        else if(v[i]==1) {k+='3';v1[v[i]]++;}
        else if(v[i]==2) {k+='7';v1[v[i]]++;}
        else {k+='9';v1[v[i]]++;}
      }
      int x = stoi(k);
      // cout<<x<<endl;
      if(bs[x])
      {
        // cout<<x<<endl;
        if(d.find(v1)==d.end() && x<=n) d[v1] = 1;
        else if(d.find(v1)==d.end()) d[v1] = x;
        else if(d[v1]==1 && x>n) d[v1] = x;
        // cout<<d[v1]<<endl;
      }
      else
      {
        d[v1] = -1;
      }
    }
    int min1 = INF;
    for(it = d.begin();it!=d.end();it++)
    {
      if(it->second>=1)
      {
        if(it->second!=1) min1 = min(min1,it->second);
      }
    }
    if(min1!=INF) printf("%d\n",min1);
    else printf("0\n");
    sc(n);
  }
  return 0;
}
