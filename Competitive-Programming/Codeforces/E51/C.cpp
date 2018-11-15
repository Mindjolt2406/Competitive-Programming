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
  int*l = (int*)calloc(101,sizeof(int));
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    int a;
    sc(a);
    l[a]++;
    v.pu(a);
  }
  int count1 = 0;
  for(int i=1;i<=100;i++) if(l[i]==1) count1++;
  if(count1%2==1)
  {
    // map<int,int> d;
    int a = -1;
    int boo = 1;
    for(int i=1;i<=100;i++)
    {
      if(l[i]>2) {boo = 0;a = i;} 
    }
    if(boo) cout<<"NO"<<endl;
    else
    {
      int boo1 = 0,boo2 = 0;
      string k;
      for(int i=0;i<v.size();i++)
      {
        if(l[v[i]]==1)
        {
          if(boo2==0) k+="A";
          else k+="B";
          boo2++;
          boo2%=2;
        }
        else if(v[i]==a && boo1==0)
        {
          boo1 = 1;
          k+="B";
        }
        else k+="A";
      }
      cout<<"YES"<<endl;
      cout<<k<<endl;
    }
  }
  else
  {
    int boo = 0;
    string k;
    for(int i=0;i<v.size();i++)
    {
      if(l[v[i]]==1)
      {
        if(boo==0) k+="A";
        else k+="B";
        boo++;
        boo%=2;
      }
      else k+="A";
    }
    cout<<"YES"<<endl;
    cout<<k<<endl;
  }
  return 0;
}

