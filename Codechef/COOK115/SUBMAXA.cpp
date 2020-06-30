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

const int N = 1e6+10;
double v[2*N] = {0};
int front[2*N] = {0}, back[2*N] = {0}, left_v[N] = {0}, right_v[N] = {0};
ll bit[N] = {0}, v_bit[N] = {0};
// vector<ld> v(N);
// vector<int> front(N),back(N);
// vector<int> left_v(N),right_v(N);
// vector<ll> bit(N);
// vector<ll> v_bit(N);

void increasing(int n, int i,ll mul)
{
  bit[i] += mul;
  bit[n+i] += (-n*mul + (-mul));
  bit[n+1+i] += n*mul;
}

void decreasing(int n,int i, ll mul)
{
  bit[i] += n*mul;
  bit[i+1] += -n*mul;
  bit[i+1] += -mul;
  bit[n+i+1] += mul;
}

void nextGreatest(int n)
{
  stack < pair<ld,int>  > s_for, s_back; 
  
  /* push the first element to stack */
  s_for.push(mp(v[0],0)); 
  s_back.push(mp(v[n-1],n-1));
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) 
  { 
    if (s_for.empty()) { 
      s_for.push(mp(v[i],i)); 
      continue; 
    } 

    if(s_back.empty())
    {
      s_back.push(mp(v[n-1-i],n-1-i));
    }

    while (s_for.empty() == false && (s_for.top()).fi < v[i]) 
    {     
      front[s_for.top().se] =  i;
      s_for.pop(); 
    } 

    while(s_back.empty() == false && (s_back.top()).fi < v[n-1-i])
    {
      back[s_back.top().se] = n-1-i;
      s_back.pop();
    }

    s_for.push(mp(v[i],i)); 
    s_back.push(mp(v[n-1-i],n-1-i));
  } 
  
  while (s_for.empty() == false) { 
    front[s_for.top().se] = -1;
    s_for.pop();
  }


  while(s_back.empty() == false)
  {
    back[s_back.top().se] = -1;
    s_back.pop();
  }
}

// void print(BIT &bit)
// {
//   ll sum1 = 0;
//   for(int i=1;i<=4;i++) 
//   {
//     sum1 += bit.sum(i);
//     cout << sum1 << " "; 
//   }
//   cout << endl;
// }

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    map<ld,int> d;
    for(int i=0;i<n;i++)
    {
      cin >> v[i];
      d[v[i]]++;
      v[i] += d[v[i]]*(1e-7);
      v[n+i] = v[i];
    }

    nextGreatest(2*n);
    for(int i=0;i<n;i++)
    {
      if(front[i] == -1) front[i] = n+i;
    }
    for(int i=n;i<2*n;i++)
    {
      if(back[i] == -1) back[i] = i-n;
    }

    
    for(int i=0;i<n;i++) right_v[i] =  front[i]-i-1;
    for(int i=n;i<2*n;i++) left_v[i-n] =  i-back[i]-1;

    // BIT bit;
    // bit.init(N);


    for(int i=0;i<n;i++)
    {
      ll min1 = min(left_v[i]+1,right_v[i]+1);
     
      int temp_n = left_v[i]+right_v[i]+1;
      ll mul = v[i];
      increasing(min1,1,mul);
      v_bit[min1+1] += min1*mul;
      v_bit[temp_n-min1+1] +=  (-min1)*mul;
      decreasing(min1,temp_n-min1+1,mul);
    }

    for(int i=1;i<=n;i++) bit[i] += bit[i-1];

    ll sum1 = 0;
    for(int i=1;i<=n;i++)
    {
      sum1 += bit[i] + v_bit[i];
      cout << sum1 << " ";
    }

    cout << endl;

    memset(bit, 0, sizeof(bit));
    memset(v_bit, 0, sizeof(v_bit));
    memset(left_v, 0, sizeof(left_v));
    memset(right_v, 0, sizeof(right_v));
    memset(v, 0, sizeof(v));
    memset(front, 0, sizeof(front));
    memset(back, 0, sizeof(back));
  }
  return 0;
}

/*
1
5
2 4 1 3 5

1
4
1 2 3 4

*/