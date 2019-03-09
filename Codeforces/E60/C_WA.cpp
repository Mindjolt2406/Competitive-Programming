#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int x1,x2,y1,y2;
  cin>>x1>>y1>>x2>>y2;
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(x1==x2 && y1==y2) {cout<<0<<endl;return 0;}
  int up = 0, right = 0;
  int x=x1,y=y1;
  if(x2>x1) right = 1;
  else if(x2==x1) right = 0;
  else right = -1;

  if(y2>y1) up = 1;
  else if(y1==y2) up = 0;
  else up = -1;

  int count = 0;
  int boo1=0,boo2=0,boo3=0,boo4=0;
  vector<int> v;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='U')
    {
      if(up>0) 
      {
        v.push_back(1);
        y1++;
        if(y2>y1) y1++;
        else if(x2>x1) x1++;
        else if(x1>x2) x1--;
      }
      else v.push_back(0);
      boo1 = 1;
    }
    else if(s[i]=='D')
    {
      if(up<0)
      {
        v.push_back(1);
        y1--;
        if(y2<y1) y1--;
        else if(x2>x1) x1++;
        else if(x2<x1) x1--;
      }
      else v.push_back(0);
      boo2 = 1;
    }
    else if(s[i]=='L')
    {
      if(right<0)
      {
        v.push_back(1);
        x1--;
        if(x1>x2) x1--;
        else if(y1>y2) y1--;
        else if(y1<y2) y1++; 
      }
      else v.push_back(0);
      boo3 = 1;
    }
    else
    {
      if(right>0)
      {
        v.push_back(1);
        if(x1<x2) x1++;
        else if(y1>y2) y1--;
        else if(y2>y1) y1++;
      }
      else v.push_back(0);
    }
    // count++;
    // // t(x1,x2,count);
    // v.push_back(abs(x-x1)+abs(y-y1));

    // if(x1==x2 && y1==y2) break;

    // // Update after every call
    // if(x2>x1) right = 1;
    // else if(x2==x1) right = 0;
    // else right = -1;

    // if(y2>y1) up = 1;
    // else if(y1==y2) up = 0;
    // else up = -1;

  }
  // t(count);
  // pr(v);
  ll sum1 = 0;
  for(int i=0;i<v.size();i++) sum1+=v[i];
  sum1*=2;

  if(sum1==0 && up!=0 && right!=0)
  {

    cout<<-1<<endl;
  } 
  else
  {
    ll dist = 2*min(abs(x-x2),abs(y-y2));
    // t(dist,sum1);
    ll a = 0,b = 0,count = 0,count1 = 0,counter = 0;
    if(sum1!=0)
    {
      a = dist/sum1;
      b = dist%sum1;
    }
    count = a*n;
    counter = 0;
    count1 = 0;
    for(int i=0;i<v.size() && b>0;i++)
    {
      counter+=v[i]*2;
      count1++;
      // t(counter,i,v[i]);
      if(counter>=b) break;
    }

    int xy = 0;
    if(abs(x-x2)>abs(y-y2)) xy = 1;
    else if(abs(x-x2)<abs(y-y2)) xy = 2;

    if(xy==1)
    {
      // UD
      int boo =0;
      for(int i=0;i<n;i++)  v[i] = 0;
      for(int i=0;i<n;i++)
      {
        if(right>0 && s[i]=='R') v[i] = 1;
        else if(right<0 && s[i]=='L') v[i] = 1;
        else if(s[i]=='U' || s[i]=='D')
        {
          boo^=1;
          if(boo) v[i] = 1;
        }
      }
    }
    else if(xy==2)
    {
      int boo =0;
      for(int i=0;i<n;i++)  v[i] = 0;
      for(int i=0;i<n;i++)
      {
        if(up>0 && s[i]=='U') v[i] = 1;
        else if(up<0 && s[i]=='D') v[i] = 1;
        else if(s[i]=='R' || s[i]=='L')
        {
          if(boo) v[i] = 1;
          boo^=1;
        }
      }
    }
    else {cout<<count+count1<<endl;return 0;}
    // t(count);
    int sum2 = 0;
    for(int i=0;i<v.size();i++) sum2+=v[i];
    sum2*=2;

    // t(sum2);
    if(sum1==0 && sum2==0) {cout<<-1<<endl; return 0;}
    dist = abs(abs(x2-x)-abs(y2-y));
    for(int i=count1;i<n && dist>0;i++)
    {
      dist-=v[i]*2;
      count++;
      if(dist<=0) break;
    }

    a = 0;b = 0;
    if(sum2!=0 && dist>0)
    {
      a = dist/sum2;
      b = dist%sum2;
    }
    count+=count1+a*n;
    for(int i=0;i<n && b>0;i++)
    {
      b-=v[i]*2;
      count++;
      if(b<=0) break;
    }

    if(count==0) cout<<-1<<endl;
    else cout<<count<<endl;
    // cout<<count<<endl;
  }
  // if(v[v.size()-1]==0) cout<<-1<<endl;
  // else
  // {
    
  //   int a = v[v.size()-1];
  //   t(a);
  //   if(a==abs(x-x2)+abs(y-y2)) {cout<<count<<endl; return 0;}
  //   ll dist = abs(x-x2)+abs(y-y2);
  //   ll b = dist/a;
  //   ll c = dist%a;
  //   ll count = b*n;
  //   for(int i=0;i<v.size();i++)
  //   {
  //     if(v[i]==c && c!=0) {count+=i+1; break;}
  //   }
  //   cout<<count<<endl;
  // }
  // cout<<count<<endl;
  return 0;
}

