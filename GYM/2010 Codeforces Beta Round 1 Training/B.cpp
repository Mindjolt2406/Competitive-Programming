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
  for(int h=1;h<=t;h++)
  {
    set<string> s;
    int n;
    sc(n);
    ll count = 0;
    for(int i=0;i<n;i++)
    {
      string s1;
      scr(s1);
      s.insert(s1);
      set<string> ::iterator it,it1,it2,end;
      end = s.end();
      end--;
      it = s.find(s1);
      int count1 = 0,count2 = 0;
      if(it!=s.begin())
      {
        it1 = it;
        it1--;
        string s2 = *(it1);
        for(int i=0;i<min((int)s1.size(),(int)s2.size());i++)
        {
          if(s1[i]==s2[i]) count1++;
          else break;
        }
      }
      if(it!=(s.end()))
      {
        it2 = it;
        it2++;
        if(it2!=s.end())
        {
          string s2 = *(it2);
          for(int i=0;i<min((int)s1.size(),(int)s2.size());i++)
          {
            if(s1[i]==s2[i]) count2++;
            else break;
          }
        }
      }
      int c = max(count1,count2);
      if(c==s1.size()) {count--;}
      if(c!=0) count+=c+1;
      else count++;
    }
    printf("Case #%d: %lld\n",h,count);
  }
  return 0;
}
