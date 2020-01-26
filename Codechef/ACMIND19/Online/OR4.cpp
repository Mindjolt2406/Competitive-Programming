/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
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

int32_t main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int ar[n];

		int del[n];

		memset(del,0,sizeof(del));

		int cnt[31];

		memset(cnt,0,sizeof(cnt));

		vector<pair<int,int>> adj[31];

		int ptl[31];

		int ptr[31];

		memset(ptl,0,sizeof(ptl));
		for(int i=0;i<=30;i++)
		{
			ptr[i]=1;
		}

		int cur=0;
		set<pair<int,int>> seq;	
		
		for(int i=0;i<n;i++)
		{
			cin>>ar[i];
			cur=cur|ar[i];
			seq.insert({ar[i],i});
			for(int j=0;j<31;j++)
			{
				if((1<<j)&ar[i])
				{
					adj[j].push_back({ar[i],i});
					ptr[j]++;			
				}
			}
		}
		t("here");
		for(int i=0;i<31;i++)
		{
			sort(adj[i].begin(),adj[i].end());
			reverse(adj[i].begin(),adj[i].end());
		}
		t("HEre");
		ll sum=0;	
		vector<int> ans;	
		
		for(int i=0;i<n;i++)
		{
			sum+=1LL*cur;
			vector<int> save;
			t("here1");
			for(int j=30;j>=0;j--)
			{
				if(ptr[j]-ptl[j]==1 && adj[j].size() )
				{
					int val=adj[j][0].second;
					save.push_back(val);
				}
			}			
			t("here2");
			if(save.size()==seq.size())
			{
				t("here3");
				auto x=seq.begin();
				auto val=*x;
				seq.erase(x);

				del[val.second]=1;

				ans.push_back(val.second);
				
				t("here4");
			}
			else
			{
				t("here5");
				for(auto y: save)
				{
					seq.erase({ar[y],y});
				}				
				t("here10");
				auto x=seq.begin();
				auto val=*x;
				t(val.first,val.second);
				seq.erase(x);
				ans.push_back(val.second);
				t("here11");
				del[val.second]=1;
				t("here12");
				for(auto y: save)
				{
					seq.insert({ar[y],y});
				}
				t("here6");
			}	
			t("here7");
			cur=0;
			for(int j=30;j>=0;j--)
			{
        t(j);
				if(adj[j].size()==0)
				{
					continue;
				}
        _;
				while(ptl[j]<adj[j].size() &&  del[adj[j][ptl[j]].second])
				{
					ptl[j]++;
				}
        _;
        t(ptr[j],adj[j],ptr[j]-1);
				while(ptr[j]>=1 && del[adj[j][ptr[j]-1].second])
				{
          t(ptr[j]);
					ptr[j]--;
				}
        _;
				if(ptr[j]-ptl[j]>=1)
				{
					cur=cur|(1<<j);
				}
			}
			t("here8");
		}
		cout<<sum<<endl;
		for(auto x: ans)
		{
			cout<<x+1<<' ';
		}
		cout<<endl;
	}
}

/*

1
5
1 2 3 4 5

*/
