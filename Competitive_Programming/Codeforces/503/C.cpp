// Will not work
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

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
}

int checkMax(vector<int>*adj,int n)
{
  int max1 = -1;
  for(int i=0;i<n;i++)
  {
    if(!adj[i].empty()) max1 = max(max1,(int)adj[i].size());
  }
  int count = 0,index = -1;
  for(int i=0;i<n;i++) if(max1==adj[i].size()) {count++;index = i;}
  if(count==1)return index;
  return -1;
}

int getMin(vector<int>*adj,int n,int maxindex,int need)
{
  int min1 = INF,min2 = INF,index1 = -1,index2 = -1;
  for(int i=0;i<n;i++)
  {
    if(i==maxindex) continue;
    if(!adj[i].empty()) {min1 = min(min1,adj[i][0]);if(min1==adj[i][0])index1 = i;}
  }
  for(int i=0;i<n;i++)
  {
    if(i==maxindex) continue;
    else if(i==index1 && adj[i].size()>1) {cout<<"size: "<<adj[i].size()<<endl;min2 = min(min2,adj[i][1]);if(min2==adj[i][1]) index2 = i;}
    else if(!adj[i].empty() && i!=index1) {min2 = min(min2,adj[i][0]); if(min2 == adj[i][0]) index2 = i;}
  }
  cout<<"min1: "<<min1<<" min2: "<<min2<<endl;
  vector<int>::iterator it;
  if(maxindex==-1 || min1+min2<adj[maxindex][0])
  {
    it = adj[index1].begin(); adj[index1].erase(it);
    if(min2!=INF)it = adj[index2].begin(); adj[index2].erase(it);
    return min1+min2;
  }
  else if (need==1 && min1<adj[maxindex][0])
  {
    it = adj[index1].begin(); adj[index1].erase(it);
    return min1;
  }
  else
  {
    int c = adj[maxindex][0];
    it = adj[maxindex].begin();
    adj[maxindex].erase(it);
    return c;
  }
}
int main()
{
  int m;sc(m);
  int n;sc(n);
  vector<int>*adj = new vector<int>[n];
  int votes = 0;
  for(int h=0;h<m;h++)
  {
    int a,b;
    sc(a);sc(b);
    a--;
    addEdge(adj,a,b);
    if(a==0) votes++;
  }
  int max1 = -1;
  for(int i=0;i<n;i++)
  {
    if(!adj[i].empty()) max1 = max(max1,(int)adj[i].size());
  }
  int need = max1-votes+1;
  cout<<"need: "<<need<<endl;
  ll cost = 0;
  while(need>0)
  {
    cout<<"need: "<<need<<endl;
    int maxindex = checkMax(adj,n);
    cout<<"maxindex: "<<maxindex<<endl;
    cost+=getMin(adj,n,maxindex,need);
    need-=2;
  }
  cout<<cost<<endl;
  return 0;
}
