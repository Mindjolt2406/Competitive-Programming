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

int getNumber(vector<int> &v,int k)
{
  if(v.size()<=5)
  {
    vector<int>w = v;
    sort(w.begin(),w.end()); 
    return w[k];
  }

  // Find median of medians
  vector<vector<int> > w;
  for(int i=0;i<v.size();i+=5)
  {
    vector<int> x;
    for(int j=0;j<=min(4,(int)v.size()-1);j++)
    {
      x.pu(v[i+j]);
    }
    sort(x.begin(),x.end()); // Takes constant time
    w.pu(x);
  }

  // vector of the middles
  vector<int> middle;
  for(int i=0;i<w.size();i++)
  {
    if(i==w.size()-1) middle.pu(w[i][w.size()/2]);
    else middle.pu(w[i][2]); 
  }

  int pivot = getNumber(middle,middle.size()/2);

  vector<int> a,b;
  int countPivot = 0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]<pivot) a.pu(v[i]);
    else if(v[i]==pivot) countPivot++;
    else b.pu(v[i]);
  }

  if(a.size()>k) return getNumber(a,k);
  else if(countPivot+a.size()>k) return pivot;
  else return getNumber(b,k-a.size()-countPivot);
}

int main()
{
  
  __;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int ans = getNumber(v,v.size()/2);
  cout<<ans<<endl;
  return 0;
}

