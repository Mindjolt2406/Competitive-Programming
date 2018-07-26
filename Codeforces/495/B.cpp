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
  int n;
  sc(n);
  int* l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int* dis = new int[n];
  dis[n-1] = 0;
  set<int> s,s1;
  for(int i=n-1;i>=0;i--)
  {
    dis[i] = s.size();
    s.insert(l[i]);
  }
  // for(int i=0;i<n;i++) cout<<dis[i]<<" ";cout<<endl;
  ll count = 0;
  for(int i=0;i<n;i++)
  {
    if(s1.find(l[i])==s1.end()) {count+=dis[i];s1.insert(l[i]);}
  }
  cout<<count<<endl;
  return 0;
}
