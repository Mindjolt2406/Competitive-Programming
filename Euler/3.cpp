#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  long int i = 2;
  long int max = 3;
  while (i<pow(n,0.5)+1)
  {
    while ((n%i)==0)
    {
      if(max<i) max = i;
      n/=i;
    }
    if(i==2)i+=1;
    else i+=2;
  }
  if (n>2)
  {
    if(max<n) max = n;
  }
  cout<<max<<endl;
  return 0;
}
