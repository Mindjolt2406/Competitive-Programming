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

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    unordered_set<ll> d;
    vector<ll> v;
    for(ll i=1;i<=sqrt(n);i++)
    {
      if(n%i==0) {v.pu(i);d.insert(i);d.insert(n/i);v.pu(n/i);}
    }
    ll count = d.size();
    sort(v.begin(),v.end());
    // pr(v);
    for(int i=1;i<v.size()-1;i++) 
    {
      for( int j=1;j<min((int) (v.size()+1)/2,i+1);j++)
      {
        // t(v[i],v[j]);
        if(v[j]>n/v[i]) break;
        ll b = v[i]*v[j];
        // if(b>n) continue;
        d.insert(b);
      }
    }

    cout<<d.size()<<endl;
    vector<ll> w;
    for(auto it : d) w.pu(it);
    sort(w.begin(),w.end());
    for(auto it : w) cout<<it+n<<endl;
  }
  return 0;
}

