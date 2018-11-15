#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int boo = 0;
  deque<int> q;
  while(n--)
  {
    char tmp[101];
    scanf("%100s", tmp);
    string s= tmp;
    if(boo==0)
    {
      if(s=="toFront")
      {
        int a;
        scanf("%d",&a);
        q.push_front(a);
      }
      else if(s=="push_back")
      {
        int a;
        scanf("%d",&a);
        q.push_back(a);
      }
      else if(s=="front")
      {
        if(q.empty()) {printf("No job for Ada?\n");continue;}
        printf("%d\n",q.front());
        q.pop_front();
      }
      else if(s=="back")
      {
        if(q.empty()) {printf("No job for Ada?\n");continue;}
        printf("%d\n",q.back());
        q.pop_back();
      }
      else if(s=="reverse")
      {
        boo  = 1;
      }
    }
    else
    {
      if(s=="push_back")
      {
        int a;
        scanf("%d",&a);
        q.push_front(a);
      }
      else if(s=="toFront")
      {
        int a;
        scanf("%d",&a);
        q.push_back(a);
      }
      else if(s=="back")
      {
        if(q.empty()) {printf("No job for Ada?\n");continue;}
        printf("%d\n",q.front());
        q.pop_front();
      }
      else if(s=="front")
      {
        if(q.empty()) {printf("No job for Ada?\n");continue;}
        printf("%d\n",q.back());
        q.pop_back();
      }
      else if(s=="reverse")
      {
        boo  = 0;
      }
    }
  }
  return 0;
}
