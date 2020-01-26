// I don't know why this is TLE!!!!!! Giving up rn!
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


int n;
const int N = 22;
// vector<vector<ll>> w(N,vector<ll>(2)); // Keeper of arrays
vector<vector<ll>> x(N,vector<ll>(2)); // Keeper of junctions
int d[(int)6e6] = {0};
vector<int> logger(6e5);

ll C2(ll x) // Returns nC2
{ 
  return (x*(x-1))/2;
}

ll merger(vector<ll> &v,int l,int r) // Merge in merge sort
{
  int mid = (l+r)>>1;

  vector<ll> w(r-l+1);
  int i = l, j = mid+1, k = 0;
  ll count = 0;

  while(k<r-l+1)
  {
    if(j==r+1)
    {
      while(i<=mid)
      {
        w[k] = v[i];
        count+=(j-mid-1);
        i++; k++;
      }
      continue;
    }
    else if(i==mid+1)
    {
      while(j<=r)
      {
        w[k] = v[j];
        j++; k++;
      }
    }
    else if(v[i]<=v[j])
    {
      w[k] = v[i];
      count+=(j-mid-1);
      i++;
    }
    else if(v[j]<=v[i])
    {
      w[k] = v[j];
      j++;
    }
    k++;
  }


  for(int k=0;k<r-l+1;k++)
  {
    v[k+l] = w[k];
  }

  return count;
}

ll merger2(vector<ll> &v,int l, int r)
{
  vector<ll> w(r-l+1);
  for(int i=l;i<=r;i++) 
  {w[i-l] = v[i];}

  int left = 0, right = w.size()-1;
  int mid = (left+right)>>1;
  for(int i=0;i<=mid;i++) swap(w[i],w[i+mid+1]);
  ll a = merger(w, 0, w.size() - 1);
  return a;
}

// ll sorter2(vector<ll> &v,int l=0, int r=n-1) // Divide and Conquer step in merge sort
// {
//   ll count = 0;
//   int n = v.size();
//   if(l<r) 
//   {
//     int mid = (l+r)>>1;
//     ll a = 0,b = 0,c = 0;
//     a = sorter2(v,l,mid);
//     b = sorter2(v,mid+1,r);
//     c = merger(v,l,r);
//     count+=a+b+c;
//     int i = n-1-r, j = n-1-l;
//     // t((int)(i*2e6 + j));
//     d[] = count;
//   }
//   return count;
// }

ll sorter(vector<ll> &v,int l=0, int r=n-1) // Divide and Conquer step in merge sort
{
  ll count = 0;
  if(l<r) 
  {
    int mid = (l+r)>>1;
    ll a = 0,b = 0,c = 0, d = 0;
    a = sorter(v,l,mid);
    b = sorter(v,mid+1,r);
    d = merger2(v,l,r);
    c = merger(v,l,r);
    // a and b are parts of the arrays


    // int junc = log2(r-l+1);
    int junc = logger[r-l+1];
    // junc = number of trailing 0s in the binary representation + 1
    x[junc][0] += c;
    x[junc][1] += d;

    count+=a+b+c;

    // int sz = log2(r-l+1);
    // w[sz][0] += count;
    // w[sz][1] += C2(r-l+1)-count;
  }
  return count;
}


int main()
{
  // __;
  for(int i=0;i<logger.size();i++) logger[i] = log2(i);
  scanf("%d",&n);
  vector<ll> v(pow(2,n));
  vector<ll> w(pow(2,n));
  for(int i=0;i<pow(2,n);i++) {scanf("%lld",&v[i]); w[i] = v[i];}

  sorter(v,0,pow(2,n)-1);

  vector<int> keepjunc(22); // Tells what junction is reversed and what isn't

  // If the juntions of size i are reversed, then the junctions representing arrays of sizes 1 to i get reversed

  int q;
  scanf("%d",&q);
  while(q--)
  {
    int a;
    cin>>a;
    for(int i=0;i<=a;i++) 
    {
      // keeparr[i]^=1;
      keepjunc[i]^=1;
    }

    // Add arrays of size i, but add all junctions representing arrays of sizes greater than i

    ll count = 0;
    // count+=w[a][keeparr[a]];
    for(int i=1;i<22;i++) count+=x[i][keepjunc[i]];

    printf("%lld\n",count);
  }
  return 0;
}

/*
2
2 1 4 3
5
0 1 2 0 2

*/