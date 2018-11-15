#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(n) for(int i=0;i<n;i+=1)
#define prarr(a,n) rep(n,1) printf("%d ",a[i] );printf("%s\n"," " );
#define sc(a) scanf("%d",&a);
#define scl(a) scanf("%lld",&a);
#define scf(a) scanf("%f",&a);
#define ff first
#define ss second
int main()
{
        int t,n,m;
        // int ans1[310][310][610]={0};
        // return 0;
        sc(t);
        while(t--)
        {
                int ans[610]={0};
                bool grid[310][310]={0};
                sc(n);sc(m);
                string s;
                rep(n)
                {
                        cin>>s;
                        for(int j=0;j<s.length();j++)
                        grid[i][j]=s[j]-'0';
                }
                // rep(n)
                // {
                //         for(int j=0;j<m;j++)
                //         printf("%d ",grid[i][j] );
                //         printf("%s\n","" );
                // }
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<m;j++)
                        {
                                if(grid[i][j])
                                {
                                        for(int r=0;r<n;r++)
                                        {
                                                for(int c=0;c<m;c++)
                                                {
                                                        if(r!=i||c!=j)
                                                        {
                                                                if(grid[r][c]) ans[abs(r-i)+abs(c-j)]++;
                                                        }
                                                }
                                        }
                                }
                        }
                }
                for(int i=1;i<n+m-1;i++)
                {
                        printf("%d ",ans[i]/2 );
                }
                printf("\n");
        }
        return 0;
}