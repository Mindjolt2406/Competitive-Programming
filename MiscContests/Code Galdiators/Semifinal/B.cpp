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

// int f(vector<int> &v, vector<int> &w)
// {
//   int a = 
// }

// std::chrono::steady_clock::time_point begin1,end1;
auto start = chrono::high_resolution_clock::now();

int max1, max2;

void sort(vector<int> &v,int max)
{
  vector<int> counter(max+1);
  for(int i=0;i<v.size();i++) counter[v[i]]++;
  v.clear();
  for(int i=max;i>0;i--)
  {
    for(int j=0;j<counter[i];j++) v.pu(i);
  }
}

bool satisfiable(std::vector<int> &a, std::vector<int> &b) {
  // _;
  sort(a,max1);
  // t(a.size());
  while (!a.empty()) {
    // _;
    // end1 = std::chrono::high_resolution_clock::now();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop - start); 
    // ld secs = std::chrono::duration_cast<std::chrono::seconds>(end1 - begin1).count();
    // cerr<<fixed<<setprecision(10);
    // t(secs);
    if(duration.count() >0.5) return true;
    sort(b,max2);
    int k = a.back();
    a.pop_back();
    if (k > b.size()) return false;
    if (k == 0) continue;
    if (b[k - 1] == 0) return false;
    for (int i = 0; i < k; i++)
      b[i]--;
  }
  for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++)
    if (*i != 0)
      return false;
  return true;
}

int main()
{
  // start = time(NULL);
  // stop = start+0.5
  __;
  // begin1 = chrono::high_resolution_clock::now();
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<int> v(n),w(m);
    ll sum1 = 0, sum2 = 0;
    max1 = 0,max2 = 0;
    int cnt1 = 0,cnt2 = 0;
    for(int i=0;i<n;i++) 
    {
      cin>>v[i];
      sum1+=v[i];
      max1 = max(max1,v[i]);
      if(v[i]) cnt1++;
    }
    for(int i=0;i<m;i++) 
    {
      cin>>w[i];
      sum2+=w[i];
      max2 = max(max2,w[i]);
      if(w[i]) cnt2++;
    }

    bool boo = satisfiable(v,w);
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    reverse(v.begin(),v.end());
    reverse(w.begin(),w.end());
    // t(cnt1,cnt2,max1,max2);
    // t(sum1,sum2);
    if(sum1!=sum2)
    {
      cout<<"NO"<<endl;
    }
    else
    {
      if(max1> cnt2 || max2>cnt1) cout<<"NO"<<endl;
      else
      {
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::seconds>(stop - start); 
        if(duration.count() >0.5) {cout<<"YES"<<endl; continue;}
        if(boo) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      }
    }
  }
  return 0;
}

