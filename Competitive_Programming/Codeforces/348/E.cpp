/*

This was an intro BIT question
Note, that in BIT, even though you can abstract it to a range update prefix sum kinda thing, the problem is that it isn't
You know, that you do some stuff to logn nodes, for each update, and you call sum on that node, it looks like a range update
However, you're actually updating some arbitrary nodes
The whole point of this explanation is that when you do a -1 update, like in this question.
The sums, for each nodes, can never become negative, but the node values by themselves can
This was an eye opener, which was given by this question
*/
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

struct BIT //int
{
  vector<map<int,int> > bit;
  int n;

  void init(int n)
  {
    this->n = n;
    for(int i=0;i<n;i++) 
    {
      map<int,int> s;
      bit.pu(s);
    }
  }

  int sum(int i,int value)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      if(bit[i].find(value)!=bit[i].end()) res+=bit[i][value];
    }
    return res;
  }

  void inc(int i, int value, int delta)
  {
    // cout<<"i: "<<i<<" value: "<<value<<" delta: "<<delta<<endl;
    for(;i<n;i = i|(i+1))
    {
      // cout<<"i: "<<i<<endl;
      // if(bit[i].find(value)!=bit[i].end()) {cout<<sum(i,value)<<endl;bit[i][value]+=(delta);cout<<sum(i,value)<<endl;}
      if(bit[i].find(value)!=bit[i].end()) bit[i][value]+=delta;
      else bit[i][value] = delta;
    }
  }

  // int getsum(int l,int r)
  // {
  //   // If l==0, sum(-1) automatically returns the default calue of res, 0
  //   return sum(r)-sum(l-1);
  // }

  // void init(vector<int> v)
  // {
  //   init(v.size());
  //   for(int i=0;i<v.size();i++) inc(i,v[i]);
  // }
};

int main()
{
  typedef struct BIT fen;
  int n;
  sc(n);
  vector<vector<int> > v1,v2;
  vector<int> v;
  set<int> s;
  set<int> ::iterator it;
  map<int,int> d;
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    sc(a);sc(b);sc(c);
    s.insert(b);
    vector<int> v = {a,b,c};
    v1.pu(v);
  }
  int count = 0;
  for(it=s.begin();it!=s.end();it++)
  {
    if(d.find(*it)==d.end()) {d[*it] = count;count++;}
  }
  for(int i=0;i<v1.size();i++)
  {
    vector<int> v = {v1[i][0],d[v1[i][1]],v1[i][2]};
    v2.pu(v);
  }
  fen bit;
  bit.init(v2.size()+2);
  for(int i=0;i<v2.size();i++)
  {
    vector<int> v = v2[i];
    if(v[0]==1)
    {
      bit.inc(v[1],v[2],1);
    }
    else if(v[0]==2)
    {
      bit.inc(v[1],v[2],-1);
    }
    else
    {
      cout<<bit.sum(v[1],v[2])<<endl;
    }
  }
  return 0;
}