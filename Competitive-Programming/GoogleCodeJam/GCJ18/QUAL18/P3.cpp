#include<cmath>
#include<iostream>
#include<iomanip>
#define PI 3.14159265359
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    long double a;
    cin>>a;
    if(a<=1.414213)
    {
      long double theta = 45 - ((acos(a/(sqrt(2))))*180)/PI;
      // cout<<"theta: "<<theta<<endl;
      cout<<"Case #"<<h<<":"<<endl;
      cout<<fixed;
      cout<<setprecision(10)<<(sin((PI*theta)/180))/2<<" "<<0.5*cos((PI*theta)/180)<<" "<<0.0<<endl;
      cout<<setprecision(10)<<(-0.5*cos((PI*theta)/180))<<" "<<0.5*sin((PI*theta)/180)<<" "<<0.0<<endl;
      cout<<0.0<<" "<<0.0<<" "<<0.5<<endl;
    }
    else
    {
      
    }
  }
  return 0;
}
