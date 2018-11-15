// Misunderstood the q
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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<": "<<x<<endl
#define t2(x, y)             cerr<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<":" <<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<endl

using namespace std;

int main()
{
  string s;
  scr(s);
  int n;
  sc(n);
  int count = 0;
  vector<int> v;
  for(int i=0;i<s.size();i++) if(s[i]-'0') {count++;v.pu(i+1);}
  if(count==1)
  {
    if(n!=1) cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      cout<<v[0]<<endl;
    }
  }
  else if(count == 2)
  {
    if(n==1) cout<<"YES\n"<<v[0]<<endl;
    else if(n==2) cout<<"YES\n"<<v[0]<<" "<<v[1]<<endl;
    else if(n==3) cout<<"YES\n"<<v[0]<<" "<<v[1]<<" "<<v[0]<<endl;
    else cout<<"NO\n";
  }
  else
  {
    int a = v[0],b = v[1],c = v[2];
    if(n==1) cout<<"YES\n"<<v[0]<<endl;
    else if(n==2) cout<<"YES\n"<<v[0]<<" "<<v[1]<<endl;
    else if(n==3) cout<<"YES\n"<<v[0]<<" "<<v[1]<<" "<<v[0]<<endl;
    else
    {
      n-=2;
      cout<<"YES\n"<<v[0]<<" "<<v[1]<<" ";
      int counter = 0;
      for(int i=0;i<n;i++)
      {
        if(counter%4==0 || counter%4==1) cout<<c<<" ";
        else cout<<b<<" ";
        counter++;
      }
    }
    cout<<endl;
  }
  return 0;
}

