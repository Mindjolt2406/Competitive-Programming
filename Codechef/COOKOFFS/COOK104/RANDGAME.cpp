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
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    vector<int> v;
    int boo =0, count = 0;
    while(n)
    {
      if(!boo && !(n&1)) count++;
      else if(n&1) boo = 1;
      v.pu(n&1);
      n>>=1;
    }

    if(count%2==1) 
    {
      cout<<"Lose"<<endl; 
      string s;
      cin>>s;
      if(s!="GG") return 0;
    }
    else
    {
      cout<<"Win"<<endl;
      int index = 0;
      // pr(v);
      while(index<v.size())
      {
        // t(index,v[index]);
        if(v[index]==0) cout<<"/2"<<endl;
        else
        {
          if(index+1<v.size())
          {
            if(v[index+1]==1) cout<<"-1"<<endl;
            else {cout<<"+1"<<endl; v[index+1] = 1;}
          }
          else cout<<"-1"<<endl;
        }
        index++;
        string s;
        cin>>s;
        if(s=="/2" && v[index]==0) index++;
      }
    }
  }
  return 0;
}

