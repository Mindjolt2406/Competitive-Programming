#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<string> v;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    v.pu(s);
  }
  map<string,int> d;
  map<int,string> e;
  d["green"] = 0;
  d["blue"] = 1;
  d["red"] = 2;
  d["yellow"] = 3;
  d["purple"] = 4;
  d["orange"] = 5;
  int l[6] = {0};
  e[0] = "Time";
  e[1] = "Space";
  e[2] = "Reality";
  e[3] = "Mind";
  e[4] = "Power";
  e[5] = "Soul";
  cout<<6-n<<endl;
  for(int i=0;i<n;i++) l[d[v[i]]] = 1;
  for(int i=0;i<6;i++)
  {
    if(l[i]==0) cout<<e[i]<<endl;
  }
}
