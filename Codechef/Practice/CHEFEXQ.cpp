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

const int SQ = 3;


int main()
{
  __;
  int n,q;
  cin >> n >> q;
  vector<int> v(n),pref(n);

  for(int i=0;i<n;i++) cin >> v[i];

  pref[0] = v[0];
  for(int i=1;i<n;i++) pref[i] ^= pref[i-1]^v[i];

  vector<int> prev(SQ+10);
  vector<map<int,int> > counter(SQ+5);

  for(int i=0;i<n/SQ + 1;i++)
  {
    for(int j=0;j<SQ && j<n;j++)
    {
      counter[i][pref[i*SQ+j]]++;
    }
    int last = pref[i*SQ + SQ - 1];
    prev[i+1] = last;
  }

  while(q--)
  {
    int type;
    cin >> type;
    
    if(type == 1)
    {
      int index,x;
      cin >> index >> x;
      index--;

      int block = index/SQ;

      int pre = prev[block];
      for(int j=0; SQ*block + j < n && j<SQ; j++)
      {
        counter[block][pref[SQ*block +j]]--;
        pref[SQ*block +j] = pre^v[SQ*block+j];
        pre = pref[SQ*block+j];
      } 

      for(int j=index;j < block + SQ && j<n; j++)
      {
        counter[block][pref[j]]--;

        pref[j] ^= v[index];
        pref[j] ^= x;

        counter[block][pref[j]]++;
      }

      for(int j=block+1; j<SQ/n+1;j++) prev[j] ^= (x^v[index]);

      v[index] = x;
    }
    else
    {
      int index,x;
      cin >> index >> x;
      index--;

      int block = index/SQ;

      int pre = prev[block];
      for(int j=0; SQ*block + j < n && j<SQ; j++)
      {
        counter[block][pref[SQ*block +j]]--;
        pref[SQ*block +j] = pre^v[SQ*block+j];
        pre = pref[SQ*block+j];
      } 

      int ans = 0;
      for(int i=0;i<block;i++)
      {
        if(counter[i].find(x) != counter[i].end()) ans += counter[i][x];
      }

      for(int j=SQ*block;j<=index;j++)
      {
        ans += (pref[j] == x);
      }

      cout << ans << endl;
    }
  }
  return 0;
}
