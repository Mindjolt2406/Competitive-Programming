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
  string s;
  scr(s);
  stack<char> st;
  map<char,int> d;
  d['['] = 0;d['('] = 0;d['<'] = 0;d['{'] = 0;
  int count = 0,boo = 0;;
  for(int i=0;i<s.size();i++) 
  {
    if(s[i]=='(' ||s[i]=='{' || s[i]=='[' || s[i]=='<') count++;
    else count--;
    if(count<0) {boo = 1;break;}
  }
  if(boo || count!=0) {cout<<"Impossible"<<endl;return 0;}  
  count = 0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='(' ||s[i]=='{' || s[i]=='[' || s[i]=='<') st.push(s[i]);
    else 
    {
      char c = st.top();
      // cout<<"c: "<<st.top()<<" s[i]: "<<s[i]<<endl;
      if(abs(s[i]-c)<=2) st.pop();
      else {st.pop();count++;}
    }
  }
  cout<<count<<endl;
  return 0;
}