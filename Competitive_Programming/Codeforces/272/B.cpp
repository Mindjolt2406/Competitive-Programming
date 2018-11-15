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
  string s1,s2;
  scr(s1);scr(s2);
  int count1 = 0,count2 = 0,count3 = 0;
  for(int i=0;i<s1.size();i++) 
  {
    if(s1[i]=='+') count1++;
    else if(s1[i]=='-') count1--;
    if(s2[i]=='+') count2++;
    else if(s2[i]=='-') count2--;
    else if(s2[i]=='?') count3++;
  }
  int count4 = abs(count1-count2);
  vector<ld> v;
  v.pu(1);
  for(int i=1;i<11;i++) v.pu(v[v.size()-1]*i);
  if(count4==0 && count3==0) cout<<1<<endl;
  else if(count4>count3) cout<<0<<endl; 
  else
  {
    // cout<<count3<<" "<<count4<<endl;
    if((count4-count3)%2!=0) {cout<<0<<endl;return 0;}
    count4 = abs(count4-count3)/2;
    cout<<v[count3]/(v[count3-count4]*v[count4]*pow(2,count3))<<endl;
  }
  return 0;
}

