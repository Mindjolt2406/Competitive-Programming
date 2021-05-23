#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wfloat-conversion"
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")

#include <iostream> // IO
#include <cmath> // sqrt, trig, ceil, log
#include <utility> // swap, pair 

// #include <algorithm> // sort, binary search, reverse, merge
// #include <bitset>
// #include <cstdio> 
// #include <cstdlib> //abs, atoi, rand 
// #include <iterator> 
#include <map>  
// #include <queue>
#include <set> 
// #include <stack> 
// #include <string> // std string
// #include <vector> 

// #include <chrono> // non c style time
// #include <complex>
// #include <deque>
// #include <iomanip> // setprecision
// #include <tuple>

#define fo(i, a, b) for(i=a; i<=b; i++)
#define ro(i, b, a) for(i=b; i>=a; i--)
#define foe(it, x) for(auto it=x.begin(); it!=x.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define fil(x, y) memset(x, y, sizeof(x))
#define deb(x) cout << #x << " " << x << "\n"
#define sz(a) ((int)(a.size()))

using namespace std;

using ll = long long;

const ll N = 5003;
const int inf = 1e9+3;
const ll M = 1e9+7;
const ll T = 998244353;
const double pi = acos(-1);

ll dp[N][N];
map<ll,ll>s[N];
ll a[N];
void solve()
{
	ll n,k,x,i,j,ans=-1;cin>>n>>k>>x;
	map<ll,ll>::iterator it;
	fo(i,1,n){
		cin>>a[i];
	}
	fo(i,0,n){
		fo(j,0,x){
			dp[i][j]=-1;
		}
	}
	dp[0][0]=0;
	s[0][0]++;
	fo(i,1,n){
		fo(j,max(1LL,x-(n-i)),x){
			if(sz(s[j-1])>0){
				it = s[j-1].end();
				it--;
				dp[i][j]=it->ff+a[i];
			}
		}
		fo(j,max(1LL,x-(n-i)),x){
			if(i>=k && dp[i-k][j]!=-1){
				it = s[j].find(dp[i-k][j]);
				if(it->ss==1){
					s[j].erase(it);
				}else {
					it->ss--;
				}
			}
			if(dp[i][j]!=-1){
				s[j][dp[i][j]]++;
			}
		}
		if(i==k){
			s[0].erase(0);
		}
	}
	fo(i,n+1-k,n){
		ans=max(ans,dp[i][x]);
	}
	//deb(dp[1][1]);
	cout << ans << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifdef Holmes7 
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int _t=1,i;
	//cin >> _t;
	for(i=1;i<=_t;i++){
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
