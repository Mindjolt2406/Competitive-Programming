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

int main()
{
  __;
  int n,q;
  cin >> n >> q;
  vector<multiset<int> > v(2e5+1);
  // for(int i=0;i<=2e5;i++) v[i].insert(-INF);
  vector<int> keep_index(1);
  vector<int> keep_val(1);

  for(int i=0;i<n;i++)
  {
    int val,ind;
    cin >> val >> ind;
    v[ind].insert(val);
    keep_index.pu(ind);
    keep_val.pu(val);
  }

  multiset<int> acc;
  for(int i=1;i<=2e5;i++)
  {
    // int temp = ((*v[i].rbegin()) == -INF) ? INF : (*v[i].rbegin());
    if(!v[i].empty()) 
    {
      acc.insert(*v[i].rbegin());
    }
  }


  while(q--)
  {
    int old_ind,new_ind,child_index;
    cin >> child_index >> new_ind;
    old_ind = keep_index[child_index];

    if(!v[old_ind].empty()) 
    {
      int temp = *v[old_ind].rbegin();
      v[old_ind].erase(v[old_ind].find(keep_val[child_index]));
      if(temp == keep_val[child_index])
      {
        acc.erase(acc.find(temp));
        if(!v[old_ind].empty()) acc.insert(*v[old_ind].rbegin());
      }
    }

    // t("before");
    // for(int i=0;i<=10;i++)
    // {
    //   if(v[i].empty()) continue;
    //   t(i);
    //   for(auto it : v[i]) t(it);
    // }
    // cout << endl;

    if(!v[new_ind].empty())
    {
      if(keep_val[child_index] > *v[new_ind].rbegin())
      {
        acc.erase(acc.find(*v[new_ind].rbegin()));
        acc.insert(keep_val[child_index]);
      }
    }
    else {acc.insert(keep_val[child_index]);}
    v[new_ind].insert(keep_val[child_index]);

    keep_index[child_index] = new_ind;

    // for(int i=0;i<=10;i++)
    // {
    //   if(v[i].empty()) continue;
    //   t(i);
    //   for(auto it : v[i]) t(it);
    // }
    // cout << endl;

    cout << *acc.begin() << endl;
  } 
  return 0;
}
