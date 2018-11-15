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
  int n;
  sc(n);
  int beg = 0,end  = INF-1;
  set<int> s1;
  cout<<0<<endl;
  fflush(stdout);
  int boo = 0,boo1 = 0;
  for(int i=0;i<n;i++)
  {
    string s;
    int mid;
    mid = (beg+end)/2;
    if(s=="black" && !boo) 
    {
      if(s1.find(mid)!=s1.end()) mid--;
      beg = mid+1;
    }
    else
    {
      if(s1.find(mid)!=s1.end()) mid++;
      end = mid-1;
    }
    cout<<mid<<endl;
    s1.insert(mid);
    fflush(stdout);
    scr(s);
    if(i==0) 
    {
      if(s=="black") boo = 0;
      else boo = 1;
    }
  }
  return 0;
}

//white

