#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;


int main()
{
    long long int t;cin>>t;
    for(int h=0;h<t;h++)
    {
        long long int n;
        cin>>n;
        long long int l[n];
        for(long long int i=0;i<n;i++)cin>>l[i];
        sort(l,l+n);
        reverse(l,l+n);
        long long int count = 0;
        long long int m[100001] = {1};
        for(int i=1;i<100001;i++)m[i] = (m[i-1]*i)%MOD;
        for(long long int i=0;i<n;i++)
        {
            //cout<<m[i+1]<<" "<<l[i]<<endl;
            count+=((l[i]*m[i+1])%MOD);
            //cout<<count<<endl;
            count%=MOD;
        }
        cout<<count<<endl;
    }
}
