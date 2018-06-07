#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n;
    string s;
    cin>>n>>s;
    // cout<<s<<endl;
    vector <int> v;
    int countswap = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='C') v.push_back(0);
      else v.push_back(1);
    }
    long long count = 0;
    long long prod = 1;
    int k=0;
    // cout<<count<<" "<<prod<<endl;
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    // cout<<endl;
    // cout<<"v: "<<v.size()<<endl;
    while(k<v.size())
    {
      if(v[k]==0) {prod*=2;k++;}
      else
      {
        int counter = 0;
        while(v[k]==1 && k<v.size())
        {
          counter++;
          k++;
        }
        count+=prod*(counter);
        // cout<<"prod: "<<prod<<endl;
        // cout<<"count: "<<count<<endl;
      }
    }
    // cout<<"count: "<<count<<endl;
    int boo = 0;
    if(v.size()!=0){
    for(int i=v.size()-1;i>=0;i--)
    {
      if(v[i]==1) continue;
      else if(i==v.size()-1){prod/=2;continue;}
      else
      {
        int j = i;
        while(j+1<=v.size()-1 && v[j+1] == 1 && count>n && prod)
        {
          int temp = v[j+1];
          v[j+1] = v[j];
          v[j] = temp;
          countswap++;
          count-=(prod/2);
          j++;
          // cout<<"count: "<<count<<" j: "<<j<<endl;
          // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
          // cout<<endl;
        }
        prod/=2;
        if(count<=n) boo = 1;
      }
      if(boo) break;
    }}
    // cout<<"count: "<<count<<" n: "<<n<<endl;
    if(boo || count<=n) cout<<"Case #"<<h<<": "<<countswap<<endl;
    else cout<<"Case #"<<h<<": IMPOSSIBLE"<<endl;
    v.clear();
  }
  return 0;
}
/*
10
1 CS
1 CSS
2 CSS
1 CCS
2 CCSS
6 SSSSSS
7 SSSSSS
5 SSSSSS
5 SSSSS

*/
