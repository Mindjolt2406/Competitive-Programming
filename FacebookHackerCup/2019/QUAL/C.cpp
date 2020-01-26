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


// typedef struct node
// {
//   int beg = 0, end = 0, op = 0;
// } node;

// bool sorter(const node &n1, const node &n2)
// {
//   if(n1.end - n1.beg <= n2.end - n2.beg) return true;
//   return false;
// }

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    string s;
    cin>>s;
    int n = s.size();
    stack<int> st,op_stack;
    // 0-> 0, 1 -> 1, 2 -> x, 3 -> X
    vector<vector<vector<int> > > dp(n,vector<vector<int> > (n,vector<int>(4,INF)));
    map<pair<int,int> ,int> d;

    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='(') st.push(i);
      else if(s[i]==')') 
      {
        int index = op_stack.top();
        d[mp(st.top(),i)] = index; // Store the operator index for an expression starting at st.top() and ending at i
        op_stack.pop();
        st.pop();
      }
      else if(s[i]=='^' || s[i]=='|' || s[i]== '&') op_stack.push(i);
      else if(s[i]=='X' || s[i]=='x') 
      {
        dp[i][i][0] = dp[i][i][1] = 1;
        if(s[i]=='X') 
        {
          dp[i][i][2] = 1;
          dp[i][i][3] = 0;
        }
        else 
        {
          dp[i][i][2] = 0;
          dp[i][i][3] = 1;
        }
      }
      else if(s[i]=='1') 
      {
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
        dp[i][i][2] = dp[i][i][3] = 1;
      }
      else
      {
        dp[i][i][0] = 0;
        dp[i][i][1] = 1;
        dp[i][i][2] = dp[i][i][3] = 1;
      }
    }

    // sort(w.begin(),w.end(),sorter);
    // t(op);
    for(int r=1;r<n;r++)
    {
      for(int l=0;l<n;l++)
      {
        int i = l, j = l+r;
        if(j>=n) break;
        if(d.find(mp(i,j))==d.end()) continue;
        int index = d[mp(i,j)];
        // t(i,j,index);
        int left0 = dp[i+1][index-1][0], left1 = dp[i+1][index-1][1], right0 = dp[index+1][j-1][0], right1 = dp[index+1][j-1][1];
        int leftx = dp[i+1][index-1][2], leftX = dp[i+1][index-1][3], rightx = dp[index+1][j-1][2], rightX = dp[index+1][j-1][3];

        // We change the sign to XOR
        int c = 0;
        if(s[index]!='^') c = 1;

        dp[i][j][0] = min(dp[i][j][0],left0+right0+c);
        dp[i][j][0] = min(dp[i][j][0],left1+right1+c);
        dp[i][j][0] = min(dp[i][j][0],leftx+rightx+c);
        dp[i][j][0] = min(dp[i][j][0],leftX+rightX+c);

        dp[i][j][1] = min(dp[i][j][1],left0+right1+c);
        dp[i][j][1] = min(dp[i][j][1],left1+right0+c);
        dp[i][j][1] = min(dp[i][j][1],leftx+rightX+c);
        dp[i][j][1] = min(dp[i][j][1],leftX+rightx+c);

        dp[i][j][2] = min(dp[i][j][2],left0+rightx+c);
        dp[i][j][2] = min(dp[i][j][2],leftx+right0+c);
        dp[i][j][2] = min(dp[i][j][2],left1+rightX+c);
        dp[i][j][2] = min(dp[i][j][2],leftX+right1+c);

        dp[i][j][3] = min(dp[i][j][3],left0+rightX+c);
        dp[i][j][3] = min(dp[i][j][3],leftX+right0+c);
        dp[i][j][3] = min(dp[i][j][3],left1+rightx+c);
        dp[i][j][3] = min(dp[i][j][3],leftx+right1+c);

        // We change the sign to AND
        c = 0;
        if(s[index]!='&') c = 1;

        dp[i][j][0] = min(dp[i][j][0],left0+c);
        dp[i][j][0] = min(dp[i][j][0],right0+c);
        dp[i][j][0] = min(dp[i][j][0],leftx+rightX+c);
        dp[i][j][0] = min(dp[i][j][0],leftX+rightx+c);

        dp[i][j][1] = min(dp[i][j][1],left1+right1+c);

        dp[i][j][2] = min(dp[i][j][2],leftx+rightx+c);
        dp[i][j][2] = min(dp[i][j][2],left1+rightx+c);
        dp[i][j][2] = min(dp[i][j][2],leftx+right1+c);

        dp[i][j][3] = min(dp[i][j][3],leftX+rightX+c);
        dp[i][j][3] = min(dp[i][j][3],left1+rightX+c);
        dp[i][j][3] = min(dp[i][j][3],leftX+right1+c);

        // We change the sign to OR

        c = 0;
        if(s[index]!='|') c = 1;

        dp[i][j][0] = min(dp[i][j][0],left0+right0+c);

        dp[i][j][1] = min(dp[i][j][1],right1+c);
        dp[i][j][1] = min(dp[i][j][1],left1+c);
        dp[i][j][1] = min(dp[i][j][1],leftx+rightX+c);
        dp[i][j][1] = min(dp[i][j][1],leftX+rightx+c);

        dp[i][j][2] = min(dp[i][j][2],left0+rightx+c);
        dp[i][j][2] = min(dp[i][j][2],leftx+right0+c);
        dp[i][j][2] = min(dp[i][j][2],leftx+rightx+c);

        dp[i][j][3] = min(dp[i][j][3],left0+rightX+c);
        dp[i][j][3] = min(dp[i][j][3],leftX+right0+c);
        dp[i][j][3] = min(dp[i][j][3],leftX+rightX+c);

        // t(i,j,dp[i][j]);
      }
    }

    int ans = min(dp[0][n-1][1],dp[0][n-1][0]);

    cout<<"Case #"<<h<<": "<<ans<<endl;

  }

  return 0;
}

/*
6
(X|x)
((X|x)&1)
(((X|x)&1)|0)
((((X|x)&1)|0)&x)
(((((X|x)&1)|0)&x)|(X&0))
((((((X|x)&1)|0)|x)&(X&0))^(((((X|x)&1)|0)|x)&(X&0)))

2
((((X|x)&1)|0)|x)
(((((X|x)&1)|0)|x)|(X&0))

*/
