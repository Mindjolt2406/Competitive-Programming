#include<iostream>
#include<cmath>
#include<algorithm>
//#define NUL -1000000001
// #define NUL 0
using namespace std;

// Define the structure you want here
typedef struct
{

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
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    //Add the leaf node here
    if(beg==end){tree[pos].maxsum = l[pos-k/2];tree[pos].maxnumber = l[pos-k/2];return tree[pos];} //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,l,2*pos+1,beg,mid,k,n);
    n2 = build(tree,l,2*pos+2,mid+1,end,k,n);
    //This is where the recursive formulae come in
    // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
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
  NUL.maxsum = 0;NUL.maxnumber = 0;
  if(beg<=end)
  {
    if(beg==end){tree[pos].maxnumber = key;tree[pos].maxsum = key;return tree[pos];} //Leaf nodes
    int mid = (beg+end)/2;
    node n1,n2;
    if(index<=mid)
    {
      n1 = update(tree,index,key,2*pos+1,beg,mid);
      n2 = tree[2*pos+2];
      tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
    }
    else
    {
      n1 = tree[pos*2+1];
      n2 = update(tree,index,key,2*pos+2,mid+1,end);
      tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
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
    n3.maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    n3.maxnumber = max(n1.maxnumber,n2.maxnumber);
    return n3;
  }
}

int main()
{
  // cout<<"There are 2 queries to find the max, 1 <index> <insert value>, 2 <Left> <Right> "<<endl;
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++)cin>>l[i];
  int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
  node* tree = (node*)calloc(k,sizeof(node));
  node NUL; //Define the blank nodes
  NUL.maxsum = 0;NUL.maxnumber = 0;
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,l,0,0,(k+1)/2 - 1,k,n);
  // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    char q1;
    cin>>q1;
    if(q1=='U')
    {
      int index,value;
      cin>>index>>value;
      update(tree,index-1,value,0,0,(k+1)/2 - 1);
      // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;;
    }
    else if(q1=='Q')
    {
      int beg,end;
      cin>>beg>>end;
      beg-=1;end-=1;
      cout<<find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).maxsum<<endl;
    }
  }
  return 0;
}
