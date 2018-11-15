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
  multiset <int> s;
  int n;
  sc(n);
  for(int i=0;i<n;i++)
  {
    int a;sc(a);
    s.insert(a);
  }
  multiset<int ,greater<int> > :: iterator it;
  for(it=s.begin();it!=s.end();it++)
  {
    cout<<*it<<" ";
  }
  cout<<endl;
  s.erase(s.find(4));
  for(it=s.begin();it!=s.end();it++)
  {
    cout<<*it<<" ";
  }
  cout<<endl;
  return 0;
}
