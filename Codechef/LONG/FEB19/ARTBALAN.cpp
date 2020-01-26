#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    vector<int> v(26);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) 
    {
      v[s[i]-'A']++;
    }
    ll sum1 = 0;
    for(int i=0;i<v.size();i++) if(v[i]!=0) {sum1+=v[i];}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll min1 = INF;
    // pr(v);
    for(int i=1;i<=26;i++)
    {
      ll k = sum1,count = 0;
      if(sum1%i==0)
      {
        for(int j=0;j<i;j++)
        {
          // t(v[j]-(sum1/i));
          if(v[j]<sum1/i) count+=abs(v[j]-(sum1/i));
        }
        min1 = min(min1,count);
        // t(sum1,i,sum1/i,count);
      }
    }
    cout<<min1<<endl;
  }
  return 0;
}

