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
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

void bsearch(int n,int boo)
{
  int beg = 0,end = n-1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    cout<<1<<" "<<mid+1<<endl;
    cout<<1<<" "<<(mid+n/2)%n+1<<endl;
    int a,b;
    cin>>a>>b;
    int c = (b-a);
    if(abs(c)<=1) {cout<<2<<" "<<mid+1<<" "<<(mid+n/2)%n+1<<endl;return;}
    if(boo) c*=-1;
    if(c<0)
    {
      beg = mid+1;
    }
    else
    {
      end = mid-1;
    }
  }
}

int main()
{
  __;
  int n;
  cin>>n;
  cout<<1<<" "<<1<<endl;
  cout<<1<<" "<<n<<endl;
  int a,b;
  cin>>a>>b;
  int boo = 0;
  boo = (int) a>b;
  bsearch(n,boo);
  return 0;
}

