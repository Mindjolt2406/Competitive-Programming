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

pair<int,int> finder(vector<int> adj[],int* visited,int*l,int u,int k)
{
    map <int,vector < pair <int,int> > > d;
    map <int,vector < pair <int,int> > > :: iterator it;
    cout<<"u: "<<u<<endl;
    //if(visited[u])return make_pair(0,0);
    if(adj[u].empty())return make_pair(1,l[u]);
    else if(adj[u].size()==1)
    {
      if(l[u]%k==0) {if (max1<1) max1 = 1; return make_pair(1,l[u]);}
      else return make_pair(1,l[u]);
    }
    //This loop constructs a hash table to keep track of the mods
    for(int i=0;i<adj[u].size();i++)
    {
        pair <int,int> p;
        p = finder(adj,visited,l,adj[u][i],k); //Each pair has a distance and a total
        cout<<"pair: "<<p.first<<" "<<p.second<<" i: "<<adj[u][i]<<" u: "<<u<<endl;
        int c = p.second;
        if(u==0)cout<<c%k<<" This ";
        if(d.find(c%k)==d.end()) d[c%k].push_back(p);
        else if((c==0 || (k%2==0 && c==k/2)) && d[c%k].size()==1) {d[c%k].push_back(p);sort(d[c%k].begin(), d[c%k].end());reverse(d[c%k].begin(),d[c%k].end());}
        else if((c==0 || (k%2==0 && c==k/2)) && d[c%k].size()==2 && c>d[c%k][1].first) {d[c%k][1] = p;sort(d[c%k].begin(), d[c%k].end());reverse(d[c%k].begin(),d[c%k].end());}
        else if(d[c%k][0].first<c)d[c%k][0] = p;
    }
    cout<<endl;
    // if(u==0)
    // {
    //   cout<<"D "<<d.size()<<endl;
    //   for(it=d.begin();it!=d.end();it++) cout<<(it->first)<<" "<<d[it->first].first<<" "<<d[it->first].second;
    //   cout<<endl;
    // }
    int dist = -1;
    int total = 0;
    int c = l[u]%k;
    visited[u] = 1;
    //This loop is supposed to calculate the max 2 heights and add them s.t height1+height2+adj[u]%k==0
    cout<<d.size()<<" D "<<" u "<<u<<endl;
    int e = 0;
    for(int i=0;i<k -l[u]%k + 1;i++)
    {
        if(d.find(i)!=d.end() && d.find(k-l[u]%k-i)!=d.end() && dist<d[i][0].first+d[k-l[u]%k-i][0].first)
        {
            dist = d[i][0].first+d[k-l[u]%k-i][0].first;
            total = d[i][0].second+d[k-l[u]%k - i][0].second;
            e = i;
        }
    }
    // 0modk+0modk = 0modk
    if(d.find(0)!=d.end())
    {
      if(dist<d[0][1].first + d[0][0].first)
      {
        dist = d[0][0].first+d[0][1].first;
        total = d[0][1].second+d[0][1].second;
        e = 0;
      }
    }
    //(k/2)modk + (k/2)modk =
    if (k%2==0 && d.find(k/2)!=d.end())
    {
      int r = k/2;
      if(dist<d[r][1].first + d[r][0].first)
      {
        dist = d[r][0].first+d[r][1].first;
        total = d[r][1].second+d[r][1].second;
        e = r;
      }
    }
    cout<<"Dictionary: "<<endl;
    for(it=d.begin();it!=d.end();it++)
    {
      for(int j=0;j<it->second.size();j++)cout<<(it->second)[j].first<<" "<<it->second[j].second<<endl;
    }
    cout<<"---"<<endl;
    dist++;
    total+=l[u];
    if(max1<dist)max1 = dist;
    cout<<"dist: "<<dist<<" total : "<<total<<" u: "<<u<<endl;
    return make_pair(dist,total);
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
    finder(adj,visited,l,0,k);
    cout<<max1<<endl;
}
