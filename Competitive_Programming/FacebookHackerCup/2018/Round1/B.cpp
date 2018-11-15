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

struct node
{
  int left;
  int right;
};

void print(vector<int> *adj,int n)
{
  for(int i=1;i<=n;i++)
  {
    cout<<i<<": ";
    for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<endl;
  }
}

void preorder(vector<int> &v, node* tree, int i)
{
  if(i)
  {
    v.pu(i);
    preorder(v,tree,tree[i].left);
    preorder(v,tree,tree[i].right);
  }
}

void postorder(vector<int> &v, node*tree, int i)
{
  if(i)
  {
    postorder(v,tree,tree[i].left);
    postorder(v,tree,tree[i].right);
    v.pu(i);
  }
}

void addEdge(vector<int> *adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

void dfs(vector<int>*adj,int*visited, int u,int key)
{
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++) {dfs(adj,visited,adj[u][i],key);}
}

int* countComponents(vector<int>*adj,int n)
{
  int* visited = (int*)calloc(n+1,sizeof(int));
  int key = 1;
  for(int i=1;i<=n;i++)
  {
    // for(int i=1;i<=n;i++) cout<<visited[i]<<" ";cout<<endl;
    if(!visited[i] && adj[i].size()) {dfs(adj,visited,i,key);key++;}
  }
  return visited;
}

int main()
{
  typedef struct node node;
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n,k;
    sc(n);sc(k);
    node* tree = new node[n+1];
    for(int i=1;i<=n;i++)
    {
      int a,b;
      sc(a);sc(b);
      tree[i].left = a;
      tree[i].right = b;
    }
    vector<int> pre,post;
    preorder(pre,tree,1);
    postorder(post,tree,1);
    // int count = 0;
    vector<int> *adj = new vector<int>[n+1];
    // cout<<"Pre: ";
    // for(int i=0;i<n;i++) cout<<pre[i]<<" ";cout<<endl;
    // cout<<"Post: ";
    // for(int i=0;i<n;i++) cout<<post[i]<<" ";cout<<endl;
    // cout<<"n: "<<n<<" k: "<<k<<endl;
    for(int i=0;i<n;i++)
    {
      if(pre[i]!=post[i])
      {
        addEdge(adj,pre[i],post[i]);
      }
      // else count+=;
    }
    // print(adj,n);
    int* visited = countComponents(adj,n);
    // for(int i=1;i<=n;i++) cout<<visited[i]<<" ";cout<<endl;
    int max1 = 0,count = 0;
    for(int i=1;i<=n;i++)
    {
      max1 = max(max1,visited[i]);
      if(visited[i]==0) count++;
    }
    if(max1+count>=k)
    {
      int i = 1,c = 1;
      if(max1>=k)
      {
        // cout<<"here"<<endl;
        for(int i=1;i<=n;i++) if(visited[i]>k || !visited[i]) visited[i] = 1;
      }
      else
      {
        // cout<<"here1"<<endl;
        // cout<<max1<<endl;
        while(max1<k && i<=n)
        {
          if(!visited[i]) {visited[i] = ++max1;}
          i++;
        }
        for(int i=1;i<=n;i++) if(!visited[i]) visited[i] = 1;
      }
      printf("Case #%d:",h);
      for(int i=1;i<=n;i++) printf(" %d",visited[i]);
      printf("\n");
    }
    else printf("Case #%d: Impossible\n",h);
    // for(int i=1;i<=n;i++) cout<<visited[i]<<" ";cout<<endl;
  }
  return 0;
}
