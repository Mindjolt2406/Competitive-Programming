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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    int counter[26] = {0};
    int index[26] = {0};
    bool check[26] = {0};
    bool horiz[26] = {0};
    pair<int,int> keep[26] = {mp(-1,-1)};
    pair<int,int> tell[26] = {mp(-1,-1)};
    set<int> s;

    for(int i=0;i<26;i++) keep[i] = tell[i] = mp(-1,-1);

    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(v[i][j]=='.') continue;
        counter[v[i][j]-'a']++;
        if(check[v[i][j]-'a']==false)
        {
          check[v[i][j]-'a'] = true;
          keep[v[i][j]-'a'] = mp(i,j);
        }
        s.insert(v[i][j]-'a');
      }
    }

    bool boo = true, boo1 = false;;

    if(boo1) {cout<<"NO"<<endl; continue;}

    for(int k=0;k<26;k++)
    {
      int j = keep[k].se;
      if(j==-1) continue;
      int cnt1 = 0, cnt2 = 0;
      int min1 = n, max1 = -1, min2 = m, max2 = -1;

      for(int i=0;i<n;i++)
      {
        if(v[i][j]-'a'==k) 
        {
          min1 = min(min1,i);
          max1 = max(max1,i);
          cnt1++;
        }
      }

      int i = keep[k].fi;
      if(i==-1) break;
      for(int j=0;j<m;j++)
      {
        if(v[i][j]-'a'==k) 
        {
          min2 = min(min2,j);
          max2 = max(max2,j);
          cnt2++;
        }
      }

      int a = max(cnt1,cnt2);
      if(cnt1>cnt2) 
      {
        horiz[k] = false;
        index[k] = j;
        tell[k] = mp(min1,max1);
      }
      else
      {
        horiz[k] = true;
        index[k] = i;
        tell[k] = mp(min2,max2);
      }

      if(a!=counter[k]) {boo1 = true; break;}
    }

    if(boo1) {cout<<"NO"<<endl; continue;}

    vector<string> w(n);
    for(int i=0;i<n;i++)
    {
      string s = "";
      for(int j=0;j<m;j++) s+='.';
      w[i] = s;
    }

    for(int k=0;k<26;k++)
    {
      int ind = index[k];
      bool boo = horiz[k];
      pair<int,int> p = tell[k];
      if(p.fi==-1) continue;

      if(boo)
      {
        int i = ind;
        for(int j=p.fi;j<=p.se;j++) w[i][j] = 'a'+k;
      }

      else
      {
        int j = ind;
        for(int i=p.fi;i<=p.se;i++) w[i][j] = 'a'+k;
      }
    }

    for(int i=0;i<n;i++)
    {
      if(w[i]!=v[i]) {boo1 = true; break;}
    }

    int ind = 0;
    pair<int,int> p;
    boo = false;
    bool is_horiz = false;
    int max_index = -1;
    // for(int i=0;i<26;i++) cout<<check[i]<<" "; cout<<endl;
    for(int i=25;i>=0;i--)
    {
      if(check[i])
      {
        max_index = max(i,max_index);
        boo = true;
        ind = index[i];
        p = tell[i];
        is_horiz = horiz[i];
      }
      else if(boo)
      {
        index[i] = ind;
        tell[i] = p;
        check[i] = true;
        horiz[i] = is_horiz;
      }
    }

    // t(max_index);
    if(boo1) {cout<<"NO"<<endl;continue;}
    else 
    {
      cout<<"YES"<<endl;
      cout<<max_index+1<<endl;
      for(int i=0;i<26;i++)
      {
        if(check[i])
        {
          if(horiz[i])
          {
            cout<<index[i]+1<<" "<<tell[i].fi+1<<" "<<index[i]+1<<" "<<tell[i].se+1<<endl;
          }
          else
          {
            cout<<tell[i].fi+1<<" "<<index[i]+1<<" "<<tell[i].se+1<<" "<<index[i]+1<<endl;
          }
        }
        else break;
      }
    }
  }
  return 0;
}

/*
2
3 3
...
...
...
4 4
..c.
adda
bbcb
....

1
4 4
..c.
adda
bbcb
....

1
3 3
...
bbb
...

 */
