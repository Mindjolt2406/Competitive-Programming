#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
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
    int f,e,a,b;
    sc(f);sc(e);sc(a);sc(b);
    vector<pair<int,int> > v;
    for(int i=0;i<e;i++) {int a,b;sc(a);sc(b);v.pu(mp(a,b));}
    int boo = 0;
    for(int i=0;i<e;i++)
    {
      int x = v[i].first,y = v[i].second;
      cout<<"a: "<<a<<" b: "<<b<<" x: "<<x<<" y: "<<y<<endl;
      if(b>=y && b<f && a<f && a>=y && y%x==a%x && y%x==b%x) {boo = 1;break;}
    }
    if(boo) printf("It is possible to move the furniture.\n");
    else printf("The furniture cannot be moved.\n");
  }
  return 0;
}

/*
2
22 4 0 6
3 2
4 7
13 6
10 0
1000 2 500 777
2 0
2 1

*/
