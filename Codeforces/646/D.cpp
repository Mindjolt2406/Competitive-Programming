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

void query(int mid,map<int,int> &invert)
{
  cout << "? " << mid << " ";
  for(int i=1;i<=mid;i++) cout << invert[i] << " "; cout << endl;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    map<int,int> convert,invert;
    vector<int> sizes;
    vector<int> prev_sizes;
    set<int> left;
    for(int i=1;i<=n;i++) left.insert(i);
    int prev = 0;
    int counter = 1;
    for(int i=0;i<k;i++)
    {
      int m; 
      cin >> m;
      prev_sizes.pu(prev);
      sizes.pu(m);
      if(sizes.size() != 1) sizes[sizes.size()-1] += sizes[sizes.size()-2];
      prev += m;
      for(int j=0;j<m;j++)
      {
        int temp;
        cin >> temp;
        left.erase(temp);
        invert[counter] = temp;
        convert[temp] = counter;
        counter++;
      }
    }

    if(counter != n+1)
    {
      prev_sizes.pu(sizes.back());
      sizes.pu(n);
      for(auto it : left)
      {
        invert[counter] = it;
        counter++;
      }
    }

    // t(sizes,prev_sizes);
    // Find max_element
    int beg= 0, end = sizes.size()-1, ans = sizes.size()-1;

    query(sizes.back(),invert);
    int max1;
    cin >> max1;
    if(max1 == -1) return 0;

    while(beg <= end)
    {
      int mid = (beg+end) >> 1;
      query(sizes[mid],invert);
      int temp_max;
      cin >> temp_max;
      if(temp_max == -1) return 0;
      if(temp_max == max1)
      {
        ans = mid;
        end = mid-1;
      }
      else beg = mid+1;
    }

    // t(ans,sizes[ans],prev_sizes[ans]);
    cout << "? " << n-(sizes[ans]-prev_sizes[ans]) << " ";
    for(int i=1;i<=prev_sizes[ans];i++) cout << invert[i] << " ";
    for(int i=sizes[ans]+1;i<=sizes.back();i++) cout << invert[i] << " ";
    cout << endl;

    int max2;
    cin >> max2;
    if(max2 == -1) return 0;
    cout << "! ";
    for(int i=0;i<k;i++)
    {
      if(i == ans) cout << max2 << " ";
      else cout << max1 << " ";
    }
    cout << endl;

    string s;
    cin >> s;
    if(s != "Correct") return 0;
  }
  return 0;
}
