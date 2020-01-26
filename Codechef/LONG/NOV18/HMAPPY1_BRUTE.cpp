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

using namespace std;

int main()
{
  int n,m,k;
  ostream_iterator< int > out( cout, " " );
  sc(n);sc(m);sc(k);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  string s1;
  scr(s1);
  // reverse(s1.begin(),s1.end());
  // reverse(l,l+n);
  vector<int> v;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(l[i]==0) 
    {
      if(count!=0) v.pu(count);count = 0;v.pu(count);
    }
    else count++;
  }
  v.pu(count);
  deque<int> q1,q2;
  set<int> s;
  s.insert(0);
  map<int,int> d;
  for(int i=0;i<v.size();i++) 
  {
    q1.pu(v[i]);
    if(v[i]!=0)
    {
      s.insert(v[i]);
      if(d.find(v[i])!=d.end()) d[v[i]]++;
      else d[v[i]] = 1;
    }
  }
  for(int i=0;i<n;i++) q2.pu(l[i]);
  for(int i=0;i<s1.size();i++)
  {
    if(s1[i]=='!')
    {
      int a = q2.back();
      q2.pop_back();
      q2.push_front(a); 
    }
    else
    {
      int count = 0;
      int max1 = -1;
      for(int i=0;i<n;i++)
      {
        if(q2[i]==1) count++;
        else
        {
          max1 = max(max1,count);
          count = 0;
        }
      }
      max1 = max(max1,count);
      cout<<min(max1,k)<<endl;
    }
  }
  return 0;
}

