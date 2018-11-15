// This problem can be solved by a single dfs. The issue was that in the string 'ALLIZZWELL', there are multiple L's
// so, it's not possible to just simply mark all the nodes and move on
// so, t counter that, I  marked the nodes with the index value in the string, and all other useless nodes as -1.
// But I never really checked the -1's though, I only checked if I wasn't repeating any past 'successful' characters
// It probably just worked out because it was a small and constant string, and that my node always had 8 children
// so at max, it would only take 8*n^2 => O(n^2)
// The main take away is that marking doesn't necessarily have to be binary, it could be anything as long as it helps

#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
using namespace std;

void print(int** visited, int n,int m)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++) cout<<visited[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}

int dfs(int i,int j,char **l, int **visited,string s,int count, int n,int m)
{
  if(i<0 || i>=n || j<0 || j>=m) return 0;//{cout<<" return 0"<<endl;return 0;}
  if((visited[i][j]<=count && visited[i][j]>=0)) return 0;//{cout<<" visited return 0"<<endl; return 0;}
  if(l[i][j]==s[count])
  {
    visited[i][j] = count;
    if(count==9) return 1;
    count++;
    if(dfs(i-1,j-1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i-1,j,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i-1,j+1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i,j-1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i,j+1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i+1,j-1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i+1,j,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    if(dfs(i+1,j+1,l,visited,s,count,n,m)) {visited[i][j] = count-1;return 1;}
    visited[i][j] = -1;
    return 0;
  }
  return 0;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    char **l = new char*[n];
    for(int i=0;i<n;i++) l[i] = new char[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>l[i][j];
    int** visited = new int*[n];
    for(int i=0;i<n;i++) visited[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = -3;
    vector < pair <int,int> > v;
    int c = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(l[i][j]=='A') c = dfs(i,j,l,visited,"ALLIZZWELL",0,n,m);
        if(c==1) break;
      }
      if(c==1) break;
    }
    if(c==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
