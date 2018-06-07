#include<iostream>
#include<queue>
#include<utility>
using namespace std;


int main()
{
    int n,m,qu;
    cin>>n>>m>>qu;
    char l[n][m];
    int arr[n][m] = {0};
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>l[i][j];arr[i][j] = 1000001;}
    queue<pair <int,int> > q;
    int x,y;
    cin>>x>>y;
    //cout<<x<<" "<<y;
    q.push(make_pair(x-1,y-1));
    x-=1;y-=1;
    //cout<<q.front().first;
    if(l[x][y]=='*')
    {
        for(int i=0;i<qu;i++)cout<<-1<<endl;
        return 0;}
    arr[x][y] = 0;
    //cout<<arr[x][y]<<endl;
    while(!q.empty())
    {
        //cout<<q.size()<<endl;
        x = q.front().first;y = q.front().second;
        if(l[x][y]=='*')arr[x][y] = -1;
        else
        {
            if((x+1<n && arr[x+1][y]>arr[x][y]+1)){arr[x+1][y] = arr[x][y]+1;q.push(make_pair(x+1,y));}
            if((x-1>=0 && arr[x-1][y]>arr[x][y]+1)){arr[x-1][y] = arr[x][y]+1;q.push(make_pair(x-1,y));}
            if((y+1<m && arr[x][y+1]>arr[x][y]+1)){arr[x][y+1] = arr[x][y]+1;q.push(make_pair(x,y+1));}
            if((y-1>=0 && arr[x][y-1]>arr[x][y]+1) ){arr[x][y-1] = arr[x][y]+1;q.push(make_pair(x,y-1));}
        }
        q.pop();
    }
    //for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<arr[i][j]<<" ";cout<<endl;}
    for(int i=0;i<qu;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;b-=1;
        if(arr[a][b]!=1000001)cout<<arr[a][b]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
