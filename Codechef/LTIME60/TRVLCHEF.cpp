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

const int N = 1e5+10;

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      v.pu(mp(a,i));
    }
    sort(v.begin(),v.end());

    int index  = -1;
    for(int i=0;i<n;i++) if(v[i].se==0) index = i;

    int boo = 0;
    for(int i=0;i<n-1;i++) if(v[i+1].fi-v[i].fi >k) {boo = 1; break;} 
    if(boo) {cout<<"NO"<<endl; continue;}
    int boo1 = 0, boo2 = 0;

    if(index==0 || index==n-1)
    {
      cout<<"YES"<<endl;
      continue;
    }

    // t(index);
    int i=index+2;

    for(;i<n;i+=2)
    {
      if(v[i].fi - v[i-2].fi > k) {boo1 = 1;}
    }
    if(i==n) i--;
    else if(i==n+1) i = n-2;
    // t(i);
    for(;i>=index+1 && i>=0;i-=2)
    {
      if(i-2>=0)
      {
        // t(i,i-2);
        if(v[i].fi - v[i-2].fi > k) {boo1 = 1;}
      } 
    }
    // }

    i=index-2;
    // if(i>=0)
    // {
    for(;i>=0;i-=2)
    {
      if(i-2>=0 && v[i].fi - v[i-2].fi > k) {boo2 = 1;}
    }
    if(i==-1) i++;
    else if(i==-2) i = 1;
    for(;i<=index+1 && i<=n-1;i+=2)
    {
      if(i-2>=0 && v[i].fi - v[i-2].fi > k) {boo2 = 1;}
    }

    // }
    // t(boo1,boo2);
    if(boo1 && boo2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}

/*
1
3 5
0 3 -3

*/