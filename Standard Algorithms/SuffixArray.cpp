#include<bits/stdc++.h>
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

// Convert all ints into lls if necessary
const int k = 20; // log(N)
const int N = 3e5+5;
int table[N][k + 1]; // Blackbox

void build(vector<int> &ar)
{
    int n = ar.size();
    for(int i = 0; i < n; i++)
    {
        table[i][0] = ar[i];            
    }
    for(int j = 1; j <= k; j++) 
    {
        for(int i = 0; i <= n - (1 << j); i++)
        {
            table[i][j] =min(table[i][j - 1],table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L,int R)
{   
    int answer=INF;	
    for(int j = k; j >= 0; j--) {
        if(L + (1 << j) - 1 <= R) {
            answer=min(answer,table[L][j]);
            L += 1 << j; // instead of having L', we increment L directly
        }
    }
    return answer;
}

vector<int> sort_cyclic(string s)
{
  int n = s.size();
  const int alph = 256;

  vector<int> p(n),c(n),cnt(max(n,alph));

  // Initialising for 0
  for(int i=0;i<n;i++)
  {
    cnt[s[i]]++;
  }
  for(int i=1;i<alph;i++)
  { 
    cnt[i] += cnt[i-1];
  }
  for(int i=0;i<n;i++)
  {
    p[--cnt[s[i]]] = i;
  }

  // t(p);
  c[p[0]] = 0;
  int classes = 0;
  for(int i=1;i<n;i++)
  {
    if(s[p[i]] != s[p[i-1]]) classes++;
    c[p[i]] = classes;
  }

  vector<int> pn(n),cn(n);

  for(int h=0;(1<<h) < n; h++)
  {
    for(int i=0;i<n;i++)
    {
      pn[i] = p[i] - (1<<h);
      if(pn[i] < 0) pn[i] += n;
    }

    fill(cnt.begin(),cnt.begin()+classes,0);
    for(int i=0;i<n;i++)
    {
      cnt[c[pn[i]]] ++;
    }
    for(int i=1;i<=classes;i++)
    {
      cnt[i] += cnt[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
      p[--cnt[c[pn[i]]]] = pn[i];
    }

    cn[p[0]] = 0;
    classes = 0;
    for(int i=1;i<n;i++)
    {
      pair<int,int> cur = {c[p[i]],c[(p[i] + (1 << h) ) % n]};
      pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1 << h) ) % n]};
      if(cur != prev) classes++;
      cn[p[i]] = classes;
    }
    c.swap(cn);
    t(p);
  }
  return p;
}

vector<int> suffix_array(string s)
{
  s += "$";
  vector<int> sorted = sort_cyclic(s);
  sorted.erase(sorted.begin());
  return sorted;
}

int main()
{
  string s;
  cin >> s;
  vector<int> v = suffix_array(s);
  for(int i=0;i<v.size();i++) cout << v[i] << " ";
  cout << endl;
}