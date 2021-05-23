#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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

ll max(ll x, ll y) {return x>y?x:y;}

void solve()
{
  int n,k,w;
  cin >> n >> k >> w;
  vector<ll> l(n),h(n);
  for(int i=0;i<k;i++) cin >> l[i];
  ll al,bl,cl,dl;
  cin >> al >> bl >> cl >> dl;
  for(int i=k;i<n;i++) l[i] = ((((al*l[i-2]) % dl) + ((bl*l[i-1]) % dl) + cl) % dl) + 1;

  for(int i=0;i<k;i++) cin >> h[i];
  ll ah,bh,ch,dh;
  cin >> ah >> bh >> ch >> dh;
  for(int i=k;i<n;i++) h[i] = ((ah*h[i-2] % dh) + (bh*h[i-1]) % dh + ch) % dh + 1;

  // t(l,h);
  ll prod = 1, prev = 0;
  for(int i=0;i<n;i++)
  {
    ll temp = 0;
    if(i == 0 || (l[i]-l[i-1] > w)) 
    {
      temp += 2*h[i] + 2*w;
      temp %= MOD;
    }
    else
    {
      temp += 2*((l[i]-l[i-1]+dl) % dl);
      temp %= MOD;
      ll maxh = 0;
      for(int j=i-1;j>=0;j--)
      {
        if(l[j]+w >= l[i])
        {
          maxh = max(maxh,h[j]);
        }
        else break;
      }
      if(h[i] > maxh) 
      {
        temp += 2*(h[i]-maxh);
        temp %= MOD;
      }
      // t(i,temp,l[i],l[i-1],h[i],maxh);
    }
    prev += temp;
    prev %= MOD;
    prod *= prev;
    prod %= MOD;
  }
  cout << prod << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

/*
1
2 2 2
1 2
0 0 0 100
3 3

*/
