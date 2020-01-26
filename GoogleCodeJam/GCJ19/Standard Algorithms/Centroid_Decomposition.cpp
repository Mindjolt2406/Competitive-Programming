/*
Rathin Bhargava
IIIT Bangalore

*/
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

/*
Steps
1. Get the centroids and make the centroid tree
  a) Do a recursive dfs on the tree, make the centroids for itself, and then go on to find the next set of centroids
    It happens like this. Find the centroid of the tree, mark it with its level. You would know the level of the centroid since
    you would've started off with the root of the tree, which currently has a centroid level of 0.
    Once you find the centroid, starting with each of its children as roots, get the new centroids and connect the old centroid 
    to the new one the moment you find it. Again recurse and recurse and recurse.
    The base case is when you have only 1 leaf node.

    So, how would you find the centroid? You know the size of the subtree you are in, and if any child has greater than N/2
    nodes go to that guy and continue. The sizes of each subtree could be precomputed.
    The moment there's no child who's size is greater than N/2, then you're at the centroid.

  b) Make structs for each of them, and have attributes number(identifier), level and parent
    We need such atributes for stuff like LCA. Here since the height of the tree is O(logn), we don't need to do some new stuff
    for LCA. If you want the LCA for 2 nodes, whose levels are a and b, go to their ancestors who's level is min(a,b). From there
    Keep comparing to check if the two nodes are the same or no. If they are, then that's the LCA. Otherwise go to their
    ancestors and repeat.   

2. Make the data structure 

  The data structure contains some information about every path from a centroid to a node in its subtree. The number of such
  paths are O(nlogn). This is easy to see. A centroid at the kth level in the centroid tree would have N/2^k nodes in its
  subtree. There are 2^k nodes at the centroid level of k. Summing up for k 1 -> logn, we get N/2^k *2^k = N*sum(1->logn)
  This becomes NlogN. 
  
  If the computation involved in these paths are associative, then we can just try
*/

dfs(vector<int>*adj, int u,int parent,int distance)
{
  
}

int main()
{
  __;
  
  return 0;
}

