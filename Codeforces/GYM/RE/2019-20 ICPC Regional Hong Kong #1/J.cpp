#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
  string str = ""; 

  int n1 = str1.length(), n2 = str2.length(); 

  reverse(str1.begin(), str1.end()); 
  reverse(str2.begin(), str2.end()); 
    
  int carry = 0; 

  for (int i=0; i<n2; i++) 
  { 
    int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 

    if (sub < 0) 
    { 
      sub = sub + 10; 
      carry = 1; 
    } 
    else
        carry = 0; 

    str.push_back(sub + '0'); 
  } 

  for (int i=n2; i<n1; i++) 
  { 
    int sub = ((str1[i]-'0') - carry); 
      
    if (sub < 0) 
    { 
      sub = sub + 10; 
      carry = 1; 
    } 
    else carry = 0; 
          
    str.push_back(sub + '0'); 
  } 

  reverse(str.begin(), str.end()); 

  return str; 
} 

ll dp[5000][60][60] = {0};
// map<vector<int> , int> dp;

// ll ret = 0;
void getDigit(string s, vector<int> &digit)
{
  digit.resize(s.size());
  for(int i=0;i<s.size();i++) digit[i] = s[i]-'0';
  reverse(digit.begin(),digit.end());
}

// ll getAns(int idx, int sumMod, int digitMod, int sumDigits, int tight, int m,vector<int> &digit,string s)
ll getAns(int idx, int sumMod, int digitMod, int sumDigits, int tight, int m,vector<int> &digit)
{
  // t(s);
  int diff = (sumMod - digitMod +m ) % m;
  if(idx == -1) 
  {
    // if(sumMod == digitMod) {string i = s;}
    return (diff == 0);
  }

  if(dp[idx][diff][sumDigits] != -1 && tight != 1)
  {
    // t(dp[idx][sumDigits][digitMod]);
    // ret +=  dp[idx][sumDigits][digitMod];
    return dp[idx][diff][sumDigits];
  }

  ll ret = 0;

  int k = (tight)? digit[idx] : 9;

  for (int i = 0; i <= k ; i++) 
  { 
    int newTight = (digit[idx] == i)? tight : 0; 
    int newSum = (sumMod*10 + i) % m;
    int newSumDigits = (sumDigits + i) % m;
    int newDigitMod = (digitMod + sumDigits * i) % m;

    // s += '0'+i;
    
    ret += getAns(idx-1, newSum,newDigitMod, newSumDigits, newTight, m,digit);
    // getAns(idx-1, newSum,newDigitMod, newSumDigits, newTight, m,digit,s); 
    ret %= MOD;
    // s.erase(s.end()-1);
  } 

  if (tight == 0) {dp[idx][diff][sumDigits] = ret;}
    

  // t(idx,sumMod,digitMod,ret);
  return ret;
}

ll solve(string a,string b,int m)
{
  // for(int i=0;i<max((int)a.size(),(int)b.size());i++)
  // {
  //   memset(dp[i],-1,sizeof(dp[i]));
  // }
  // memset(dp,-1,sizeof(dp));

  vector<int> digitA;
  getDigit(findDiff(a,"1"),digitA);

  ll ans1 = getAns(digitA.size()-1,0,0,0,1,m,digitA);

  // ll ans1 = 0;

  vector<int> digitB;
  getDigit(b,digitB);

  string s;
  ll ans2 = getAns(digitB.size()-1,0,0,0,1,m,digitB);

  return (ans2-ans1+MOD) % MOD;
}

int main()
{
  __;
  int t;
  cin >> t;
  memset(dp,-1,sizeof(dp));
  while(t--)
  {
    string a,b;
    cin >> a >> b;
    int m;
    cin >> m;
    cout << solve(a,b,m) << endl;
  }
  return 0;
}


/*
1
50 50 17

1
33
33
3


*/