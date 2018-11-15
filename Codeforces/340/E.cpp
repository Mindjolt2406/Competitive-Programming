// WHAT I'VE DONE IS CRAP
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
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t3, t2, t1)(__VA_ARGS__)


using namespace std;

int block,xorcount = 0;

typedef struct node
{
  int first,second,i;
}node;

bool sorter(const node &a, const node &b) 
{ 
  if(a.fi/block < b.fi/block) return true;
  else if(a.fi/block> b.fi/block) return false;
  else
  {
    if(a.se<b.se) return true;
    return false;
  }
} 

int add(int k,int*l,int pos)
{
  int count = 0;
  xorcount^=l[pos];
  if(xorcount==k) count++;
  else count--;
  return count;
}

int remove(int k,int*l,int pos)
{
  int count =0 ;
  xorcount^=l[pos];
  if(xorcount==k) count++;
  else count--;
  return count;
}

int main()
{
  int n,q,k;
  sc(n);sc(q);sc(k);
  int*l = new int[n];
  // int*counter = (int*)calloc(1000001,sizeof(int));
  for(int i=0;i<n;i++) sc(l[i]);
  int ans[q];
  node *arr = new node[q];
  for(int i=0;i<q;i++)
  {
    sc(arr[i].fi);
    sc(arr[i].se);
    arr[i].fi--;arr[i].se--;
    arr[i].i = i;
  }

  block = int(sqrt(n));
  sort(arr,arr+q,sorter);
  
  int left = -1,right = -1,count = 0;
  for(int i=0;i<q;i++)
  {
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(left>a)
    {
      left--;
      count+=add(k,l,left);
    }
    while(left<a)
    {
      if(left==-1) {left++;continue;}
      count+=remove(k,l,left);
      left++;
    }
    while(right<b)
    {
      right++;
      count+=add(k,l,right);
    }
    while(right>b)
    {
      count+=remove(k,l,right);
      right--;
    }
    ans[p.i] = count;
  }

  for(int i=0;i<q;i++)
  {
    printf("%d\n",ans[i]);
  }  

  return 0;
}

