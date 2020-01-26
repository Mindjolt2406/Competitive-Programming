#include<iostream>
#include<vector>
using namespace std;
const int size=1050;
typedef pair <int,int> pi;
int a[size][size],b[size][size];
vector <pi> g[size];
bool visited[size];
int color[size];
bool flag;
void dfs(int src,int col)
{
    visited[src] = 1;
    color[src]=col;
    for(auto i:g[src])
    {
        if(!visited[i.first])
            dfs(i.first,col*i.second);
        else
        {
            if(i.second*col!=color[i.first])
            {
                flag=0;
                return;
            }
        }
        if(!flag)
            return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<size;i++)
            g[i].clear(),visited[i]=color[i]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>a[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cin>>b[i][j];
        flag=1;
        for(int i=0;i<n&&flag;i++)
        {
            for(int j=0;j<n&&flag;j++)
            {
                if(a[i][j]==b[i][j] && a[j][i]==b[j][i] && a[i][j]==b[j][i])
                    continue;
                else if(a[i][j]==b[i][j] && a[j][i] == b[j][i])
                g[i].push_back({j,1}),g[j].push_back({i,1});
                else if(a[i][j]==b[j][i] && a[j][i]==b[i][j])
                g[i].push_back({j,-1}),g[j].push_back({i,-1});
                else
                {
                    flag=0;
                }
            }
        }
        if(!flag)
        {
            cout<<"No\n";
            continue;
        }
        for(int i=0;i<n&&flag;i++)
        if(!visited[i])
        dfs(i,1);
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
