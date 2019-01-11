// Simple DSU, implement Kruskal if necessary
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

const int N = 300100;
int p[N], sz[N];

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x);
  y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  for(int i=1;i<=n;i++) create(i);
  for(int i=0;i<k;i++)
  {
    string a;
    cin>>a;
    if(a=="Q")
    {
      int b;
      sc(b);
      cout<<sz[find(b)]<<endl;
    }
    else
    {
      int b,c;
      sc(b);sc(c);
      merge(b,c);
    }
  }
	return 0;
}