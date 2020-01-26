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
#define int ll

using namespace std;

const int N = 1e5+10;
ll sum = 0;
vector<int> adj[N] = {};
set<int> s;
int mx = -1;
int freq[N] ={0}; // Gives the frequency of the ith colour
int ff[N] = {0}; // Gives the number of colours with that frquency
int ff2[N] = {0}; // Gives the sum of the colours with that frequency
int col[N] = {0};
int sz[N] = {0};
ll ans[N] = {0};
bool big[N] = {0};


void add(int u,int p, int val)
{
  if(val==1)
  {
    // t(ff[freq[col[u]]],u);
    freq[col[u]]++;
    ff[freq[col[u]]]++;
    ff2[freq[col[u]]]+=col[u];
    ff[freq[col[u]]-1]--;
    ff2[freq[col[u]]-1]-=col[u];
    if(ff[freq[col[u]]-1]==0) {s.erase(freq[col[u]]-1);}

    if(mx==freq[col[u]]) sum+=col[u];
    else if(mx<freq[col[u]]) 
    {
      s.insert(freq[col[u]]);
      sum = col[u];
      mx = freq[col[u]];
    }
  }
  else
  {
    ff[freq[col[u]]]--;
    ff2[freq[col[u]]]-=col[u];
    if(ff[freq[col[u]]]==0) 
    {
      s.erase(freq[col[u]]);
      if(freq[col[u]]==mx) 
      {
        sum-=col[u]; 
        if(!s.empty())
        {
          mx = *s.rbegin(); 
          sum = ff2[mx];
        }
        else mx = 0;
      } 
    }
    freq[col[u]]--;
    ff[freq[col[u]]]++;
    ff2[freq[col[u]]]+=col[u];
  }
  for(auto v : adj[u]) if(!big[v] && v-p) add(v,u,val); 
}

int dfs1(int u,int par = -1) // Gets the size of the subtree
{
  // t(u);
  int count = 1;
  for(auto v : adj[u]) if(v-par) count+=dfs1(v,u);
  sz[u] = count;
  return count;
}

void dfs(int u,int par = -1, bool keep = false)
{
  // cout<<"u: "<<u<<endl;
  // t(u);
  int bigChild = -1;
  int max1 = -1;
  for(auto v : adj[u])
  {
    if(sz[v]>max1 && v-par) {max1 = sz[v]; bigChild = v;}
  }
  
  // Clear from the global array
  for(auto v : adj[u]) if(par-v && v!=bigChild) dfs(v,u,0);
  
  // Add the bigchild to the array
  if(bigChild!=-1) {dfs(bigChild, u,1); big[bigChild] = 1;}
  
  // Compute the rest by doing a dfs down
  add(u,par,1);
  
  // Answer the queries here
  // t(u); 
  // for(int i=0;i<=2;i++) cout<<counter[i]<<" ";cout<<endl;

  // t(u,sum);
  ans[u] = sum;
  // t(u);
  // cout<<"freq: ";
  // for(int i=0;i<6;i++) cout<<freq[i]<<" ";
  // cout<<endl;
  // cout<<"ffreq: ";
  // for(int i=0;i<6;i++) cout<<ff[i]<<" ";
  // cout<<endl;
  // Clear the bigChild first, because you're done with your work
  if(bigChild!=-1) big[bigChild] = 0;

  // If you're not a bigChild, you shouldn't keep your work
  if(keep==0) add(u,par,-1);
  // cout<<"u: "<<u<<" sum: "<<sum<<" boo: "<<keep<<" after"<<endl;
  // cout<<"freq: ";
  // for(int i=0;i<6;i++) cout<<freq[i]<<" ";
  // cout<<endl;
  // cout<<"ffreq: ";
  // for(int i=0;i<6;i++) cout<<ff[i]<<" ";
  // cout<<endl<<endl;
}

int32_t main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n;i++) 
  {
    cin>>col[i];
    // freq[col[i]]++; 
    // ff[freq[col[i]]]++;
    // ff2[freq[col[i]]]+=col[i];
    // s.insert(freq[col[i]]);
    ff[0]++;
  }
  // for(int i=0;i<5;i++) cout<<freq[col[i]]<<" ";cout<<endl;
  // for(int i=0;i<5;i++) cout<<ff[i]<<" ";cout<<endl;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs1(0,-1);
  dfs(0);
  for(int i=0;i<n;i++) cout<<ans[i]<<" ";
  cout<<"\n";
  return 0;
}

