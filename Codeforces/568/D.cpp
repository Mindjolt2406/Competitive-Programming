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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n),w(n);
  // vector<pair<int,int> > w(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    w[i] = v[i];
    // w[i] = mp(v[i],i);
  }

  sort(v.begin(),v.end());

  int dif1 = v[1]-v[0];
  int dif2 = v[v.size()-1] - v[v.size()-2];

  int i = 0, j = 1;
  int boo = 0, index = 0;
  bool change = false;
  while(i<n-1 && j<n)
  {
    int a = v[j]-v[i];
    // t(i,j,a);
    if(a==dif1) 
    {
      i++; j++;
    }
    else 
    {
      // Check whether i is wrong or j is wrong
      boo++;
      index = j;
      if(i+2<n)
      {
        int a = v[i+2] - v[i];
        int b = v[i+2] - v[i+1];
        // t(i,v[i],v[i+1],v[i+2],a,b);
        // t(dif1);
        if(b==dif1)
        {
          if(i>0) 
          {
            if(v[i+1]-v[i-1]!=dif1) boo = 2;
          }
          index = i;
        }
        else if(a==dif1) index = j;
        else boo = 2;
      }
      j = i+3;
      i = i+2;
    }
  }

  // t(boo);
  if(boo<=1)
  {
    int a = v[index];
    // t(a);
    for(int i=0;i<w.size();i++) if(w[i]==a) {cout<<i+1<<endl; return 0;}
  }
  else
  {
    int i = 0, j = 1;
    int boo = 0, index = 0;
    bool change = false;
    while(i<n-1 && j<n)
    {
      int a = v[j]-v[i];
      // t(i,j,a,dif2);
      if(a==dif2) 
      {
        i++; j++;
      }
      else 
      {
        // Check whether i is wrong or j is wrong
        boo++;
        index = j;
        if(i+2<n)
        {
          int a = v[i+2] - v[i];
          int b = v[i+2] - v[i+1];
          // t(i,v[i],v[i+1],v[i+2],a,b);
          if(b==dif2)
          {
            if(i>0) 
            {
              if(v[i+1]-v[i-1]!=dif1) boo = 2;
            }
            index = i;
            // t(index);
          }
          else if(a==dif2) index = j;
          else boo = 2;
        }
        j = i+3;
        i = i+2;
      }
    }

    t(boo);
    if(boo<=1)
    {
      int a = v[index];
      for(int i=0;i<w.size();i++) if(w[i]==a) {cout<<i+1<<endl; return 0;}
    }
    else cout<<-1<<endl;
  }
  return 0;
}

