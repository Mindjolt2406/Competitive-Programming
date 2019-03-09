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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

typedef struct node
{
  int x;
  int y;
  int color;
  int level;
} node;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

node* newNode()
{
  node* n = new node;
  return n;
}

set<node*> keep;

void bfs2(int nx,int m,node* orig,vector<vector<int> > &v)
{
  queue<node*> q;
  q.push(orig);
  
  while(!q.empty())
  {
    node*n = q.front();
    q.pop();

    if(n==NULL) continue;
    for(int i=0;i<4;i++)
    {
      int a = n->x + dx[i];
      int b = n->y + dy[i];
      if(a<0 || a>=nx || b<0 || b>=m) continue;
      if(v[a][b]==0 && n->level>0) 
      {
        node* n1 = newNode();
        n1->x = a;
        n1->y = b;
        n1->color = n->color;
        n1->level = n->level-1;

        q.push(n1);
        if(n1->level==0 && !(n1->x<0 || n1->x>=nx || n1->y<0 || n1->y>=m)) keep.insert(n1);
        v[a][b] = n->color;

        for(int i1=0;i1<nx;i1++) pr(v[i1]);
        cout<<endl;
      }
    }

    // if(n->level==0) keep.insert(n);
  }
}

void bfs(int n1,int m,vector<vector<int> > &v,vector<int> &speed)
{
  queue<node*> q;
  vector<vector<node*> > w(11);
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<4;k++)
      {
        int a = i+dx[k],b = j+dy[k];
        if(a<0 || a>=n1 || b<0 || b>=m) continue;
        if(v[i][j]<=0) continue;
        node* n = newNode();
        n->x = i;
        n->y = j;
        n->color = v[i][j];
        n->level = speed[v[i][j]];
        w[v[i][j]].pu(n);
      }
    }
  }

  for(int i=1;i<=10;i++) 
  {
    for(int j=0;j<w[i].size();j++) 
    {
      q.push(w[i][j]);
    }
  }

  while(!q.empty())
  {
    node *n = q.front();
    q.pop();
    
    // if(n==NULL) continue;
    bfs2(n1,m,n,v);
    int level = n->level;
    if(!keep.empty())
    {
      for(auto it = keep.begin();it!=keep.end();it++) {(*it)->level = level;q.push(*it);}
      keep.clear();
    }
  }
}

int main()
{
  __;
  int n,m,p;
  cin>>n>>m>>p;
  vector<int> speed(p+1);
  for(int i=1;i<=p;i++) cin>>speed[i];
  vector<vector<int> > v(n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      char c;
      cin>>c;
      if(c=='#') v[i].pu(-1);
      else if(c=='.') v[i].pu(0);
      else v[i].pu(c-'0');
    }
  }

  bfs(n,m,v,speed);

  vector<int> counter(11);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]>0) counter[v[i][j]]++;
    }
  }

  for(int i=1;i<=p;i++)
  {
    cout<<counter[i]<<" ";
  }
  cout<<endl;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<v.size();j++) cout<<v[i][j]<<" ";
    cout<<endl;
  }

  
  return 0;
}

