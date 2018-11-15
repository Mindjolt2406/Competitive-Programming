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
  if(n%2==0) {cout<<-1<<endl; return 0;}
  for(int i=0;i<n;i++) cout<<i<<" ";cout<<endl;
  for(int i=0;i<n;i++) cout<<i<<" ";cout<<endl;
  for(int i=0;i<n;i++) cout<<(2*i)%n<<" "; cout<<endl;
  return 0;
}

