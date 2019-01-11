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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int n,k;
  cin>>n>>k;
  vector<int> v(n),index(k),temp(k+1);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<k;i++) {cin>>index[i];index[i]--;temp[i] = index[i];}
  reverse(index.begin(),index.end());
  temp[k] = n-1;
  sort(temp.begin(),temp.end());
  // pr(temp);
  vector<ll> sum(n),end(n); 
  int start = 0,j = 0;
  ll sum1 = 0;
  for(int i=0;i<n;i++)
  {
    sum1+=v[i]; 
    if(i==temp[j] && j<=k)
    {
      // t(i,j,temp[j]);
      end[start] = i;
      end[i] = start;
      sum[i] = sum1;
      sum[start] = sum1;
      start = i+1;
      sum1 = 0;
      j++;
    }
  }
  // pr(temp);
  // pr(end);
  // pr(sum);

  // Iterate through index and merge
  ll max1 = -1;
  vector<ll> ans;
  for(int i=0;i<sum.size();i++) max1 = max(max1,sum[i]);
  for(int i=0;i<index.size();i++)
  {
    int a = index[i];
    int b = end[a];
    int c = a+1;
    int d = end[c];
    // b and d will be updated
    // t(a,c);
    end[b] = d;
    end[d] = b;
    ans.pu(max1);
    sum[b] = sum[d] = sum[a]+sum[c];
    max1 = max(max1,sum[b]);
  }
  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
  return 0;
}

