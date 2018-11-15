#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void print(vector<int> *adj,int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<i<<": ";
    for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<endl;
  }
}

void addEdge(vector<int>* adj,int u,int v)
{
  adj[u].pu(v);
}

int dfs(vector<int>*adj,int* visited, int u, stack<int> &s)
{
  // cout<<"u: "<<u<<endl;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(visited[adj[u][i]]==1) return 1;
    else if(visited[adj[u][i]]==0 && dfs(adj,visited,adj[u][i],s)) return 1;
  }
  visited[u] = 2;
  s.push(u);
  return 0;
}

int main()
{
  int n;
  cin>>n;
  vector<string> v;
  int l[26][26] = {0};
  vector<int>*adj = new vector<int>[26];
  int* visited = (int*)calloc(26,sizeof(int));
  stack<int> st;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    v.pu(s);
  }
  int boo = 1;
  for(int i=0;i<n-1;i++)
  {
    string s = v[i],t = v[i+1];
    int count = 0;
    int j=0;
    while(s[j]==t[j] && j<min(s.size(),t.size())) j++;
    if(j==min(s.size(),t.size()))
    {
      if(s.size()<=t.size()) continue;
      else {boo = 0;break;}
    }
    l[s[j]-'a'][t[j]-'a'] = 1;
  }
  if(!boo) {cout<<"Impossible"<<endl;return 0;}
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<26;j++)
    {
      if(l[i][j]) addEdge(adj,i,j);
    }
  }
  // print(adj,26);
  for(int i=25;i>=0;i--)
  {
    // cout<<"i: "<<i<<" visited[i]: "<<visited[i]<<endl;
    if(!visited[i])
    {
      int c = dfs(adj,visited,i,st);
      if(c==1) {cout<<"Impossible"<<endl;return 0;}
    }
  }
  // cout<<"size: "<<st.size()<<endl;
  while(!st.empty())
  {
    int u = st.top();
    st.pop();
    cout<<(char)(u+'a');
  }
  cout<<endl;
}
