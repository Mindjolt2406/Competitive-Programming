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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int*l;
int k;

long long int size;
bitset<10000010> bs;
vi prime;
int*visited;

void sieve(ll upperbound)
{
  visited = (int*)calloc(upperbound,sizeof(int));
  visited[1] = 1;
  ll size = upperbound + 1;
  for(ll i = 2;i< size;i++)
  {
    visited[i]+=2;
    for(ll j = 2*i;j<size;j+=i) {visited[j]++;}
  }
}
// Define the structure you want here
struct node
{
  ll sum;
  void combine(node &n1,node &n2)
  {
    // The recursive formulae here
    //maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    sum = n1.sum + n2.sum;
  }
  void assign(ll value)
  {
    // Assigning values to the leaf nodes
    sum = value;
  }

};

// Define the NUL node structure here
node generate()
{
  node NUL;
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
    tree[pos].combine(n1,n2);
    return tree[pos];
  }
  else //NULL version of the structure
  {
    return NUL;
  }
}

node update(node*tree,int index,ll key,int pos,int beg,int end)
{
  int mid = (beg+end)/2;
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" mid: "<<mid<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos]
    // int value = l[pos-k/2];
    if(beg==end){tree[pos].assign(key);return tree[pos];} //Leaf node
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
  sieve(1000010);
  // for(int i=1;i<=30;i++) t(i,visited[i]);
  typedef struct node node;
  int n,q;
  sc(n);sc(q);
  set<int> s;
  l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  for(int i=0;i<n;i++)
  {
    if(l[i]!=1) s.insert(i);
  }
  k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
  node* tree = (node*)calloc(k,sizeof(node));
  node NUL = generate();
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,l,0,0,(k+1)/2 - 1,k,n);
  // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
  for(int i=0;i<q;i++)
  {
    int q1;
    sc(q1);
    if(q1==1)
    {
      int left,right;
      sc(left);sc(right);   
      set<int> :: iterator it = s.lower_bound(left-1);
      vector<int> v;
      if(it==s.end()) continue;
      for(;*it<right && it!=s.end();it++)
      {
        int i = *it;
        int c = l[i];
        // t(c,visited[c],left,right);
        if(visited[c]==1 || visited[c]==2) v.pu(i);
        update(tree,i,visited[c],0,0,(k+1)/2 - 1);
        l[i] = visited[c];
      }

      for(int i=0;i<v.size();i++) s.erase(v[i]);
      // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;;
    }
    else if(q1==2)
    {
      int beg,end;
      sc(beg);sc(end);
      beg-=1;end-=1;
      printf("%lld\n",find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).sum);
      // cout<<find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).sum<<endl;
    }
  }
  return 0;
}
