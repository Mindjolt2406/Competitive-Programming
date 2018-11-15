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

void primeFactors(int n,vector<int> &v) 
{ 
  while (n%2 == 0) 
  { 
    v.pu(2);
    n = n/2; 
  }

  for (int i = 3; i <= sqrt(n); i = i+2) 
  { 
    while (n%i == 0) 
    { 
      v.pu(i);
      n = n/i; 
    } 
  } 

  if (n > 2) v.pu(n);
} 
  

int main()
{
  vector<int> vn,vm,vk;
  ll n,m;
  int k;
  scll(n);scll(m);sc(k);
  ll prod = (2*n*m)/k;
  if((2*n*m)%k!=0) {cout<<"NO"<<endl;return 0;}
  multiset<int> s;
  multiset<int> :: iterator it;
  int i=0,prodn = 1,prodm = 1;
  int n1 = n,m1 = m;
  primeFactors(n,vn);
  primeFactors(m,vm);
  primeFactors(k,vk);
  s.insert(2);
  for(int i=0;i<vn.size();i++) s.insert(vn[i]);
  for(int i=0;i<vm.size();i++) s.insert(vm[i]);
  for(int i=0;i<vk.size();i++) s.erase(s.find(vk[i]));
  for(it=s.begin();it!=s.end();)
  {
    if(n1%(*it)==0)
    {
      n1/=(*it);
      prodn*=(*it);
      it = s.erase(it);
    }
    else if(m1%(*it)==0)
    {
      m1/=(*it);
      prodm*=(*it);
      it = s.erase(it);
    }
    else it++;
  }
  for(it=s.begin();it!=s.end();)
  {
    if(*it*prodn<=n) {prodn*=(*it);it++;}
    else if(*it*prodm<=m) {prodm*=(*it);it++;}
  }

  // prod/=2;
  // cout<<"prod: "<<prod<<endl;
  // for(it=s.begin();it!=s.end()&&n1;)
  // {
  //   // cout<<"*it: "<<*it<<endl;
  //   if(n1%(*it)==0) 
  //   {
  //     if(prodn*(*it)>n) break;
  //     n1/=*it;
  //     prodn*=(*it);
  //     it = s.erase(it);
  //   }
  //   else it++;
  // }
  // // cout<<s.size()<<endl;
  // for(it=s.begin();it!=s.end() && m1;)
  // {
  //   prodm*=(*it);
  //   it++;
  // }
  cout<<"YES"<<endl;
  cout<<0<<" "<<0<<endl;
  cout<<prodn<<" "<<0<<endl;
  cout<<0<<" "<<prodm<<endl;
  return 0;
}

