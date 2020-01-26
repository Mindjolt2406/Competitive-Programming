/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define int long long int
#define ld long double
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

#define MAXN 200010
int RA[MAXN], SA[MAXN], LCP[MAXN], *FC, *SC, step;

int get_distinct(vector<vector<int> > &pref,int n,int i,int j)
{
  int cnt = 0;
  for(int k=0;k<26;k++)
  {
    int ans;
    if(i>0) ans = pref[j][k] - pref[i-1][k];
    else ans = pref[j][k];
    // t(ans,k);
    if(ans>0) cnt++;
  }
  return cnt;
}

bool cmp(int a, int b) 
{
  if (step==-1 || FC[a]!=FC[b]) return FC[a] < FC[b];
  return FC[a+(1<<step)] < FC[b+(1<<step)];
}

void suffix_array(string &S, int n) 
{ // O(n log^2(n)) 
  for (int i=0; i<n; i++) RA[i] = S[SA[i] = i];
  for (FC=RA, SC=LCP, step=-1; (1<<step)<n; step++) 
  {
    sort(SA, SA+n, cmp);
    int cnt = 0;
    for (int i=0; i<n; i++) 
    {
      if (i>0 && cmp(SA[i-1],SA[i])) cnt++;
      SC[SA[i]] = cnt; 
    }

    if (cnt==n-1) break; // all distinct, no need to continue
     swap(FC,SC);
  }

  for (int i=0; i<n; i++) RA[SA[i]] = i; 
}

int32_t main()
{
  __;
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  s = s+'$';
  vector<vector<int> > pref(n,vector<int>(26));

  // Prerequisite to count distinct substrings
  for(int i=0;i<n;i++)
  {
    pref[i][s[i]-'a']++;
  }

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<26;j++) pref[i][j]+=pref[i-1][j];
  }

  // Suffix Array
  suffix_array(s,n+1);
  for(int i=0;i<n;i++) cout<<SA[i]<<" "; cout<<endl;
  // KMP
  // string temp = s;
  // reverse(temp.begin(),temp.end());
  // for(int i=1;i<n;i++)
  // {
  //   int c = p[i-1];
  //   while(c>0 && temp[c]!=temp[i]) c = p[c-1];
  //   if(temp[c]==temp[i]) c++;
  //   p[i] = c;
  // }

  vector<int> p(n);
  int cnt = 0;
  char c = '$';
  int counter[26] = {0};
  for(int i=n-1;i>=0;i--)
  {
    p[s[i]-'a'] = counter[s[i]-'a'];
    counter[s[i]-'a']++;
  }

  // pr(p);
  // reverse(p.begin(),p.end());

  vector<int> p_suffix(n),sum_suffix(n+1);
  for(int i=0;i<n;i++)
  {
    p_suffix[i] = n-SA[i+1] - p[SA[i+1]];
  }

  pr(p);
  // d[p_suffix[0]] = 0;
  for(int i=1;i<=n;i++) 
  {
    int j = SA[i+1];
    sum_suffix[i] = p_suffix[i-1]+sum_suffix[i-1];
  }

  // pr(p_suffix);
  // pr(sum_suffix);

  int max1 = sum_suffix[n];
  // for(int i=0;i<n;i++) cout<<SA[i]<<" "; cout<<endl;
  while(q--)
  {
    int beg = 0, end = n-1,ans = -1;
    int val;
    cin>>val;
    if(val>max1) {cout<<-1<<endl;continue;}


    while(beg<=end)
    {
      int mid = (beg+end)>>1;
      if(val>sum_suffix[mid]) 
      {
        ans = mid;
        beg = mid+1;
      }
      else end = mid-1;
    }

    // t(ans);
    if(ans==-1) cout<<ans<<endl;
    else
    {
      int i = SA[ans+1];
      // t(ans,SA[ans],RA[ans]);
      // t(val,sum_suffix[ans],p[SA[ans]],ans,SA[ans]);
      int j = val-sum_suffix[ans]-1+i+p[i];
      // if(ans>0) 
      // {
      //   j+= p[SA[ans-1]];
      // }
      t(i,j);
      cout<<get_distinct(pref,n,i,j)<<endl;
    }
  }


  return 0;
}

/*
6 10
aabcda
1

 */