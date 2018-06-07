#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n = s.size();
  int counta = 0,countb = 0,countab = 0,countba = 0,countaba = 0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='a') counta++;
    else countb++;
  }
  int boo = 0;
  int i=0;
  vector<int> v;
  while(i<n)
  {
    if(s[i]=='b'&& !boo) continue;
    int count = 0;
    while(s[i] =='a' && i<n) {count++;i++;boo = 1;}
    v.pu(count);
    count = 0;
    while(s[i] =='b' && i<n) {count++;i++;}
    v.pu(count);
  }
  for(int i=0;i<v.size();i++)
  {
    if(i%2==0) countab = max(countab,v[i]);
    if(i%2==1) countab+=v[i];
  }
  i = 0;boo = 0
  v.clear();
  while(i<n)
  {
    if(s[i]=='a' && !boo) continue;
    int count = 0;
    while(s[i] =='b' && i<n) {count++;i++;boo = 1;}
    v.pu(count);
    count = 0;
    while(s[i] =='a' && i<n) {count++;i++;}
    v.pu(count);
  }
  for(int i=0;i<v.size();i++)
  {
    if(i%2==0) countba = max(countba,v[i]);
    if(i%2==1) countba+=v[i];
  }
  i = 0;boo = 0;
  v.clear();
  while(i<n)
  {
    if(s[i]=='b'&& !boo) continue;
    int count = 0;
    while(s[i] =='a' && i<n) {count++;i++;boo = 1;}
    v.pu(count);
    count = 0;
    while(s[i] =='b' && i<n) {count++;i++;}
    v.pu(count);
  }
  if(v.size()>=3)
  {
    for(int i=0;i<v.size();i++)
    {

    }
  }
}
