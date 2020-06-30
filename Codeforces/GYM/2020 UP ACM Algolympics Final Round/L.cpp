#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 999983
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

ll power(ll x, ll y, ll p)
{
        ll res = 1;      // Initialize result
        x = x % p;  // Update x if it is more than or
        while (y > 0)
        {
                        if (y & 1)
                                        res = (res*x) % p;
                        y = y>>1; // y = y/2
                        x = (x*x) % p;
        }
        return res;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,k,l;
    cin >> l >> k >> n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
      int temp;
      cin >> temp;
      temp %= MOD;
      temp += MOD;
      temp %= MOD;
      s.insert(temp);
    }
    n = s.size();
    vector<int> v;
    for(auto it : s) v.pu(it);
    
    vector<vector<ll> > mat(n,vector<ll>(n)); 
    vector<ll> mat_sum;
    ll sum1 = 0;
    for(int i=0;i<n;i++) 
    {
      mat[0][i] = v[i];
      sum1 += mat[0][i];
      sum1 %= MOD;
    }

    mat_sum.pu(sum1);

    for(int i=1;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        mat[i][j] = ((mat_sum[i-1] - mat[i-1][j]+MOD) % MOD) *v[j];
        mat[i][j] %= MOD;
        // mat[i][j] *= power(2,MOD-2,MOD);
        // mat[i][j] %= MOD;
      }
      ll sum1 = 0;
      for(int j=0;j<n;j++) 
      {
        sum1 += mat[i][j];
        sum1 %= MOD;
      }
      sum1 *= power((i+1),MOD-2,MOD);
      sum1 %= MOD;
      mat_sum.pu(sum1);
    }

    if(n < k)
    {
      // Infinite
      mat_sum.pu(0);
      cout << l << endl;
      for(int add = 0;add<l;add++)
      {
        cout << n+1 << " ";
        cout << 1 << " ";

        for(int j=0;j<(int)mat_sum.size();j++)
        {
          if(! (j&1)) cout << "-";
          if(j == 0) 
          {
            cout << (mat_sum[j]+add) % MOD;
            if(mat_sum.size() != 1) cout << " ";
          }
          else
          {
            cout << ((mat_sum[j-1]*add) % MOD + mat_sum[j]) % MOD;
            if(j != mat_sum.size()-1) cout << " ";
          }
        }
        
        cout << endl;
        // if(! (((int)mat_sum.size()-1)&1)) cout << "-";
        // if(mat_sum.size() == 1) cout << (mat_sum[0] + add)  % MOD << endl;
        // else
        // {
        //   cout << ((mat_sum[(int)mat_sum.size()-2]*add) % MOD + mat_sum[mat_sum.size()-1]) % MOD << endl;
        // }
      } 
    }
    else if(n == k)
    {
      // Exactly one solution
      cout << l << endl;
      for(int mul=1;mul<=l;mul++)
      {
        cout << n << " ";
        cout << mul << " ";
        for(int i=0;i<n;i++) 
        {
          if(! (i&1)) 
          {
            cout << ((-1*mat_sum[i]*mul) % MOD + MOD)%MOD;
          }
          else cout << (mat_sum[i]*mul) % MOD;
          if(i != n-1) cout << " ";
        }
        cout << endl;

      }
      // if(! ((n-1)&1)) cout << "-";
      // cout << mat_sum[n-1] << endl;
    }
    else cout << 0 << endl;

    // if(t != 0) cout << endl;
    // cout << endl;

    // Take care of degree cases

    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //   {
    //     cout << mat[i][j] <<" ";
    //   }
    //   cout << endl;
    // }

    // t(mat_sum);
  }
  return 0;
}
