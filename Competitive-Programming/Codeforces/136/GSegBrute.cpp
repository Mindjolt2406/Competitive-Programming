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

// Define the structure you want here
struct node
{
  // vector<int> array;
  int* array;
  ll count;
  int size;
  void combine(node &no1,node &no2)
  {
    // The recursive formulae here
    //maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // int* v1 = (int*)calloc(no1.size,sizeof(int));
    // v1 = no1.array;
    // int* v2 = (int*)calloc(no2.size,sizeof(int));
    // v2 = no2.array;
    int* v1 = no1.array;
    int*v2 = no2.array;
    // array.clear();
    int n1 = no1.size, n2 = no2.size;
    int i=0,j=0,k = 0;
    count = no1.count+no2.count;
    while(k<size)
    {
      if(j==n2)
      {
        while(i<n1)
        {
          array[k] = v1[i];
          // array.pu(v1[i]);
          count+=(n2);
          i++;k++;
        }
        continue;
      }
      else if(i==n1)
      {
        while(j<n2)
        {
          array[k] = v2[j];
          // array.pu(v2[j]);
          j++;k++;
        }
        continue;
      }
      else if(v1[i]<=v2[j])
      {
        array[k] = v1[i];
        // array.pu(v1[i]);
        count+=j;
        i++;
      }
      else if(v1[i]>v2[j])
      {
        array[k] = v2[j];
        // array.pu(v2[j]);
        j++;
      }
      k++;
    }
    // free(v1);free(v2);
  }
  void assign(int value)
  {
    // Assigning values to the leaf nodes
    // array.clear();
    size = 1;
    array = new int[1];
    array[0] = value;
    count = 0;
  }
};

// Define the NUL node structure here
node generate()
{
  node NUL;
  // NUL.array.clear();
  // NUL.array.pu(INF);
  NUL.array = new int[1];
  NUL.array[0] = INF;
  NUL.count = 0;
  NUL.size = 1;
  // Eg NUL.maxsum = 0
  return NUL;
}

node build(node* tree,int*l,int pos,int beg,int end,int k,int n)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos].
    int value = l[pos-k/2];
    if(beg==end){tree[pos].assign(value);return tree[pos];} //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,l,2*pos+1,beg,mid,k,n);
    n2 = build(tree,l,2*pos+2,mid+1,end,k,n);
    tree[pos].size = n1.size+n2.size;
    tree[pos].array = (int*)calloc(tree[pos].size,sizeof(int));
    tree[pos].combine(n1,n2);
    return tree[pos];
  }
  else //NULL version of the structure
  {
    return NUL;
  }
}

// node update(node*tree,int index,int key,int pos,int beg,int end)
// {
//   int mid = (beg+end)/2;
//   // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" mid: "<<mid<<endl;
//   node NUL = generate();
//   if(beg<=end)
//   {
//     // Here take care of the leaf nodes condition. Also, remember to return tree[pos]
//     int value = l[pos-k/2];
//     if(beg==end){tree[pos].update(value);return tree[pos];} //Leaf node
//     int mid = (beg+end)/2;
//     node n1,n2;
//     if(index<=mid)
//     {
//       n1 = update(tree,index,key,2*pos+1,beg,mid);
//       n2 = tree[2*pos+2];
//       tree[pos].combine(n1,n2);
//     }
//     else
//     {
//       n1 = tree[pos*2+1];
//       n2 = update(tree,index,key,2*pos+2,mid+1,end);
//       tree[pos].combine(n1,n2);
//     }
//     return tree[pos];
//   }
//   else
//   {
//     return NUL;
//   }
// }

pair<node,int> find(node* tree,int l,int r,int beg,int end,int pos,int k,int n)
{
  //3 cases Go left, go right, split up
  int mid = (beg+end)/2;
  if(l==beg&&r==end) return mp(tree[pos],1);
  if(r<=mid) return find(tree,l,r,beg,mid,2*pos+1,k,n);
  else if(l>mid) return find(tree,l,r,mid+1,end,2*pos+2,k,n);
  else
  {
    pair<node,int> p1,p2;
    node n1,n2,n3;
    p1 = find(tree,l,mid,beg,mid,2*pos+1,k,n);
    p2 = find(tree,mid+1,r,mid+1,end,2*pos+2,k,n);
    n1 = p1.first;
    n2 = p2.first;
    n3.size = n1.size+n2.size;
    n3.array = (int*)calloc(n3.size,sizeof(int));
    n3.combine(n1,n2);
    if(p1.second==0) free(n1.array);
    if(p2.second==0) free(n2.array);
    return mp(n3,0);
  }
}

pair<node,int> get(node*tree,int beg,int end,int k)
{
  return find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2);
}

int main()
{
  typedef struct node node;
  int n;ll x;
  sc(n);scll(x);
  int l[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
  node* tree = (node*)calloc(k,sizeof(node));
  node NUL = generate();
  for(int i=0;i<k;i++)tree[i] = NUL;
  cout<<"here"<<endl;
  build(tree,l,0,0,(k+1)/2 - 1,k,n);
  cout<<"here"<<endl;
  // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
  // for(int i=0;i<k;i++)
  // {
  //   cout<<"i: "<<i<<" ans: "<<tree[i].count<<endl;
  //   for(int j=0;j<tree[i].size;j++) cout<<tree[i].array[j]<<" ";cout<<endl;
  // }
  // cout<<tree[0].count<<endl;
  int left = 0,right = 1;
  ll count = 0;
  while(right<n)
  {
    ll c;
    node n1,n2,n3;
    if(left==right) right++;
    if(right>=n) break;
    // cout<<"rogjt: "<<right<<endl;
    pair<node,int> p1,p2;
    p1 = get(tree,0,left,k);
    p2 = get(tree,right,n-1,k);
    n1 = p1.first;
    n2 = p2.first;
    n3.size = n1.size+n2.size;
    n3.array = (int*)calloc(n3.size,sizeof(int));
    n3.combine(n1,n2);
    c = n3.count;
    if(p1.second==0) free(n1.array);
    if(p2.second==0) free(n2.array);
    free(n3.array);
    // try {delete n1.array;
    // delete n2.array;}
    // delete n1;
    // delete n2;
    // delete n3;
    // cout<<"c: "<<c<<" x: "<<x<<endl;
    while(c>x)
    {
      // int c = get(tree,left,right,k);
      right++;
      if(left<=right)
      {
        if(left==right) right++;
        if(right>=n) break;
        node n1,n2,n3;
        // cout<<"rogjt: "<<right<<endl;
        pair<node,int> p1,p2;
        p1 = get(tree,0,left,k);
        p2 = get(tree,right,n-1,k);
        n1 = p1.first;
        n2 = p2.first;
        n3.size = n1.size+n2.size;
        n3.array = (int*)calloc(n3.size,sizeof(int));
        n3.combine(n1,n2);
        c = n3.count;
        if(p1.second==0) free(n1.array);
        if(p2.second==0) free(n2.array);
        free(n3.array);
        // delete n1.array;
        // delete [] n2;
        // delete [] n3;
        // cout<<"left: "<<left<<" right: "<<right<<" c: "<<c<<" count: "<<count<<endl;
        // cout<<"c: "<<c<<endl;
      }
      else break;
    }
    // if(boo) right++;
    count+=n-right;
    cout<<"left: "<<left<<" right: "<<right<<" count: "<<count<<endl;
    left++;
  }
  printf("%lld\n",count);
  // cout<<sizeof(tree)<<endl;
  return 0;
}
