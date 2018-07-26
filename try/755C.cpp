#include<iostream>

using namespace std;

struct node
{
    bool connected;
};

int main()
{
    int n;
    cin>>n;
    struct node arr[10001];
    for(int i=0;i<n;i++)
    {
        arr[i].connected=false;
    }
    int temp,count=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(arr[temp-1].connected==false && arr[i].connected==false)
        {
            count++;
            arr[temp-1].connected=true;
            arr[i].connected=true;
        }
    }
    cout<<count<<endl;
    return 0;
}
