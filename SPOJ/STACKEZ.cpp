#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  stack<long long int> s;
  while(t--)
  {
    int a;
    scanf("%d",&a);
    if(a==1)
    {
      long long int b;
      scanf("%lld",&b);
      s.push(b);
    }
    else if(a==2)
    {
      if(s.empty()) continue;
      else s.pop();
    }
    else if(a==3)
    {
      if(s.empty()) printf("Empty!\n");
      else printf("%lld\n",s.top());
    }
    else{t++;continue;}
  }
  return 0;
}
