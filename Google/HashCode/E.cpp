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
  vector<vector<int> > book_lib(n_books);
  vector<int> book_score(n_books);

  // < signup, scan/day , index> 
  vector<vector<int> > lib_info(n_lib); 

  int max_score = 0;
  for(int i=0;i<n_books;i++) {cin >> book_score[i]; max_score += book_score[i];}

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
      book_lib[temp].pu(i);
    }
  }

  for(int i=0;i<n_lib;i++)
  {
    vector<pair<int,int> > lib_i;
    for(int j=0;j<library[i].size();j++) 
    {
      lib_i.pu(mp(book_score[library[i][j]],library[i][j]));
    }
    sort(lib_i.begin(),lib_i.end());
    reverse(lib_i.begin(),lib_i.end());

    for(int j=0;j<library[i].size();j++)
    {
      library[i][j] = lib_i[j].se;
    }
  }

  // int max1 = 0;
  int score = 0;
  vector<bool> taken(n_books),taken2(n_books);

  vector<vector<int> > lib_ans(n_lib);
  set<int> taken_lib;

  int cnt = 0;
  vector<pair<int,int> > best;
  for(int i=0;i<n_lib;i++)
  {
    // t(i);
    bool thi = false;
    if(lib_info[i][0] == 1)
    {
      int temp_score = 0;
      for(int j=0;j<library[i].size();j++)
      {
        if(!taken[library[i][j]]) 
        {
          thi = true;
          temp_score += book_score[library[i][j]];

          lib_ans[i].pu(library[i][j]);
          taken_lib.insert(i);
          taken[library[i][j]] = true;
        }
      }

      if(thi) 
      {
        cnt += lib_info[i][0];
        score += temp_score;
      }
    }
    else if(lib_info[i][0] == 2)
    {
      int temp_score = 0;
      for(int j=0;j<library[i].size();j++)
      {
        if(!taken[library[i][j]]) 
        {
          thi = true;
          temp_score += book_score[library[i][j]];
          taken[library[i][j]] = true;
        }
      }
      if(thi) 
      {
        best.pu(mp(temp_score,i));
      }
    }
    // _;
  }

  // _;
  sort(best.begin(),best.end());
  reverse(best.begin(),best.end());

  for(int i=0;i<min((int)best.size(),44);i++) 
  {
    score += best[i].fi;
    cnt += 2;
    taken_lib.insert(best[i].se);
  }
  t(score,max_score,cnt);

  cout << taken_lib.size() << endl;

  int score_ans = 0;
  for(int i=0;i<n_lib;i++)
  {
    if(taken_lib.count(i))
    {
      cout << i << " " << library[i].size() << endl;
      for(int j=0;j<library[i].size();j++) 
      {
        cout << library[i][j] << " ";
        score_ans += book_score[library[i][j]];
      }
      cout << endl;
    }
  }

  // int books_cnt = 0;
  // for(int i=0;i<taken2.size();i++) if(taken2[i]) books_cnt++;



  return 0;
}
