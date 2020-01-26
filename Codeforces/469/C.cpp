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


using namespace std;

int main()
{
  __;
  string s;
  // vector<int> a,b;
  set<int> a,b;
  cin>>s;
  int prev = -1, curr = -1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]-'0'==0) 
    {
      a.insert(i+1);
    }
    else 
    {
      b.insert(i+1);
    }
  }
  if(a.empty()) {cout<<-1<<endl; return 0;}
  string k;
  int count = 0;
  while(!a.empty())
  {
    if(b.empty()) {k+="1 "+to_string(*a.begin())+"\n";a.erase(*a.begin());count++;}
    else
    {
      auto ita = a.begin(), itb = b.begin();
      vector<int> v;
      v.pu(*ita);
      while(ita!=a.end() && itb!=b.end())
      {
        itb = b.upper_bound(*ita);
        if(itb!=b.end()) v.pu(*itb);
        else break;
        ita = a.upper_bound(*itb);
        if(ita==a.end()) {cout<<-1<<endl; return 0;}
        else v.pu(*ita);
      }
      k+=to_string((int)v.size())+" ";
      for(int i=0;i<v.size();i++) k+=to_string(v[i])+" ";
      k+="\n";
      count++;
      for(int i=0;i<v.size();i++)
      {
        if(a.find(v[i])!=a.end()) a.erase(v[i]);
        else b.erase(v[i]);
      }
    }
  }
  if(!b.empty()) cout<<-1<<endl;
  else {k = to_string(count)+"\n" + k; cout<<k<<endl;}
  return 0;
}

