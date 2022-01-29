#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_set<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_multiset<T> & vec);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::unordered_map<T1,T2> & p);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_set<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_multiset<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p){
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p){
    os<<"{";
    for(auto x: p)
        os<<x.first<<"->"<<x.second<<", ";
    os<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::unordered_map<T1,T2> & p){
    os<<"{";
    for(auto x: p)
        os<<x.first<<"->"<<x.second<<", ";
    os<<"}";
    return os;
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#ifndef ONLINE_JUDGE
#define tr(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#else 
#define tr(...)
#endif
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
// #define MOD 1000000007
// #define MOD 998244353
#define endl "\n"
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

// int find_parent(int parent[], int a)
// {
//     if (parent[a] >= 0)
//         return parent[a] = find_parent(parent, parent[a]);
//     else
//         return a;
// }
// void merge_sets(int parent[], int a, int b)
// {
//     int p1 = find_parent(parent, a), p2 = find_parent(parent, b);
//     if (p1 == p2)
//         return;
//     if (abs(parent[p1]) < abs(parent[p2]))
//         swap(p1, p2);
//     parent[p1] -= abs(parent[p2]);
//     parent[p2] = p1;
// }
struct DSU
{
    int parent = -1;
    // int color = 0;
    int lazy_color_invert = 0;
};
int find_parent(vector<DSU> &ds, int v)
{
    while(ds[v].parent >= 0)
        v = ds[v].parent;
    return v;
}
int find_color(vector<DSU> &ds, int v){
    
    int color = 0;
    while(ds[v].parent >= 0)
    {
        color ^= ds[v].lazy_color_invert;
        v = ds[v].parent;
    }
    return color;
}
bool bipartite = true;
void merge_sets(vector<DSU> &ds, int a, int b)
{
    int p1 = find_parent(ds, a),c1 = find_color(ds,a);

    int p2 = find_parent(ds, b),c2 = find_color(ds, b);
    if(p1 == p2)
    {
        int c1 = find_color(ds, p1);
        int c2 = find_color(ds, p2);
        if(c1 == c2)
        {
            bipartite = false;
        }
        return;
    }
    if(abs(ds[p1].parent)<abs(ds[p2].parent))
    {
        swap(p1, p2);
        swap(a, b);
        swap(c1,c2);
    }
    ds[p1].parent -= abs(ds[p2].parent);
    ds[p2].parent = p1;
    // tr(a,b,p1,p2,c1,c2);
    ds[p2].lazy_color_invert ^= (c1==c2);
}

bool check_2_matching(set<pair<int,int>> &se)
{
    assert(se.size() > 0);
    auto tmp = *(se.begin());
    int a = tmp.first;
    
    bool flag1 = true;
    tr(se);
    for(auto x: se)
    {
        // tr(x, flag);
        flag1 = flag1 & (x.first == a || x.second == a);
        // tr(x,flag);
    }
    bool flag2 = true;
    a = tmp.second;
    for(auto x: se)
    {
        flag2 = flag2 & (x.first == a || x.second == a);
    };
    // tr(flag);
    return ((!flag1) && (!flag2));
}
bool check_triangle(set<pair<int,int>> &se)
{
    if(se.size() > 6)
        return true;
    
    set<int> nodes;
    for(auto x: se)
    {
        nodes.insert(x.first);
        nodes.insert(x.second);
    }
    if(nodes.size() != 3)
        return true;
    vector<int> v(nodes.begin(),nodes.end());
    
    vector<vector<int>> mat(3, vector<int>(3));
    for (auto p : se) {
        mat[p.first][p.second] = mat[p.second][p.first] = 1;
    }

    if (mat[0][1] && mat[1][2] && mat[2][0])
        return false;

    for(int i=0;i<3;i++)
    {
        if(se.count({v[i],v[i]}) && se.count({min({v[(i+1)%3],v[(i+2)%3]}), max({v[(i+1)%3],v[(i+2)%3]})}))
            return true;
        if(se.count({v[i],v[i]}) && se.count({v[(i+1)%3],v[(i+1)%3]}))
            return true;
    }

    return false;
}
signed main()
{
    fastio();
    int n,m;
    cin>>n>>m;
    map<int,vector<pair<int,int>>> tmp_edges;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int w;
        cin>>w;
        tmp_edges[w].push_back({u,v});
    }
    vector<pair<int,vector<pair<int,int>>>> edges;
    for(auto x: tmp_edges)
    {
        edges.push_back(make_pair(x.first, x.second));
    }
    reverse(edges.begin(), edges.end());
    set<int> ans;
    vector<DSU> ds(n+1);
    for(auto tmp : edges)
    {
        int w = tmp.first;
        auto v = tmp.second;
        if(!bipartite)
            break;
        tr(w, v);
        set<pair<int,int>> se;
        for(auto edge : v)
        {
            int p1 = find_parent(ds, edge.first);
            int c1 = find_color(ds, edge.first);
            int p2 = find_parent(ds, edge.second);
            int c2 = find_color(ds, edge.second);
            // tr(p1, c1, p2, c2);
            if(p1 == p2 && c1 != c2)
                continue;
            int t1 = ((p1<<1)|c1);
            int t2 = ((p2<<1)|c2);
            if(t1 > t2)
                swap(t1, t2);
            se.insert({t1,t2});
        }
        tr(w,se);
        if(se.size()>=2 && check_2_matching(se) && check_triangle(se))
        {
            ans.insert(w);
        }
        for(auto edge : v)
        {
            merge_sets(ds, edge.first, edge.second);
        }
        // for(int i=1;i<=n;i++)
        // {
        //     tr(ds[i].parent, ds[i].lazy_color_invert);
        // }
    }
    if(bipartite)
        ans.insert(0);
    if(ans.size() == 0)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(auto x: ans){
        cout<<x<<endl;
    }
}