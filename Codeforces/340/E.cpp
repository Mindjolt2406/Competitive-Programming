// WHAT I'VE DONE IS CRAP
// NOT ANYMORE
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
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;

int block,xorcount = 0;
const int N = 5e6+10;
ll counterl[N] = {0}, counterr[N] = {0};
// int counter[N] = {0};
vector<int> prefl(1e5+10),prefr(1e5+10);
int n;

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

ll add(int k,vector<int> &v,int pos,int l,int r,bool boo)
{
  ll count = 0;
  int xorcnt;
  counterr[prefr[pos]]++;
  counterl[prefl[pos]]++;
  // counter[prefl[pos]]++;

  if(boo) // Adding from the right
  {
    if(pos<n-1) xorcnt = prefr[pos+1];
    else xorcnt = 0;
    count+=counterr[k^xorcnt];
  }
  else
  {
    if(pos>0) xorcnt = prefl[pos-1];
    else xorcnt = 0;
    count+=counterl[k^xorcnt];
  }

  // t(l,r,count);
  // for(int i=0;i<=3;i++) t(i,cosunter[i]);
  return count;
}

ll remove(int k,vector<int> &v,int pos,int l,int r,bool boo)
{
  ll count =0 ;
  int xorcnt;

  if(boo) // Removing from the right
  {
    if(pos<n-1) xorcnt = prefr[pos+1];
    else xorcnt = 0;
    count-=counterr[k^xorcnt];
  }
  else
  {
    if(pos>0) xorcnt = prefl[pos-1];
    else xorcnt = 0;
    count-=counterl[k^xorcnt];
  }

  counterl[prefl[pos]]--;
  counterr[prefr[pos]]--;
  // t(l,r,count);
  return count;
}

int main()
{
  __;
  int q,k;
  cin>>n>>q>>k;
  vector<int>  v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  // Construct the left and right prefix arrays
  prefl[0] = v[0];
  prefr[n-1] = v[n-1];

  for(int i=1;i<n;i++) prefl[i] = prefl[i-1]^v[i];
  for(int i=n-2;i>=0;i--) prefr[i] = prefr[i+1]^v[i];

  
  vector<ll> ans(q);
  vector<node> arr(q);
  for(int i=0;i<q;i++)
  {
    cin>>arr[i].fi>>arr[i].se;
    arr[i].fi--;arr[i].se--;
    arr[i].i = i;
  }

  block = int(sqrt(n));
  sort(arr.begin(),arr.end(),sorter);
  
  int left = -1,right = -1;
  ll count = 0;
  for(int i=0;i<q;i++)
  {
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(left>a)
    {
      left--;
      count+=add(k,v,left,left,right,0);
    }
    while(left<a)
    {
      if(left==-1) {left++;continue;}
      count+=remove(k,v,left,left+1,right,0);
      left++;
    }
    while(right<b)
    {
      right++;
      count+=add(k,v,right,left,right,1);
    }
    while(right>b)
    {
      count+=remove(k,v,right,left,right,1);
      right--;
    }
    ans[p.i] = count;
  }

  for(int i=0;i<q;i++)
  {
    cout<<ans[i]<<endl;
  }  

  return 0;
}

