#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.14159265
using namespace std;

int main()
{
  int n;
  setprecision(10);
  cin>>n;
  long double min = 1000L,max = 0L;
  while(n--)
  {
    int x,y;
    cin>>x>>y;
    long double t = atan2(y,x);
    t = (t*180)/PI;
    if(t>180)t-=360;
    if(max<t)max = t;
    if(min>t)min = t;
  }
  cout.precision(10);
  cout<<fixedl
  cout<<max-min<<endl;
  return 0;
}
