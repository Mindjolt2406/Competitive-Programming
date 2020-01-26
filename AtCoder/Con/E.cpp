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
  int n;
  cin >> n;
  
  // First colour
  string col;
  cout << "? ";
  for(int i=1;i<=n;i++) cout << i << " ";
  cout << endl;

  cin >> col;

  int beg = 1, end = n+1, ans = n+1;
  while(beg <= end)
  {
    int mid = (beg + end) >> 1;
    cout << "? ";
    for(int i=mid;i<mid+n;i++) cout << i << " ";
    cout << endl;

    string temp;
    cin >> temp;

    if(temp == "-1") return 0;
    if(col == temp) beg = mid+1;
    else
    {
      end = mid-1;
      ans = mid;
    }
  }

  vector<char> v(2*n);
  vector<int> red,blue;
  for(int i=1;i<=2*n;i++)
  {
    if(i>= ans && i<ans+n-1) continue;
    cout << "? "; 
    for(int j=ans;j<ans+n-1;j++) cout << j << " ";
    cout << i << endl;

    string temp;
    cin >> temp;
    if(temp == "-1") return 0;
    v[i-1] = temp[0];
    if(temp[0] == 'R' && red.size() < n/2) red.pu(i);
    else if(temp[0] == 'B' && blue.size() < n/2) blue.pu(i);
  }

  // t(red);
  // t(blue);

  for(int i=ans;i<ans+n-1;i++)
  {
    cout << "? ";
    for(int j=0;j<blue.size();j++) cout << blue[j] << " ";
    for(int j=0;j<red.size();j++) cout << red[j] << " ";
    cout << i << endl;

    string temp;
    cin >> temp;
    v[i-1] = temp[0];
  }

  cout << "! ";
  for(int i=0;i<v.size();i++) cout << v[i];
  cout << endl;
  return 0;
}

