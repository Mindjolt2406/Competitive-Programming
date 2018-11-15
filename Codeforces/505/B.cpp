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

void primeFactors(int n,set<int>&s)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
        s.insert(n);
}

int main()
{
  set<int> s1,s2;
  int n;
  sc(n);
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    v.pu(mp(a,b));
  }
  pair<int,int> p = v[0];
  primeFactors(p.first,s1);
  primeFactors(p.second,s2);
  set<int> :: iterator it;
  for(it=s1.begin();it!=s1.end();it++)
  {
    int boo = 1;
    int c = *it;
    for(int i=0;i<v.size();i++)
    {
      if(v[i].first%c!=0 && v[i].second%c!=0) {boo = 0;break;}
    }
    if(boo) {cout<<c<<endl;return 0;}
  }
  for(it=s2.begin();it!=s2.end();it++)
  {
    int boo = 1;
    int c = *it;
    for(int i=0;i<v.size();i++)
    {
      if(v[i].first%c!=0 && v[i].second%c!=0) {boo = 0;break;}
    }
    if(boo) {cout<<c<<endl;return 0;}
  }
  cout<<-1<<endl;
  return 0;
}
