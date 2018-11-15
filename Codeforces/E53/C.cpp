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

using namespace std;

int change(string &s,int k, int x,int y)
{
  if(k>s.size()) return 0;
  int countx =0,county = 0,otherx =0,othery = 0;
  int n = s.size();
  for(int i=0;i<k;i++)
  {
    if(s[i]=='U') county++;
    else if(s[i]=='D') county--;
    else if(s[i]=='L') countx--;
    else countx++;
  }
  for(int i=0;i<n;i++)
  {
    if(s[i]=='U') othery++;
    else if(s[i]=='D') othery--;
    else if(s[i]=='L') otherx--;
    else otherx++;
  }

  // cout<<"k: "<<k<<" cx: "<<countx<<" cy: "<<county<<endl;
  if(abs(otherx-countx-x) + abs(othery-county-y)<=k && (abs(otherx-countx-x) + abs(othery-county-y))%2==k%2) return 1;
  int left = 0,right = k-1;
  while(right<n)
  { 
    if(s[left]=='U') county--;
    else if(s[left]=='D') county++;
    else if(s[left]=='L') countx++;
    else countx--;

    right++;
    if(right==n) break;
    if(s[right]=='U') county++;
    else if(s[right]=='D') county--;
    else if(s[right]=='L') countx--;
    else countx++;

    left++;
    // cout<<"k: "<<k<<" cx: "<<countx<<" cy: "<<county<<" left: "<<left<<" right: "<<right<<endl;
    // cout<<"OTHER: "<<otherx-countx<<" "<<othery-county<<endl;
    if(abs(otherx-countx-x) + abs(othery-county-y)<=k && (abs(otherx-countx-x) + abs(othery-county-y))%2==k%2) return 1;
  }
  // cout<<"k : "<<k<<endl;
  return 0;
}

int main()
{
  int n;
  sc(n);
  string s;
  scr(s);
  int x,y;
  sc(x);sc(y);
  int beg = 0,end = n/2;
  int min1 = INF;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    // cout<<mid<<endl;
    // mid*=2;
    if(change(s,mid*2,x,y)) {min1 = min(min1,mid*2);end = mid-1;}
    else beg = mid+1;
  }
  beg = 0,end = n/2;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    // cout<<mid<<endl;
    // mid*=2;mid++;
    if(change(s,mid*2+1,x,y)) {min1 = min(min1,mid*2+1);end = mid-1;}
    else beg = mid+1;
  }

  // Check for n
  if(min1==INF) cout<<-1<<endl;
  else cout<<min1<<endl;
  return 0;
}

