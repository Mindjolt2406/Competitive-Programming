// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
// #define int ll
const int N = 2003;
int n,k;
map<int,vector<int> >grp,g,cc;
vector<int> pre,post;
int visited[N],ans[N];


void dfs1(int v,int p){
    pre.pb(v);
    for(auto u:grp[v]){
        dfs1(u,v);
    }
}

void dfs2(int v,int p){
    for(auto u:grp[v]){
        dfs2(u,v);
    }
    post.pb(v);
}

void dfs(int v,int c){
    visited[v] = 1;
    cc[c].pb(v);
    for(auto u:g[v]){
        if(visited[u]==1)continue;
        dfs(u,c);
    }
}

int solve(int test){
    // tr(test);
    cin>>n>>k;
    grp.clear();
    g.clear();
    pre.clear();
    post.clear();
    cc.clear();
    MEMS(visited,0);
    MEMS(ans,0);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a!=0)grp[i].pb(a);
        if(b!=0)grp[i].pb(b);
    }
    dfs1(1,0);
    dfs2(1,0);
    // tr(pre);
    // tr(post);
    for(int i=0;i<n;i++){
        int x = pre[i];
        int y = post[i];
        g[x].pb(y);
        g[y].pb(x);
    }
    int c = 1;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i,c);
            c++;
        }
    }
    if((c-1)<k){
        cout<<"Case #"<<test<<": "<<"Impossible"<<endl;
        return 0;
    }
    for(int i=1;i<c;i++){
        for(auto j:cc[i]){
            int color = i;
            if(i>k){
                color = 1;
            }
            ans[j] = color;
        }
    }
    cout<<"Case #"<<test<<": ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}


int32_t main(){ _
           int t;
           cin>>t;
           for(int i=0;i<t;i++){
               solve(i+1);
           }
           return 0;
}
