#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pu push_back
using namespace std;

const long long int N = 100100;
long long int p[N], sz[N];



void create(long long int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

long long int finder(long long int x){
  if(x == p[x]) return x;
  return p[x] = finder(p[x]);
}

long long int merge(long long int x, long long int y){
	x = finder(x), y = finder(y);
	if(x == y) return 0;
  if(sz[x] < sz[y])
  {
    long long int t = x;
    x = y;
    y = t;
  }
  p[y] = x;
  sz[x] += sz[y];
  return 1;
}

void addEdge(vector<pair <long long int,long long int> >*adj,long long int u,long long int v,long long int key)
{
  adj[u].pu(mp(v,key));
  adj[v].pu(mp(u,key));
}

int main()
{
  long long int n,q;
  cin>>n>>q;
  vector< pair <long long int,long long int> > *adj = new vector<pair<long long int,long long int> >[n];
  vector< tuple<long long int,long long int,long long int> > v;
  for(long long int h=0;h<q;h++)
  {
    long long int a,b,c;
    cin>>a>>b>>c;
    a-=1;b-=1;
    v.pu(mt(c,a,b));
  }
  sort(v.begin(),v.end());
  // Creating the DSU
  for(long long int i=0;i<n;i++)
  {
    create(i);
  }
  long long int count = 0,counter = 0;
  for(long long int i=0;i<v.size();i++)
  {
    tuple<long long int,long long int,long long int> t;
    t = v[i];
    long long int a = get<1>(t),b = get<2>(t),c = get<0>(t);
    if(merge(a,b)) {addEdge(adj,a,b,c);count++;counter+=c;}
    if(count==n-1) break;
  }
  cout<<counter<<endl;
  return 0;
}
