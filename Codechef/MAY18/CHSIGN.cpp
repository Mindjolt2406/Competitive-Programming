#include<bits/stdc++.h>
#define pu push_back
#define INF 1000000001
using namespace std;

struct node
{
  long long int marked = 0;
  long long int left = 0;
  long long int right = 0;
  long long int data = 0;
};

node* generate(long long int key)
{
  node* p = new node;
  p->left = -1;
  p->right = -1;
  p->data = key;
  p->marked = 0;
  return p;
}

void solve(vector<long long int> w,vector < long long int > &w1)
{
  long long int n = w.size();
  // for(int i=0;i<w.size();i++) cout<<w[i]<<" ";
  // cout<<endl;
  long long int dp[n];
  for(long long int i=0;i<n;i++) { dp[i] = INF;} // Initialising the DP array to take care of all invalid states
  dp[0] = w[0]; dp[1] = w[1];
  for(long long int i=2;i<n;i++)
  {
    dp[i] = w[i] + min(dp[i-1],dp[i-2]);
  }
  long long int minsum = min(dp[n-1],dp[n-2]);
  // cout<<"minsum: "<<minsum<<endl;
  long long int c = n;
  // for(int i=0;i<n;i++) cout<<dp[i]<<" ";
  // cout<<endl;
  while (minsum)
  {
    c = (minsum==dp[c-1]) ? c-1:c-2;
    // cout<<"c: "<<c<<endl;
    minsum-=w[c];
    w1.pu(c);
  }
}

int main()
{
  typedef struct node node;
  long long int t;
  cin>>t;
  while(t--)
  {
    long long int n;
    cin>>n;
    vector < node* > v;
    for(long long int i=0;i<n;i++)
    {
      long long int key;
      cin>>key;
      node* p = generate(key);
      v.pu(p);
    }
    // Fixing subarrays of length 2
    for(long long int i=0;i<n-1;i++)
    {
      if(v[i]->data > v[i+1]->data) v[i]->marked = 1;
      else if(v[i+1]->data > v[i]->data ) v[i+1]->marked = 1;
      else {v[i]->marked = 1; v[i+1]->marked = 1;}
    }
    // Giving 1's and 0's to form chains
    for(long long int i=0;i<n;i++)
    {
      if(i==0 && v[i]->marked == 0) v[i]->left = 1;
      if(i==n-1 && v[i]->marked == 0) v[i]->right = 1;
      if(v[i]->marked)
      {
        long long int c = 0, d = 0;
        if(i-1>=0 && !v[i-1]->marked) c = v[i-1]->data;
        if(i+1<n && !v[i+1]->marked) d = v[i+1]->data;

        if(c && d && c+d>=v[i]->data)
        {
          if(c) v[i-1]->right = 0;
          if(d) v[i+1]->left = 0;
        }
        else
        {
          if(c) v[i-1]->right = 1;
          if(d) v[i+1]->left = 1;
        }
      }
      else continue;
    }
    // for(int i=0;i<n;i++) cout<<v[i]->marked<<" "<<v[i]->left<<" "<<v[i]->right<<endl;
    // Solving for each chain
    long long int i = 0;
    while(i<n)
    {
      if(v[i]->marked) {i++;continue;}
      if(v[i]->left==1 && v[i]->right==1) v[i]->data*=-1;
      else if(v[i]->left==1 && v[i]->right==0) // Chain starts
      {
        vector < long long int > w,w1;
        long long int k = i;
        while(v[i]->left!=0 || v[i]->right!=1) {w.pu(v[i]->data);v[i]->data*=-1;i+=2;}
        // cout<<"IDK"<<endl;
        w.pu(v[i]->data);
        v[i]->data*=-1;
        solve(w,w1);
        // for(int i=0;i<w1.size();i++) cout<<w1[i]<<" ";
        // cout<<endl;
        for(long long int i=0;i<w1.size();i++) v[w1[i]*2 + k]->data *= -1;
      }
      i++;
    }
    // Prlong long inting the final output
    for(long long int i=0;i<n;i++) cout<<v[i]->data<<" ";
    cout<<endl;
  }
  return 0;
}


/*
In short
1. Take every pair of adjacent elements and mark the higher one
2. For every marked node give a pair value to it's adjacent unmarked nodes if any
3. This pair value for every unmarked node, left and right corresponds to whether the left or right marked node would be okay if it becomes negative
4. Use DP for every chain you see
5. If you see an unmarked node as 1,1 leave it negative
*/

/*
1
5
10 1 2 10 5

*/
