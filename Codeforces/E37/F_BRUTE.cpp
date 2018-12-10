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
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

long long int size;
bitset<10000010> bs;
vi prime;
int*visited;

void sieve(ll upperbound)
{
  visited = (int*)calloc(upperbound,sizeof(int));
  visited[1] = 1;
  ll size = upperbound + 1;
  for(ll i = 2;i< size;i++)
  {
    visited[i]+=2;
    for(ll j = 2*i;j<size;j+=i) {visited[j]++;}
  }
}

int main()
{
  sieve(1000010);
  int n,k;
  sc(n);sc(k);
  int*l  = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  for(int i=0;i<k;i++)
  {
    int a;
    sc(a);
    int b,c;
    sc(b);sc(c);
    if(a==1)
    {
      for(int i=b-1;i<c;i++)
      {
        l[i] = visited[l[i]];
      }
    }
    else
    {
      int sum1 = 0;
      for(int i=b-1;i<c;i++)
      {
        sum1+=l[i];
      }
      cout<<sum1<<endl;
    }
  }
  return 0;
}

