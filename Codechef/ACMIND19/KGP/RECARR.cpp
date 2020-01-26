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


int main()
{
  __;
  int n = 1e5;
  // int n = 10;
  srand(128364);
  vector<int> v(n);
  for(int i=0;i<n/3;i++)
  {
    int a = 3*i;
    cout << 1 << " " << a+1 << " " << a + 3 << endl;
    int sum1;
    cin >> sum1;
    if(sum1 == 0)
    {
      v[a] = v[a+1] = v[a+2] = 0;
    }
    else if(sum1 == 3)
    {
      v[a] = v[a+1] = v[a+2] = 1;
    }
    else if(sum1 == 1)
    {
      int x = a + rand()%3 + 1;
      cout << 1 << " " << x << " " << x << endl;
      cin >> sum1;
      if(sum1 == 1)
      {
        v[x-1] = 1;
      }
      else 
      {
        vector<int> w;
        for(int i=1;i<=3;i++) if(x != a+i) w.pu(a+i);
        int y = rand()%2;
        cout << 1 << " " << w[y] << " " << w[y] << endl;
        cin >> sum1;
        if(sum1 == 0)
        {
          if(w[0] != w[y]) v[w[0]-1] = 1;
          else v[w[1]-1] = 1;
        }
        else
        {
          v[w[y]-1] = 1;
        }
      }
    }
    else if(sum1 == 2)
    {
      int x = a + rand()%3 + 1;
      cout << 1 << " " << x << " " << x << endl;
      cin >> sum1;
      v[a] = v[a+1] = v[a+2] = 1;
      if(sum1 == 0)
      {
        v[x-1] = 0;
      }
      else 
      {
        vector<int> w;
        for(int i=1;i<=3;i++) if(x != a+i) w.pu(a+i);
        int y = rand()%2;
        cout << 1 << " " << w[y] << " " << w[y] << endl;
        cin >> sum1;
        if(sum1 == 1)
        {
          if(w[0]!= w[y]) v[w[0]-1] = 0;
          else v[w[1]-1] = 0;
        }
        else
        {
          v[w[y]-1] = 0;
        }
      }
    }
  }
  cout << 1 << " " << 100000 << " " << 100000 << endl;
  // cout << 1 << " " << 10 << " " << 10 << endl;
  int sum1;
  cin >> sum1;
  v[99999] = sum1;
  // v[9] = sum1;
  cout << 2 << " ";
  for(int i=0;i<v.size();i++) cout << v[i] << " ";
  cout << endl;
  return 0;
}

