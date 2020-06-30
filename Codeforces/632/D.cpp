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

void print(int &idx,vector<int> &v,int n)
{
  for(int i=idx;i<idx+n;i++) cout << v[i]+1 << " "; cout << "\n";
  idx += n;
}

int main()
{
  __;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> v(n);
  for(int i=0;i<s.size();i++) 
  {
    if(s[i] == 'R') v[i] = 1;
    else v[i] = 0;
  }

  vector<int> w;
  vector<int> idx;
  int temp_cnt = 0;
  int sum1 = 0;
  while(temp_cnt < 2*n)
  {
    int i = 0;
    int cnt = 0;
    while(i<n-1)
    {
      if(v[i] > v[i+1])
      {
        swap(v[i],v[i+1]);
        idx.pu(i);
        i++;
        cnt++;
      }
      i++;
    }
    if(cnt == 0) break;
    w.pu(cnt);
    sum1 += cnt;
    temp_cnt++;
  }

  if(sum1 < k || k < w.size())
  {
    cout << -1 << endl;
  }
  else
  {
    // t(w.size());
    // t(w);
    int i = 0;
    int temp = k-w.size();
    int cnt_index = 0;
    while(i < w.size())
    {
      if(temp == 0) 
      {
        cout << w[i] << " ";
        print(cnt_index,idx,w[i]);
        i++;
      }
      else 
      {
        cout << 1 << " ";
        print(cnt_index,idx,1);
        temp--;
        w[i]--;
        if(w[i] == 0)
        {
          temp++;
          i++;
        }
      }
    }
  }
  return 0;
}
