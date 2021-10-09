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

int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n),life(n),kill(n);
  for(int i=0;i<n;i++) {cin>>v[i];v[i]--;}
  stack<int> s;
  s.push(v[0]);
  life[v[0]] = INF;
  for(int i=1;i<v.size();i++)
  {
    int a = s.top();
    int b =v[i];
    if(a>b) // Kill!
    {
      kill[a]++;
      life[b] = kill[a];
      if(kill[a]==life[a]) s.pop();
      s.push(b);
    }
    else
    {
      while(s.top()<b)
      {
        if(life[s.top()]==INF) 
        {
          life[b] = INF;
          s.push(b);
          break;
        }
        else s.pop();
      }
      if(s.top()>b) 
      {
        int a = s.top();
        kill[a]++;
        life[b] = kill[a];
        if(kill[a]==life[a]) s.pop();
        s.push(b);
      }
    }
    // t(i,v[i],s.top());
    // pr(life);pr(kill);
  }
  int max1 = 0;
  for(int i=0;i<n;i++)
  {
    if(life[i]!=INF) max1 = max(max1,life[i]);
  }
  // pr(life);pr(kill);
  cout<<max1<<endl;
  return 0;
}
