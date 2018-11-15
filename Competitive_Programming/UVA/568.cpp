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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;
int count2,count5;
int reduce(int n)
{
  // cout<<"n: "<<n<<" count2: "<<count2<<" count5: "<<count5<<endl;
  while(count5 && n%5==0) {n/=5;count5--;}
  while(count2 && n%2==0) {n/=2;count2--;}
  // cout<<"n: "<<n<<" count2: "<<count2<<" count5: "<<count5<<endl;
  return n;
}

int main()
{
  string s;
  while(getline(cin,s))
  {
    int n = stoi(s);
    // cout<<"n: "<<n<<endl;
    int prod = 5;
    int count = 0;
    while(n/prod)
    {
      count+=n/prod;
      prod*=5;
    }
    count2 = count;
    count5 = count;
    // cout<<count<<endl;
    int prod1 = 1;
    for(int i=1;i<=n;i++)
    {
      int c = reduce(i);
      // cout<<"c: "<<c<<endl;
      prod1*=c;
      prod1%=10;
    }
    printf("%5d -> %d\n",n,prod1);
  }
  return 0;
}
