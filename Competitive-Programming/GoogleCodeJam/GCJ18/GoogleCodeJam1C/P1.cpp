#include<bits/stdc++.h>
#define MOD 1000000007
#define pu push_back
using namespace std;

void print(vector < set<string> > v)
{
  set <string>::iterator it;
  for(int i=0;i<v.size();i++)
  {
    cout<<i<<": ";
    for(it=v[i].begin();it!=v[i].end();it++) cout<<(*it)<<" ";
    cout<<endl;
  }
}
int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n,k;
    cin>>n>>k;
    vector < set <string> > v(k, set<string>());
    vector < set <char> > v1(k, set<char>());
    // set <string> s1;
    // set <char> s2;
    // for(int i=0;i<k;i++) {v.pu(s1);v1.pu(s2);}
    for(int i=0;i<n;i++)
    {
      string s,s1;
      cin>>s;
      s1 ="";
      for(int j=0;j<k;j++) {s1+=s[j]; v[j].insert(s1); v1[j].insert(s[j]);}
    }
    if(k==1) {cout<<"Case #"<<h<<": -"<<endl;continue;}
    // print(v);
    vector <string> l;
    set <string> :: iterator iter;
    set <char> :: iterator it;
    iter = v[0].begin();
    while(iter!= v[0].end()) {l.pu(*iter); iter++;}
    // for(iter=v[0].begin(),iter!=v[0].end();(iter++)) l.pu((*iter));
    for(int i=1;i<k;i++)
    {
      vector < string> m;
      int count = 0,boo = 0;
      it = v1[i].begin();
      // for(iter=v[i].begin();iter!=v[i].end();iter++) cout<<(*iter)<<" ";
      // cout<<endl;
      while(m.size()<n+2 && count<n && it!=v1[i].end())
      {
        for(int j=1;j<l.size();j++)
        {
          if(v[j].find((l[j]+(*it))) == v[j].end()) m.pu(l[j] + (*it));
          else {count++;}
          if(m.size()>=n+2 || count>=n || it==v1[i].end()) {break;boo = 1;}
          // cout<<"m: "<<c<<" count: "<<count<<" string: "<<l[j]+(*it)<<endl;
          // for(int i=0;i<m.size();i++) cout<<m[i]<<" "; cout<<endl;
        }
        if(boo) break;
        it++;
      }

      // for(int i=0;i<m.size();i++) cout<<m[i]<<" "; cout<<endl;
      l = m;
    }
    if(l.size()!=0) cout<<"Case #"<<h<<": "<<l[0]<<endl;
    else cout<<"Case #"<<h<<": -"<<endl;
  }
  return 0;
}

/*
5
4 1
A
B
C
D
4 2
WW
AA
SS
DD
4 2
AA
AB
BA
BB
3 4
CAKE
TORN
SHOW
5 7
HELPIAM
TRAPPED
INSIDEA
CODEJAM
FACTORY

1
4 2
WW
AA
SS
DD

*/
