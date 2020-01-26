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
  if(count) v.pu(count);
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
      if(d.find(v[i])!=d.end()) {d[v[i]]++;}
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
      if(a==1)
      {
        int b = q1.back();
        q1.pop_back();
        d[b]--;
        if(d[b]==0) {if(s.find(b)!=s.end()) s.erase(s.find(b));}
        b--;
        if(b!=0)
        {

          if(d.find(b)==d.end()) d[b] = 1;
          else d[b]++;
          s.insert(b);
          q1.pu(b);
        }
        
        if(q1.empty())
        {
          d[1] = 1;
          s.insert(1);
          q1.push_front(1);
          continue;
        }
        int c = q1.front();
        if(c!=0)
        {
          q1.pop_front();
          d[c]--;
          if(d[c]==0) {if(s.find(c)!=s.end()) s.erase(s.find(c));}
        }
        
        c++;
        if(d.find(c)!=d.end()) d[c]++;
        else d[c] = 1;
        s.insert(c);
        q1.push_front(c);
      }
      else
      {
        int a = q1.back();
        q1.pop_back();
        q1.push_front(a);
      }
    }
    else
    {
      int a = *s.rbegin();
      printf("%d\n",min(a,k));
    }
  }
  return 0;
}

