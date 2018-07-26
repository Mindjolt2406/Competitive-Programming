#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

bitset<33000> bs;
int size = 33001;
vi prime;

void sieve()
{
  bs.set();
  bs.set(0,false);bs.set(1,false);
  for(int i=2;i<32999;i++)
  {
    if(bs.test(i))
    {
      for(int j=i*i;j<32999;j+=i) bs.set(j,false);
      prime.pu(i);
    }
  }
}

int main()
{
  sieve();
  string s;
  getline(cin,s);
  while(s[0]!='0')
  {
    istringstream buf(s);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end); // done!
    vector<int> v;
    for(auto& s: tokens)
        v.pu(stoi(s));
    // for(auto i: v) cout<<i<<" ";cout<<endl;
    int prod = 1;
    for(int i=0;i<v.size();i+=2)
    {
      prod*=pow(v[i],v[i+1]);
    }
    prod--;
    vector<int> ans;
    int i=prime.size()-1,j=0;
    while(prod && i>=0)
    {
      // cout<<prime[i]<<" ";
      if(prod%prime[i]==0)
      {
        ans.pu(prime[i]);
        ans.pu(0);
        j++;
        while(prod%prime[i]==0)
        {
          ans[j]++;
          prod/=prime[i];
        }
        j++;
      }
      i--;
    }
    for(int i=0;i<ans.size()-1;i++) printf("%d ",ans[i]);//printf("\n");//cout<<ans[i]<<" ";cout<<endl;
    getline(cin,s);
    if(s[0]!='0') {printf("%d",ans[ans.size()-1]);printf("\n");}
    else {printf("%d",ans[ans.size()-1]);printf("\n");}
  }
  return 0;
}
/*
17 1
5 1 2 1
509 1 59 1
0

*/
