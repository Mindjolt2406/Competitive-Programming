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
  vector<pair<int,int> > v;
  v.assign(1000001,mp(0,0));
  int*visited = (int*)calloc(1000001,sizeof(int));
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    if(u+4<=1000000 && !visited[u+4])
    {
      q.push(u+4);
      v[u+4] = mp(v[u].first+1,v[u].second);
      visited[u+4] = 1;
    }
    if(u+7<=1000000 && !visited[u+7])
    {
      q.push(u+7);
      v[u+7] = mp(v[u].first,v[u].second+1);
      visited[u+7] = 1;
    }
  }
  int n;
  sc(n);
  pair<int,int> p = v[n];
  string s;
  int c = p.first/7;
  p.first -= c*7;
  p.second+=4*c;
  for(int i=0;i<p.first;i++) s+="4";
  for(int i=0;i<p.second;i++) s+="7";
  if(s!="") cout<<s<<endl;
  else cout<<-1<<endl;
  return 0;
}

