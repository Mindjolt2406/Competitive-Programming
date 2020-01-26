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
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int n;
  cin>>n;
  string s;
  cin>>s;
  int boo = 0;
  int min1 = INF;
  for(int i=0;i<n-3;i++)
  {
    int count = 0;
    count+=min(min(abs(s[i]-'A'),'Z'-s[i]+1),s[i]-'A'+1+'Z'-'A');
    count+=min(min(abs(s[i+1]-'C'),'Z'-s[i+1]+'C'-'A' + 1),s[i+1]-'A'+1+'Z'-'C');
    count+=min(min(abs(s[i+2]-'T'),'Z'-s[i+2]+'T'-'A' + 1),s[i+2]-'A'+1+'Z'-'T');
    count+=min(min(abs(s[i+3]-'G'),'Z'-s[i+3]+'G'-'A' + 1),s[i+3]-'A'+1+'Z'-'G');
    min1 = min(min1,count);
    // t(i,count);
  }
  cout<<min1<<endl;
  return 0;
}

