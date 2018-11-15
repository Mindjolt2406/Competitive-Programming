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
  int n,m;
  sc(n);sc(m);
  int t;
  sc(t);
  while(t--)
  {
    set<pair<int,int> > s1,s2,s3,s4;
    set<pair<int,int> > :: iterator it;
    int x,y,x1,y1,x2,y2;
    sc(x);sc(y);sc(x1);sc(y1);sc(x2);sc(y2);
    int x3=x,y3=y;
    // cout<<x3<<" "<<y3<<endl;
    while(x3<=n && y3<=m && x3>0 && y3>0) {s1.insert(mp(x3++,y3++));}
    // cout<<endl;
    x3 = x;y3 = y;
    // cout<<x3<<" "<<y3<<endl;
    while(x3<=n && y3<=m && x3>0 && y3>0) {s2.insert(mp(x3--,y3++));}
    // cout<<endl;
    x3 = x;y3 = y;
    while(x3<=n && y3<=m && x3>0 && y3>0) {s3.insert(mp(x3--,y3--));}
    // cout<<endl;
    x3 = x;y3 = y;
    while(x3<=n && y3<=m && x3>0 && y3>0) {s4.insert(mp(x3++,y3--));}
    // cout<<endl;
    // for(it = s1.begin();it!=s1.end();it++) cout<<it->first<<" "<<it->second<<endl;
    // cout<<endl;
    // for(it = s2.begin();it!=s2.end();it++) cout<<it->first<<" "<<it->second<<endl;
    // cout<<endl;
    if((s1.find(mp(x1,y1))!=s1.end() && s3.find(mp(x2,y2))!=s3.end()) || (s2.find(mp(x1,y1))!=s2.end() && s4.find(mp(x2,y2))!=s4.end()) || (s3.find(mp(x1,y1))!=s3.end() && s1.find(mp(x2,y2))!=s1.end()) || (s4.find(mp(x1,y1))!=s4.end() && s2.find(mp(x2,y2))!=s2.end())) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}
