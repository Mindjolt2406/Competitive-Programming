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
  int t;
  cin >> t;
  while(t--)
  {
    int days,k;
    cin >> days >> k;
    string s;
    cin >> s;
    int n = s.size();

    int start = 0;
    for(int i=0;i<s.size();i++) if(s[i] == '1') start++;
    int end = n;

    queue<int> q;
    vector<int> vis(100,-1);
    q.push(start);
    bool boo = false;
    while(!q.empty())
    {
      int u = q.front();
      q.pop();
      // t(u);
      if(u == end) 
      {
        boo = true;
        break;
      }

      for(int i=0;i<=min(u,k);i++)
      {
        // There are u set bits right now
        // Take i set bits -> valid
        // Take k-i unset bits
        if(k-i <= n-u)
        {
          int temp = u-i+(k-i);
          if(vis[temp] == -1)
          {
            // t(u,temp);
            vis[temp] = u;
            q.push(temp);
            // if(temp == 0) break;
          }
        }
      }
    }

    if(!boo) cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS" << endl;
    else
    {
      int cnt = 0;
      int temp = end;
      vector<int> keep;
      keep.pu(temp);
      // for(int i=0;i<10;i++) t(i,vis[i]);
      while(vis[temp] != -1)
      {
        cnt++;
        temp = vis[temp];
        keep.pu(temp);
        if(temp == start) break;
      }
      // _;
      if(cnt > days) cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS" << endl;
      else
      {
        cout << cnt << endl;
        vector<string> ans;
        vector<string> final_ans;
        ans.pu(s);
        reverse(keep.begin(),keep.end());
        for(int i=1;i<(int)keep.size();i++)
        {
          string s = ans[i-1];
          int before = keep[i-1];
          int after = keep[i];
          int take = (before+k-after)/2;
          int not_take = k-take;
          string t = "";
          string temp = "";

          for(int i=0;i<s.size();i++)
          {
            if(s[i] == '0')
            {
              if(not_take)
              {
                not_take--;
                t += '1';
                temp += '1';
              }
              else 
              {
                t += '0';
                temp += '0';
              }
            }
            else
            {
              if(take)
              {
                take--;
                t += '0';
                temp += '1';
              }
              else 
              {
                t += '1';
                temp += '0';
              }
            }
          }
          ans.pu(t);
          final_ans.pu(temp);
        }
        // reverse(ans.begin(),ans.end());
        for(int i=0;i<final_ans.size();i++) cout << final_ans[i] << endl;
      }
    }
  }
  return 0;
}
