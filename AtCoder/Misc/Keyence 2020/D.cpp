#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

int getInvCount(vector<int> &arr,int n) 
{ 
    // Create an empty set and insert first element in it 
    multiset<int> set1; 
    set1.insert(arr[0]); 
  
    int invcount = 0; // Initialize result 
  
    multiset<int>::iterator itset1; // Iterator for the set 
  
    // Traverse all elements starting from second 
    for (int i=1; i<n; i++) 
    { 
        // Insert arr[i] in set (Note that set maintains 
        // sorted order) 
        set1.insert(arr[i]); 
  
        // Set the iterator to first greater element than arr[i] 
        // in set (Note that set stores arr[0],.., arr[i-1] 
        itset1 = set1.upper_bound(arr[i]); 
  
        // Get distance of first greater element from end 
        // and this distance is count of greater elements 
        // on left side of arr[i] 
        invcount += distance(itset1, set1.end()); 
    } 
  
    return invcount; 
} 

void get(int i,vector<bool> &mask,int n)
{
  while(n)
  {
    if(i&1) mask.pu(1);
    else mask.pu(0);
    i >>= 1;
    n--;
  }
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> a(n),b(n);

  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];

  int min1 = INF;
  for(int i=0;i<pow(2,n);i++)
  {
    vector<bool> mask;
    get(i,mask,n);
    vector<int> v;
    for(int j=0;j<n;j++)
    {
      if(mask[j]) v.pu(a[j]);
      else v.pu(b[j]);
    }

    // t(mask,v);
    vector<int> w = v;
    sort(w.begin(),w.end());
    
    map<int,set<int> > d;
    vector<int> x;
    for(int j=0;j<n;j++)
    {
      d[w[j]].insert(j);
    }

    bool chuck = false;
    for(int j=0;j<n;j++)
    {
      // j is the orig pos
      bool boo = mask[j];
      // If boo, even distance

      int k = *d[v[j]].begin();
      // vector<bool> temp = {1,0,0,1,1};
      // if(mask == temp) 
      // {
      //   t(j,v[j],k,!mask[j]);
      // }
      if(boo)
      {
        bool flag = false;
        if(abs((j-k))%2 == 1)  k++;  
        while(!d[v[j]].empty() && k <= *d[v[j]].rbegin())
        {
          if(d[v[j]].count(k)) 
          {
            x.pu(k);
            d[v[j]].erase(k);
            break;
          }
          k += 2;
        }
      }
      else
      {
        bool flag = false;
        if(abs((j-k))%2 == 0) k++;
        while(!d[v[j]].empty() && k <= *d[v[j]].rbegin())
        {
          if(d[v[j]].count(k)) 
          {
            x.pu(k);
            d[v[j]].erase(k);
            break;
          }
          k += 2;
        }
      }
    }

    if(x.size() != v.size()) continue;

    // t(x);
    int c = getInvCount(x,n);
    min1 = min(min1,c);
  }

  if(min1 == INF) cout << -1 << endl;
  else cout << min1 << endl;

  return 0;
}
