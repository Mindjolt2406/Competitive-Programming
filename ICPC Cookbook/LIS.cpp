int bsearch(int k,int*memo,int n)
{
  int beg = 1,end = k-1,max1 = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(memo[mid]<n) {max1 = max(max1,mid);beg = mid+1;}
    else if(memo[mid]>=n) {end = mid-1;}
  }
  return max1;
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int*dp = new int[n];
  int*memo = new int[n+1];
  for(int i=0;i<n+1;i++) memo[i] = INF;
  // dp[0] = 1;
  if(n==1) printf("1\n");
  else
  {
    dp[0] = 1;
    memo[1] = l[0];
    for(int i=1;i<n;i++)
    {
      int c = bsearch(n,memo,l[i]);
      if(c==-1) {dp[i] = 1;memo[1] = min(l[i],memo[1]);}
      else {dp[i] = c+1;memo[c+1] = min(l[i],memo[c+1]);}
    }
    int max1 = 0;
    for(int i=0;i<n;i++) max1 = max(dp[i],max1);
    printf("%d\n",max1);
  }
  return 0;
}
