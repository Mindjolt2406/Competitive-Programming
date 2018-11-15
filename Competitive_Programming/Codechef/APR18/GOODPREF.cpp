#include <iostream>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    int n;
    cin>>s>>n;
    vector< pair <int,int> > v1,v2,v3;
    int a=0,b=0;
    int count = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='a') a++;
      else b++;
      if(a<b) v1.pu(m(a,b));
      else if(a==b) v2.pu(m(a,b));
      else v3.pu(m(a,b));
    }
    // cout<<"a: "<<a<<" b: "<<b<<endl;
    if(a==b) count+=(n*v3.size());
    else if(a<b)
    {
      // count+=v3.size();
      // cout<<"count: "<<count<<endl;
      for(int i=0;i<v3.size();i++)
      {
        int c= floor((v3[i].first - v3[i].second)/(float)(b-a));
        // cout<<"first: "<<v1[i].first<<" second: "<<v1[i].second<<" c: "<<c<<endl;
        if(c>n-1) {count+=n;}
        else count+=c+1;
      }
    }
    else
    {
      count+=(n*v3.size());
      // cout<<"count: "<<count<<endl;
      count+=((n-1)*v2.size());
      // cout<<"count: "<<count<<endl;
      for(int i=0;i<v1.size();i++)
      {
        // cout<<"count: "<<count<<endl;
        int c =floor((v1[i].second - v1[i].first)/(float)(a-b));
        // cout<<"first: "<<v1[i].first<<" second: "<<v1[i].second<<" c: "<<c<<endl;
        count+= max(n-1-c,0);
        // cout<<"count: "<<count<<endl;
      }

    }
    // for(int i=0;i<v1.size();i++) cout<<v1[i].first<<" "<<v1[i].second<<endl;
    // cout<<endl;
    // for(int i=0;i<v2.size();i++) cout<<v2[i].first<<" "<<v2[i].second<<endl;
    // cout<<endl;
    // for(int i=0;i<v3.size();i++) cout<<v3[i].first<<" "<<v3[i].second<<endl;
    // cout<<endl;
    cout<<count<<endl;
  }
	return 0;
}
