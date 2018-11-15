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
  set<int > s;
  set<int> ::iterator it;
  // vector<pair<int,int> > v;
  vector<pair<int,int> > v;
  int count = 0;
  map<int,int> d;
  map<int,int> ::iterator it1;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    if(b!=n) 
    {
      cout<<"NO"<<endl;
      return 0;
    }
    if(d.find(a)==d.end()) d[a] = 1;
    else d[a]++;
    s.insert(a);
  }
  int count1 = 0;
  for(it1 = d.begin();it1!=d.end();it1++)
  {
    count1+=it1->second;
    if(it1->first<count1)
    {
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;

  map<int,vector<int> > d1;
  map<int,vector<int> > ::iterator it2;
  for(int i=0;i<n;i++)
  {
    if(s.find(i)!=s.end() && d[i] == 1)
    {
      s.erase(i);
      d[i] = 0;
      d1[i].pu(i);
    }
    else if(s.find(i)!=s.end())
    {
      d[i]--;
      d1[i].pu(i);
    }
  }
  for(int i = 1;i<n;i++)
  {
    if(d.find(i)!=d.end() && d[i]==0) continue;
    else
    {
      int c= *s.upper_bound(i);
      d1[c].pu(i);
      d[c]--;
      if(d[c]==0) s.erase(c);
    }
  }
  for(it2 = d1.begin();it2!=d1.end();it2++)
  {
    if(it2->second.size()==0) continue;
    for(int i=0;i<it2->second.size()-1;i++)
    {
      cout<<it2->second[i]<<" "<<it2->second[i+1]<<endl;
    }
    cout<<n<<" "<<it2->second[it2->second.size()-1]<<endl;
  }
  return 0;
}
