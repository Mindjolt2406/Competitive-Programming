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

ll merger(vector<ll> &v,int l,int r)
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
    else if(v[i]<v[j])
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

ll sorter(vector<ll> &v,int l = 0, int r = n-1)
{
  ll count = 0;
  if(l<r) 
  {
    int mid = (l+r)>>1;
    count+=sorter(v,l,mid);
    count+=sorter(v,mid+1,r);
    count+=merger(v,l,r);
  }
  return count;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<sorter(v)<<endl;
  }
  return 0;
}

