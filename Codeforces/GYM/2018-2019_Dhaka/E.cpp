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
  while(n)
  {
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;

      vector<int> v;
      int temp = 0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i] == ':')
        {
          v.pu(temp);
          temp = 0;
        }
        else
        {
          temp *= 10;
          temp += s[i]-'0';
        }
      }
      v.pu(temp);

      int a = v[1]*3600 + v[2]*60 + v[3];
      int b = v[4]*3600 + v[5]*60 + v[6];

      // t(v,a,b);

      a = max(a, 8*3600+30*60);
      b = max(b, 8*3600+30*60);

      if(s[0] == 'D')
      {
        if(a <= 9*3600 + 30*60)
        {
          if(b-a < 8*3600) cnt++;
        }
        else cnt++;
      }
      else
      {
        if(a <= 12*3600 + 30*60)
        {
          if(b-a < 9*3600) cnt++;
        }
        else cnt++;
      }
    }

    if(cnt == 0) cout << "All OK" << endl;
    else if(cnt == 1) cout << "1 Point(s) Deducted" << endl;
    else if(cnt == 2) cout << "2 Point(s) Deducted" << endl;
    else if(cnt == 3) cout << "3 Point(s) Deducted" << endl;
    else cout << "Issue Show Cause Letter" << endl;

    cin >> n;
  }
  return 0;
}

/*
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:16:30:00
D:9:30:00:17:30:20
E:11:30:01:20:31:00
3
D:8:30:00:17:30:20
D:9:30:01:17:30:20
E:11:30:01:20:00:00
4
D:8:00:00:16:15:20
D:9:30:01:17:30:00
E:11:30:01:20:00:00
E:11:30:01:20:00:00
0

*/
