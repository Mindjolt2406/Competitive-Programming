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

int main()
{
  __;
  int n,k;
  cin>>n>>k;
  int max1 = -1,min1 = INF;
  vector<int> v(n);
  set<int> s;
  for(int i=0;i<n;i++) {cin>>v[i];max1 = max(max1,v[i]);min1 = min(min1,v[i]);s.insert(v[i]);}



  vector<int> min_index(k+10,-1), max_index(k+10,INF);

  // for(int i=1;i<=k;i++) if(i<min1) min_index[i] = max_index[i] = -INF+i;
  // for(int i=1;i<=k;i++) if(i>max1) min_index[i] = max_index[i] = INF+i;


  for(int i=0;i<n;i++)
  {
    if(min_index[v[i]]==-1) min_index[v[i]] = i;
    max_index[v[i]] = i;
  }

  // for(int i=1;i<=k;i++) t(i,min_index[i],max_index[i]);

  vector<pair<int,int> > left_sort(k+2), right_sort(k+2);
  vector<int> is_left(k+2),is_right(k+2);

  left_sort[0] = mp(-INF,-INF);
  right_sort[k+1] = mp(INF+k+1,INF+k+1); 


  for(int i=1;i<=k;i++)
  {
    int a = min_index[i], b = max_index[i];
    pair<int,int> p = left_sort[i-1];

    // t(i,p.se,a);
    if(p.se<=a) is_left[i] = 1;
    else break;

    left_sort[i] = mp(a,b);
  }


  for(int i=k;i>=1;i--)
  {
    int a = min_index[i], b = max_index[i];
    pair<int,int> p = right_sort[i+1];

    // t(i,b,p.se);
    if(b<=p.fi) is_right[i] = 1;
    else break;
    right_sort[i] = mp(a,b);
  }

  vector<int> find(k+10);
  int a = -INF;
  for(int i=1;i<=k;i++)
  {
    if(s.find(i)!=s.end())
  }
  for(int i=1;i<=k;i++)
  {
    if(s.find(i)==s.end()) 
    {
      int a = *s.lower_bound(i);
      if(s.lower_bound(i)==s.end()) 
      {
        min_index[i] = max_index[i] = min_index[max1];
        is_left[i]  = is_left[max1];
        is_right[i] = is_right[max1];
        left_sort[i] = left_sort[max1];
        right_sort[i] = right_sort[max1];
      }
      else 
      {
        t(i,a);
        min_index[i] = max_index[i] = min_index[a];
        is_left[i]  = is_left[a];
        is_right[i] = is_right[a];
        left_sort[i] = left_sort[a];
        right_sort[i] = right_sort[a];
      }
    }
  }
  // pr(is_left);
  // pr(is_right);
  is_left[0] = 1; // Empty on the left
  is_right[k+1] = 1;

  ll count = 0;
  for(int i=0;i<=k;i++)
  {
    t(i,is_left[i]);
    if(!is_left[i]) break;
    
    int beg = i+1, end = k, ans = k+1;
    while(beg<=end)
    {
      int mid = (beg+end)/2;
      // Right has to be sorted
      if(!is_right[mid]) 
      {
        beg = mid+1;
        continue;
      }

      // Combination has to be sorted
      if(left_sort[i].se <= right_sort[mid].fi) 
      {
        end = mid-1;
        ans = mid;
      }
      else {beg = mid+1;}
    }
    count += k+1-ans+1;
    t(i,ans,count);
  }

  cout<<count<<endl;
  return 0;
}

