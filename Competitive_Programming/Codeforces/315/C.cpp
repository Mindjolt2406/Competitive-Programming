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

long long int size;
bitset<10000010> bs;
vector<int> v;
vi prime;

void sieve(ll upperbound)
{
  size = upperbound + 1;
  v.assign(upperbound,1);
  bs.set();
  bs[0] = bs[1] = false;
  v[0] = v[1] = 0;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      for(ll j = i*i;j<size;j+=i) {bs[j] = false;v[j] = false;}
    }
    prime.pu((int)i);
  }
}

int compare(int a,int b,int p,int q)
{
  // cout<<"a: "<<a<<" b: "<<b<<" p: "<<p<<" q: "<<q<<endl;
  if(a*q<=b*p) {return 1;}
  return 0;
}

int counter(string s1,int boo)
{
  // string s1 = s2.substr(0,(s2.size()+1)/2);
  // cout<<"s2: "<<s2<<"s2.size(): "<<s2.size()<<endl; 
  if(!boo)
  {
    string k1;
    int k = s1.size();
    // cout<<"k: "<<k<<endl;
    while(k) {k1+='9';k--;}
    if(k1!="") return stoi(k1);
    return 0;
  }
  else
  {
    string k1;
    int k = s1.size();
    // cout<<"s1: "<<s1<<endl;
    k--;
    while(k) {k1+='9';k--;}
    if(k1!="") return stoi(k1);
    return 0;
  }
}

int palindrome(int n)
{
  string s,s1,s2,s3,s4;
  s = to_string(n);
  s1 = s.substr(0,(s.size()+1)/2);
  // cout<<"s: "<<s<<" s1: "<<s1<<endl;
  s2 = s1;
  reverse(s1.begin(),s1.end());
  if(s.size()%2==1) s2 = s2.substr(0,s2.size()-1);
  s2+=s1;
  reverse(s1.begin(),s1.end());
  s3 = to_string(stoi(s1)-1);
  if(s3.size()!=s1.size()) 
  {
    // cout<<"HERE TAKING CARE OF THIS SHIT"<<endl;
    string k;
    for(int i=0;i<s.size()/2;i++) k+='9';
    // cout<<"k: "<<k<<endl;
    int b = stoi(k);
    // cout<<"b: "<<b<<endl;
    b+=counter(k,(s.size()-1)%2);
    // cout<<"after: "<<b<<endl;
    // cout<<"Palindrome of "<<n<<": "<<b<<endl;
    return b;
  }
  int a = stoi(s2),b = stoi(s3);
  // cout<<"s1: "<<s1<<" s2: "<<s2<<" s3: "<<s3<<" a: "<<a<<endl;
  // cout<<"Palindrome of "<<n<<": ";
  if(n>=a) 
  {
    a = stoi(s1);
    // cout<<a<<" ";
    a+=counter(s1,s2.size()%2);
    // cout<<a<<endl;
    return a;
  }
  else
  {
    // cout<<b<<" ";
    b+=counter(s3,s.size()%2);
    // cout<<b<<endl;
    return b;
  }
}


int countprime(int n)
{
  return v[n];
}

int main()
{
  int p,q;
  sc(p);sc(q);
  sieve(3000000);
  // cout<<"here"<<endl;
  for(int i=1;i<v.size();i++) v[i]+=v[i-1];
  int max1 = -1;
  // cout<<palindrome(100005)<<endl;
  for(int i=1;i<2000000;i++) 
  {
    int mid = i;
    if(compare(countprime(mid),palindrome(mid),p,q)) {max1 = max(max1,mid);}
  }
  if(max1!=-1) cout<<max1<<endl;
  else cout<<"Palindromic tree is better than splay tree"<<endl;
  return 0;
}

