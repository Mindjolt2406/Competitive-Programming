#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
#define mt make_tuple
#define INF 1000000001
#define ld long double
using namespace std;

ld calculate(ld x1,ld y1,ld x2,ld y2)
{
  return pow(x2-x1,2) + pow(y2-y1,2);
}

int main()
{
  ld x1,x2,x3,y1,y3,y2;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  ld dist1,dist2,dist3,dist;
  dist1 = calculate(x1,y1,x2,y2);
  dist2 = calculate(x3,y3,x2,y2);
  dist3 = calculate(x1,y1,x3,y3);
  if(dist2==dist3)
  {
    dist = dist2;
    ld t;
    t = x3;
    x3 = x2;
    x2 = t;
    t = y3;
    y3 = y2;
    y2 = t;
  }
  else if(dist1==dist3)
  {
    dist = dist3;
    ld t;
    t = x1;
    x1 = x2;
    x2 = t;
    t = y1;
    y1 = y2;
    y2 = t;
  }
  else dist = dist1;
  ld slope1,slope2,angle,angle1=0;
  slope1 =  (y2-y1)/(x2-x1);
  slope2 = (y3-y2)/(x3-x2);
  // cout<<slope1<<" "<<slope2<<endl;
  angle = atan((slope2-slope1)/(1+slope1*slope2));
  if(x1==x2) angle = atan(slope2);
  else if(x2==x3) angle = atan(slope1);
  // angle1 = sin((slope2-slope1)/(1+slope1*slope2));
  // cout<<angle1<<endl;
  ld n;
  angle = (angle*180)/3.14159265;
  // cout<<angle<<endl;
  if(x1==x2 || x2==x3) angle = 90-angle;
  if(angle<0) angle+=90;
  // cout<<angle<<endl;
  n = 360/(180-angle);
  ld ans = 0.25*n*pow(dist,2)*(1/tan(3.14159265/n));
  printf("%.10Lf\n",ans);
  // cout<<0.25*n*pow(dist,2)*(1/tan(3.14159625/n))<<endl;
  return 0;
}
