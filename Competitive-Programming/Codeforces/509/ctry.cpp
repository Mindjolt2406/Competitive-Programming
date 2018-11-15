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

int main()
{
  int n,m,k;
  sc(n);sc(m);sc(k);
  k++;
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  map<int,vector<int> > d;
  map<int,int> d1;
  for(int i=0;i<n;i++)
  {
    int c = l[i]%k;
    if(c==0) c = k;
    d[c].pu(l[i]);
    d1[l[i]] = c;
  }
  map<int,vector<int> > :: iterator it;
  map<pair<int,int> , vector<int> > d2;
  vector<pair<int,int> > v;
  for(it = d.begin();it!=d.end();it++)
  {
    sort(it->second.begin(),it->second.end());
    pair<int,int> p = mp(it->second[it->second.size()-1],it->second[0]);
    d2[p] = it->second;
  }

  cout<<d.size()<<endl;
  // map<int,int > :: iterator it;
  for(int i=0;i<n;i++)
  {
    cout<<d1[l[i]]<<" ";
  }
  cout<<endl;
  return 0;
}
