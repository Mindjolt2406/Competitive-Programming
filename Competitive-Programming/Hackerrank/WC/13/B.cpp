#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define pu push_back
#define mt make_tuple
#define mp make_pair
using namespace std;

const int N = 100100;
int p[N], sz[N], grade1[N], grade2[N], grade3[N];
map<string, pair <int,int> > d;
map<int, pair<int,string> > e;
int min1,max1;
int a1[3];

void create(int x){
	p[x] = x;
	sz[x] = 1;
  if(e[x].first==1) grade1[x] = 1;
  else if(e[x].first==2) grade2[x] = 1;
  else grade3[x] = 1;
	return;
}

int finder(int x){
  if(x == p[x]) return x;
  return p[x] = finder(p[x]);
}

void merge(int x, int y){
	x = finder(x), y = finder(y);
  if(x == y) return;
  if(sz[x]+sz[y]<=max1 && grade1[x]+grade1[y]<=a1[0] && grade2[x]+grade2[y]<=a1[1] && grade3[x]+grade3[y]<=a1[2])
  {
    if(sz[x] < sz[y]) swap(x, y);
    p[y] = x;
    sz[x] += sz[y];
    grade1[x]+=grade1[y];
    grade2[x]+=grade2[y];
    grade3[x]+=grade3[y];
    sz[y] = 0;
  }
  return;
}

int main()
{
  int n,m;
  cin>>n>>m;
  cin>>min1>>max1;
  cin>>a1[0]>>a1[1]>>a1[2];
  for(int i=0;i<n;i++)
  {
    string s;
    int a;
    cin>>s>>a;
    d[s] = mp(i,a);
    e[i] = mp(a,s);
    create(i);
  }
  for(int h=0;h<m;h++)
  {
    string a,b;
    cin>>a>>b;
    merge(d[a].first, d[b].first);
  }
  int max2 = 0;
  for(int i=0;i<n;i++) max2 = max(max2,sz[i]);
  set<int> s;
  for(int i=0;i<n;i++)
  {
    if(sz[i]==max2) s.insert(i);
  }
  vector<string> v;
  for(int i=0;i<n;i++)
  {
    int c = finder(i);
    if(s.find(c)!=s.end() && sz[c]>=min1) v.pu(e[i].second);
  }
  sort(v.begin(),v.end());
  if(max2>=min1) for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
  else cout<<"no groups"<<endl;
  return 0;
}
