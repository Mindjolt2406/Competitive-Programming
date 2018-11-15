#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000000000000001
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

// TLE with nlogn??
ll min(ll x,ll y)
{
  if(x<y) return x;
  return y;
  return x<y ? x : y;
}

int bsearch1(vector<ll> &v,float value)
{
  int beg = 0,end = v.size()-1;
  int max1 = -1,boo = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]==value) {boo = 1;return mid;}
    else if(v[mid]<value && boo == 0) {beg = mid+1;max1 = max(max1,mid);}
    else if(boo) beg = mid+1;
    else end = mid-1;
  }
  return max1;
}

ll getcount(vector<ll> &v,ll val,ll val2, vector<ll> &pref)
{
  ll n = v.size();
  ll c = bsearch1(v,val+0.1),count = 0;
  if(c==-1) count = val2*n - pref[n-1] + val*n;
  else if(c==n-1) count = val*n - pref[n-1];
  else 
  {
    count = val*(n) + val2*(n-c-1) - pref[n-1];
  }
  return count;
}

ll getcount(vector<ll> &v1, vector<pair<ll,ll> > &v2, int val)
{
  ll n = v1.size();
  ll c = bsearch1(v1,val+0.1), count = 0;
  if(c==-1) count+=val*n + v2[n-1].second - v2[n-1].first;
  else if(c==n-1) count = val*n - v2[n-1].first;
  else
  {
    count = val*n - v2[n-1].first + v2[n-1].second - v2[c].second;
  }
  return count;
}


int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    ll*l = new ll[n];
    ll*m = new ll[n];
    ll min1 = INF;
    for(int i=0;i<n;i++) scll(l[i]);
    for(int i=0;i<n;i++) {scll(m[i]);min1 = min(min1,m[i]);l[i]%=m[i];}
    vector<ll> v,v2,v5; // The original numbers are in v, their prefix sum is in v5, v2 has the other numbers
    vector<pair<ll,ll> > v1,v3; // The other numbers along with their b's are stored in v1, their prefix sums are in v3
    ll count = 0;
    for(int i=0;i<n;i++) 
    {
      if(m[i]==min1) v.pu(l[i]);
      else 
      {
        if(l[i]<min1)
        {
          v1.pu(mp(l[i],m[i]));
          v2.pu(l[i]);
        }
        else  {count+=m[i]-l[i];v.pu(0);}
      }
    }
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end());
    v5.pu(v[0]);
    for(int i=1;i<v.size();i++) v5.pu(v5[i-1]+v[i]);
    vector<ll> v4;
    for(int i=0;i<v1.size();i++) v4.pu(v1[i].first);
    // prefix sum of the b array
    if(!v1.empty())v3.pu(v1[0]);
    for(int i=1;i<v1.size();i++)
    {
      pair<ll,ll> p1,p2;
      p1 = v1[i];
      p2 = v3[i-1];
      p2.first+=p1.first;
      p2.second+=p1.second;
      v3.pu(p2);
    }
    ll min2 = INF;
    for(int i=0;i<v.size();i++)
    {
      if(!v1.empty()) min2 = min(min2,getcount(v4,v3,v[i])+getcount(v,v[i],min1,v5));
      else min2 = min(min2,getcount(v,v[i],min1,v5));
    }
    if(!v1.empty())
    {
      for(int i=0;i<v2.size();i++)
      {
        min2 = min(min2,getcount(v4,v3,v2[i])+getcount(v,v2[i],min1,v5));
      }
    }
    printf("%lld\n",min2+count);
    // cout<<min2+count<<endl;
  }
  return 0;
}

/*
1
3
4 2 2
5 3 4

1
4
0 3 3 7 
10 6 4 9 

*/
