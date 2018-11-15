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

int bsearch1(ll*l,int n,ll value)
{
  value++;
  int beg = 0,end = n-1,maxindex = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(l[mid]<value) {maxindex = mid;beg = mid+1;}
    else end = mid-1;
  }
  return maxindex;
}

int main()
{
  int n;
  sc(n);
  ll x;
  scll(x);
  set<int> s;
  map<int,int> d,d2;
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    s.insert(a);
    s.insert(b+1);
    v.pu(mp(a,b+1));
  }
  set<int>::iterator it;
  int count = 0;
  for(it = s.begin();it!=s.end();it++)
  {
    if(d.find(*it)==d.end()) {d[*it] = count;d2[count]=*it;count++;}
  }
  int n2 = count;
  ll*l = (ll*)calloc(n2+1,sizeof(ll));
  for(int i=0;i<n;i++)
  {
    l[d[v[i].first]]++;
    l[d[v[i].second]]--;
  }
  // for(int i=0;i<n2;i++) cout<<l[i]<<" ";cout<<endl;
  // cout<<"n2: "<<n2<<endl;
  for(int i=1;i<n2;i++) l[i]+=l[i-1];
  // for(int i=0;i<n2;i++) cout<<l[i]<<" ";cout<<endl;
  for(int i=0;i<n2;i++)
  {
    ll y = x - (l[i])*(d2[i+1]-d2[i]);
    if(y<=0)
    {
      cout<<((x-1)/l[i])+d2[i]<<endl;
      return 0;
    }
    else x = y;
  }
  // for(it1 = d2.begin();it1!=d2.end();it1++) cout<<it1->first<<" "<<it1->second<<endl;
  // for(int i=0;i<n2;i++) cout<<l[i]<<" ";cout<<endl;
  // cout<<d2[bsearch1(l,n2,x)]<<endl;
  return 0;
}

/*
1
1
2 4

*/
