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

int n;

int cnt = 0;
int query(int i)
{
  cnt++;
  if(i == -1) return 0;
  cout << i+1 << endl;
  char c;
  cin >> c;
  if(c == 'N') 
  {
    exit(0);
  }
  return c-'0';
}

void answer(string &s)
{
  // t(cnt);
  cout << s << endl;
  char c;
  cin >> c;
  if(c == 'N') exit(0);
}

void solve()
{
  if(n == 10)
  {
    string s;
    for(int i=0;i<10;i++) 
    {
      s += '0'+query(i);
    }
    answer(s);
  }
  else if(n == 20)
  {
    vector<int> v(20),change(20),ans(20);
    for(int i=0;i<10;i++)
    {
      v[i] = query(i);
      v[19-i] = query(19-i);
      change[i] = v[i] != v[19-i];
    }

    // t(v,change);
    vector<int> temp_00(2);
    vector<int> temp_01(2);

    for(int j=0;j<2;j++)
    {
      bool boo00 = false;
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 0 && !boo00) 
        {
          temp_00[j] = query(index)^v[index];
          boo00 = true;
        }
      }
      if(!boo00) query(5*j);
    }

    for(int j=0;j<2;j++)
    {
      bool boo01 = false;
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 1 && !boo01)
        {
          temp_01[j] = query(index)^v[index];
          boo01 = true;
        }
      }
      if(!boo01) query(5*j);
    }


    for(int j=0;j<2;j++)
    {
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 0) v[index] ^= temp_00[j];
        else v[index] ^= temp_01[j];
      }
    }

    for(int i=0;i<10;i++)
    {
      v[19-i] = v[i] ^ change[i];
    }

    string s;
    for(int i=0;i<20;i++) s += v[i]+'0';
    answer(s);
  }
  else
  {
    vector<int> v(100),change(100),ans(100);
    for(int i=0;i<50;i++)
    {
      v[i] = query(i);
      v[99-i] = query(99-i);
      change[i] = v[i] != v[99-i];
    }

    // t(v,change);
    vector<int> temp_00(10);
    vector<int> temp_01(10);
    int index00 = -1, index01 = -1,index00_j = -1,index01_j = -1;

    for(int j=0;j<10;j++)
    {
      bool boo00 = false;
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 0 && !boo00) 
        {
          if(index00 == -1) 
          {
            index00 = index;
            index00_j = j;
          }
          temp_00[j] = query(index)^v[index];
          boo00 = true;
          break;
        }
      }
      if(!boo00) query(5*j);
    }

    // t(cnt);

    for(int j=0;j<10;j++)
    {
      bool boo01 = false;
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 1 && !boo01)
        {
          if(index01 == -1) 
          {
            index01 = index;
            index01_j = j;
          }
          temp_01[j] = query(index)^v[index];
          boo01 = true;
          break;
        }
      }
      if(!boo01) query(5*j);
    }

    int a = query(index00)^temp_00[index00_j]^v[index00];
    int b = query(index01)^temp_01[index01_j]^v[index01];
    // t(cnt,index00,index01,a,b);

    for(int i=0;i<10;i++) temp_00[i] ^= a;
    for(int i=0;i<10;i++) temp_01[i] ^= b;

    for(int j=0;j<10;j++)
    {
      for(int i=0;i<5;i++)
      {
        int index = 5*j+i;
        if(change[index] == 0) v[index] ^= temp_00[j];
        else v[index] ^= temp_01[j];
      }
    }

    for(int i=0;i<50;i++)
    {
      v[99-i] = v[i] ^ change[i];
    }

    string s;
    for(int i=0;i<100;i++) s += v[i]+'0';
    answer(s);
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  cin >> n;
  // t(n);
  while(t--)
  {
    solve();
    cnt = 0;
  }
  return 0;
}
