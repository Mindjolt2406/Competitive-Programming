#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
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
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int boo1 = 0,boo2 = 0;

int find(string &s,int j)
{
  // if(j%2==0) boo = 1;
  if(j==0) return -1;
  // Check if s[0...j] is a palindrome
  // int boo = 0;
  int a = 0, b = j;
  int mid = j/2;
  // t(a,b,j);
  if(j%2==1)
  {
    while(a<b && s[a]==s[b])
    {
      a++;b--;
    }
    // if(a<b) return -2;
  }
  else
  {
    while(a<mid && s[a]==s[b])
    {
      a++;b--;
    }
  }
  if(a<b) // Not a palindrome
  {
    return j+1;
  }
  else // recurse
  {
    if(j%2==0) boo2 = 1;  // There is one odd sub part
    if((j-1)/2 %2==0)boo1 = 1;
    // t((j-1)/2,boo);
    // t(j);
    // if((j-1)
    int a = find(s,(j-1)/2);
    return a;
  }
}

int main()
{
  __;
  string s;
  cin>>s;
  int n = s.size();
  int a = find(s,n-1);
  int boo = 0;
  // char s1 = s[0];
  set<char> s1;
  for(int i=0;i<n;i++) s1.insert(s[i]);
  if(a==-1 && s1.size()<=2) {cout<<"Impossible"<<endl;return 0;}
  else
  {
    if(n%2==1 && n/2==a) cout<<2<<endl;
    else if(n%2==1 && boo1) cout<<2<<endl; 
    else if(n%2==1) cout<<2<<endl;
    else if(n%2==0 && boo2==0) cout<<1<<endl;
    else if(n%2==0) cout<<2<<endl;
  }
  return 0;
}

