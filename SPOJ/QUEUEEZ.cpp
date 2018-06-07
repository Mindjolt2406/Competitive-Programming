#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  queue<long long int> q;
  scanf("%d",&n);
  while(n--)
  {
    int a;
    scanf("%d",&a);
    if(a==1)
    {
      long long int b;
      scanf("%lld",&b);
      q.push(b);
    }
    else if(a==2)
    {
      if(q.empty()) continue;
      else q.pop();
    }
    else if(a==3)
    {
      if(q.empty()) printf("Empty!\n");
      else printf("%lld\n",q.front());
    }
  }
  return 0;
}
