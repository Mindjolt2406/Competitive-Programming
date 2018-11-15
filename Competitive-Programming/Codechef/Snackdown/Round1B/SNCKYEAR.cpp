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
  set<int> s;
  s.insert(2010);
  s.insert(2015);
  s.insert(2016);
  s.insert(2017);
  s.insert(2019);
  while(t--)
  {
    int n;
    sc(n);
    if(s.find(n)==s.end()) cout<<"NOT HOSTED"<<endl;
    else cout<<"HOSTED"<<endl;
  }
  return 0;
}

