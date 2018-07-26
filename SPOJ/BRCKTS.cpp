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
  int open;
  int close;
  int ans;
  void combine(node &n1,node &n2)
  {
    // The recursive formulae here
    //maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    close = n1.close + max(n2.close-n1.open,0);
    open = n2.open + max(n1.open-n2.close,0);
    if(!close && !open) ans = 1;
    else ans = 0;
  }
  void assign(char value)
  {
    // Assigning values to the leaf nodes
    if(value=='(') {open = 1;close = 0;}
    else {open = 0;close = 1;}
    ans = 0;
  }
};

// Define the NUL node structure here
node generate()
{
  node NUL;
  // Eg NUL.maxsum = 0
  NUL.open = 0;
  NUL.close = 0;
  NUL.ans = 0;
  return NUL;
}

node build(node* tree,string l,int pos,int beg,int end,int k,int n)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos].
    char value = l[pos-k/2];
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

node update(node*tree,int index,char key,int pos,int beg,int end)
{
  int mid = (beg+end)/2;
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" mid: "<<mid<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos]
    if(beg==end)
    {
      if(tree[pos].open) {tree[pos].open = 0;tree[pos].close = 1;}
      else {tree[pos].open = 1;tree[pos].close = 0;}
      return tree[pos];
    } //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    if(index<=mid)
    {
      n1 = update(tree,index,key,2*pos+1,beg,mid);
      n2 = tree[2*pos+2];
      tree[pos].combine(n1,n2);
    }
    else
    {
      n1 = tree[pos*2+1];
      n2 = update(tree,index,key,2*pos+2,mid+1,end);
      tree[pos].combine(n1,n2);
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
  int count = 1;
  // string s1;
  // char temp[1000000];
  int n;
  while(scanf("%d",&n)==1)
  {
    // s1 = temp;
    // int n;
    // n = stoi(s1);
    string s;
    scr(s);
    // int l[n];
    // for(int i=0;i<n;i++) sc(l[i]);
    int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
    node* tree = (node*)calloc(k,sizeof(node));
    node NUL = generate();
    for(int i=0;i<k;i++)tree[i] = NUL;
    build(tree,s,0,0,(k+1)/2 - 1,k,n);
    // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
    int q;
    sc(q);
    printf("Test %d:\n",count);
    for(int i=0;i<q;i++)
    {
      int q1;
      sc(q1);
      if(q1!=0)
      {
        // ll index,value;
        // cin>>index>>value;
        update(tree,q1-1,0,0,0,(k+1)/2 - 1);
        // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;;
      }
      else
      {
        // int beg,end;
        // cin>>beg>>end;
        // beg-=1;end-=1;
        if(find(tree,0,n-1,0,(k+1)/2 - 1,0,k,(k+1)/2).ans) printf("YES\n");
        else printf("NO\n");
      }
    }
    count++;
  }
  return 0;
}
