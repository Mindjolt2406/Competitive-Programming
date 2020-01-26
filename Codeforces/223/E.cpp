/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;


// Define the structure you want here
struct node
{
  int open_count = 0, closed_count = 0, ans = 0, un_open = 0, un_closed = 0; 
  void combine(node &n1,node &n2)
  {
    // The recursive formulae here
    //maxsum = max(max(n1.maxsum,n2.maxsum),n1.maxnumber+n2.maxnumber); //The recursive formulae
    open_count = n1.open_count+n2.open_count;
    closed_count = n1.closed_count + n2.closed_count;
    int temp = min(n1.un_open, n2.un_closed);
    un_open = n2.un_open + n1.un_open - temp;
    un_closed = n1.un_closed + n2.un_closed - temp;
    ans = n1.ans + n2.ans + 2*temp;
  }
  void assign(char value)
  {
    // Assigning values to the leaf nodes
    if(value=='(')
    {
      open_count++;
      un_open++;
    }
    else
    {
      closed_count++;
      un_closed++;
    }
  }
};

// Define the NUL node structure here
node generate()
{
  node NUL;
  // Eg NUL.maxsum = 0
  return NUL;
}

node build(node* tree,string &s,int pos,int beg,int end,int k,int n)
{
  // cout<<"pos: "<<pos<<" beg: "<<beg<<" end: "<<end<<" pos-k/2: "<<pos-k/2<<endl;
  node NUL = generate();
  if(beg<=end)
  {
    if (pos-k/2>=n)return NUL;
    // Here take care of the leaf nodes condition. Also, remember to return tree[pos].
    char value = s[pos-k/2];
    if(beg==end){tree[pos].assign(value);return tree[pos];} //Leaf node
    int mid = (beg+end)/2;
    node n1,n2;
    n1 = build(tree,s,2*pos+1,beg,mid,k,n);
    n2 = build(tree,s,2*pos+2,mid+1,end,k,n);
    tree[pos].combine(n1,n2);
    return tree[pos];
  }
  else //NULL version of the structure
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
    // t(n1.open_count,n1.closed_count, n1.ans, n1.un_open,n1.un_closed);
    // t(n2.open_count,n2.closed_count, n2.ans, n2.un_open,n2.un_closed);
    // t(n3.open_count,n3.closed_count, n3.ans, n3.un_open,n3.un_closed);
    return n3;
  }
}

int main()
{
  __;
  typedef struct node node;
  string s;
  cin>>s;
  int n = s.size();
  int k = 2*pow(2,ceil(log(n)/log(2.0)))-1;
  node* tree = (node*)calloc(k,sizeof(node));
  node NUL = generate();
  for(int i=0;i<k;i++)tree[i] = NUL;
  build(tree,s,0,0,(k+1)/2 - 1,k,n);
  // for(int i=0;i<k;i++) t(i,tree[i].open_count,tree[i].closed_count, tree[i].ans, tree[i].un_open,tree[i].un_closed);
  // for(int i=0;i<k;i++)cout<<"i: "<<i<<" maxsum: "<<tree[i].maxsum<<" maxnumber: "<<tree[i].maxnumber<<endl;
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int beg,end;
    cin>>beg>>end;
    beg-=1;end-=1;
    cout<<find(tree,beg,end,0,(k+1)/2 - 1,0,k,(k+1)/2).ans<<endl;
  }
  return 0;
}

