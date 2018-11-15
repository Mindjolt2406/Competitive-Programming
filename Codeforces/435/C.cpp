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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n,k;
  sc(n);sc(k);
  set<int> s,s1;
  set<int> :: iterator it;
  int a = 524287;
  int c = 10;
  if(n==2 && k==0) {cout<<"NO"<<endl;return 0;}

  if(n%4==1) {s.insert(k);n--;s1.insert(k);}
  else if(n%4==2)
  {
    if(k==0) 
    {
      // cout<<"here"<<endl;
      s.insert(1<<17);s.insert(2<<17);s.insert(3<<17);
      s.insert(7<<14);s.insert(9<<14);s.insert(14<<14);
      n-=6;
    }
    else
    {
      s.insert(0);s.insert(k);
      s1.insert(0);s1.insert(k);
      n-=2;
    }
  }
  else if(n%4==3)
  {
    if(k==0)
    {
      s.insert(1<<17);s.insert(2<<17);s.insert(3<<17);
      s1.insert(1<<17);s1.insert(2<<17);s1.insert(3<<17);
      n-=3;
    }
    else
    {
      s.insert(1<<17);s.insert(k^(1<<17));s.insert(0);
      s1.insert(k^(1<<17));s1.insert(1<<17);s1.insert(0);
      n-=3;
    }
  }
  else
  {
    s.insert(k);
    s.insert(1<<17);s.insert(2<<17);s.insert(3<<17);
    s1.insert(1<<17);s1.insert(2<<17);s1.insert(3<<17);s1.insert(k);
    n-=4;
  }

  while(n)
  {
    if(c!=k && s1.find(c)==s1.end() && s1.find(a-c)==s1.end() && c!=a-c) {s.insert(c);s.insert(a-c);n-=2;} 
    c++;
  }
  // cout<<s.size()<<endl;
  cout<<"YES"<<endl;
  for(it=s.begin();it!=s.end();it++) cout<<*it<<" "; cout<<endl;
  return 0;
}

