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
  int n;
  sc(n);
  vector<vector<int> > v;
  multiset<int> rx,ry;
  multiset<int, greater<int> > lx,ly;
  multiset<int> ::iterator it1,it2,it3,it4;
  for(int i=0;i<n;i++)
  {
    vector<int> v1(4);
    sc(v1[0]);sc(v1[1]);sc(v1[2]);sc(v1[3]);
    lx.insert(v1[0]);
    ly.insert(v1[1]);
    rx.insert(v1[2]);
    ry.insert(v1[3]);
    v.pu(v1);
  }
  if(*(lx.begin())<=*(rx.begin()) && *(ly.begin())<=*(ry.begin()))
  {
    cout<<*(lx.begin())<<" "<<*(ly.begin())<<endl;
    return 0;
  }

  for(int i=0;i<v.size();i++)
  {
    vector<int> v1 = v[i];
    lx.erase(lx.find(v1[0]));
    ly.erase(ly.find(v1[1]));
    rx.erase(rx.find(v1[2]));
    ry.erase(ry.find(v1[3]));
    if(*(lx.begin())<=*(rx.begin()) && *(ly.begin())<=*(ry.begin()))
    {
      cout<<*(lx.begin())<<" "<<*(ly.begin())<<endl;
      return 0;
    }
    lx.insert(v1[0]);
    ly.insert(v1[1]);
    rx.insert(v1[2]);
    ry.insert(v1[3]);
  }
  return 0;
}
