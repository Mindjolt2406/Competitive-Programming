#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pu push_back
#define INF 10000
using namespace std;

int main()
{
  string s;
  cin>>s;
  if(s[0]=='0') {cout<<-1<<endl;return 0;}
  int n = s.size();
  int a=-1,b=-1,c=-1,d=-1,e=-1; //a,b for 0s, c for the 5, d for the 2 and e for the 7
  int boo = 0;
  for(int i=n-1;i>=0;i--)
  {
    if(a==-1 && s[i]=='0') a = i;
    else if(b==-1 && s[i]=='0') b = i;
    else if(c==-1 && s[i]=='5') c = i;
    else if(d==-1 && s[i]=='2') d = i;
    else if(e==-1 && s[i]=='7') e = i;
  }
  if(a!=-1)a = n-1-a;
  if(b!=-1)b = n-1-b;
  if(c!=-1)c = n-1-c;
  if(d!=-1)d = n-1-d;
  if(e!=-1)e = n-1-e;
  // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
  if((a!=-1 && b!=-1) || (d!=-1 && c!=-1) || (a!=-1 && c!=-1) || (e!=-1 && c!=-1))
  {
    //a,b for 0s, c for the 5, d for the 2 and e for the 7
    int min1 = INF,boo = 0;
    if(a!=-1 && b!=-1)  { min1  = min(min1,a+b-1);}
    if(d!=-1 && c!=-1)
    {
      if(c+d-1==min1) boo =1;
      else boo = 0;
      min1  = min(min1,c+d-1);
      if(c>d && min1==c+d-1 && !boo)min1++;
    }
    if(a!=-1 && c!=-1)
    {
      if(c+a-1==min1) boo =1;
      else boo = 0;
      min1  = min(min1,a+c-1);
      if(a>c && min1==a+c-1 && !boo)min1++;
    }
    if(e!=-1 && c!=-1)
    {
      if(c+e-1==min1) boo =1;
      else boo = 0;
      min1  = min(min1,c+e-1);
      if(c>e && min1==c+e-1 && !boo)min1++;
    }
    cout<<min1<<endl;
  }
  else cout<<-1<<endl;
  return 0;
}
