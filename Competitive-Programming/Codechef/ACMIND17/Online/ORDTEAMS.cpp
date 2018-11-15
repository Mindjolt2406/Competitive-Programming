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

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    vector<tuple<int,int,int> > v;
    tuple<int,int,int> t1,t2,t3;
    int a,b,c;
    sc(a);sc(b);sc(c);
    t1 = mt(a,b,c);
    sc(a);sc(b);sc(c);
    t2 = mt(a,b,c);
    sc(a);sc(b);sc(c);
    t3 = mt(a,b,c);
    v = {t1,t2,t3};
    sort(v.begin(),v.end());
    if(get<0>(v[0])<=get<0>(v[1]) && get<1>(v[0])<=get<1>(v[1]) && get<2>(v[0])<=get<2>(v[1]) && get<0>(v[1])<=get<0>(v[2]) && get<1>(v[1])<=get<1>(v[2]) && get<2>(v[1])<=get<2>(v[2]) && t1!=t2 && t2!=t3 && t3!=t1) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}

