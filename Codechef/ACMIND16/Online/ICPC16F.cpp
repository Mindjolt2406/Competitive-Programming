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
  int t;
  sc(t);
  while(t--)
  {
    int n,m,d1,d2;
    sc(n);sc(m);sc(d1);sc(d2);
    float n1 = n;
    if((m%n==0 && m/n>=d1 && m/n<=d2) ||  (m%n!=0 && m/n>=d1 && (m/n+1)<=d2))
    {
      int k = 0;
      for(int j=0;j<n;j++)
      {
        for(int i=0;i<n;i++)
        {
          cout<<i+1<<" "<<(i+j)%(n)+1<<endl;
          k++;
          if(k==m) break;
        }
        if(k==m) break;
      }
    }
    else cout<<-1<<endl;
  }
  return 0;
}

