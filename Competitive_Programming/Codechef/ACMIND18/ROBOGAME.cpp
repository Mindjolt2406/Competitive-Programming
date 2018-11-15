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
#define scr(s) {char temp[100];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int  t;
  sc(t);
  while(t--)
  {
    string s;
    scr(s);
    int*l = (int*)calloc(100,sizeof(int));
    int boo = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]!='.')
      {
        int c = s[i]-'0';
        int b = max(0,i-c);
        l[b]++;
        l[c+i+1]--;
      }
      int sum1 = 0;
      for(int i=0;i<s.size();i++)
      {
        sum1+=l[i];
        if(sum1>=2) {boo = 1;break;}
      }
    }
    // for(int i=0;i<s.size();i++) cout<<l[i]<<" ";cout<<endl;
    if(boo) printf("unsafe\n");
    else printf("safe\n");
    free(l);
  }
  return 0;
}

