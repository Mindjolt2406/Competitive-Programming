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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

long long int size;
bitset<100110> bs;
vector<int> prime;
const int N = 1e5+100;
vector<int> adj[N] = {};

void sieve()
{
  size = N;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      adj[i].pu(i);
      for(ll j = i*i;j<size;j+=i) 
      {
        bs[j] = false;
        // adj[j].pu(i);
      }
    }
    prime.pu((int)i);
  }
}

int main()
{
  sieve();
  __;
  int t;
  cin>>t;
  ll n = sqrt(1e9), m = 2*n+13;
  while(t--)
  {
    cout<<1<<" "<<n<<endl;
    ll a = 1LL*n*n;
    int c;
    cin>>c;
    if(c==-1) return 0;
    ll x = a-c;

    cout<<1<<" "<<m<<endl;
    ll b = 1LL*m*m;
    int d;
    cin>>d;
    if(d==-1) return 0;
    ll y = b - d;

    
    ll g = gcd(x,y);

    unordered_set<int> primer;
    ll k = g;

    for(auto i : prime)
    {
      if(k%i==0)
      {
        primer.insert(i);
        while(k%i==0) {k/=i;}
      }
    }
    if(k!=1) primer.insert(k);
    // Prime factorise x and take only the ones which occur once

    for(auto it : primer)
    {
      // t(x,y,it,c,d);
      if(a%it==c && b%it==d) 
      {
        cout<<2<<" "<<it<<endl;
        break;
      }
    }

    string s;
    cin>>s;
    if(s=="Yes") continue;
    else return 0;
  }
  return 0;
}

