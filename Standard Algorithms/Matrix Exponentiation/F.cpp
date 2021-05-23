#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 2e18
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

ll min(ll x, ll y) { return x<y?x:y;}

template <typename T> class Matrix
{
  public:
    vector<vector<T> > mat;
    int row;
    int col;

    vector<T>& operator[](const int &i)
    {
      return mat[i];
    }

    Matrix(int row,int col,const T& initial)
    {
      this->row = row;
      this->col = col;

      mat.resize(row);
      for(int i=0;i<row;i++) mat[i].resize(col,initial);
    }

    Matrix(int row) // Identity
    {
      this->row = this->col = row;

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

      mat.resize(row);
      for(int i=0;i<row;i++) mat[i].resize(col);

      for(int i=0;i<row;i++) for(int j=0;j<col;j++) mat[i][j] = rhs(i,j);

      return *this;
    }

    Matrix(const Matrix<T> &rhs)
    {
      *this = rhs;
    }

    Matrix& operator*=(Matrix<T> &rhs)
    {
      Matrix res(row,rhs.col,INF);
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<rhs.col;j++)
        {
          for(int k=0;k<col;k++)
          {
            if(mat[i][k] == INF || rhs(k,j) == INF) continue;
            res[i][j] = min(mat[i][k]+rhs(k,j),res(i,j));
            // ll temp = (mat[i][k] == INF || rhs(k,j) == INF) ? INF : mat[i][k]+rhs(k,j);
            // res[i][j] = min(temp,res[i][j]);
          }
        }
      }
      *this = res;
      return *this;
    }

    Matrix<T> power(ll y)
    {
      Matrix prod = *this;
      Matrix res(row);

      while(y)
      {
        // t(y);
        if(y&1) res*=prod;
        y>>=1;
        prod*=prod;
      }

      return res;
    }

    void print()
    {
      for(int i=0;i<row;i++) t(i,mat[i]);
    }
};

int main()
{
  __;

  int n,m,k;
  cin >> n >> m >> k;
  Matrix<ll> exp(n,n,INF);


  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    exp[a][b] = c;
  }

  // exp.print();
  Matrix<ll> final = exp.power(k);
  // final.print();

  ll sum1 = INF;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      sum1 = min(sum1,final(i,j));
    }
  }

  // final.print();
  (sum1 == INF) ? cout << "IMPOSSIBLE" << endl : cout << sum1 << endl;
  return 0;
}
