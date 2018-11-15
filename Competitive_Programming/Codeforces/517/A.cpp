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
  int l,b,k;
  cin>>l>>b>>k;
  ll count = 0;
  while(k-- && l>=2 && b>=2)
  {
    count+=l*b;
    if(l>=2 && b>=2) {l-=2;b-=2;count-=l*b;}
    l-=2;b-=2;
  }
  cout<<count<<endl;
  return 0;
}

