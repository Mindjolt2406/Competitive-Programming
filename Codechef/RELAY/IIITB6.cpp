#include <bits/stdc++.h>
using namespace std;

int N = 500010;

int in1[1000010] = {0},in2[1000010] = {0},a[1000010] = {0}, b[1000010] = {0};


int main()
{
    int n;
    cin>>n;
    int l[n],m[n];
    for(int i=0;i<n;i++) {cin>>l[i]; in1[l[i]] = 1;}
    for(int i=0;i<n;i++) {cin>>m[i]; in2[m[i]] = 1;}

    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            if(in1[j]) a[i] = j;
        }
    }

    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)
        {
            if(in2[j]) b[i] = j;
        }
    }

    int max1 = -1;
    for(int i=0;i<=1000000;i++)
    {
        if(a[i]&&b[i]) max1 = max(max1,i);
    }    

    cout<<a[max1]+b[max1]<<endl;

}