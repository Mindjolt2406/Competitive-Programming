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
    int n;string s;
    sc(n);scr(s);
    int count1 = 0,count2 = 0;
    for(int i=0;i<n;i++)
    {
      string s;
      scr(s);
      if(s[0]==s[s.size()-1] && s[0]=='0') count1++;
      else if(s[0]==s[s.size()-1] && s[0]=='1') count2++;
    }
    // cout<<count1<<" "<<count2<<endl;
    if(s=="Dee")
    {
      if(count1<=count2) cout<<"Dee"<<endl;
      else cout<<"Dum"<<endl;
    }
    else
    {
      if(count2<=count1) cout<<"Dum"<<endl;
      else cout<<"Dee"<<endl;
    }
    // else if(count2>count1) cout<<"Dum"<<endl;
    // else cout<<s<<endl;
  }
  return 0;
}

