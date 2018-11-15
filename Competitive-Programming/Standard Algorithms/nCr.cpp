long long int c(int n,int k) //Not my code
{
    long long int ans=1;
    k=k>n-k?n-k:k;
    int j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}

// Less constraints, but higher usage of repeated result=\
];

int dp[max][max];
//Initialise array elements with zero
int nCr(int n, int r)
{
       if(n==r) return dp[n][r] = 1; //Base Case
       if(r==0) return dp[n][r] = 1; //Base Case
       if(r==1) return dp[n][r] = n;
       if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
       return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}


