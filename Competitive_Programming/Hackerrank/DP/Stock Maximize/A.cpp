/*
In this problem, I realised it would be enough if ine just found the max, then found the max in the remaiing subarray and so on.
Those would be the places one would sell and one would buy on the all the other days.
So I sorted the sequence and chucked out the ones which were lesser than the index of the latest maximum. This is actually a little
extra work. Instead you can just iterate from the back and kept the record when the max changes
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

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    int* mark = (int*)calloc(n,sizeof(int));
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++) {sc(l[i]);v.pu(mp(l[i],i));}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    // for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    int i=-1;
    for(int j=0;j<v.size();j++)
    {
      pair<int,int> p = v[j];
      int c = p.second;
      // cout<<"c: "<<c<<endl;
      if(c>i) {mark[c] = 1;i = c;}
    }
    ll profit = 0, count = 0;
    // for(int i=0;i<n;i++) cout<<mark[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++)
    {
      if(mark[i])
      {
        profit+=count*l[i];
        count = 0;
      }
      else {count++;profit-=l[i];}
    }
    printf("%lld\n",profit);
  }
  return 0;
}
