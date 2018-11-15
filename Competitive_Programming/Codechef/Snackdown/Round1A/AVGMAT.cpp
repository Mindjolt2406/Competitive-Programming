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
#define scr(s) {char temp[310];scanf("%s",temp);s = temp;}

using namespace std;

int check[300][300] = {0};

bool poss(int i,int j,int n,int m)
{
  if(i>=0 && j>=0 && i<n && j<m) return true;
  return false;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,m;
    sc(n);sc(m);
    vector<pair<int,int> > v;
    vector<string> l;
    for(int i=0;i<n;i++)
    {
      string s;
      scr(s);
      l.pu(s);
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(l[i][j]-'0') v.pu(mp(i,j));
    // for(int i=0;i<n;i++) for(int j=0;j<m;j++) {sc(l[i][j]);if(l[i][j]) v.pu(mp(i,j));}
    int count[610] = {0};
    for(int i=0;i<v.size();i++)
    {
      int a = v[i].first, b = v[i].second;
      for(int j=1;j<n+m-1;j++)
      {
        set<pair<int,int> >s;
        set<pair<int,int> > :: iterator it;
        for(int k=0;k<=j;k++)
        {
          int c,d;
          c = a+k, d  = b+j-k;
          s.insert(mp(c,d));
          c = a-k, d  = b-(j-k);
          s.insert(mp(c,d));
          c = a+k, d  = b-(j-k);
          s.insert(mp(c,d));
          c = a-k, d  = b+(j-k);
          s.insert(mp(c,d));
        }
        for(it=s.begin();it!=s.end();it++)
        {
          pair<int,int> p = *it;
          int c = p.first, d = p.second;
          if(poss(c,d,n,m) && l[c][d]-'0') count[j]++; 
        }
      }
      // cout<<a<<" "<<b<<" "<<count[1]<<endl;
    }
    // for(int i=0;i<n+m-1;i++) cout<<count[i]<<" ";cout<<endl;
    for(int i=1;i<n+m-1;i++) printf("%d ",count[i]/2);
    printf("\n");
  }
  return 0;
}

