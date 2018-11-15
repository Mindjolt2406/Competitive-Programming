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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

struct BIT //ll
{
  vector<ll> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  ll sum(int i)
  {
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    i++; // Already incrementing so that the value starts incrementing from the next guy
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
};

int main()
{
  typedef struct BIT fen;
  int n;
  sc(n);
  ll k;
  scll(k);
  // Compress the array
  // ---
  int*l = new int[n];
  set<int> s;
  map<int,int> d;
  set<int> :: iterator it;
  for(int i=0;i<n;i++) {sc(l[i]); s.insert(l[i]);}
  ll count = 1;
  for(it = s.begin();it!=s.end();it++)
  {
    if(d.find(*it)==d.end()) {d[*it] = count;count++;}
  }
  for(int i=0;i<n;i++) l[i] = d[l[i]];
  // ---

  vector<int> v;
  v.assign(100001,0);
  fen bit1,bit2;
  bit1.init(v);
  bit2.init(v);
  ll countinv = 0;
  for(int i=0;i<n;i++) 
  {
    countinv += i-bit2.sum(l[i]+1);
    bit2.inc(l[i],1);
  }
  // cout<<countinv<<endl;
  int left = 0,right = 1;
  bit2.inc(l[0],-1);
  // countinv-=bit2.sum(l[0]);
  bit1.inc(l[0],1);
  // cout<<countinv<<endl;
  count = 0;
  while(left<right)
  {
    while((right<n-1 && countinv>k))
    {
      cout<<"in"<<endl;
      cout<<"left: "<<left<<" right: "<<right<<" inv: "<<countinv<<endl;
      for(int i=1;i<8;i++) cout<<bit2.sum(i)<<" ";cout<<endl;
      // If right increases, delete the element from bit2
      countinv-=bit2.sum(l[right]);
      bit2.inc(l[right],-1);
      countinv-=(left+1-bit1.sum(l[right]+1));
      right++;
      for(int i=1;i<8;i++) cout<<bit2.sum(i)<<" ";cout<<endl;
      for(int i=1;i<8;i++) cout<<bit1.sum(i)<<" ";cout<<endl;
      cout<<"left: "<<left<<" right: "<<right<<" countinv: "<<countinv<<endl;
    }
    count+=n-right;
    if(right==n) right--;
    // If left increases, add the element to bit1
    if(left+1==right)
    {
      countinv-=bit2.sum(l[right]);
      bit2.inc(l[right],-1);
      countinv-=(left+1-bit1.sum(l[right]+1));
      right++;
    }
    left++;
    if(left==n-1) break;
    countinv+=left-bit1.sum(l[left]);
    countinv+=bit2.sum(l[left]);
    cout<<"out"<<endl;
    cout<<"left: "<<left<<" right: "<<right<<" inv: "<<countinv<<endl;
    if(left==right) 
    {
      countinv-=bit2.sum(l[right]);
      bit2.inc(l[right],-1);
      countinv-=(left+1-bit1.sum(l[right]+1));
      right++;
    }
    for(int i=1;i<8;i++) cout<<bit2.sum(i)<<" ";cout<<endl;
    for(int i=1;i<8;i++) cout<<bit1.sum(i)<<" ";cout<<endl;
    cout<<"left: "<<left<<" right: "<<right<<" countinv: "<<countinv<<endl;
    bit1.inc(l[left],1);
  }
  cout<<count<<endl;
  return 0;
}

/*
4 4
4 3 2 1

*/
