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

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int boo = 0,count = 0,count1 = 0,count2 = 0, x = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='.' && boo==0) continue;
      else if(s[i]=='.') count++;
      else if(s[i]=='A' && boo == 0) boo = 1;
      else if(s[i]=='B' && boo == 0) boo = 2;
      else if(s[i]=='A' && boo == 1) {count1+=count;count = 0;boo = 0;}
      else if(s[i]=='B' && boo == 2) {count2+=count;count = 0;boo = 0;}
      else {x^= count; count = 0;boo = 0;}
    }
    if(boo == 1) count1+=count;
    else if(boo == 2) count2+=count;
    if(count1>count2) cout<<"A"<<endl;
    else if(count2>count1) cout<<"B"<<endl;
    else if(x==0) cout<<"B"<<endl;
    else cout<<"A"<<endl;
  }
  return 0;
}

