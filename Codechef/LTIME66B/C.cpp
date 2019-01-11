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

vector<int> l,lcopy,ans;
int size1;
vector<pair<int,int> > reverser;
int counter = 0;

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

void recur(set<int> s, vector<int> v,int n)
{
  // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  if(s.empty())
  {
    // t(counter);
    for(int i=0;i<v.size();i++) reverse(l.begin()+reverser[v[i]-1].fi,l.begin()+reverser[v[i]-1].se+1);
    // for(int i=0;i<l.size();i++) cout<<l[i]<<" ";cout<<endl;
    if(l==ans) counter++;
    for(int i=0;i<size1;i++) l[i] = lcopy[i];
    return;
  }

  for(int i=1;i<=n;i++)
  {
    if(s.find(i)!=s.end())
    {
      v.pu(i);
      s.erase(i);
      recur(s,v,n);
      v.pop_back();
      s.insert(i);
    }
  }
}

int main()
{
  int t;
  sc(t);
  int fact[10] = {0};
  fact[0] = 1;
  for(int i=1;i<10;i++) fact[i] =fact[i-1]*i;
  // for(int i=0;i<10;i++) cout<<fact[i]<<" ";cout<<endl;
  while(t--)
  {
    l.assign(9,0);
    lcopy.assign(9,0);
    ans.assign(9,0);
    int n,k;
    sc(n);sc(k);
    size1 = n;
    for(int i=0;i<n;i++) {sc(l[i]);ans[i] = l[i];lcopy[i] = l[i];}
    set<int> s1;
    vector<int> v;
    // for(int i=1;i<=n;i++) s1.insert(i);
    int c = 1;
    for(int i=0;i<k;i++)
    {
      int a,b;
      sc(a);sc(b);
      a--;b--;
      if(a==b) continue;
      reverse(ans.begin()+a,ans.begin()+b+1);
      reverser.pu(mp(a,b));
      s1.insert(c);
      c++;
    }
    recur(s1,v,s1.size());
    k = s1.size();
    // t(counter,fact[k]);
    // t(gcd(counter,fact[k]));
    if(counter!=0) printf("%d/%d\n",counter/gcd(counter,fact[k]),fact[k]/gcd(counter,fact[k]));
    else printf("0/1\n");
    counter = 0;
    reverser.clear();

  }
  return 0;
}

