#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pu push_back
using namespace std;

int main()
{
  map<string,int> d;
  map<string,int> e;
  vector<string> v;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    if(e.find(s)==e.end())
    {
      v.pu(s);
      e[s] = 1;
    }
    else e[s]++;
  }
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v.size();j++)
    {
      // char*a = new char[100];
      // a = v[i];
      // char*b = new char[100];
      // b =  v[j];
      if(i!=j && strstr(v[i].c_str(),v[j].c_str()))
      {
        if(d.find(v[i])!=d.end())d[v[i]]++;
        else d[v[i]] = 1;
      }
    }
  }
  vector< pair<int,string> > v1;
  for(int i=0;i<v.size();i++)
  {
    v1.pu(mp(d[v[i]],v[i]));
  }
  sort(v1.begin(),v1.end());
  int c = v1.size();
  int boo = 1;
  for(int i=0;i<c;i++)
  {
    if(v1[i].first!=i) {boo = 0;break;}
  }
  if(!boo) cout<<"NO"<<endl;
  else
  {
    cout<<"YES"<<endl;
    for(int i=0;i<v1.size();i++)
    {
      for(int j=0;j<e[v1[i].second];j++) cout<<v1[i].second<<endl;
    }
  }
  return 0;
}
