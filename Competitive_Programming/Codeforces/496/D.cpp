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
  int left = 0,right = 0;
  int i=0;
  int sum1 = 0,count = 0;
  // while(left<n && right<n)
  // {
  //   sum1+=s[right];
  //   if(sum1%3==0)
  //   {
  //     while(sum1%3==0) {sum1-=s[left];left++;}
  //     if(s[left]==0 && left==right) count+
  //   }
  //   if(left==right){right++;sum1+=s[right]}
  // }
  int n = s.size();
  int prev = 0;
  set<int> s1;
  s1.insert(prev);
  while(i<n)
  {
    sum1+=s[i]-48;
    // if(s[i]-48==0) {count++;sum1 = 0;}
    // cout<<sum1<<endl;
    if(s1.find(sum1%3)!=s1.end()) {count++;s1.clear();}
    prev = sum1%3;
    s1.insert(prev);
    i++;
  }

  cout<<count<<endl;
  return 0;
}
