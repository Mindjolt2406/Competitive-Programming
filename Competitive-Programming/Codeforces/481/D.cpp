#include<bits/stdc++.h>
#define pu push_back
#define INF 1000000001
using namespace std;

int check(vector <int> v,int a,int b)
{
  v[0]+=a;v[1]+=b;
  int k = v[1]-v[0];
  int boo = 1;
  int count = 0;
  if(a) count++;
  if(b) count++;
  int n = v.size();
  for(int i=1;i<n;i++)
  {
    int c = v[i]-v[i-1];
    int d = c-k;
    if(abs(d)<=1)
    {
      if(d!=0) {v[i]-=d; count++;}
    }
    else {boo = 0;break;}
  }
  // cout<<"boo: "<<boo<<" count: "<<count<<endl;
  if(boo) return count;
  else return INF;
}

int main()
{
  int n;
  cin>>n;
  vector <int> v;
  int min1 = INF;
  for(int i=0;i<n;i++) {int a; cin>>a; v.pu(a);}
  if(n<=2) {cout<<0<<endl;return 0;}
  else
  {
    int k = v[1]-v[0];
    int a = v[0], b = v[1];
    int m[5] = {b-a-2,b-a-1,b-a,b-a+1,b-a+2};
    for(int i=0;i<5;i++)
    {
      if(i==0) min1 = min(min1,check(v,-1,+1));
      else if(i==1)
      {
        min1 = min(min1,check(v,0,1));
        min1 = min(min1,check(v,-1,0));
      }
      else if(i==2)
      {
        min1 = min(min1,check(v,1,1));
        min1 = min(min1,check(v,0,0));
        min1 = min(min1,check(v,-1,-1));
      }
      else if(i==3)
      {
        min1 = min(min1,check(v,1,0));
        min1 = min(min1,check(v,0,-1));
      }
      else if(i==4)
      {
        min1 = min(min1,check(v,1,-1));
      }
    }
  }
  if(min1!=INF)cout<<min1<<endl;
  else cout<<-1<<endl;
  return 0;
}
