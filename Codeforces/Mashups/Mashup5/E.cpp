// #include<bits/stdc++.h>
#include<iostream>
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

ll counter = 0;
void merge(int*l,int i,int c,int j)
{
  //int *l = *p;
  int*m = (int*)calloc((j-i+1),sizeof(int));
  int x=i,y=c+1;
  int k=0;
  while(k<j-i+1)
  {
    if(y==j+1)
    {
      while(x<=c)
      {
        m[k] = l[x];
        counter+=(y-c-1);
        x++;
        k++;
      }
      continue;
    }
    else if(x==c+1)
    {
      while(y<=j)
      {
        m[k] = l[y];
        y++;
        k++;
      }
      continue;
    }
    else if(l[x]<l[y])
    {
      m[k] = l[x];
      counter+=(y-c-1);
      x++;
    }
    else if(l[y]<=l[x])
    {
      m[k] = l[y];
      y++;
    }
    k++;
  }
  //Copying
  for(int k=0;k<j-i+1;k++)
  {
    l[k+i] = m[k];
  }
}


void sort(int *l,int i,int j)
{
  //int *l = *p;
  if(i<j)
  {
    int c = (i+j)/2;
    sort(l,i,c);
    sort(l,c+1,j);
    merge(l,i,c,j);
  }
    // printf("%d %d Indices \t",i,j);
    // for(int k=i;k<j+1;k++)
    // {
    //   printf("%d ",l[k]);
    // }
    // printf("\n");
    // printf("%lld\n",count);
}



int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  sort(l,0,n-1);
  // t(counter);
  cout<<(counter/2)*4 + counter%2 <<endl;
  return 0;
}

