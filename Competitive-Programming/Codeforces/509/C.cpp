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
  set<int> s;
  map<int,int> d;
  for(int i=0;i<n;i++) {sc(l[i]);s.insert(l[i]);d[l[i]] = 0;}
  set<int> :: iterator it;
  int key=  1;
  for(it = s.begin();it !=s.end();it++)
  {
    int c = *it;
    // cout<<"c: "<<c<<endl;
    if(d[c]!=0) continue;
    d[c] = key;
    while(c<=m)
    {
      // cout<<"c: "<<c<<endl;
      if(s.find(c+k)!=s.end()) 
      {
        c+=k;
        d[c] = key;
      } 
      else if(s.upper_bound(c+k)!=s.end())
      {
        int c1 = *s.upper_bound(c+k);
        c = c1;
        d[c] = key;
      }
      else
      {
        key++;
        break;
      }
    }
  }
  
  map<int,int> ::iterator it1;
  set<int> s1;
  for(int i=0;i<n;i++) s1.insert(d[l[i]]);
  cout<<s1.size()<<endl;
  for(int i=0;i<n;i++) cout<<d[l[i]]<<" ";cout<<endl;
  return 0;
}
