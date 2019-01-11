#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int bsearch1(vector<ll> &v, int value)
{
  int beg = 0, end = v.size()-1;
  int max1 = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]<=value) {max1 = mid; beg = mid+1;}
    else end = mid-1;
  }
  return max1;
}


ll getsum(vector<ll> &v, int i,int j)
{
  if(j==-1) return 0;
  if(i>=v.size()) return 0;
  if(i==0) return v[j];
  else return v[j] - v[i-1];
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};


int main()
{
  int n,q;
  sc(n);
  vector<vector<ll> > v(n);
  vector<vector<ll> > pref(n);
  unordered_map<pair<int,int> , ll, pair_hash> d;
  for(int i=0;i<n;i++)
  {
    int m;
    sc(m);
    for(int j=0;j<m;j++)
    {
      ll a;
      scll(a);
      v[i].pu(a);
      pref[i].pu(a);
    }
  }

  for(int i=0;i<n;i++) {sort(v[i].begin(),v[i].end()); sort(pref[i].begin(),pref[i].end());}
  for(int i=0;i<n;i++)
  {
    for(int j=1;j<pref[i].size();j++) 
    {
      pref[i][j]+=pref[i][j-1];
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<v[i].size();j++)
  //   {
  //     cout<<pref[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  sc(q);
  for(int i=0;i<q;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    if(d.find(mp(a,b))!=d.end()) {printf("%lld\n",d[mp(a,b)]);continue;}
    vector<ll> *x,*y,*xpref,*ypref;
    if(v[a].size()<v[b].size())
    {
      x = &v[a];
      y = &v[b];
      xpref = &pref[a];
      ypref = &pref[b];
    }
    else 
    {
      x = &v[b];
      y = &v[a];
      ypref = &pref[a];
      xpref = &pref[b];
    }

    ll sum1 = 0;

    for(int i=0;i<(*x).size();i++)
    {
      int n = (*y).size();
      ll c = bsearch1(*y,(*x)[i]);
      // t(c,(c+1)*x[i],getsum(ypref,0,c));
      if(c!=-1) sum1+=(c+1)*(*x)[i] - getsum(*ypref,0,c);
      if(c!=n-1) sum1+= getsum(*ypref,c+1,n-1) - (n-1-c)*(*x)[i]; 
      // t(sum1);s
    }

    d[mp(a,b)] = sum1;
    printf("%lld\n",sum1);
  }
  return 0;
}

/*
3
4 1 2 3 4
4 5 6 7 8
2 9 10
3
1 3

*/