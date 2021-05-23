#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 4294967296
#define EPS 1e-6
#define ll unsigned long long int
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
    vector<Matrix> precomp;

    Matrix() {}

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

    vector<T>& operator[](const int &i)
    {
      return mat[i];
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

      for(int i=0;i<row;i++) for(int j=0;j<col;j++) res[i][j] = (rhs(i,j)+mat[i][j])%mod;

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
      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j] = (mat[i][j] + rhs(i,j))% mod;
      return *this;
    }

    Matrix<T>& operator-=(const Matrix<T> &rhs)
    {
      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j]-=rhs(i,j);
      return *this;
    }

    void precompute()
    {
      Matrix prod = *this;
      int pow = 1;
      while(pow < 1e9)
      {   
        precomp.pu(prod);
        prod *= prod;
        pow <<= 1;
      }
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

      int i = 0;
      while(y)
      {
        if(y&1) res*=precomp[i];
        // _;
        y>>=1;
        i++;
        // prod*=prod;
      }

      return res;
    }

    void print()
    {
      for(int i=0;i<row;i++) t(i,mat[i]);
    }
};

void computeSum(Matrix<ll> &mat,int n, int k, Matrix<ll> &ans)
{
  Matrix<ll> res(n,n,0,MOD);

  if(k&1)
  {
    res += mat.power(k,MOD);
    k--;
    // computeSum(mat,n,k-1,res);
    // ans = mat + res*mat;
    // return; 
  }

  if(!k) {ans = res;return;}

  Matrix<ll> temp;
  computeSum(mat,n,k/2,temp);
  res += temp + temp*mat.power(k/2,MOD);
  ans = res;

  // t(k,ans[0]);
}

int main()
{
  __;
  int dx[8] = {-2,-2,-1,-1,1,1,2,2};
  int dy[8] = {-1,1,-2,2,-2,2,-1,1};

  ll k;
  cin >> k;
  Matrix<ll> mat(64,64,0,MOD);
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      int index = 8*i+j;
      pair<int,int> p = mp(i,j);
      for(int k=0;k<8;k++)
      {
        pair<int,int> temp = mp(i+dx[k],j+dy[k]);
        if(temp.fi >= 0 && temp.fi < 8 && temp.se >= 0 && temp.se < 8)
        {
          int temp_index = 8*temp.fi + temp.se;
          mat[index][temp_index] = 1;
        }
      }
    }
  }


  Matrix<ll> ans;
  mat.precompute();
  computeSum(mat,64,k,ans);
  // mat.print();
  ll sum1 = 0;
  for(int i=0;i<64;i++)
  {
    sum1 += ans[0][i];
    if(sum1 >= MOD) sum1 -= MOD;
  }

  cout << (sum1+1)%MOD << endl;
  return 0;
}

94944377
96188134

96187640