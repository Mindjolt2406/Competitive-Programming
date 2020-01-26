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

  int k;
  cin >> k;
  if(k>=2)
  {
    cout << 10 + 8*(k-1) << " " << 15 + 12*(k-1) << endl;

    int x = (k-1)*8 + 1;
    cout << x << " " << x+1 << endl;
    cout << x+5 << " " << x+6 << endl;

    // The connecting edges between the vertex gadgets
    for(int i=0;i<k-2;i++)
    {
      int a = 8*i;
      cout << a+8 << " " << a+9 << endl;
    }

    // The 8 vertex gadget
    for(int i=0;i<k-1;i++)
    {
      vector<int> v;
      for(int j=0;j<8;j++) v.pu(8*i+j+1);
      cout << v[1] << " " << v[2] << endl;
      cout << v[1] << " " << v[7] << endl;
      cout << v[1] << " " << v[6] << endl;

      cout << v[0] << " " << v[2] << endl;
      cout << v[0] << " " << v[4] << endl;

      cout << v[3] << " " << v[7] << endl;
      cout << v[3] << " " << v[4] << endl;
      cout << v[3] << " " << v[6] << endl;

      cout << v[5] << " " << v[2] << endl;
      cout << v[5] << " " << v[4] << endl;
      cout << v[5] << " " << v[6] << endl;
    }

    // t(x);
    // The ending bridges
    cout << x+4 << " " << 1 << endl;
    cout << x+9 << " " << 8*(k-1) << endl;

    cout << x << " " << x+2 << endl;
    cout << x+1 << " " << x+3 << endl;
    cout << x << " " << x+3 << endl;
    cout << x+1 << " " << x+2 << endl;
    cout << x+4 << " " << x+2 << endl;
    cout << x+4 << " " << x+3 << endl;

    x += 5;
    cout << x << " " << x+2 << endl;
    cout << x+1 << " " << x+3 << endl;
    cout << x << " " << x+3 << endl;
    cout << x+1 << " " << x+2 << endl;
    cout << x+4 << " " << x+2 << endl;
    cout << x+4 << " " << x+3 << endl;

    cout << 2 << endl;
    cout << 1 << " " << 2 << endl;
    // // Indices
    // for(int i=0;i<k;i++) cout << i+1 << " ";

    // f(G)
  }
  else if(k==0)
  {
    cout << 6 << " " << 9 << endl;
    cout << 1 << " " << 4 << endl;
    cout << 1 << " " << 5 << endl;
    cout << 1 << " " << 6 << endl;
    
    cout << 2 << " " << 4 << endl;
    cout << 2 << " " << 5 << endl;
    cout << 2 << " " << 6 << endl;

    cout << 3 << " " << 4 << endl;
    cout << 3 << " " << 5 << endl;
    cout << 3 << " " << 6 << endl;
    
    cout << 0 << endl;
  }
  else
  {
    cout << 10 << " " << 15 << endl;
    cout << 1 << " " << 2 << endl;
    cout << 9 << " " << 10 << endl;
    cout << 5 << " " << 6 << endl;

    cout << 2 << " " << 4 << endl;
    cout << 4 << " " << 5 << endl;
    cout << 2 << " " << 3 << endl;
    cout << 4 << " " << 1 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 3 << " " << 5 << endl;

    cout << 6 << " " << 7 << endl;
    cout << 6 << " " << 8 << endl;
    cout << 7 << " " << 9 << endl;
    cout << 8 << " " << 10 << endl;
    cout << 8 << " " << 9 << endl;
    cout << 7 << " " << 10 << endl;

    cout << 2 << endl;
    cout << 1 << " " << 2 << endl;
  }
  return 0;
}







