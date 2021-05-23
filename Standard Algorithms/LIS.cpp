int computeLIS(vector<int> &v, vector<int> &lis) // Both n length arrays
{
  int n = v.size();
  // vector<int> lis(n);
  vector<int> I(n+1);

  I[0] = -INF;
  for(int i=1;i<=n;i++) I[i] = INF;

  int lenLIS = 0;

  for(int i=0;i<n;i++)
  {
    int beg = 0, end = n;
    while(beg <= end)
    {
      int mid = (beg+end) >> 1;
      if(I[mid] < v[i])
      {
        beg = mid+1;
      }
      else end = mid-1;
    }

    I[beg] = v[i];
    lis[i] = beg;
    if(beg > lenLIS) lenLIS = beg;
  }

  return lenLIS;
}