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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

map<int,int> d;

int input(int index)
{
  if(d.find(index)==d.end()) 
  {
    cout<<1<<" "<<index+1<<endl;
    fflush(stdout);
    int a;
    sc(a);
    d[index] = a;
    return a;
  }
  else return d[index];
}

int bsearch1(int value,int n)
{
  int beg = 0, end = n-1;
  int max1 = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    // t(beg,end,mid);
    int a = input(mid);
    if(value==a) {max1 = mid; beg = mid+1;}
    else end = mid-1;
  }
  return max1;
}

int bsearch2(int value,int n)
{
  int beg = 0, end = n-1;
  int min1 = INF;
  while(beg<=end)
  {
    int mid= (beg+end)/2;
    int a = input(mid);
    if(value==a) {min1 = mid;end = mid-1;}
    else beg = mid+1;
  }
  return min1;
}

int bsearch3(int n,int k) // n is the total size, k is the correct size
{
  int beg = 1, end = (n-1)/k;
  int min1 = -1,min2 = -1;
  int boo = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    mid*=k;
    if(boo==mid) break;
    int a = input(mid);
    int b = input(mid-1);
    if(a==b) {min1 = mid-1;end = mid/k -1;min2 = b;}
    else beg = mid/k+1;
    boo = mid;
  }
  // t(min1,n%k);
  int a = input(min1-(k-n%k));
  return a;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    // Get the values of l[0] and l[n-1]
    // Bsearch to get the left and right bounds
    // Get the value of k 
    // Bsearch for k
    int a = input(0);
    d[0] = 0;
    int b = input(n-1);
    d[n-1] = b;
    int x = bsearch1(a,n);
    x++;
    // t(x);
    // int y = bsearch2(b,n);
    // y = n-y;
    int b1 = input(n-x-1);
    int b2 = input(n-x);
    d[n-x-1] = b1;
    d[n-x] = b2;

    if(b!=b2) cout<<2<<" "<<b<<endl;
    else if(b==b1) cout<<2<<" "<<a<<endl;
    else {int a = bsearch3(n,x);cout<<2<<" "<<a<<endl;}
    fflush(stdout);
  }

  return 0;
}

/* 
1 11 5 7 6 5 5 7 6 6

*/