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
    int n;
    sc(n);
    int*l = new int[n];
    int*m = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    for(int i=0;i<n;i++) sc(m[i]);
    int boo = 1;
    for(int i=0;i<n;i++)
    {
      // cout<<"l[i]: "<<l[i]<<" m[i]: "<<m[i]<<endl;
      if(m[i]<l[i]) {boo = 0;break;}
      else if(m[i]>l[i] && n-i<3) {boo = 0;break;}
      else if(m[i]>l[i])
      {
        int c = m[i]-l[i];
        m[i]-=c;
        m[i+1]-=2*c;
        m[i+2]-=3*c;
      }
    }
    if(!boo) cout<<"NIE"<<endl;
    else cout<<"TAK"<<endl;
  }
  return 0;
}

/*

5
1 1 1 0 0

*/
