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

using namespace std;

int block;
ll sum1 = 0;

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


// int bring(int dest,int src, int*counter,int*l,int boo)
// {
//   // cout<<"dest: "<<dest<<" src: "<<src<<" boo: "<<boo<<endl;
//   int count = 0;
//   while(dest!=src)
//   {
//     if((dest>src)) 
//     {
//       if(!boo)
//       {
//         if(src==-1) {src++;continue;}
//         if(counter[l[src]]==1) count--;
//         counter[l[src]]--;
//         src++;
//       }
//       else
//       {
//         src++;
//         counter[l[src]]++;
//         if(counter[l[src]]==1) count++;
//       }
//     }
//     else 
//     {
//       if(!boo)
//       {
//         src--;
//         if(src<=-1) break;
//         counter[l[src]]++;
//         if(counter[l[src]]==1) count++;
//       }
//       else
//       {
//         if(counter[l[src]]==1) count--;
//         counter[l[src]]--;
//         src--;
//       }
//     }
//   }
//   return count;
// }

void add(int*counter,int*l,int pos)
{
  int count = 0;
  ll c = counter[l[pos]];
  sum1-=c*c*l[pos];
  counter[l[pos]]++; c++;
  sum1+=c*c*l[pos];
  // if(counter[l[pos]]==1) count++;
  // return count;
}

void remove(int*counter,int*l,int pos)
{
  int count =0 ;
  ll c = counter[l[pos]];
  sum1-=c*c*l[pos];
  counter[l[pos]]--; c--;
  sum1+=c*c*l[pos];
  // if(counter[l[pos]]==0) count--;
  // return count;
}

int main()
{
  // ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  sc(n);
  int q;
  sc(q);
  int*l = new int[n];
  int*counter = (int*)calloc(1000001,sizeof(int));
  for(int i=0;i<n;i++) sc(l[i]);
  ll ans[q];
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
    // node p = arr[i];
    // int a = p.fi,b = p.se;
    // count+=bring(a,left,counter,l,0);
    // left = a;
    // count+=bring(b,right,counter,l,1);
    // right = b;
    // ans[p.i] = count;
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(left>a)
    {
      left--;
      add(counter,l,left);
    }
    while(left<a)
    {
      if(left==-1) {left++;continue;}
      remove(counter,l,left);
      left++;
    }
    while(right<b)
    {
      right++;
      add(counter,l,right);
    }
    while(right>b)
    {
      remove(counter,l,right);
      right--;
    }
    ans[p.i] = sum1;
  }

  for(int i=0;i<q;i++)
  {
    printf("%lld\n",ans[i]);
  }  
  return 0;
}

