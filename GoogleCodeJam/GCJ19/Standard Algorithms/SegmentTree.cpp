#include<iostream>
#include<cmath>
#include<algorithm>
//#define NUL -1000000001
#define NUL 0
using namespace std;

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

int build(int* tree,int*l,int pos,int beg,int end,int k,int n)
{
  cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<" k: "<<k<<endl;
  if(beg<=end)
  {if (pos-k/2>=n)return NUL;
  if(beg==end ){tree[pos] = l[pos-k/2];return l[pos-k/2];}
  // else if(beg==end) return NUL;
  int mid = (beg+end)/2;
  tree[pos] = max(build(tree,l,2*pos+1,beg,mid,k,n),build(tree,l,2*pos+2,mid+1,end,k,n));
  return tree[pos];}
  else return NUL;
}

int update(int*tree,int index,int key,int pos,int beg,int end)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<endl;
  if(beg==end){tree[pos] = key;return tree[pos];}
  int mid = (beg+end)/2;
  if(index<=mid) tree[pos] = max(update(tree,index,key,2*pos+1,beg,mid),tree[2*pos+2]);
  else tree[pos] = max(tree[pos*2+1],update(tree,index,key,2*pos+2,mid+1,end));
  return tree[pos];
}

int find(int* tree,int l,int r,int beg,int end,int pos,int k,int n)
{
  //3 cases Go left, go right, split up
  int mid = (beg+end)/2;
  cout<<"beg: "<<beg<<" end: "<<end;
  cout<<" mid: "<<mid<<endl;
  if(l==beg&&r==end) return tree[pos];
  if(r<=mid) return find(tree,l,r,beg,mid,2*pos+1,k,n);
  else if(l>mid) return find(tree,l,r,mid+1,end,2*pos+2,k,n);
  else
  {
    return max(find(tree,l,mid,beg,mid,2*pos+1,k,n),find(tree,mid+1,r,mid+1,end,2*pos+2,k,n));
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
  int* tree = (int*)calloc(k,sizeof(int));
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,l,0,0,k/2-1,k,n);
  for(int i=0;i<k;i++)cout<<tree[i]<<" ";
  cout<<endl;
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int q1;
    cin>>q1;
    if(q1==1)
    {
      int index,value;
      cin>>index>>value;
      update(tree,index-1,value,0,0,k/2-1);
      // for(int j=0;j<k;j++)cout<<tree[j]<<" ";
      // cout<<endl;
    }
    else if(q1==2)
    {
      int beg,end;
      cin>>beg>>end;
      beg-=1;end-=1;
      cout<<find(tree,beg,end,0,k/2-1,0,k,n)<<endl;
    }
  }
  return 0;
}
