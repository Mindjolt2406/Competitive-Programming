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

tuple<ld,ld,ld> getline(ld x1,ld y1,ld x2,ld y2)
{
  ld a = y1-y2;
  ld b = x2-x1;
  ld c = x1*(y2-y1) - y1*(x2-x1);
  return mt(a,b,c);
}

int checksq(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3,ld x4,ld y4,ld x,ld y)
{
  tuple<ld,ld,ld> t = getline(x1,y1,x2,y2);
  ld a = get<0>(t);
  ld b = get<1>(t);
  ld c = get<2>(t);
  int boo = 0;
  if(a*x + b*y + c == 0 || a*x3 + b*y3 +c ==0) boo = 1;
  else if(a*x + b*y + c >= 0 && a*x3 + b*y3 +c >= 0) boo = 1;
  else if(a*x + b*y + c <= 0 && a*x3 + b*y3 +c <=0) boo = 1;
  if(!boo) return 0;
  t = getline(x3,y3,x4,y4);
  a = get<0>(t);
  b = get<1>(t);
  c = get<2>(t);
  boo = 0;
  if(a*x + b*y + c == 0 || a*x1 + b*y1 +c ==0) boo = 1;
  else if(a*x + b*y + c >= 0 && a*x1 + b*y1 +c >= 0) boo = 1;
  else if(a*x + b*y + c <= 0 && a*x1 + b*y1 +c <=0) boo = 1;
  if(!boo) return 0;

  t = getline(x1,y1,x4,y4);
  a = get<0>(t);
  b = get<1>(t);
  c = get<2>(t);
  boo = 0;
  if(a*x + b*y + c == 0 || a*x3 + b*y3 +c ==0) boo = 1;
  else if(a*x + b*y + c >= 0 && a*x3 + b*y3 +c >= 0) boo = 1;
  else if(a*x + b*y + c <= 0 && a*x3 + b*y3 +c <=0) boo = 1;
  if(!boo) return 0;
  t = getline(x3,y3,x2,y2);
  a = get<0>(t);
  b = get<1>(t);
  c = get<2>(t);
  boo = 0;
  if(a*x + b*y + c == 0 || a*x1 + b*y1 +c ==0) boo = 1;
  else if(a*x + b*y + c >= 0 && a*x1 + b*y1 +c >= 0) boo = 1;
  else if(a*x + b*y + c <= 0 && a*x1 + b*y1 +c <=0) boo = 1;
  if(!boo) return 0;
  // cout<<"x: "<<x<<" y: "<<y<<endl;
  return 1;
}

int main()
{
  ld x1,x2,x3,x4,x5,x6,x7,x8,y1,y2,y3,y4,y5,y6,y7,y8;
  scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6,&x7,&y7,&x8,&y8);
  // if (checksq(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5)) printf("YES\n");
  // else if(checksq(x1,y1,x2,y2,x3,y3,x4,y4,x6,y6)) printf("YES\n");
  // else if(checksq(x1,y1,x2,y2,x3,y3,x4,y4,x7,y7)) printf("YES\n");
  // else if(checksq(x1,y1,x2,y2,x3,y3,x4,y4,x8,y8)) printf("YES\n");
  // else if(checksq(x5,y5,x6,y6,x7,y7,x8,y8,x1,y1)) printf("YES\n");
  // else if(checksq(x5,y5,x6,y6,x7,y7,x8,y8,x2,y2)) printf("YES\n");
  // else if(checksq(x5,y5,x6,y6,x7,y7,x8,y8,x3,y3)) printf("YES\n");
  // else if(checksq(x5,y5,x6,y6,x7,y7,x8,y8,x4,y4)) printf("YES\n");
  // else printf("NO\n");
  int boo = 0;
  for(int i=-100;i<=100;i++)
  {
    for(int j=-100;j<=100;j++)
    {
      if(checksq(x1,y1,x2,y2,x3,y3,x4,y4,i,j) && checksq(x5,y5,x6,y6,x7,y7,x8,y8,i,j)) {boo = 1;break;}
    }
  }
  if(boo) printf("YES\n");
  else printf("NO\n");
  return 0;
}
