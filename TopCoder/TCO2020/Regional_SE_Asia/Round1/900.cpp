#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

#define NIL -1 
using namespace std; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
    void APUtil(int v, bool visited[], int disc[], int low[],  
                int parent[], bool ap[]); 
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w);   // function to add an edge to graph 
    int AP();    // prints articulation points 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// A recursive function that find articulation points using DFS traversal 
// u --> The vertex to be visited next 
// visited[] --> keeps tract of visited vertices 
// disc[] --> Stores discovery times of visited vertices 
// parent[] --> Stores parent vertices in DFS tree 
// ap[] --> Store articulation points 
void Graph::APUtil(int u, bool visited[], int disc[],  
                                      int low[], int parent[], bool ap[]) 
{ 
    // A static variable is used for simplicity, we can avoid use of static 
    // variable by passing a pointer. 
    static int time = 0; 
  
    // Count of children in DFS Tree 
    int children = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    list<int>::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
        int v = *i;  // v is current adjacent of u 
  
        // If v is not visited yet, then make it a child of u 
        // in DFS tree and recur for it 
        if (!visited[v]) 
        { 
            children++; 
            parent[v] = u; 
            APUtil(v, visited, disc, low, parent, ap); 
  
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // u is an articulation point in following cases 
  
            // (1) u is root of DFS tree and has two or more chilren. 
            if (parent[u] == NIL && children > 1) 
               ap[u] = true; 
  
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u. 
            if (parent[u] != NIL && low[v] >= disc[u]) 
               ap[u] = true; 
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// The function to do DFS traversal. It uses recursive function APUtil() 
int Graph::AP() 
{ 
    // Mark all the vertices as not visited 
    int cnt = 0;
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
    bool *ap = new bool[V]; // To store articulation points 
  
    // Initialize parent and visited, and ap(articulation point) arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
        ap[i] = false; 
    } 
  
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            APUtil(i, visited, disc, low, parent, ap); 
  
    // Now ap[] contains articulation points, print them 
    for (int i = 0; i < V; i++) 
        if (ap[i] == true) 
            cnt++;
    return cnt;
} 



class BridgesAndCutVertices
{
  public:
  vector <int> construct(int B, int C)
  // {
  //   int linegraph = min(B+1,C+2);
  //   vector<pair<int,int> > edges;
  //   int cur = 0;
  //   bool flag = false;
  //   if(linegraph > 1)
  //   {
  //     flag = 1;
  //     for(int i=1;i<linegraph;i++)
  //     {
  //       edges.pu(mp(i-1,i));
  //     }
  //     cur = linegraph;
  //     B -= (linegraph-1);
  //     C -= (linegraph-2);
  //   }
  //   if(B>0)
  //   {
  //     while(B--)
  //     {
  //       edges.pu(mp(cur,cur+1));
  //       cur += 2;
  //     }
  //   }
  //   if(C>0)
  //   {
  //     cur = max(0,cur-1);
  //     for(int i=0;i<2*C-2;i++)
  //     {
  //       edges.pu(mp(cur+i,cur+i+1));
  //       if(i%2 ==0) edges.pu(mp(cur+i,cur+i+2));
  //     }
  //     int last = cur+2*C-2;
  //     edges.pu(mp(last+1,last+2));
  //     edges.pu(mp(last,last+2));
  //     edges.pu(mp(last,last+1));
  //     if(!flag)
  //     {
  //       edges.pu(mp(0,last+3));
  //       edges.pu(mp(0,last+4));
  //       edges.pu(mp(last+3,last+4));
  //     }
  //   }
  //   vector<int> ans;
  //   for(auto x : edges) {ans.pu(x.fi);ans.pu(x.se);};
  //   return ans;
  // }
  {
    vector<int> ans;
    int counter = 1;
    if(B == 0 && C == 0) 
    {
      ans.pu(0);
      ans.pu(1);
      ans.pu(1);
      ans.pu(2);
      ans.pu(2);
      ans.pu(0);
      return ans;
    }

    if(B==0)
    {
      vector<int> ans;
      int shift = 0;
      for(int i=0;i<C+1;i++)
      {
        ans.pu(shift+i);
        ans.pu(shift+i+1);
      }

      int counter = C+2;
      for(int i=0;i<C+1;i++)
      {
        ans.pu(shift+counter-C-2);
        ans.pu(shift+counter);

        ans.pu(shift+counter-C-1);
        ans.pu(shift+counter);

        counter++;
      }
      return ans;
    }
    else if(C == 0)
    {
      vector<int> ans;
      for(int i=0;i<B;i++)
      {
        ans.pu(2*i);
        ans.pu(2*i+1);
      }
      return ans;
    }

    while(B && C)
    {
      ans.pu(counter-1);
      ans.pu(counter);
      counter++;
      B--; 
      if(!B) break;
      C--;
    }

    if(C)
    {
      C--;
      int shift = counter-1;
      for(int i=0;i<C+1;i++)
      {
        ans.pu(shift+i);
        ans.pu(shift+i+1);
      }

      int counter = C+2;
      for(int i=0;i<C+1;i++)
      {
        ans.pu(shift+counter-C-2);
        ans.pu(shift+counter);

        ans.pu(shift+counter-C-1);
        ans.pu(shift+counter);

        counter++;
      }
    }
    else if(B)
    {
      while(B--)
      {
        ans.pu(0);
        ans.pu(counter);
        counter++;
      }
    }
    return ans;
  }
};

int main()
{
  __;
  BridgesAndCutVertices b;
  t(b.construct(0,2));
  int full_max = -1;
  for(int i=0;i<=23;i++)
  {
    for(int j=0;j<=23;j++)
    {
      vector<int> v = b.construct(i,j);
      int max1 = -1;
      for(auto it : v) max1 = max(max1,it);
      
      Graph g(max1+1);
      for(int i=0;i<v.size();i+=2)
      {
        // t(v[i],v[i+1]);
        g.addEdge(v[i],v[i+1]);
      }
      // if(g.bridge() == i) ;
      // if(!j) {t(i,v);}
      if(g.AP() == j);
      else 
      {
        t(i,j);
        t(v);
        cout << "False" << endl;
        // return 0;
      }
    }
  }

  return 0;
}
