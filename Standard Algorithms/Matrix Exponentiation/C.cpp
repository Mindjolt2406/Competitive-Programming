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

template <typename T> class Matrix
{
  public:
    vector<vector<T> > mat;
    int row;
    int col;
    ll mod;

    Matrix(int row,int col,const T& initial, ll mod = 1e18+1)
    {
      this->row = row;
      this->col = col;
      this->mod = mod;

      mat.resize(row);
      for(int i=0;i<row;i++) mat[i].resize(col,initial);
    }

    Matrix(int row,ll mod = 1e18+1) // Identity
    {
      this->row = this->col = row;
      this->mod = mod;

      mat.resize(row);
      for(int i=0;i<row;i++) mat[i].resize(col,0);

      for(int i=0;i<row;i++) mat[i][i] = 1;
    }

    virtual ~Matrix(){}

    // Operator Overloading
    T operator()(const int &i,const int &j) const
    {
      return this->mat[i][j];
    }

    Matrix<T>& operator=(const Matrix<T> &rhs)
    {
      if(&rhs == this) return *this;

      this->row = rhs.row;
      this->col = rhs.col;
      this->mod = rhs.mod;

      mat.resize(row);
      for(int i=0;i<row;i++) mat[i].resize(col);

      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j] = rhs(i,j);

      return *this;
    }

    Matrix(const Matrix<T> &rhs)
    {
      *this = rhs;
    }

    Matrix<T> operator+(const Matrix<T> &rhs)
    {
      Matrix res(row,col,0);

      for(int i=0;i<row;i++) for(int j=0;j<col;j++) res[i][j] = rhs(i,j)+mat[i][j];

      return res;
    }

    Matrix<T> operator-(const Matrix<T> &rhs)
    {
      Matrix res(row,col,0);

      for(int i=0;i<row;i++) for(int j=0;j<col;j++) res[i][j] = rhs(i,j)-mat[i][j];
      return res;
    }

    Matrix<T> operator*(const Matrix<T> &rhs)
    {
      Matrix res(row,rhs.col,0,rhs.mod);
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<rhs.col;j++)
        {
          for(int k=0;k<col;k++)
          {
            res[i][j]+=(1LL*mat[i][k]*rhs(k,j))%mod;
            if(res[i][j]>=mod) res[i][j]-=mod;
          }
        }
      }
      return res;
    }

    Matrix<T>& operator+=(const Matrix<T> &rhs)
    {
      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j]+=rhs(i,j);
      return *this;
    }

    Matrix<T>& operator-=(const Matrix<T> &rhs)
    {
      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j]-=rhs(i,j);
      return *this;
    }

    Matrix& operator*=(const Matrix<T> &rhs)
    {
      Matrix res(row,rhs.col,0,rhs.mod);
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<rhs.col;j++)
        {
          for(int k=0;k<col;k++)
          {
            res[i][j]+=(1LL*mat[i][k]*rhs(k,j))%mod;
            if(res[i][j]>=mod) res[i][j]-=mod;
          }
        }
      }
      *this = res;
      return *this;
    }

    Matrix<T> power(ll y, ll mod)
    {
      Matrix prod = *this;
      prod.mod = mod;
      Matrix res(row,mod);

      while(y)
      {
        if(y&1) res*=prod;
        // _;
        y>>=1;
        prod*=prod;
      }

      return res;
    }

    vector<T>& operator[](const int &i)
    {
      return mat[i];
    }

    void print()
    {
      for(int i=0;i<row;i++) t(i,mat[i]);
    }
};

int main()
{
  __;

  Matrix<ll> exp(2,2,MOD);
  Matrix<ll> last(2,1,MOD);
  last[0][0] = 1;

  exp[0] = {1,1};
  exp[1] = {1,0};

  ll n;
  cin >> n;
  Matrix<ll> final = exp.power(n,MOD);
  final *= last;

  cout << final[0][1] << endl;
  return 0;
}
