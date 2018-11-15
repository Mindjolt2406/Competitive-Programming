#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    // Uncomment below lines to see contents of BITree[]
    // for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
    return BITree;
}


// Driver program to test above functions
int main()
{
    // int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    // int n = sizeof(freq)/sizeof(freq[0]);
    // int *BITree = constructBITree(freq, n);
    // cout << "Sum of elements in arr[0..5] is "
    //      << getSum(BITree, 5);
    //
    // // Let use test the update operation
    // freq[3] += 6;
    // updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]
    //
    // cout << "\nSum of elements in arr[0..5] after update is "
    //      << getSum(BITree, 5);
    int n,m;
    sc(n);sc(m);
    string s;
    for(int i=0;i<m;i++)
    {
      int a,b;
      sc(a);sc(b);
    }
    for(int i=0;i<n;i++)
    {
      if(i%2==0) s+='0';
      else s+='1';
    }
    cout<<s<<endl;
    // int sum1 = 0;
    // vector<pair<int,int> > v;
    // for(int i=0;i<n;i++)
    // {
    //   sum1+=pref[i];
    //   v.pu(mp(sum1,i));
    // }
    // sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());
    // int *ans = (int*)calloc(n,sizeof(int));
    // for(int i=0;i<n;i++)
    // {
    //   int c = v[i].second;
    //   // cout<<"c: "<<c<<endl;
    //   int sum1 = 0,sum2 = 0;
    //   for(int j=0;j<m;j++)
    //   {
    //     pair<int,int> p = v1[j];
    //     // cout<<"pair: "<<p.first<<" "<<p.second<<" sum1: ";
    //     if(p.first==0)
    //     {
    //       int c1 = getSum(bit,p.second);
    //       sum1+= c1*(p.second-c1);
    //     }
    //     else
    //     {
    //       int c1 = (getSum(bit,p.second) - getSum(bit,p.first-1));
    //       sum1 += c1*(p.second-p.first+1-c1);
    //     }
    //     // cout<<sum1<<endl;
    //   }
    //   updateBIT(bit,n,c,1);
    //   for(int j=0;j<m;j++)
    //   {
    //     pair<int,int> p = v1[j];
    //     // cout<<"pair: "<<p.first<<" "<<p.second<<" sum2: ";
    //     if(p.first==0)
    //     {
    //       int c1 = getSum(bit,p.second);
    //       sum2+= c1*(p.second-c1);
    //     }
    //     else
    //     {
    //       int c1 = (getSum(bit,p.second) - getSum(bit,p.first-1));
    //       sum2 += c1*(p.second-p.first+1-c1);
    //     }
    //     // cout<<sum2<<endl;
    //   }
    //   if(sum1>sum2) updateBIT(bit,n,c,-1);
    //   else ans[c] = 1;
    //   // for (int i=1; i<=n; i++) cout << bit[i] << " ";cout<<endl;
    //   // cout<<sum1<<" "<<sum2<<" "<<c<<endl;
    // }
    // for(int i=0;i<n;i++) cout<<ans[i];cout<<endl;
    return 0;
}
