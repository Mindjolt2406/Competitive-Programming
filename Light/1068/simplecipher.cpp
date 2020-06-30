#include<bits/stdc++.h>
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


int main()
{
  __;
  string s = "Kotcdqmes, the lrbrr qsn't goov eumeoh, sometamlq dpe peoplw dlqozve more. Kotcdqmes peohll boaerve to zacc dpeir failh ycgirded; anqwhwc, pere's yomr ycgird -zenswCAD{f1o3n3r3_15_4w350m3}";
  string s2 = "Sometimes, the !!!!! isn't good enough, sometimes the people deserve more. Sometimes people believe to !!!! !!!!! !!!!! answered; !!!!!!!, here's your answer -zenseCTF{f1o3n3r3_15_4w350m3}";
  
  for(int i=0;i<s.size();i++) 
  {
    if((s[i] >= 'a' && s[i] <= 'z') || (s2[i] >= 'A' && s2[i] <= 'Z'))
    cout << (s2[i]-s[i]) << " "; 
  }
  cout << endl;
  // vector<int> v = {12,4,-3,6,12,-4,4,4,4,4,4,4,4,4};
  vector<int> v = {8,0,-7,2,16,-8,0,0,0,0,0,0};
  // for(int i=0;i<v.size();i++) v[i] -= 4;

  for(int j=0;j<1;j++)
  {
    string s2 = s;
    int counter = 0;
    for(int i=0;i<s.size();i++)
    {
      if((s2[i] >= 'a' && s2[i] <= 'z'))
      {
        s2[i] = (v[(counter+j)%((int)v.size())]+s2[i]-'a'+52)%26+'a';
        counter++;
      }
      else if((s2[i] >= 'A' && s2[i] <= 'Z'))
      {
        s2[i] = (v[(counter+j)%((int)v.size())]+s2[i]-'A'+52)%26+'A';
        counter++;
      }
    }
    t(s2,j); 
  }

  return 0;
}
