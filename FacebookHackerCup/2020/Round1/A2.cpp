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
ll min(ll x, ll y) {return x<y?x:y;}

pair<ll,ll> merge(pair<ll,ll> p1, pair<ll,ll> p2)
{
  if(p1 > p2) swap(p1,p2);
  if(p1.se < p2.fi) return mp(-1,-1);
  else return mp(min(p1.fi,p2.fi),max(p1.se,p2.se));
}

void solve()
{
  int n,k;
  cin >> n >> k;
  vector<ll> l(n),h(n),w(n),per(n);

  for(int i=0;i<k;i++) cin >> l[i];
  ll al,bl,cl,dl;
  cin >> al >> bl >> cl >> dl;
  for(int i=k;i<n;i++) l[i] = ((((al*l[i-2]) % dl) + ((bl*l[i-1]) % dl) + cl) % dl) + 1;

  for(int i=0;i<k;i++) cin >> w[i];
  ll aw,bw,cw,dw;
  cin >> aw >> bw >> cw >> dw;
  for(int i=k;i<n;i++) w[i] = ((aw*w[i-2] % dw) + (bw*w[i-1]) % dw + cw) % dw + 1;

  for(int i=0;i<k;i++) cin >> h[i];
  ll ah,bh,ch,dh;
  cin >> ah >> bh >> ch >> dh;
  for(int i=k;i<n;i++) h[i] = ((ah*h[i-2] % dh) + (bh*h[i-1]) % dh + ch) % dh + 1;

  set<pair<ll,ll> > s;
  pair<ll,ll> bad = mp(-1,-1);
  
  ll prod = 1;
  ll curr = 0;

  for(int i=0;i<n;i++)
  {
    ll sum1 = 0,sum2 = 0;

    pair<ll,ll> p = {l[i],l[i]+w[i]};
    auto it = s.upper_bound(p);
    pair<ll,ll> next = (it == s.end()) ? bad : merge(*it,p);
    pair<ll,ll> prev;
    bool merged_before = false;

    if(it != s.begin()) 
    {
      it--;
      prev = *it;
      if(merge(*it,p) == bad) prev = bad;
      else
      {
        p = merge(*it,p);
        sum1 += ((*it).se - (*it).fi);
        sum1 %= MOD;
        merged_before = true;
        s.erase(it);
      }
    }
    else prev = bad;

    if(prev == bad && next == bad) 
    {
      curr += (2*h[i]) % MOD;
      curr %= MOD;
      curr += (2*(p.se-p.fi)) % MOD;
      curr %= MOD;
      prod *= curr;
      prod %= MOD;
      s.insert(p);
      continue;
    }
    
    while(true)
    {
      auto it = s.upper_bound(p);
      if(it != s.end())
      {
        
        pair<ll,ll> after = *it;
        pair<ll,ll> merged = merge(after,p);
        if(merged != bad)
        {
          if(merged_before) {sum2 += (2*h[i]) % MOD; sum2 %= MOD;}
          merged_before = true;
          p = merged;
          s.erase(it);
          sum1 += ((*it).se - (*it).fi);
          sum1 %= MOD;
        }
        else break;
      }
      else break;
    }

    curr = (curr - (2*sum1)% MOD + MOD) % MOD;
    curr = (curr - sum2 + MOD) % MOD;
    curr += 2*(p.se - p.fi);
    curr %= MOD;
    s.insert(p);

    prod *= curr;
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
2 2
1 2
0 0 0 100

1
2 2
1 2
0 0 0 100
2 2
0 0 0 100
3 3
0 0 0 100
2 2
10 20
0 0 0 100
2 2
0 0 0 100
3 3
0 0 0 100
5 5
8 3 10 16 2
0 0 0 100
3 1 5 2 18
0 0 0 100
9 6 6 4 1
0 0 0 100
10 3
14 5 14
4 7 2 47
6 4 13
2 3 17 33
29 23 22
1 0 27 31
50 10
100 26 4 28 106 59 9 105 10 97
14 40 784 4832
130 12 82 487 12 30 214 104 104 527
21 81 410 605
938 903 899 899 896 857 841 837 834 834
1 0 924 951

*/