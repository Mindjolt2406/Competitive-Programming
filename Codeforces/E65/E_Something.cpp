// Read the question wrong
// I've implemented where f(l,r) = delete all the elements from l to r

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

const int N = 1e6+10;

typedef struct BIT //int
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;


int main()
{
  __;
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int counter[N] = {0};
  
  vector<int> right_sort(n),left_sort(n);

  int max1 = -1;
  for(int i=0;i<n;i++)
  {
    if(v[i]>=max1) {left_sort[i] = 1;max1 = v[i];}
    else break;
  }

  int min1 = INF;
  for(int i=n-1;i>=0;i--)
  {
    if(v[i]<=min1) {min1 = v[i]; right_sort[i] = 1;}
  }

  BIT bit;
  bit.init(N);

  int count1 = 0; // Keeps the count of number of numbers in the BIT

  // Inserting the elements into the BIT
  for(int i=0;i<n;i++)
  {
    if(right_sort[i]) 
    {
      count1++;
      bit.inc(v[i],1);
    } 
  }

  pr(left_sort);
  pr(right_sort);

  // The final answer
  ll count = count1; // Taken care of the l = -1 case

  // For every left sorted element, take the right sorted element, and do something
  for(int i=0;i<n;i++)
  {
    // First check if i is left sorted
    if(!left_sort[i]) break;

    int rank = bit.sum(v[i]-1); // Number of numbers < v[i]
    count+=count1-rank; // Count1 - rank = Number of numbers >=v[i]. They are potential rights

    // Delete this element, if it's right sorted
    if(right_sort[i]) {bit.inc(v[i],-1);count1--;}
  }

  cout<<count<<endl;
  return 0;
}

