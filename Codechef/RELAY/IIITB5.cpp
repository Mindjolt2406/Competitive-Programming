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
#define t(...) GET_MACRO(VA_ARGS,t5, t4, t3, t2, t1)(VA_ARGS)
#define _ cout<<"here"<<endl;
#define int long long int

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

int isPalindrome(vector<int> v,int start,int end){
  for(int i=start;i<=end;i++){
    if(v[i] != v[end-i]) return 0;
  }
  return 1;
}

int getLongestPalSubStr(vector<int> v){
  int maxLen = 0;
  for(int i=0;i<v.size();i++){
    for(int j=i+1;j<v.size();j++){
      if(isPalindrome(v,i,j)){
        int len = j - i;
        if(len > maxLen) maxLen = len;
      }
    }
  }
  return maxLen;
}

int_32 main()
{
  int n,k,m;
  sc(n);sc(k);sc(m);
  for(int i=1;i<=n;i++) create(i);
  for(int i=0;i<k;i++)
  {
    int a,b;
    sc(a);sc(b);
    merge(a,b);
  }
  vector<int> v;
  for(int i=0;i<m;i++) 
  {
    int a;
    sc(a);
    v.pu(a);
  }
  map<int,int> d;
  for(int i=0;i<v.size();i++) 
  {
    int a = p[v[i]];
    // cout<<v[i]<<" "<<p[v[i]]<<endl;
    if (d.find(a) == d.end())
      d[a] = 1;
    else
      d[a] ++;
  }
  map <int, int> :: iterator it;
  int count = 0, boo = 0;
  for (it = d.begin(); it != d.end(); it++)
  {
    int a = it->first;
    int b = it->second;
    if (a % 2 == 1)
      boo = 1;
    // cout<<b<<endl;
    count += (b/2)*2;
  }
  count += boo;
  cout << count << endl;
	return 0;
}