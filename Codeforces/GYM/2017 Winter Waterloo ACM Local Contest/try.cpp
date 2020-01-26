/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

double hm(vector<int> v)
{
	double sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum+=1.00/v[i];
	}
	int n=v.size();
	return n/sum;
}

bool recur(set<int> s, vector<int> v,int n,int k)
{
  if(s.empty())
  {
    bool boo = true;
    for(int i=1;i<=n-1;i++)
    {
      vector<double> x,y;
      for(int j=0;j<n-i+1;j++)
      {
        vector<int> w;
        for(int k1=0;k1<i;k1++)
        {
          w.pu(v[k1+j]);
        }

        // t(v,w,i);
        x.pu(hm(w));
        y.pu(hm(w));
        // t(x);
      }
      // t(v,x,i);
      if(i==k)
      {
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        if(x!=y) boo = false;     
        // if(boo) t(y);
      }
      else
      {
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());
        if(x==y) boo = false;
      }
      if(!boo) break;
    }
    if(boo) 
    {
      _;
      t(v);
      return true;
    }
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    // cout<<endl;
    return false;
  }

  for(int i=1;i<=n;i++)
  {
    if(s.find(i)!=s.end())
    {
      v.pu(i);
      s.erase(i);
      if(recur(s,v,n,k)) return true;
      v.pop_back();
      s.insert(i);
    }
  }
  return false;
}



int main()
{
  int n;
  cin >> n;
  set<int> s1;
  vector<int> v;
  for(int i=1;i<=n;i++) s1.insert(i);
  for(int k=1;k<=n-1;k++)
  {
    t(k);
    recur(s1,v,n,k);
  }
  return 0;
}
