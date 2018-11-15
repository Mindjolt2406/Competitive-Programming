#include<bits/stdc++.h>
#define pu push_back
#define mt make_tuple
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int min1,max1;
  cin>>min1>>max1;
  int a1[3];
  cin>>a1[0]>>a1[1]>>a1[2];
  map<string,int> d;
  for(int i=0;i<n;i++)
  {
    string s;
    int a;
    cin>>s>>a;
    d[s] = a;
  }
  vector< tuple<set<string>,int*> > v;
  for(int i=0;i<m;i++)
  {
    string s1,s2;
    cin>>s1>>s2;
    int boo = 0;
    int a=-1,b=-1;
    for(int i=0;i<v.size();i++)
    {
      if(get<0>(v[i]).find(s1)!=get<0>(v[i]).end()) a = i;
      if(get<0>(v[i]).find(s2)!=get<0>(v[i]).end()) b = i;
    }
    // cout<<"A: "<<a<<" B: "<<b<<" "<<s1<<" "<<s2<<endl;
    if(a==b && a!=-1) {boo = 1;}
    else if(a!=b && a!=-1 && b!=-1)
    {
      boo = 1;
      // cout<<"ehre"<<endl;
      if(get<1>(v[a])[0]+get<1>(v[b])[0] <=a1[0] && get<1>(v[a])[1]+get<1>(v[b])[1] <=a1[1] && get<1>(v[a])[2]+get<1>(v[b])[2] <= a1[2] && get<0>(v[a]).size() + get<0>(v[b]).size()<=max1)
      {
        // cout<<"Entered "<<s1<<" "<<s2<<endl;
        // merge(get<0>(v[a]).begin(),get<0>(v[a]).end(),get<0>(v[b]).begin(),get<0>(v[b]).end(),get<0>(v[a]).begin());
        get<0>(v[a]).insert(get<0>(v[b]).begin(),get<0>(v[b]).end());
        for(int i=0;i<3;i++) get<1>(v[a])[i]+=get<1>(v[b])[i];
        v.erase(v.begin()+b);
      }
    }
    else if(a==-1 && b!=-1)
    {
      boo = 1;
      int c = d[s1];
      if(get<1>(v[b])[c-1]+1<=a1[c-1] && get<0>(v[b]).size()+1<=max1) {get<1>(v[b])[c-1]++; get<0>(v[b]).insert(s1);}
    }
    else if(a!=-1 && b==-1)
    {
      boo = 1;
      int c = d[s2];
      if(get<1>(v[a])[c-1]+1<=a1[c-1] && get<0>(v[a]).size()+1<=max1) {get<1>(v[a])[c-1]++; get<0>(v[a]).insert(s2);}
    }
    if(!boo)
    {
      int b = d[s1],c = d[s2];
      set<string> ss;
      ss.insert(s1);
      ss.insert(s2);
      int b1[3] = {0,0,0};
      b1[b-1]++;
      b1[c-1]++;
      v.pu(mt(ss,b1));
    }
  }
  vector<set<string> > v1;
  for(int i=0;i<v.size();i++)
  {
    if(get<0>(v[i]).size()<min1) continue;
    else v1.pu(get<0>(v[i]));
  }
  if(v1.empty()) cout<<"no groups"<<endl;
  else
  {
    int max2 = 0;
    for(int i=0;i<v1.size();i++) max2 = max(max2,(int)v1[i].size());
    vector<string> v2;
    for(int i=0;i<v1.size();i++)
    {
      if(v1[i].size()==max2)
      {
        set<string> :: iterator it;
        for(it = v1[i].begin();it!=v1[i].end();it++) v2.pu(*it);
      }
    }
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++) cout<<v2[i]<<endl;
  }
}

/*
 - total number of students
 - number of requests
 and  - minimum and maximum number of students in a group, respectively.
 ,  and  - maximum number of first, second and third grade students in a group, respectively.
 */
