#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n],m[n];
  for(int i=0;i<n;i++) cin>>l[i];
  for(int i=0;i<n;i++) cin>>m[i];
  if(n==1)
  {
    if((l[0]^m[0])==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  int c;
  if(l[0]!=0) c = l[0];
  else c = l[1];
  int k;
  for(int i=0;i<n;i++) if(m[i]==c){k = i;break;}
  int boo = 0;
  int i=0,j=k;
  while(i<n)
  {
    j%=n;
    if(l[i]==0) i++;
    else if(m[j]==0) j++;
    else if(l[i]==m[j]) {i++;j++;}
    else {boo=1;break;}
  }
  if(boo==1) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}
