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

//#define NUL -1000000001
// #define NUL 0
using namespace std;

// Define the structure you want here
typedef struct
{
  int left;
  int right;
  int level;
  int ans;
}node;

void print(int* l,int n)
{
  int prod = 0;
  for(int i=0;i<n;i++)
  {
    if(i+1==pow(2,prod))
    {
      cout<<endl;
      prod++;
    }
    cout<<l[i]<<" ";
  }
  cout<<endl;
}

node build(node* tree,int*l,int pos,int beg,int end,int k,int n)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<endl;
  //Empty node
  node NUL;
  //Define The null pointer here
  // Eg. NUL.maxsum = 0;NUL.maxnumber = 0;
  NUL.left = 0;
  NUL.right = 0;
  NUL.level = -1;
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    //Add the leaf node here
    // if(beg==end){tree[pos].maxsum = l[pos-k/2];tree[pos].maxnumber = l[pos-k/2];return tree[pos];} //Leaf node
    if(beg==end){tree[pos].left = l[pos-k/2];tree[pos].right = l[pos-k/2];tree[pos].level = 0;tree[pos].ans = l[pos-k/2];return tree[pos];}
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,l,2*pos+1,beg,mid,k,n);
    n2 = build(tree,l,2*pos+2,mid+1,end,k,n);
    //This is where the recursive formulae come in
    // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
    tree[pos].level = max(n1.level,n2.level);
    tree[pos].left = n1.ans;
    tree[pos].right = n2.ans;
    if(tree[pos].level==-1) tree[pos] = NUL;
    else if(tree[pos].level==1) {tree[pos].level = 0;tree[pos].ans = tree[pos].left ^ tree[pos].right;}
    else if(tree[pos].level== 0) {tree[pos].level++;tree[pos].ans = tree[pos].right | tree[pos].left;}
    return tree[pos];
  }
  else //NULL version of the structure
  {
    return NUL;
  }
}

node update(node*tree,int index,int key,int pos,int beg,int end)
{
  int mid = (beg+end)/2;
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" mid: "<<mid<<endl;
  // Define The NUL pointer here(for the blank nodes)
  node NUL;
  NUL.left = 0;
  NUL.right = 0;
  NUL.level = -1;
  // NUL.maxsum = 0;NUL.maxnumber = 0;
  if(beg<=end)
  {
    // if(beg==end){tree[pos].maxnumber = key;tree[pos].maxsum = key;return tree[pos];} //Leaf nodes
    if(beg==end){tree[pos].left = key;tree[pos].right = key;tree[pos].level = 0;tree[pos].ans = key;return tree[pos];}
    int mid = (beg+end)/2;
    node n1,n2;
    if(index<=mid)
    {
      n1 = update(tree,index,key,2*pos+1,beg,mid);
      n2 = tree[2*pos+2];
      // The recursive formulae
      // tree[pos].level = max(n1.level,n2.level);
      tree[pos].left = n1.ans;
      tree[pos].right = n2.ans;
      if(tree[pos].level==-1) tree[pos] = NUL;
      else if(tree[pos].level== 0) {tree[pos].ans = tree[pos].left ^ tree[pos].right;}
      else if(tree[pos].level== 1) {tree[pos].ans = tree[pos].right | tree[pos].left;}
      // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
    }
    else
    {
      n1 = tree[pos*2+1];
      n2 = update(tree,index,key,2*pos+2,mid+1,end);
      // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
      // tree[pos].level = max(n1.level,n2.level);
      tree[pos].left = n1.ans;
      tree[pos].right = n2.ans;
      if(tree[pos].level==-1) tree[pos] = NUL;
      else if(tree[pos].level== 0) {tree[pos].ans = tree[pos].left ^ tree[pos].right;}
      else if(tree[pos].level== 1) {tree[pos].ans = tree[pos].right | tree[pos].left;}
    }
    return tree[pos];
  }
  else
  {
    return NUL;
  }
}

node find(node* tree,int l,int r,int beg,int end,int pos,int k,int n)
{
  //3 cases Go left, go right, split up
  int mid = (beg+end)/2;
  // cout<<"beg: "<<beg<<" end: "<<end;
  // cout<<" mid: "<<mid<<" pos: "<<pos<<endl;
  if(l==beg&&r==end) return tree[pos];
  if(r<=mid) return find(tree,l,r,beg,mid,2*pos+1,k,n);
  else if(l>mid) return find(tree,l,r,mid+1,end,2*pos+2,k,n);
  else
  {
    node n1,n2,n3;
    n1 = find(tree,l,mid,beg,mid,2*pos+1,k,n);
    n2 = find(tree,mid+1,r,mid+1,end,2*pos+2,k,n);
    // n3.level = max(n1.level,n2.level);
    n3.left = n1.ans;
    n3.right = n2.ans;
    if(n3.level==0) {n3.ans = n3.left ^ n3.right;}
    else if(n3.level== 1) {n3.ans = n3.right | n3.left;}
    // n3.maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // n3.maxnumber = max(n1.maxnumber,n2.maxnumber);
    return n3;
  }
}

int main()
{
  // cout<<"There are 2 queries to find the max, 1 <index> <insert value>, 2 <Left> <Right> "<<endl;
  int n,q;
  cin>>n>>q;
  n = pow(2,n);
  int l[n];
  for(int i=0;i<n;i++)cin>>l[i];
  int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
  node* tree = (node*)calloc(k,sizeof(node));
  node NUL; //Define the blank nodes
  // NUL.maxsum = 0;NUL.maxnumber = 0;
  NUL.left = 0;
  NUL.right = 0;
  NUL.level = -1;
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,l,0,0,(k+1)/2 - 1,k,n);
  // for(int i=0;i<k;i++)cout<<"i: "<<i<<" left: "<<tree[i].left<<" right: "<<tree[i].right<<" ans: "<<tree[i].ans<<" level: "<<tree[i].level<<endl;
  for(int i=0;i<q;i++)
  {
    int p,b;
    cin>>p>>b;
    p--;
    update(tree,p,b,0,0,(k+1)/2 - 1);
    // for(int i=0;i<k;i++)cout<<"i: "<<i<<" left: "<<tree[i].left<<" right: "<<tree[i].right<<" ans: "<<tree[i].ans<<" level: "<<tree[i].level<<endl;
    cout<<find(tree,0,n-1,0,(k+1)/2 - 1,0,k,(k+1)/2).ans<<endl;
    // char q1;
    // cin>>q1;
    // if(q1=='U')
    // {
    //   int index,value;
    //   cin>>index>>value;
    //   update(tree,index-1,value,0,0,(k+1)/2 - 1);
    //   // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;;
    // }
    // else if(q1=='Q')
    // {
    //   int beg,end;
    //   cin>>beg>>end;
    //   beg-=1;end-=1;
    //   cout<<find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).maxsum<<endl;
    // }
  }
  return 0;
}
