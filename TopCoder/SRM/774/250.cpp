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

class TimeDifference
{
  public: 
    string calculate(string a,string b)
    {
      string ah,at,bh,bt;
      bool ca = false, cb = false;

      for(int i=0;i<a.size();i++) 
      {
        if(a[i] == ':') 
        {
          ca = true;
          continue;
        }

        if(!ca) ah += a[i];
        else at += a[i];
      }

      for(int i=0;i<b.size();i++) 
      {
        if(b[i] == ':') 
        {
          cb = true;
          continue;
        }

        if(!cb) bh += b[i];
        else bt += b[i];
      }

      int a_h,a_m,b_h,b_m;
      a_h = stoi(ah);
      a_m = stoi(at);
      b_h = stoi(bh);
      b_m = stoi(bt);

      int ans_h = 0,ans_m = 0;
      bool neg = false;

      if(mp(b_h,b_m) < mp(a_h,a_m))
      {
        swap(a_h,b_h);
        swap(a_m,b_m);
        neg = true;
      }

      ans_m = b_m - a_m;
      if(ans_m < 0)
      {
        ans_m += 60;
        b_h--;
      }

      ans_h = b_h - a_h;


      string ans;
      if(neg) ans += '-';

      ans += to_string(ans_h);
      ans += ':';
      if(to_string(ans_m).size() == 1) ans += '0';
      ans += to_string(ans_m);

      return ans;

    }
};

int main()
{

  TimeDifference t;
  cout << t.calculate("100:15","13:23") << endl;
}

