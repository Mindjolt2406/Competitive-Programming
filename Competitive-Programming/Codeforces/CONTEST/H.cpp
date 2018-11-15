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
  int t;
  sc(t);
  map<string,int> d;
  map<string,string> d1;
  for(int i=0;i<t;i++)
  {
    string s;
    cin>>s;
    int n = s.size();
    set<string> ss;
    set<string> :: iterator it;
    for(int i=0;i<n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        string s1 =  s.substr(i,j);
        ss.insert(s1);
      }
    }
    for(it=ss.begin();it!=ss.end();it++)
    {
      if(d.find(*it)!=d.end()) d[*it]++;
      else {d[*it] = 1;d1[*it] = s;}
    }
  }
  int q;
  sc(q);
  for(int i=0;i<q;i++)
  {
    string s;
    cin>>s;
    if(d.find(s)==d.end()) printf("0 -\n");
    else printf("%d %s\n",d[s],d1[s].c_str());
  }
  return 0;
}

