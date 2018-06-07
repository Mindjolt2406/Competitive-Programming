#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++) cin>>l[i];
    int a[(n+1)/2];
    int b[n/2];
    int c = 0,d = 0;
    for(int i=0;i<n;i++)
    {
      if(i%2==0) {a[c] = l[i];c++;}
      else {b[d] = l[i];d++;}
    }
    sort(a,a+(n+1)/2);
    sort(b,b+(n/2));
    int e = a[0];
    c=1;d=0;
    int i=1;
    int boo = 0;
    for(;i<n;i++)
    {
      if(i%2==1 && b[d]>=e){e = b[d];d++;}
      else if(i%2==0 && a[c]>=e){e = a[c];c++;}
      else {boo = 1;break;}
    }
    if(boo) cout<<"Case #"<<h<<": "<<i-1<<endl;
    else cout<<"Case #"<<h<<": "<<"OK"<<endl;
  }
}
