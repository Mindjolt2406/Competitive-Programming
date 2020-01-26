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
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;

int block;
const int N = 1e5;
vector<int> v(N), counter(N);

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

int add(int pos)
{
  int count = 0;
  counter[v[pos]]++;
  if(counter[v[pos]]==1) count++;
  return count;
}

int remove(int pos)
{
  int count =0 ;
  counter[v[pos]]--;
  if(counter[v[pos]]==0) count--;
  return count;
}

int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>v[i];
  int q;
  cin>>q;
  vector<int> ans(q);
  vector<node> arr(q);

  for(int i=0;i<q;i++)
  {
    cin>>arr[i].fi>>arr[i].se;
    arr[i].fi--;arr[i].se--;
    arr[i].i = i;
  }

  block = int(sqrt(n));
  sort(arr.begin(),arr.end(),sorter);
  
  int left = 0,right = -1,count = 0;
  for(int i=0;i<q;i++)
  {
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(right<b)
    {
      right++;
      count+=add(right);
    }
    while(right>b)
    {
      count+=remove(right);
      right--;
    }
    while(left>a)
    {
      left--;
      count+=add(left);
    }
    while(left<a)
    {
      count+=remove(left);
      left++;
    }
    ans[p.i] = count;
  }

  for(int i=0;i<q;i++)
  {
    cout<<ans[i]<<endl;
  }  

  return 0;
}

