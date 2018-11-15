#include<bits/stdc++.h>
using namespace std;

int check(string s, int k)
{
  int n = s.size();
  set<string> s1;
  int boo =0;
  for(int i=0;i<n-k+1;i++)
  {
    string t = s.substr(i,k);
    if(s1.find(t)==s1.end()) s1.insert(t);
    else {boo = 1;break;}
  }
  return boo;
}

int main()
{
  string s;
  cin>>s;
  int n = s.size();
  int beg = 1, end = n-1;
  int max1 = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    // cout<<"mid: "<<mid<<endl;
    int c = check(s,mid);
    if(c) {max1 = max(max1,mid);beg = mid+1;}
    else end = mid - 1;
  }
  cout<<max1<<endl;
  return 0;
}
