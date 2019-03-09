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
  int n;
  cin>>n;
  vector<int> v(1001);
  for(int i=0;i<n*n;i++)
  {
    int a;
    cin>>a;
    v[a]++;
  }

  int boo = 0, a = 0, count = 0;
  for(int i=1;i<=1000;i++)
  {
    if(v[i]%4==1) {boo++; a = i;}
    else if(v[i]%4==2)count++;
    else if(v[i]%4==3) {count++;boo++;}
  }
  // t(boo,count);
  if(boo>0 && n%2==0) cout<<"NO"<<endl;
  else if(n%2==1 && boo!=1) cout<<"NO"<<endl;
  else if(n%2==1 && count>n-1) cout<<"NO"<<endl;
  else if(n%2==0 && count) cout<<"NO"<<endl;
  else
  {
    // _;
    vector<vector<int> > mat(n,vector<int>(n));
    mat[n/2][n/2] = a;
    // t(a);
    v[a]--;
    vector<int> w4,w2;
    _;
    for(int i=1;i<=1000;i++)
    {
      if(v[i]%4==2 && n%2==1) {w2.push_back(i);v[i]-=2;}
      while(v[i]!=0) {w4.push_back(i);v[i]-=4;}
    }
    // _;
    // pr(w2);
    // pr(w4);
    while(n%2==1 && w2.size()!=2*n-2) {int a = w4[w4.size()-1]; w2.push_back(a); w2.push_back(a);w4.erase(w4.end()-1);}

    // pr(w);
    int k=0;
    // t(w[0]);
    // _;
    for(int i=0;i<(n)/2;i++)
    {
      for(int j=0;j<(n)/2;j++)
      {
        // t(i,j,w4[k]);
        if(i==(n)/2 && j==(n)/2) continue;
        mat[i][j] =  w4[k];
        mat[n-1-i][j] = w4[k];
        mat[i][n-1-j] = w4[k];
        mat[n-1-i][n-j-1] = w4[k];
        k++;
        // t(k);
      }
    }
    // _;
    k = 0;
    if(n%2==1)
    {
      for(int i=0;i<n/2;i++) {mat[n/2][i] = mat[n/2][n-1-i] = w2[k];k++;}
    
      for(int i=0;i<n/2;i++) {mat[i][n/2] = mat[n-1-i][n/2] = w2[k];k++;}
    }
    // for(int i=0;i<n/2;i++)
    // _;
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}

