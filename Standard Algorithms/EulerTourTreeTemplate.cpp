// https://www.programmersought.com/article/36898968/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define MAXN 200010
using namespace std;
inline void read(int &x){
   int s=0,w=1;
   char c=getchar();
   while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}
   while(isdigit(c)){s=(s<<3)+(s<<1)+c-'0';c=getchar();}
   x=s*w;
}
inline void write(long long x){
     if(x<0)x=-x,putchar('-');
     if(x>9)write(x/10);
     putchar(x%10+'0');
}
struct edge{
   int to,nxxt;
}e[MAXN];
int head[MAXN],cnt;
inline void add(int x,int y){
   e[++cnt].to=y;
   e[cnt].nxxt=head[x];
   head[x]=cnt;
}
int fa[MAXN],size[MAXN],son[MAXN][2],l[MAXN],r[MAXN],mark[MAXN],dfn[MAXN],tot,a[MAXN];
long long lazy[MAXN],sum[MAXN],val[MAXN];
inline void push_up(int root){
   sum[root]=sum[son[root][0]]+sum[son[root][1]]+val[root];
   size[root]=size[son[root][0]]+size[son[root][1]]+mark[root];
}
inline void push_down(int root){
   if(root&&fa[root])push_down(fa[root]);
   if(!root||!lazy[root])return ;
   lazy[son[root][0]]+=lazy[root],lazy[son[root][1]]+=lazy[root];
   val[son[root][0]]+=lazy[root]*mark[son[root][0]],val[son[root][1]]+=lazy[root]*mark[son[root][1]];
   sum[son[root][0]]+=(long long)size[son[root][0]]*lazy[root],sum[son[root][1]]+=(long long)size[son[root][1]]*lazy[root];
   lazy[root]=0;
}
inline int dir(int root){
   return son[fa[root]][1]==root;
}
inline void rotate(int root,int d){
   int temp=son[root][d^1];
   son[root][d^1]=son[temp][d];
   if(son[root][d^1])fa[son[root][d^1]]=root;
   fa[temp]=fa[root];
   if(fa[root])son[fa[root]][dir(root)]=temp;
   fa[root]=temp;
   son[temp][d]=root;
   push_up(root),push_up(temp);
}
inline void splay(int root,int goal){
   push_down(root);
   while(fa[root]!=goal){
      if(fa[fa[root]]!=goal&&dir(root)==dir(fa[root]))
         rotate(fa[fa[root]],dir(root)^1);
      rotate(fa[root],dir(root)^1);
    }
}
inline int find_left(int x){
   splay(x,0);
   x=son[x][0];
   while(son[x][1])x=son[x][1];
     return x;
   }
inline int find_right(int x){
   splay(x,0);
   x=son[x][1];
   while(son[x][0])x=son[x][0];
   return x;
}
int build(int left,int right){
   if(left>right)return 0;
   int mid=(left+right)>>1;
   if(mid<right)fa[son[mid][1]=build(mid+1,right)]=mid;
   if(left<mid)fa[son[mid][0]=build(left,mid-1)]=mid;
   val[mid]=(dfn[mid]>0)?a[dfn[mid]]:-a[-dfn[mid]];
   mark[mid]=(dfn[mid]>0)?1:-1;
   push_up(mid);
   return mid;
}
void dfs(int x){
   dfn[l[x]=++tot]=x;
   for(int i=head[x];i;i=e[i].nxxt)
      dfs(e[i].to);
   dfn[r[x]=++tot]=-x;
}
int n,x,y,m;
char opt;
int main(){
   read(n);
   for(int i=2;i<=n;i++) {
      read(x);
      add(x,i);
   }
   dfs(1);
   for(int i=1;i<=n;i++)read(a[i]);
   build(1,tot+1);
   read(m);
   while(m--) {
        opt=getchar();
        while(opt!='Q'&&opt!='C'&&opt!='F')
       opt=getchar();
       read(x);
      if(opt=='Q') {
         splay(l[x],0);
         write(sum[son[l[x]][0]]+val[l[x]]),putchar(10);
      }
      else if(opt=='C'){
         read(y);
         int aa=find_left(l[x]),bb=find_right(r[x]);
         splay(aa,0),splay(bb,aa);
         int temp=son[bb][0];
         son[bb][0]=0;
         push_up(bb),push_up(aa);
         splay(x=find_left(r[y]),0),splay(r[y],x);
         fa[temp]=r[y];
         son[r[y]][0]=temp;
         push_up(r[y]),push_up(x);
    }
    else{
         read(y);
         int aa=find_left(l[x]),bb=find_right(r[x]);
         splay(aa,0),splay(bb,aa);
         lazy[son[bb][0]]+=y,val[son[bb][0]]+=y*mark[son[bb][0]],sum[son[bb][0]]+=(long long)size[son[bb][0]]*y;
      }
   }
}
