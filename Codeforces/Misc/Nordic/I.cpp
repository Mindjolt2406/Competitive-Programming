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

const int N=505;
vector<int> adj[N];
int dis[N][N];
int parent[N][N];

void get(vector<int>  &ans,int i,int j)
{
	int k = parent[i][j];
	if(i==k) return;
	// t(i,j,k);
	get(ans,i,k);
	ans.pu(k);
	get(ans,k,j);

}

int32_t main()
{
	//ios::sync_with_stdio(0);cin.tie(0);
	int n;
	memset(parent,-1,sizeof(parent));
	cin>>n;
	string s[n+1];
	map<string,int> stoi;
	map<int,string> itos;
	for(int i=1;i<=n;i++)
	{	
		cin>>s[i];
		stoi[s[i]]=i;
		itos[i]=s[i];
	}		
	for(int i=1;i<=n;i++)
	{
		string tmp;int k;
		cin>>tmp>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>tmp;
			char ch[50000];
			scanf("%[^\n]s",ch);
			//printf("%s\n",ch);
			int siz=strlen(ch);
			string cur="";
			for(int j=1;j<siz;j++)
			{
				if(ch[j]==',')
				{
					// adj[i].push_back(stoi[cur]);

					dis[stoi[cur]][i]=1;
					parent[stoi[cur]][i] = stoi[cur];
					// t(cur,i,stoi[cur]);
					cur="";
					j++;
					continue;
				}
				cur+=ch[j];
			}
			// adj[i].push_back(stoi[cur]);
			dis[stoi[cur]][i]=1;
			parent[stoi[cur]][i] = stoi[cur];
			// t(cur,i,stoi[cur]);
		}	
	}


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]==0)
			{
				dis[i][j]=INF;
			}
		}
	}



	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					parent[i][j]=k;
				}
			}
		}
	}
	int mi=INF;
	int cur=0;
	for(int i=1;i<=n;i++)
	{	
		if(dis[i][i]<mi)
		{
			mi=dis[i][i];
			cur=i;
		}
	}

	if(cur > 0)
	{
		vector<int> ans;
		get(ans,cur,cur);
		reverse(ans.begin(),ans.end());
		if(ans.size() < mi) ans.pu(cur);
		for(int i=0;i<ans.size();i++) cout << itos[ans[i]] << " "; cout << endl;
	}
	else cout << "SHIP IT" << endl;
}

/*
4
a b c d
a 1
import d, b, c
b 2
import d
import c
c 1
import c
d 0

*/
	