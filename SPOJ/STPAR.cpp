#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  while(n)
  {
    int l[n];
    stack <int> s;
    queue<int> q;
    for(int i=0;i<n;i++) {scanf("%d",&l[i]);q.push(l[i]);}
    int i = 1,boo = 0;
    while(i<=n)
    {
      if(q.front()!=i)
      {
        if(s.empty()){s.push(q.front());q.pop();}
        else if(s.top()==i){s.pop();i++;continue;}
        else if(s.top()>q.front()) {s.push(q.front());q.pop();}
        else {printf("no\n"); boo = 1;break;}
      }
      else {q.pop();i++;}
    }
    if(!boo) printf("yes\n");
    scanf("%d",&n);
  }
  return 0;
}
