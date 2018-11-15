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

map<pair<int,int>,int > d;

void countSort(vector<pair<int,int> > &v)
{
  vector<pair<int,int> > *adj1 = new vector<pair<int,int> >[n];
  vector<pair<int,int> > *adj2 = new vector<pair<int,int> >[n];
  for(int i=0;i<v.size();i++)
  {
    adj1[v[i].second].pu(v[i]);
  }
  v.clear();
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<adj1[i].size();j++)
    {
      v.pu(adj1[i][j]);
    }
  }
  for(int i=0;i<v.size();i++)
  {
    adj2[v[i].second].pu(v[i]);
  }
  v.clear();
  int count = 0;
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<adj2[i].size();j++)
    {
      if(d.find(adj2[i][j])!=d.end())
      {
        count++;
        d[adj2[i][j]] = count;
      }
      v.pu(adj2[i][j]);
    }
  }
}

void findRank(int*l, string s)
{
  int* rank = (int*)calloc(130,sizeof(int));
  for(int i=0;i<s.size();i++)
  {
    rank[s[i]] = 1;
  }
  int count = 0;
  for(int i=0;i<130;i++) {count+=s[i];s[i] = count;}
  for(int i=0;i<s.size();i++)
  {
    l[i] = rank[s[i]];
  } 
}

int main()
{
  string s;
  scr(s);
  s+='$';
  int*rank = (int*)calloc(n,sizeof(int));
  
  return 0;
}
