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
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    int*l = new int[n];
    set<int> s;
    set<int> :: iterator it;
    map<int,int> d;
    for(int i=0;i<n;i++) {sc(l[i]);s.insert(l[i]);}
    for(it = s.begin();it!=s.end();i++)
    {
      if(d.find(*it)==d.end()) d[*it]++;
      d[*it] = 1;
    }
    
  }
  return 0;
}

