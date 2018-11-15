#include<bits/stdc++.h>
#define pu push_back
using namespace std;

struct node
{
  int colour;
  int size;
  int index;
  map<int,int> check;
  node()
  {
    colour = 0;
    size = 0;
    index = 0;
  }
};

int key = 0;
node* newNode(int colour,int size,int index)
{
  node *n = new node;
  n->colour = 0;
  n->index = 0;
  n->size = 0;
  return n;
}

void print(vector<node*> *adj,int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<i<<": "<<endl;
    for(int j=0;j<adj[i].size();j++)cout<<"Size: "<<adj[i][j]->size<<" colour: "<<adj[i][j]->colour<<" index: "<<adj[i][j]->index<<endl;
  }
}

int N = 4000000;

void register1(vector<node*> *adj, node* *store, int index, int **visited,int colour,int i,int j)
{
  cout<<"Entered i: "<<i<<" j: "<<j<<" colour: "<<colour<<" index: "<<key<<endl;
  node* p;
  p = newNode(0,0,0);
  store[key]->colour = colour;
  store[key]->size = 0;
  store[key]->index = key;
  // store[key] = p;
  adj[index].pu(store[index]);
  adj[key].pu(store[index]);
  visited[i][j] = -1*key;
  cout<<"colour: "<<store[key]->colour;
  key++;
  cout<<" key: "<<key<<endl;
}
int shrink(vector<node*> *adj, node* *store, int **visited,int **l, int i,int j,int n,int m, int index)
{
  if(visited[i][j]==1) return 0;
  cout<<"i: "<<i<<" j: "<<j<<" key: "<<key<<" colour: "<<store[index]->colour<<endl;
  int size = 1;
  visited[i][j] = 1;
  if(i-1>=0 && l[i-1][j]!=store[index]->colour && !visited[i-1][j])
  {
    register1(adj,store,index,visited,l[i-1][j],i-1,j);
  }
  else if(i-1>=0) size+=shrink(adj,store,visited,l,i-1,j,n,m,index);
  if(i+1<n && l[i+1][j]!=store[index]->colour && !visited[i+1][j])
  {
    register1(adj,store, index, visited, l[i+1][j],i+1,j);
  }
  else if(i+1<n) size+=shrink(adj,store,visited,l,i+1,j,n,m,index);
  if(j-1>=0 && l[i][j-1]!=store[index]->colour && !visited[i][j-1])
  {
    register1(adj,store, index, visited, l[i][j-1], i, j-1);
  }
  else if(j-1>=0) size+=shrink(adj,store,visited,l,i,j-1,n,m,index);
  if(j+1<m && l[i][j+1]!=store[index]->colour && !visited[i][j+1])
  {
    register1(adj,store, index, visited, l[i][j+1], i, j+1);
  }
  else if(j+1<m) size+=shrink(adj,store,visited,l,i,j+1,n,m,index);
  return size;
}

int main()
{
  typedef struct node node;
  int a,b;
  cin>>a>>b;
  set<int> s;
  set<int> ::iterator it;
  int **l = new int*[a];
  for(int i=0;i<a;i++) l[i] = new int[b];
  int **visited = new int*[a];
  for(int i=0;i<a;i++) visited[i] = new int[b];
  for(int i=0;i<a;i++) for(int j=0;j<b;j++) visited[i][j] = 0;
  for(int i=0;i<a;i++) for(int j=0;j<b;j++) {cin>>l[i][j];}
  vector<node*>*adj = new vector<node*>[N];
  node* *store = new node*[N];
  node NUL;
  for(int i=0;i<N;i++)
  {
    // node* NUL;
    store[i] = newNode(0,0,0);
    // store[i] = NUL;
  }

  for(int i=0;i<a;i++)
  {
    for(int j=0;j<b;j++)
    {
      if(visited[i][j]!=1)
      {
        int c = visited[i][j];
        node* temp;
        temp = newNode(0,0,0);
        if(c==0)
        {
          temp->index = key;
          temp->colour = l[i][j];
          store[key] = temp;
          key++;
        }
        else
        {
          node* temp = store[-1*c];
        }
        temp->size = shrink(adj,store,visited,l,i,j,a,b,temp->index);
      }
    }
  }
  int n = key-1;
  print(adj,n);
  return 0;
}
