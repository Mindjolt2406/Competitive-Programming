#include <bits/stdc++.h>
#define mid (tl+tr)/2
#define mod 1000000007
#define fain(arr) for(int i=0;i<n;i++)cin>>arr[i];
#define faio(arr) for(int i=0;i<n;i++)cout<<arr[i]<<" ";
#define all(x) x.begin(),x.end()
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define bugv(n1) if(DEBUG)cout<<#n1<<" is "<<n1<<'\n';
#define FILE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl '\n'
#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pi acos(-1)
#define sz(x) ((int)x.size())
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
#define DEBUG true
using namespace std;

int main() {
 // FILE;
  SPEED;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    ll d;
    cin>>n>>d;
    ll arr[n];
    fain(arr);
    ll start = arr[0];
    sort(arr,arr+n);
    bool flag=true;
    for(int i=1;i<n;i++)
    {
       if(arr[i]-arr[i-1]>d)
       {
         flag=false;
         break;
       }
    }
    if(!flag)
    {
      cout<<"NO"<<endl;
      continue;
    }
    bool visited[n];
    for(int i=0;i<n;i++)visited[i]=false;
    auto p = lower_bound(arr,arr+n,start);
    visited[p-arr]=true;

    //right first
    bool flagr=true;
    while(p!=arr+(n-1))
    {
      // cout<<*p<<endl;
       auto np = upper_bound(arr,arr+n,*p+d);
       np--;
       if(np==p)
        {
          flagr=false;
          break;
        }
        p=np;
        visited[p-arr]=true;
    }

    visited[n-1]=true;

    int prev = n-1;
    int current=n-1;

    int kk = 0;

    while(visited[kk]==true&&(kk<=n-1))kk++;
    // cout<<kk;
    if(kk!=n)
    while(true&&flagr)
    {

      while((visited[current]==true)&&current>=kk)
      {
         current--;
      }
      // bugv(prev);
      // bugv(current);
      if(arr[prev]-arr[current]>d)
      {
        // bugv(flagr);
        flagr=false;
        break;
      }
      prev=current;
      visited[current]=true;
      if(current==kk)break;
   }

   //left
   bool flagl=true;
   p = lower_bound(arr,arr+n,start);
   // cout<<*p;
   for(int i=0;i<n;i++)visited[i]=false;
    visited[p-arr]=true;
   while(p!=arr)
   {
      auto np = lower_bound(arr,arr+n,*p-d);
      if(np==p)
      {
        // bugv(flagl);
        flagl=false;
        break;
      }
      p=np;
      visited[p-arr]=true;
   }
   // for(int i=0;i<n-1;i++)cout<<visited[i]<<" ";
   // cout<<endl; 
   visited[0]=true;
   int another=n-1;
   while(visited[another]==true&&(another>=0))another--;
   prev=0;
   current=0;
   // if(another!=-1);
   // bugv(flagr);
   while(true&&flagl)
   {
      while((visited[current]==true)&&current<=n-1)
      {
        current++;
      }

      if(arr[current]-arr[prev]>d)
      {
         flagl=false;
         break;
      }

      prev=current;
      visited[current]=true;

      if(current==another)break;
   }

   if(flagl|flagr)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

    
  } 

}