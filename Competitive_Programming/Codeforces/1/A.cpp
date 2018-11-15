#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
#define mt make_tuple
#define INF 1000000001
using namespace std;

int main()
{
  long long int n,m,a;
  cin>>n>>m>>a;
  long long int sum1 = 0;
  long long int b=0,c=0;
  b = n/a;
  c = m/a;
  if(m%a) c++;
  if(n%a) b++;

  cout<<b*c<<endl;
  // if(m%a) sum1+=(n/a);
  // if(n%a) sum1+=(m/a);
  // if(m%a && n%a) sum1++;
  // cout<<sum1<<endl;
  return 0;
}
