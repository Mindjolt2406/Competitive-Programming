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
  int t;
  sc(t);
  while(t--)
  {
    ld count = 0;
    int k;
    sc(k);
    map<string,ld> d;
    for(int i=0;i<k;i++)
    {
      string s;
      scr(s);
      int n = s.size();
      int boo = 0;
      if(s[0]=='d'||s[0]=='f')  boo = 1;
      ld count1 = 0;
      count1+=2;
      for(int i=1;i<n;i++)
      {
        int boo1 = 0;
        if(s[i]=='d'||s[i]=='f')  boo1 = 1;
        if(boo1 == boo) count1+=4;
        else count1+=2;
        boo = boo1;
      }
      // cout<<"s: "<<s<<" count: "<<count1<<endl;
      if(d.find(s)!=d.end()) count+=count1/2;
      else {count+=count1;d[s] = count;}
    }
    cout<<count<<endl;
  }
  return 0;
}

