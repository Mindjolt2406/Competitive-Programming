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
  int n,k;
  sc(n);sc(k);
  int*l  = new int[n];
  set<int> s,s1;
  int boo = 0;
  for(int i=0;i<n;i++)
  {
    sc(l[i]);
    if(s.find(l[i])!=s.end()) {boo = 1;break;}
    else s.insert(l[i]);
  }
  if(boo){cout<<0<<endl;return 0;}
  for(int i=0;i<n;i++)
  {
    if(s.find(l[i]&k)!=s.end() && (l[i]&k)!=l[i]) {boo = 1;break;}
    else if(s1.find(l[i]&k)!=s1.end()) {boo = 2;}
    else s1.insert(l[i]&k);
  }
  if(boo){cout<<boo<<endl;return 0;}
  else cout<<-1<<endl;
  return 0;
}
