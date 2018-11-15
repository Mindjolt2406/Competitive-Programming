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

int bsearch1(int a,vector<int> v)
{
  int n = v.size();
  int beg = 0,end = n-1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]>=a) return 1;
    end = mid-1;
  }
  return 0;
}

int bsearch2(int a,vector<int> v)
{
  int n = v.size();
  int beg = 0,end = n-1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]<=a) return 1;
    beg = mid+1;
  }
  return 0;
}
int main()
{
  int n;
  sc(n);
  set<int> sx,sy;
  vector<vector<int> > v;
  for(int i=0;i<n;i++)
  {
    int a,b,c,d;
    vector<int> v1;
    sc(a);sc(b);sc(c);sc(d);
    v1.pu(a);v1.pu(b);v1.pu(c);v1.pu(d);
    v.pu(v1);
    sx.insert(a);sx.insert(c);
    sy.insert(b);sy.insert(d);
  }
  int count = 0;
  map<int,int> dx,dy;
  // vector<int> vx,vy;
  // vx.pu(0);vy.pu(0);
  set<int> ::iterator it;
  for(it = sx.begin();it!=sx.end();it++)
  {
    if(dx.find(*it)==dx.end()) {dx[*it] = count;count++;}
  }
  int* l1 = (int*)calloc(140000,sizeof(int));
  for(int i=0;i<n;i++)
  {
    l1[dx[v[i][0]]]++;
    l1[dx[v[i][2]]+1]--;
  }
  count = 0;
  for(it = sy.begin();it!=sy.end();it++)
  {
    if(dy.find(*it)==dy.end()) {dy[*it] = count;count++;}
  }
  int* l2 = (int*)calloc(140000,sizeof(int));
  for(int i=0;i<n;i++)
  {
    l2[dy[v[i][1]]]++;
    l2[dy[v[i][3]]+1]--;
  }
  int sum1 = 0;
  for(int i=0;i<140000;i++) {sum1+=l1[i];l1[i] = sum1;}
  for(int i=0;i<140000;i++) {sum1+=l2[i];l2[i] = sum1;}
  // int a = -1,b = -1;
  // for(int i=1;i<140000;i++)
  // {
  //   if(l1[i]>=n-1) {a = vx[i];break;}
  // }
  // for(int i=1;i<140000;i++)
  // {
  //   if(l2[i]>=n-1) {b = vy[i];break;}
  // }
  vector<pair<int,int> > v2;
  for(int i=0;i<n;i++)
  {
    int a = v[i][0],b = v[i][1],c = v[i][2],d = v[i][3];
    if(l1[dx[a]]>=n-1 && l2[dy[b]]>=n-1 &&(l1[dx[a]] == n || l2[dy[b]]==n )) {cout<<a<<" "<<b<<endl;break;return 0;}
    else if(l1[dx[a]]>=n-1 && l2[dy[d]]>=n-1 &&(l1[dx[a]] == n || l2[dy[d]]==n)) {cout<<a<<" "<<d<<endl;break;return 0;}
    else if(l1[dx[c]]>=n-1 && l2[dy[b]]>=n-1 &&(l1[dx[c]] == n || l2[dy[b]]==n)) {cout<<c<<" "<<b<<endl;break;return 0;}
    else if(l1[dx[c]]>=n-1 && l2[dy[d]]>=n-1 &&(l1[dx[c]] == n || l2[dy[d]]==n)) {cout<<c<<" "<<d<<endl;break;return 0;}
    else if (l1[dx[a]]==n-1 && l2[dy[b]]==n-1) v2.pu(mp(a,b));
    else if (l1[dx[a]]==n-1 && l2[dy[d]]==n-1) v2.pu(mp(a,b));
    else if (l1[dx[c]]==n-1 && l2[dy[b]]==n-1) v2.pu(mp(a,b));
    else if (l1[dx[c]]==n-1 && l2[dy[d]]==n-1) v2.pu(mp(a,b));
  }
  vector<int> vx,vy;
  for(int i=0;i<140000;i++) {if(l1[i]==n-1) vx.pu(i);if(l2[i]==n-1) vy.pu(i);}
  for(int i=0;i<v2.size();i++)
  {
    int a = v2[i].first,b = v2[i].second;
    if(bsearch1(dx[a],vx) && bsearch2(dy[b],vy)) {cout<<a<<" "<<b<<endl;return 0;}
  }
  // for(int i=0;i<5;i++) cout<<l1[i]<<" ";cout<<endl;
  // for(int i=0;i<5;i++) cout<<l2[i]<<" ";cout<<endl;
  // cout<<a<<" "<<b<<endl;
  // int count= 1;
  // for(it = sy.begin();it!=sy.end();it++)
  // {
  //   if(dy.find(*it)==dy.end()) {dy[*it] = count;count++;}
  // }
  // int**
  return 0;
}
