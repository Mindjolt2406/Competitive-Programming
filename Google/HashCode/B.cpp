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

void B()
{

}

int main()
{
  __;
  int n_books, n_lib, days;
  cin >> n_books >> n_lib >> days;

  // Check various conditions
  set<int> diff_books;
  vector<int> book_freq(n_books);
  // ----------------

  vector<vector<int> > library(n_lib);
  vector<int> book_score(n_books);

  // < signup, scan/day , index> 
  vector<vector<int> > lib_info(n_lib); 

  for(int i=0;i<n_books;i++) cin >> book_score[i];

  for(int i=0;i<n_lib;i++)
  {
    int n,signup,scan;
    cin >> n >> signup >> scan;

    lib_info[i] = {signup,scan,i,n};

    for(int j=0;j<n;j++)
    {
      int temp;
      cin >> temp;
      library[i].push_back(temp);
    }
  }

  // B

  sort(lib_info.begin(),lib_info.end());
  // for(int i=0;i<5;i++) cout << lib_info[i];

  int cnt = 0;
  int temp_day = 0;
  int temp_book = 0;
  int index = -1;
  int prev_day = 0;

  vector<int> ans;
  queue< pair<int,int> > q;
  map<int,int> d;

  vector<int> times;
  for(int i=0;i<lib_info.size();i++)
  {
    prev_day += lib_info[i][0];
    times.pu(prev_day);
    if(prev_day > days)
    {
      index = i;
      break;
    }
  }

  if(index == -1) index = lib_info[lib_info.size()-1][0];
  
  for(int i=0;i<=index;i++)
  {
    d[lib_info[i][2]] = max(1000-times[i],0);
  }

  int ans_cnt = 0;
  for(int i=0;i<lib_info.size();i++)
  {
    if(!d.count(lib_info[i][2]) || !d[lib_info[i][2]]) continue;
    ans_cnt++;
  }

  cout << ans_cnt << endl;

  for(int i=0;i<lib_info.size();i++)
  {
    if(!d.count(lib_info[i][2]) || !d[lib_info[i][2]]) continue;

    cout << lib_info[i][2] << " " << d[lib_info[i][2]] << endl;
    for(int j=0;j<d[lib_info[i][2]];j++) cout << lib_info[i][2]*1000 + j << " ";
    cout << endl;  
  }


  // while(temp_day < days)
  // {
  //   if(prev_day + lib_info[index][0] == temp_day)
  //   {
  //     temp_book +=  lib_info[index][3];
  //     prev_day = temp_day;
  //     q.push(mp(lib_info[index][2],lib_info[index][3]));
  //     ans.pu(lib_info[index][2]);
  //     // cout << lib_info[index][2] << " " << temp_day << endl;
  //     index++;
  //   }

  //   if(!q.empty())
  //   {
  //     d[q.front().fi]++;
  //     q.front().se--;
  //     if(q.front().se == 0) q.pop();
  //   }

  //   temp_day++;
  // }

  // int ans_cnt = 0;
  // for(int i=0;i<ans.size();i++) if(d[ans[i]]) ans_cnt++;

  // cout << ans_cnt << endl;

  // for(int i=0;i<ans.size();i++)
  // {
  //   if(!d[ans[i]]) break;

  //   cout << ans[i] << " " << d[ans[i]] << endl;

  //   for(int j=0;j<d[ans[i]];j++) cout << 1000*ans[i] + j << " " ; cout << endl;
  // }
  // return 0;
}
