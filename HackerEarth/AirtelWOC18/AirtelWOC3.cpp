#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<iterator>
using namespace std;

int max1 = 0;

void add1(vector<int> adj[],int u,int v)
{

    cout<<u-1<<" "<<v-1<<endl;
    cout<<"Vector: ";
    for(int j=0;j<adj[u].size();j++)cout<<adj[u][j]<<" ";
    cout<<endl;
}
int finder(vector <int> adj[])
{
  
}

int main()
{
    int n,k;
    cin>>n>>k;
    int l[n];
    for(int i=0;i<n;i++)cin>>l[i];
    vector<int> adj[n];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    for(int i=0;i<n;i++)
    {
      cout<<i<<" : ";
      for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";
      cout<<endl;
    }
    int* visited = (int*)calloc(n,sizeof(int));
    //finder(adj,visited,l,0,k);
    cout<<max1<<endl;
}
