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

  void init(vector<int> &v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;

int main()
{
  __;
  // Take the permutation, find the factoradic number
  // The factoradic number is equivalent to the rank
  // Add the two ranks, by adding the factoradic numbers (in a special way)
  // Get the sum and convert back
  
  // Conversions from permutation -> factoradic
  // Example -> 3 0 2 1
  // The rank of 3 is 3. So the first number is 3. Remove 3 from the set
  // Then consider 0, rank is 0. Remove 0.
  // You get 2, it's rank is 1. Take that
  // Lastly you have a 1, it's rank is 0.
  // The factoradic number is 3010. 3*3! + 0*2! + 1*1! + 0*0! = rank = 19

  // When you take a factoradic number, and you want to convert it back to a permutation, do the same thing
  // Given 3010 and an ordered sequence = {0,1,2,3}
  // The index 3 in the sequence is 3. Remove 3. Index 0 is 0. Remove 0. Index 1 is 2. Remove 2. Index 0 is 0. Remove 0.
  
  // Both of them can be implemented using a BIT and binary searching to get the desired rank
  // Assume you have a BIT, whose initial values are all 1. 
  // Now to get the rank(i),just look at the cumulative sum till i. While removing, make BIT[i] = 0. 

  // The reverse way is slightly harder. To get which element has a rank of i, we need to binary search and get the 
  // closest one which has a rank of i.
  // Go left, if the rank is too high
  // Go right, if the rank is too low
  // Go left, if the rank is same and record the answer

  // The only thing left is adding. How would you add two factoradic numbers? Let's look at it's representation once again
  // Let the ith digit be k. It has a value of k*i!. Let's forget about the carry for now. 
  // We're going to add k1*i! + k2*i! That's (k1+k2)*i!. If k1+k2 >= (i+1), we would take that 
  // Do this fast, now that you've thought about every single detail in this question

  // The main learning in this problem is that you can insert, delete and find the rank of numbers using a BIT if a[i]<=1e6

  int n;
  cin>>n;
  vector<int> v(n),w(n),x(n),y(n),z(n),p(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<n;i++) cin>>w[i];

  BIT bit1, bit2;

  vector<int> a(n);
  for(int i=1;i<n;i++) a[i] = 1;

  bit1.init(a);
  bit2.init(a);

  for(int i=0;i<n;i++)
  {
    int a = bit1.sum(v[i]);
    x[i] = a;
    bit1.inc(v[i],-1);
    a = bit2.sum(w[i]);
    y[i] = a;
    bit2.inc(w[i],-1);
  }

  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());

  // pr(x); pr(y);

  int carry = 0;
  for(int i=0;i<n;i++)
  {
    int a = x[i]+y[i]+carry;
    carry = a/(i+1);
    z[i] = a%(i+1);
    // t(i,z[i]);
  }

  // Converting it all back

  // pr(z);
  reverse(z.begin(),z.end());

  BIT bit3;
  bit3.init(a);

  for(int i=0;i<n;i++)
  {
    // Get rank from z[i];
    int beg = 0, end = n-1, ans = -1;
    while(beg<=end)
    {
      int mid = (beg+end)/2;
      int a = bit3.sum(mid);
      if(a==z[i]) {ans = mid; end = mid-1;}
      else if(a>z[i]) end = mid-1;
      else beg = mid+1;
    }
    bit3.inc(ans,-1);
    p[i] = ans;
  }

  for(int i=0;i<n;i++) cout<<p[i]<<" ";
  cout<<endl;
  return 0;
}

