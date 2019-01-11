#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N=(1e6)+10 ;
const int M=(1e3)+10 ;

vector<int> adj[M] ;
int arr[N], prel[N], prer[N] ;
bool vis[M] ;

void dfs(int node)
{
	if(vis[node])
		return ;
	vis[node]=true ;
	for(int i=0 ; i<adj[node].size() ; i++){
		dfs(adj[node][i]) ;
	}
}

int main(){
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;

	int t;
	cin>>t;
	while(t--){
		string s ;
		int m ;
		cin >> s >> m ;
		int sz=s.size() ;
		for(int i=0 ; i<=m ; i++){
			adj[i].clear() ;
			vis[i]=false ;
		}
		for(int i=0 ; i<sz ; i++){
			arr[i+1]=s[i]-'0' ;
		}
		prel[0]=0 ; prer[sz+1]=0 ;
		int po=1%m ;
		for(int i=1 ; i<=sz ; i++){
			prel[i]=(prel[i-1]*10+arr[i])%m ;
		}	
		for(int i=sz ; i>=1 ; i--){
			prer[i]=(prer[i+1]+po*arr[i])%m ;
			po=(po*10)%m ;
		}
		int po10[sz+2] ;
		po10[0]=1%m ;
		for(int i=1 ; i<sz+2 ; i++){
			po10[i]=(po10[i-1]*10)%m ;
		}
		set<int> poss ;
		vector<int> nums ;
		for(int i=1 ; i<=sz ;i++){
			int cur=(prer[i+1]+po10[sz-i]*prel[i-1])%m;
			poss.insert(cur) ;
			nums.push_back(cur) ;
		}
		for(int i=0 ; i<m ; i++){
			for(auto iter=poss.begin() ; iter!=poss.end() ; iter++){
				int r=(i*po10[sz-1]+(*iter))%m ;
				adj[r].push_back(i) ;
			}
		}
		dfs(0) ;
		int tot=0 ;
		for(int i=0 ; i<nums.size() ; i++){
			if(vis[nums[i]])
				tot++ ;
		}
		cout << tot << endl ;
	}
}