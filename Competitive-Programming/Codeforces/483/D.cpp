#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  vector < vector <int> > v;
  vector <int> w1;
  w1.pu(0);
  v.pu(w1);
  vector <int> w;
  w.pu(1);
  v.pu(w);
  for(int i=1;i<5001;i++)
  {
    vector<int> w;
    w.pu(1);
    for(int j=0;j<v[i].size()-1;j++)
    {
      w.pu(v[i][j]^v[i][j+1]);
    }
    w.pu(1);
    v.pu(w);
  }
  vector <vector <int> > v1;
  for(int i=0;i<5001;i++)
  {
    vector<int> w1;
    for(int j=0;j<v[i].size();j++)
    {
      if(v[i][j]) w1.pu(j);
    }
    v1.pu(w1);
  }
  int counter = 0;
  for(int i=0;i<v1.size();i++)
  {
    counter+=v[i].size();
    cout<<i<<" : ";
    for(int j=0;j<v1[i].size();j++) cout<<v1[i][j]<<" ";
    cout<<endl;
  }
  int maxarr[5001] = {0};
  for(int i = n-1;i>=0;i--)
  {
    int max1 = -1;
    for(int j= 1;j<=n-i;j++) // j<= n-1-i+1 // Size
    {
      int x = 0;
      for(int k=0;k<j;k++)
      {
        if(v1[j][k]) x^=l[k+i];
        max1 = max(x,max1);
      }
    }
    maxarr[i] = max1;
  }
  for(int i=0;i<n;i++) cout<<maxarr[i]<<" ";
  cout<<endl;
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    if(maxarr[a]!=maxarr[b+1]) cout<<maxarr[a]<<endl;
    else
    {
      int max2 = l[b];
      int beg = a-1,end = b-1;
      while(beg<=end)
      {
        int mid = (beg+end)/2;
        if(l[mid]==l[a]) beg = mid+1;
        else if(l[mid]>=max2) {end = mid-1;max2= l[mid];}
      }
      cout<<max2<<endl;
    }
  }
  cout<<"Counter: "<<counter<<endl;
  return 0;
}

/*
1. Build that 0,1 matrix -> O(n^2)
2. For each size , use the 0,1 matrix as reference and compute the xors
3. The computation will be done in the order - all subarrays starting with index n-1, then index n-2 and so on
4. There will be a array max[] which will store the maximums
5. For each query (a,b), do a binary search for the maximum if max[a]==max[b+1]

*/
