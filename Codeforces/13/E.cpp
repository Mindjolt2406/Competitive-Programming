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

void apply(vector<int> &update,vector<int> &block,vector<int> &b, vector<int> &next,vector<int> &ans1, vector<int> &ans2,vector<int> &count,int i,int n,int h)
{
  update[i] = h;
  if(b[i]==n) 
  {
    next[i] = -1;
    ans1[i] = i;
    ans2[i] = 1;
    count[i] = 1;
  }
  else
  {
    if(block[i]!=block[b[i]]) 
    {
      next[i] = b[i];
      count[i] = 1;
      ans1[i] = ans1[next[i]];
      ans2[i] = ans2[next[i]]+count[i]; 
    }
    else 
    {
      //b[i] has the right answer
      // b[i] has our next
      // Let's utilise it to the fullest
      next[i] = next[b[i]];
      count[i] = 1+count[b[i]];
      ans1[i] = ans1[b[i]];
      ans2[i] = ans2[b[i]]+1;
    }
  }
  // t(b,ans1,ans2,block,next,count);  
}

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<int> a(n), b(n), next(n), update(n),ans1(n),ans2(n), block(n),count(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int sq = sqrt(n);
  for(int i=n-1;i>=0;i--)
  {
    if(a[i]+i >= n) 
    {
      b[i] = n;
      ans1[i] = i;
      ans2[i] = 1;
    }
    else 
    {
      b[i] = a[i]+i;
      // t(i,b[i],ans1[b[i]]);
      ans1[i] = ans1[b[i]];
      ans2[i] = ans2[b[i]]+1;
    }
    block[i] = i/sq;
  }

  // Computing next and count
  for(int i=n-1;i>=0;i--)
  {
    if(b[i]==n) 
    {
      next[i] = -1;
      count[i] = 1;
    }
    else
    {
      if(block[i]!=block[b[i]]) 
      {
        next[i] = b[i];
        count[i] = 1;
      }
      else 
      {
        next[i] = next[b[i]];
        count[i] = 1+count[b[i]];
      }
    }
  }

  // t(b,ans1,ans2,block,next,count);  
  for(int h=1;h<=q;h++)
  {
    int a;
    cin>>a;
    if(a==0)
    {
      int index,val;
      cin>>index>>val;
      index--;
      b[index] = min(n,val+index);
      int j = (index/sq)*sq,i = index;
      // t(i,index);
      while(block[index]==block[i])
      {
        apply(update,block,b,next,ans1,ans2,count,i,n,h);
        i--;
      }
    }
    else
    {
      int index;
      cin>>index;
      index--;
      int i = index;
      int max1 = update[index];
      int cnt = 0;
      while(index+1 && index<n && next[index]!=-1)
      {
        cnt+=count[index];
        if(update[next[index]]>=max1)
        {
          max1 = update[next[index]];
          ans1[i] = ans1[next[index]];
          ans2[i]= ans2[next[index]]+cnt;
        }
        index = next[index];
        // t(index,next[index],cnt);
      }
      cout<<ans1[i]+1<<" "<<ans2[i]<<endl; 
    }
    // t(h);
    // t(b,ans1,ans2,block,next,count);  
  }
  return 0;
}

/*
21 5
9 11 19 8 17 1 16 18 6 15 3 11 21 21 12 19 8 17 9 14 3
0 10 1
0 1 12
0 21 10
0 14 4
0 7 14

*/