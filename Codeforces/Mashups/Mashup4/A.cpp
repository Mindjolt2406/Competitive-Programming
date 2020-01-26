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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int t;
  sc(t);
  ld sum1 = 0;
  int count = 1;
  vector<ll> keep(200010);
  ll sum2= 0;
  int ptr = 0;
  stack<ll> s;
  s.push(0);
  while(t--)
  {
    int a;
    sc(a);
    if(a==1)
    {
      ll b,c;
      scll(b);scll(c);
      keep[b-1] += c;
      // if(ptr==b-1) sum2+=c;
      sum1+=b*c;
    }
    else if(a==2)
    {
      // keep[ptr] += sum2;
      ptr++;
      // sum2 = 0;
      ll b;
      scll(b);
      sum1+=b;
      s.push(b);
      count++;
    }
    else
    {
      ll b = s.top();
      s.pop();
      sum1-=(b+keep[ptr]);
      keep[ptr-1] +=keep[ptr];
      keep[ptr] = 0;
      ptr--;
      // keep[ptr]+=sum2;
      count--;
    }
    // for(int i=0;i<count;i++) cout<<keep[i]<<" ";cout<<endl;
    printf("%.12Lf\n",sum1/count);
    // else printf("0\n");
  }
  return 0;
}

