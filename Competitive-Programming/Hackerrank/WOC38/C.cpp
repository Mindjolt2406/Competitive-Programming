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

map <long long int,long long int> d;
map <long long int,long long int> ::iterator it;
long long int* parent;
vector< pair<long long int,long long int> >prt;
vector < pair <long long int,long long int> > *adj;

void addEdge(ll a,ll b,ll c)
{
  adj[a].pu(mp(b,c));
  adj[b].pu(mp(a,c));
}

// void bfs(vector<pair<int,int> >*adj,int*visited)
// {
//   queue<pair<int,int> > q;
//   q.push(0);
//   int* visited = (int*)calloc(n,sizeof(int));
//   while(!q.empty())
//   {
//     pair<int,int> p = q.front();
//     q.pop();
//     int u = q.first;
//     int parent = q.second;
//     for(int i=0;i<adj[u].size();i++)
//     {
//       if(adj[u][i].first!=parent)
//       {
//         int c =
//       }
//     }
//   }
// }

// void dfs(vector<pair<int,int> >*adj,set<int> *visited,int u,int k,int*dp,int n)
// {
//   if(u==n-1) return;
//   for(int i=0;i<adj[u].size();i++)
//   {
//     if(visited[u].find(adj[u][i].first)==visited[u].end())
//     {
//       // if(dp[adj[u][i].first]==INF) dp[adj[u][i].first] = adj[u][i].second;
//       int c = adj[u][i].second+dp[u];
//       cout<<"c: "<<c<<" u: "<<u<<" adj[u][i].first: "<<adj[u][i].first<<endl;
//       if(2*k-c%(2*k)>0 && n%(2*k)>=k) c+=2*k-c%(2*k);
//       dp[adj[u][i].first] = min(dp[adj[u][i].first],c);
//       visited[adj[u][i].first].insert(u);
//       dfs(adj,visited,adj[u][i].first,k,dp,n);
//     }
//   }
// }

void bottomupheapify(vector< pair<long long int,long long int> > &l,long long int n,long long int index)
{
  d[l[index].first] = index;
  while(index>0 && l[(index-1)/2].second>l[index].second)
  {
    //Swapping for the map
    d[l[index].first] = (index-1)/2;
    d[l[(index-1)/2].first] = index;
    //Swapping the elements
    long long int k = l[index].second;
    long long int k1 = l[index].first;
    l[index].second = l[(index-1)/2].second;
    l[index].first = l[(index-1)/2].first;
    l[(index-1)/2].second = k;
    l[(index-1)/2].first = k1;
    index = (index-1)/2;
  }
}

void topdownheapify(vector< pair<long long int,long long int> >&l,long long int n,long long int index)
{
  while(2*index+1<n)
  {
    long long int left = 2*index+1,right = 2*index+2,c;
    if(right<n)
    {
      if(l[left].second<l[index].second && l[left].second<l[right].second) c = left;
      else if(l[right].second<l[index].second) c = right;
      else break;
    }
    else if(right>=n)
    {
      if(l[left].second<l[index].second) c = left;
      else break;
    }
    else break;
    long long int k = l[index].second;
    long long int k1 = l[index].first;
    l[index].second = l[c].second;
    l[index].first = l[c].first;
    l[c].second = k;
    l[c].first = k1;
    d[l[index].first] = index;
    index = c;
    d[l[index].first] = index;
  }
}

void insert(vector< pair<long long int,long long int> >&l,long long int n,pair <long long int,long long int> p)
{
  // cout<<"Entered: "<<p.first<<" n: "<<n<<endl;
  l.push_back(p);
  // print(l);
  bottomupheapify(l,n,n-1);
  // print(l);
  // cout<<"Exit: "<<p.first<<" "<<d[p.first]<<endl;
}

void deletemin(vector< pair<long long int,long long int> >&l, long long int n)
{
  long long int k = l[0].second;
  long long int k1 = l[0].first;
  l[0].second = l[n-1].second;
  l[0].first = l[n-1].first;
  l[n-1].second = k;
  l[n-1].first = k1;
  d[l[0].first] = 0;
  d[l[n-1].first] = n-1;
  d.erase(l[n-1].first);
  l.pop_back();
  topdownheapify(l,n-1,0);
}

void delete1(vector< pair<long long int,long long int> >&l,long long int n,long long int key)
{
  long long int index = d[key];
  l[index].second = l[0].second-1;
  bottomupheapify(l,n,index);
  deletemin(l,n);
}

void dijkstra(long long int s,long long int n,ll k)
{
  // cout<<"jere"<<endl;
  vector< pair <long long int,long long int> >heap; //Initialising the heap
  // Priority
  long long int* colour = new long long int[n];
  // cout<<"here2"<<endl;
  for(long long int i=0;i<n;i++) {colour[i] = 0;parent[i] = i;}
  for(long long int i=0;i<n;i++) prt.pu(mp(i,INF));
  prt[s].second = 0;
  parent[s] = s;
  // Dijkstra initialisation
  heap.pu(prt[s]);
  long long int counter = 1;
  colour[s] = 1;
  // cout<<"here"<<endl;
  while(!heap.empty())
  {
    pair <long long int,long long int> p = heap[0];
    long long int u = p.first;
    long long int pr = p.second;
    // cout<<"Min: "<<u<<" "<<pr<<endl;
    deletemin(heap,counter);
    // print(heap);
    counter--;
    // printm();
    colour[u] = 2;
    // cout<<"u: "<<u<<" pr: "<<pr<<endl;
    for(long long int i=0;i<adj[u].size();i++)
    {
      // printprt();
      // printcolour(colour,n);
      // for(int i=0;i<n;i++)
      // {
      //   cout<<"i: "<<i<<" parent: "<<parent[i]<<endl;
      // }
      long long int v = adj[u][i].first;
      long long int w = adj[u][i].second;
      pair <long long int,long long int> p1;
      ll c = w+pr;
      if(k<=c%(2*k) && adj[u][i].first!=n-1) c+=(2*k - c%(2*k));
      if(colour[v]==0)
      {
        counter++;
        colour[v] = 1;
        p1 = mp(v,c);
        prt[v] = p1;
        // cout<<"Inserting "<<p1.first<<endl;
        insert(heap,counter,p1);
        // cout<<"Succesful! "<<p1.first<<endl;
        // printm();
        parent[v] = u;
      }
      else if(colour[v]==1)
      {
        p1 = mp(v,min(c,prt[v].second));
        if(c<prt[v].second)parent[v] = u;
        prt[v] = p1;
        long long int index = d[v];
        heap[index].second = p1.second;
        // cout<<"Heapify "<<p1.first<<endl;
        topdownheapify(heap,counter,index);
        // cout<<"Succesful Heapify! "<<p1.first<<endl;
        // printm();
      }
    }
    // cout<<endl;
    // print(heap);
  }
}


int main()
{
  ll n,k,q;
  cin>>n>>k>>q;
  // tuple<int,int,int> t;
  parent = new ll[n];
  adj = new vector<pair<ll,ll> >[n];
  set<ll>*visited = new set<ll>[n];
  map<pair<ll,ll>, ll> e;
  map<pair<ll,ll>, ll> :: iterator it1;
  // ll*dp = new int[n];
  // for(int i=0;i<n;i++) prt[i] = INF;
  for(int h=0;h<q;h++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    // cout<<a<<" "<<b<<endl;
    if(true)
    {
      if(e.find(mp(a,b))!=e.end()) {e[mp(a,b)] = min((int)e[mp(a,b)],(int)c);}
      else e[mp(a,b)] = c;
      // else addEdge(a,b,c);
    }
  }
  for(it1=e.begin();it1!=e.end();it1++)
  {
    pair<ll,ll> p = it1->first;
    ll key= it1->second;
    addEdge(p.first,p.second,key);
  }
  // dp[0] = 0;
  // dfs(adj,visited,0,k,dp,n);
  dijkstra(0,n,k);
  for(int i=0;i<n;i++) cout<<prt[i].second<<" ";cout<<endl;
  printf("%lld\n",prt[n-1].second);
  return 0;
}
