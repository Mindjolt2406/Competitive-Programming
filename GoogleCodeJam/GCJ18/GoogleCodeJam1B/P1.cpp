#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int a,n;
    cin>>a>>n;
    long long int k = a;
    long double e = (long double)1/a;
    // cout<<"e: "<<e<<endl;
    vector<pair <long double,long double> > v;
    for(int i=0;i<n;i++)
    {
      double c,d;
      cin>>c;
      k-=c;
      c/=a;
      c*=100;
      v.pu(m(c - (int)c,c));
    }
    // for(int i=0;i<n-a;i++)v.pu(m(0,0.000001));
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long int count = 0;
    // for(int i=0;i<n;i++)
    // {
    //   cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    // cout<<"e: "<<e*100<<endl;
    for(int i=0;i<n;i++)
    {
      // cout<<"Count: "<<count<<endl;
      if(v[i].first >=0.5) {count+=(long long int)v[i].second+1;continue;}
      else if(v[i].first==0) {count+=(long long int)v[i].second;}
      else
      {
        long double d = ceil((0.5 - v[i].first)/(e*100 - (int)(e*100)));
        // cout<<"d: "<<d<<" k: "<<k<<" e*d*100: "<<e*d*100<<endl;
        if(k-d>=0) {count+=1+(long long int)v[i].second +d*(long long int)(e*100);k-=d;}
        else count+=(long long int)v[i].second;
      }
    }
    // cout<<"Count: "<<count<<" k: "<<k<<" e: "<<e<<" product: "<<e*k*100<<endl;
    long double c = (e*100 - ((int)(e*100)));
    // cout<<"c: "<<c<<endl;
    if ((c-0.5)>=0) {count+= k*(((long long int)(e*100)) +1);}
    else if(c==0) count+=k*((long long int)(e*100));
    else
    {
      long long int d = ceil((0.5 - c)/c);
      // cout<<"d: "<<d<<endl;
      count+= ((long long int)((double)k/d)) + (k/d)*((long long int)(e*100));
      count+=(k%d)*((long long int)(e*100));
    }
    // count+= ((double)k/a)*100;
    cout<<"Case #"<<h<<": "<<count<<endl;
  }
}

/*
4
3 2
1 1
10 3
1 3 2
6 2
3 1
9 8
1 1 1 1 1 1 1 1

1 7 2 1 1

*/
