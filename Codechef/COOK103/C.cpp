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

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    vector<int> v(100001), w1(100001), w2(100001);
    vector<pair<int,int> > vp;
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;
      v[a]++;
      v[b+1]--;
      vp.push_back(mp(a,b));
    }

    int sum1 = 0, count = 0;
    for(int i=0;i<v.size();i++) 
    {
      sum1+=v[i];
      v[i] = sum1;
      if(v[i]==k) count++;
    }

    for(int i=0;i<v.size();i++)
    {
      if(v[i]==k) w1[i]++;
      if(v[i]==k+1) w2[i]++;
    }

    for(int i=1;i<w1.size();i++) {w1[i]+=w1[i-1]; w2[i]+=w2[i-1];}

    int max1 = -1;
    for(int i=0;i<vp.size();i++)
    {
      int a = vp[i].fi, b = vp[i].se;
      int countk1 = 0, countk2 = 0;
      if(a==0)
      {
        countk1 = w1[b];
        countk2 = w2[b];
      }
      else
      {
        countk1 = w1[b]-w1[a-1];
        countk2 = w2[b]-w2[a-1];
      }

      max1 = max(max1, count-countk1+countk2);
    }
    cout<<max1<<endl;
  }
  return 0;
}

