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

void getbin(vector<int> &v,int a)
{
  for(int i=0;i<30;i++)
  {
    v.pu(a%2);
    a/=2;
  }
}

int getdec(vector<int>&v)
{
  int prod = 1;
  int sum1 = 0;
  for(int i=0;i<30;i++)
  {
    if(v[i]==1) sum1+=prod;
    prod*=2;
  }
  return sum1;
}

int main()
{
  int n,m;
  sc(n);sc(m);
  vector<vector<int> > v;
  v.resize(n);
  for(int i=0;i<n;i++) v[i].assign(30,0);

  vector<vector<int> > query(m);
  
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    sc(a);sc(b);sc(c);
    a--;b--;
    query[i].pu(a);query[i].pu(b);query[i].pu(c);
  }



  for(int i=0;i<m;i++)
  {
    int a = query[i][0], b = query[i][1], c = query[i][2];
    // t(i);
    vector<int> w;
    getbin(w,c);
    for(int j=0;j<30;j++)
    {
      if(w[j]==1)
      {
        // if(j<3) t(a,b+1,j);
        v[a][j]++; 
        if(b+1<n) v[b+1][j]--;
      }
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<30;j++)
  //   {
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  // Take cumulative sum in order to get the final array
  for(int j=0;j<30;j++)
  {
    int sum1 =0;
    for(int i=0;i<n;i++)
    {
      sum1+=v[i][j];
      v[i][j] = sum1;
      if(v[i][j]>1) v[i][j] = 1;
      else if(v[i][j]<0) v[i][j] = 0;
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<30;j++)
  //   {
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  // Get the array to be printed
  vector<int> w;
  for(int i=0;i<n;i++)
  {
    vector<int> v1;
    for(int j=0;j<30;j++)
    {
      v1.pu(v[i][j]);
    }
    // pr(v1);
    int c = getdec(v1);
    w.pu(c);
  }

  // Take prefix sum of this next and then crosscheck

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<30;j++)
    {
      v[i][j]+=v[i-1][j];
    }
  }

  for(int i=0;i<m;i++)
  {
    int a = query[i][0], b = query[i][1], c = query[i][2];
    vector<int> w;
    getbin(w,c);
    int size = b-a+1;
    for(int j=0;j<30;j++)
    {
      if(w[j]==0)
      {
        int sum = 0;
        if(a==0) sum = v[b][j];
        else sum = v[b][j] - v[a-1][j];
        // t(sum,size,c,j);
        if(sum==size) {cout<<"NO"<<endl;return 0;}
      }
    }
  }

  cout<<"YES"<<endl;
  for(int i=0;i<w.size();i++) cout<<w[i]<<" ";cout<<endl;
  return 0;
}

