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


void recur(set<int> s, vector<int> v,int n,vector<vector<int> > &v1,int boo)
{
  if(s.empty())
  {
    if(boo && v[0]!=7 && v[0]!=4)v1.pu(v);
    else if(!boo) v1.pu(v);
    return;
  }

  for(int i=1;i<=n;i++)
  {
    if(s.find(i)!=s.end())
    {
      v.pu(i);
      s.erase(i);
      recur(s,v,n,v1,boo);
      v.pop_back();
      s.insert(i);
    }
  }
}

int main()
{
  int n;
  string s;
  set<int> prime;
  vector <int> prime1 = {2,3,5,7,11,13,17,19,23,29,31};
  prime.insert(prime1.begin(),prime1.end());
  int count = 1;
  int fact[7] = {1,1,2,6,24,120,720};
  while(getline(cin,s))
  {
    printf("Case %d:\n",count);
    vector<vector<int> > v1,v2;
    n = stoi(s);
    if(n==2) {printf("1 2\n\n");continue;}
    set<int> s1,s2;
    vector<int> v;
    for(int i=1;i<=n/2;i++) s1.insert(i);
    for(int i=1;i<=n/2 - 1;i++) s2.insert(i);
    recur(s1,v,n/2,v1,1);
    recur(s2,v,n/2-1,v2,0);
    for(int i=0;i<v1.size();i++)
    {
      vector<int> v3 = v1[i];
      // if(v3[i]==7 || v3[i]==4) continue;
      for(int i1 = 0;i1<v3.size();i1++) v3[i1]*=2;
      int j = 0;
      while(j<v2.size())
      {
        vector<int> v4 = v2[j];
        // The inner loop if conditions
        if(v3[0]==16)
        {
          if(2*v4[0]+1== 5 || 2*v4[0]+1== 11 || 2*v4[0]+1== 9) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==12)
        {
          if(2*v4[0]+1== 3 || 2*v4[0]+1== 13 || 2*v4[0]+1== 9 || 2*v4[0]+1== 15) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==10)
        {
          if(2*v4[0]+1== 5 || 2*v4[0]+1== 11 || 2*v4[0]+1== 15) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==6)
        {
          if(2*v4[0]+1== 3 || 2*v4[0]+1== 9 || 2*v4[0]+1== 15) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==6)
        {
          if(2*v4[0]+1== 3 || 2*v4[0]+1== 9 || 2*v4[0]+1== 15) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==4)
        {
          if(2*v4[0]+1== 5 || 2*v4[0]+1== 11) {j+=fact[n/2-2];continue;}
        }
        else if(v3[0]==2)
        {
          if(2*v4[0]+1== 7 || 2*v4[0]+1== 13) {j+=fact[n/2-2];continue;}
        }
        // If conditions end
        for(int j1 = 0;j1<v4.size();j1++) v4[j1] = 2*v4[j1] + 1;
        int k = 1,boo = 1;
        if(prime.find(1+v3[0])!=prime.end() && prime.find(1+v3[n/2-1])!=prime.end()) boo = 0;
        while(k<n-1)
        {
          if(k%2==1)
          {
            if(prime.find(v3[k/2]+v4[k/2])==prime.end()){boo = 1;break;}
          }
          else
          {
            if(prime.find(v3[k/2]+v4[k/2-1])==prime.end()) { boo = 1;break;}
          }
          k++;
        }
        if(!boo)
        {
          k = 0;
          printf("1 ");
          while(k<n-2)
          {
            if(k%2==0) printf("%d ",v3[k/2]);
            else printf("%d ",v4[k/2]);
            k++;
          }
          printf("%d\n",v3[k/2]);
        }
        j++;
      }
    }
    v1.clear();v2.clear();
    count++;
    printf("\n");
  }
  return 0;
}

/*
2
4
6
8

*/
