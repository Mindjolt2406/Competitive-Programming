#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
  int n;
  setprecision(6);
  cin>>n;
  long double PI = 4.0 * atan(1.0);
  long double min1 = 1000,max1 = -1000;
  while(n--)
  {
    int x,y;
    cin>>x>>y;
    long double t = atan2(y,x);
    t = (t*180)/PI;
    
    if(t>180)t-=360;
    else if(t<-180)t+=360;
    if(max1<t)max1 = t;
    if(min1>t)min1 = t;
  }
  printf("%.10Lf\n",max1-min1);
  // cout.precision(6);
  // cout<<fixed;
  // cout<<(max1-min1)<<endl;
  return 0;
}
