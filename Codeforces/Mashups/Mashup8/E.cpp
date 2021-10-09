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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int n,start,x;
  cin>>n>>start>>x;
  unordered_set<int> s;

  // std::random_device dev;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1,n); // distribution in range [1, n]
  
  // Query 1000 random indices
  // Take the best one and keep going next for another 999 times
  // The probability you won't get the answer is miniscule

  vector<int> v(n);
  for(int i=0;i<v.size();i++) v[i] = i+1;

  shuffle(v.begin(),v.end(),rng);

  // 1000 queries
  int max1 = -1, index = -1;
  for(int i=0;i<min(1000,(int)v.size());i++)
  {
    cout<<"? "<<v[i]<<endl;
    int a,next;
    cin>>a>>next;
    if(a<=x && a>max1)
    {
      max1 = a;
      index = next;
    }
  }

  if(max1==x) cout<<"! "<<max1<<endl;
  else
  {
    int max2 = -1;
    int a;
    if(index==-1) index = start;
    for(int i=0;i<999;i++)
    {
      if(index==-1) break;
      cout<<"? "<<index<<endl;
      cin>>a>>index;
      if(a>=x) {max2 = a; break;}
    }
    cout<<"! "<<max2<<endl;
  }
  return 0;
}
