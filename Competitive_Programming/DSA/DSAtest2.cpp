#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
//#define NUL -1000000001
// #define NUL 0
#define MAX 10000000
#define MIN -10000000
using namespace std;

// Define the structure you want here
typedef struct
{
  int minimum;
  int index;
  int pos;
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
  NUL.minimum = MAX;NUL.index = MAX;
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    if(beg==end){tree[pos].minimum = l[pos-k/2];tree[pos].index = pos-k/2;return tree[pos];} //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,l,2*pos+1,beg,mid,k,n);
    n2 = build(tree,l,2*pos+2,mid+1,end,k,n);
    // cout<<"pos: "<<pos<<"n1: "<<n1.maxsum<<"n2: "<<n2.maxsum<<endl;
    tree[pos].minimum = min(n1.minimum,n2.minimum);
    int c;
    if(n1.minimum<=n2.minimum) c = n1.index;
    else c = n2.index;
    tree[pos].index = c;
    // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
    tree[pos].pos = pos;
    return tree[pos];
  }
  else //NULL version of the structure
  {
    return NUL;
  }
}

node update(node*tree,int*l,int index,int key,int pos,int beg,int end,int k)
{
  int mid = (beg+end)/2;
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" mid: "<<mid<<endl;
  node NUL;
  NUL.minimum = MAX;NUL.index = MAX;
  if(beg<=end)
  {
    if(beg==end){tree[pos].minimum += key;l[pos - k/2] += key;cout<<"pos: "<<pos<<endl;return tree[pos];}
    int mid = (beg+end)/2;
    node n1,n2;
    if(index<=mid)
    {
      n1 = update(tree,l,index,key,2*pos+1,beg,mid,k);
      n2 = tree[2*pos+2];
      // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
      tree[pos].minimum = min(n1.minimum,n2.minimum);
      int c;
      if(n1.minimum<=n2.minimum) c = n1.index;
      else c = n2.index;
      tree[pos].index = c;
    }
    else
    {
      n1 = tree[pos*2+1];
      n2 = update(tree,l,index,key,2*pos+2,mid+1,end,k);
      // tree[pos].maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
      // tree[pos].maxnumber = max(n1.maxnumber,n2.maxnumber);
      tree[pos].minimum = min(n1.minimum,n2.minimum);
      int c;
      if(n1.minimum<=n2.minimum) c = n1.index;
      else c = n2.index;
      tree[pos].index = c;
    }
    tree[pos].pos = pos;
    return tree[pos];
  }
  else
  {
    return NUL;
  }
}

node find(node* tree,int l,int r,int beg,int end,int pos,int k,int n,vector < int > &v)
{
  //3 cases Go left, go right, split up
  int mid = (beg+end)/2;
  // cout<<"beg: "<<beg<<" end: "<<end;
  // cout<<" mid: "<<mid<<" pos: "<<pos<<endl;
  if(l==beg&&r==end) {cout<<"Entered"<<endl;v.push_back(pos);return tree[pos];}
  if(r<=mid) return find(tree,l,r,beg,mid,2*pos+1,k,n,v);
  else if(l>mid) return find(tree,l,r,mid+1,end,2*pos+2,k,n,v);
  else
  {
    node n1,n2,n3;
    n1 = find(tree,l,mid,beg,mid,2*pos+1,k,n,v);
    n2 = find(tree,mid+1,r,mid+1,end,2*pos+2,k,n,v);
    // n3.maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    // n3.maxnumber = max(n1.maxnumber,n2.maxnumber);
    n3.minimum = min(n1.minimum,n2.minimum);
    int c;
    if(n1.minimum<=n2.minimum) {c = n1.index;}
    else {c = n2.index;}
    n3.index = c;
    n3.pos = pos;
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
  node NUL;
  NUL.minimum = MAX;NUL.index = MAX;
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,l,0,0,(k+1)/2 - 1,k,n);
  for(int i=0;i<k;i++)cout<<"i: "<<i<<" minimum: "<<tree[i].minimum<<" index: "<<tree[i].index<<endl;
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int q1;
    cin>>q1;
    // if(q1=='U')
    // {
    //   int index,value;
    //   cin>>index>>value;
    //   update(tree,index-1,value,0,0,(k+1)/2 - 1);
    //   for(int i=0;i<k;i++)cout<<"i: "<<i<<" minimum: "<<tree[i].minimum<<" index: "<<tree[i].index<<endl;
    // }
    vector <int> v;
    if(q1==1) // Moveright
    {
      int beg,end = (k+1)/2 - 1;
      cin>>beg; // beg = i, end = n-1 for moveright
      node n = find(tree,beg+1,end,0,(k+1)/2 - 1,0,k,(k+1)/2,v);
      int d;
      for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
      cout<<endl;
      // sort(v.begin(),v.end());
      // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
      // cout<<endl;
      for(int i=0;i<v.size();i++)
      {
        int pos = v[i];
        int min1 = tree[pos].minimum;
        cout<<"i: "<<i<<" v[i]: "<<v[i]<<" minimum: "<<tree[pos].minimum<<" something: "<<tree[(k+1)/2 -1 + beg].minimum<<endl;
        if(tree[(k+1)/2 -1 + beg].minimum<tree[pos].minimum) continue;
        cout<<"i: "<<i<<" v[i]: "<<v[i]<<" minimum: "<<tree[pos].minimum<<endl;
        int min2 = tree[pos].index;
        while(2*pos+2<k)
        {
          if(tree[2*pos+1].minimum==min1) {min2 = tree[pos].index; pos = 2*pos +1;}
          else if(tree[2*pos+1].minimum<=tree[(k+1)/2 -1 + beg].minimum) {min1 = tree[(k+1)/2 -1 + beg].minimum; pos = 2*pos +1;}
          else pos = 2*pos+2;
        }
        cout<<"pos: "<<pos<<endl;
        // d = pos;
        d = pos-(k+1)/2+1;
        break;
      }
      cout<<"d-beg: "<<d-beg<<" d: "<<d<<endl;
      update(tree,l,d,d-beg,0,0,(k+1)/2 - 1,k);
      for(int i=0;i<k;i++)cout<<"i: "<<i<<" minimum: "<<tree[i].minimum<<" index: "<<tree[i].index<<endl;
    }
    else if(q1==2) //Moveleft
    {
      int beg = 0,end;
      cin>>end;
      node n = find(tree,beg,end-1,0,(k+1)/2 - 1,0,k,(k+1)/2,v);
      int c = n.pos;
    }
  }
  return 0;
}
/*
8
6 10 9 14 13 12 9 1

*/
