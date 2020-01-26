#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;

long double dot(long double*l, long double*m)
{
  return l[0]*m[0]+l[1]*m[1]+l[2]*m[2];
}

long double mod2(long double*l)
{
  return l[0]*l[0]+l[1]*l[1]+l[2]*l[2];
}

long double calculate(long double lambda,long double* p, long double* q, long double* d, long double* o, long double* a, long double* b)
{
  for(int i=0;i<3;i++) a[i] = p[i] + lambda*d[i];
  for(int i=0;i<3;i++) b[i] = q[i] - a[i];
  long double* temp = new long double[3];
  long double* c = new long double[3];
  for(int i=0;i<3;i++) temp[i] = a[i] - o[i];
  long double temp1 = dot(b,temp)/mod2(b);
  for(int i=0;i<3;i++)
  {
    c[i] = a[i] - temp1*b[i];
    // cout<<c[i]<<" ";
  }
  for(int i=0;i<3;i++) temp[i] = c[i]-o[i];
  return mod2(temp);
}

int main()
{
  long double *p = new long double[3];
  long double *d = new long double[3];
  long double *q = new long double[3];
  long double *o = new long double[3];
  long double *a = new long double[3];
  long double *b = new long double[3];
  int t;
  cin>>t;
  while(t--)
  {
    long double r;
    cin>>p[0]>>p[1]>>p[2]>>q[0]>>q[1]>>q[2]>>d[0]>>d[1]>>d[2]>>o[0]>>o[1]>>o[2]>>r;
    r*=r;
    long double beg = 0;
    long double end = 1000000001,mid,min1 = INF;
    while(beg<=end)
    {
      mid = (beg+end)/2;
      long double c = calculate(mid,q,p,d,o,a,b);
      // cout<<"mid: "<<mid<<" c: "<<c<<" r: "<<r<<endl;
      if(abs(r-c)<0.0000001){if(min1==mid) {min1 = min(min1,mid);break;} min1 = min(min1,mid);end = mid-0.0000001;}
      else if(r>c) beg = mid+0.0000001;
      else end = mid-0.0000001;
    }
    printf("%.10Lf\n",mid);
  }
}
