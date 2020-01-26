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

int count1 = 0;

void recur(set<int> s, vector<int> v,int n)
{
  if(s.empty())
  {
    count1++;
    cout<<count1<<endl;
    if(count1==1000000)
    {
      for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
      cout<<endl;
      return;
    }
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    // cout<<endl;
    return;
  }

  for(int i=0;i<=n;i++)
  {
    if(s.find(i)!=s.end())
    {
      v.pu(i);
      s.erase(i);
      recur(s,v,n);
      v.pop_back();
      s.insert(i);
    }
  }
}

int main()
{
  int n;
  // string s;
  // while(getline(cin,s))
  // {
  sc(n);
  set<int> s1;
  vector<int> v;
  for(int i=0;i<=n;i++) s1.insert(i);
  cout<<"ehre"<<endl;
  recur(s1,v,n);
  return 0;
}
