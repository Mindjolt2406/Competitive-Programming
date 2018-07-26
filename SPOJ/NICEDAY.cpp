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
  int a;
  int b;
  int c;
  int ans;
  void combine(node &n1,node &n2)
  {
    // The recursive formulae here
    //maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    if(n1.a <= n2.a && n1.b<=n2.b && n1.c<=n2.c)
    {
      a = n1.a;b = n1.b;c = n1.c;
      ans = n1.ans;
    }
    else if (n1.a >= n2.a && n1.b>=n2.b && n1.c>=n2.c)
    {
      a = n2.a;b = n2.b;c = n2.c;
      ans = n2.ans;
    }
    else ans = 0;

    // a = min(n1.a,n2.a);
    // b = min(n1.b,n2.b);
    // c = min(n1.c,n2.c);
  }
  void assign(tuple<int,int,int> value)
  {
    // Assigning values to the leaf nodes
    a = get<0>(value);
    b = get<1>(value);
    c = get<2>(value);
    ans = 1;
  }
};

// Define the NUL node structure here
node generate()
{
  node NUL;
  // Eg NUL.maxsum = 0
  NUL.a = NUL.b = NUL.c = INF;
  NUL.ans = 0;
  return NUL;
}

node build(node* tree,tuple<int,int,int>*l,int pos,int beg,int end,int k,int n)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos].
    tuple<int,int,int> value = l[pos-k/2];
    if(beg==end){tree[pos].assign(value);return tree[pos];} //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,l,2*pos+1,beg,mid,k,n);
    n2 = build(tree,l,2*pos+2,mid+1,end,k,n);
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

node find(node* tree,int l,int r,int beg,int end,int pos,int k,int n)
{
  //3 cases Go left, go right, split up
  int mid = (beg+end)/2;
  if(l==beg&&r==end) return tree[pos];
  if(r<=mid) return find(tree,l,r,beg,mid,2*pos+1,k,n);
  else if(l>mid) return find(tree,l,r,mid+1,end,2*pos+2,k,n);
  else
  {
    node n1,n2,n3;
    n1 = find(tree,l,mid,beg,mid,2*pos+1,k,n);
    n2 = find(tree,mid+1,r,mid+1,end,2*pos+2,k,n);
    n3.combine(n1,n2);
    return n3;
  }
}

int main()
{
  typedef struct node node;
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    tuple<int,int,int> l[n];
    for(int i=0;i<n;i++)
    {
      int a,b,c;
      sc(a);sc(b);sc(c);
      get<0>(l[i]) = a;
      get<1>(l[i]) = b;
      get<2>(l[i]) = c;
    }
    int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
    node* tree = (node*)calloc(k,sizeof(node));
    node NUL = generate();
    for(int i=0;i<k;i++)tree[i] = NUL;
    build(tree,l,0,0,(k+1)/2 - 1,k,n);
    printf("%d\n",find(tree,0,n-1,0,(k+1)/2 - 1,0,k,(k+1)/2).ans);
    // for(int i=0;i<k;i++) cout<<"i: "<<i<<" ans: "<<tree[i].ans<<" a: "<<tree[i].a<<" b: "<<tree[i].b<<" c: "<<tree[i].c<<endl;
    // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
    // int q;
    // cin>>q;
    // for(int i=0;i<q;i++)
    // {
    //   int q1;
    //   sc(q1);
    //   if(q1==0)
    //   {
    //     ll index,value;
    //     cin>>index>>value;
    //     update(tree,index-1,value,0,0,(k+1)/2 - 1);
    //     // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;;
    //   }
    //   else if(q1==1)
    //   {
    //     int beg,end;
    //     cin>>beg>>end;
    //     beg-=1;end-=1;
    //     cout<<find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).ans<<endl;
    //   }
    // }
  }
  return 0;
}
