#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first 
#define se second
#define ld long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front

#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pi>
#define vvi vector<vector<ll>>
#define vvc vector<vector<char>>
#define um unordered_map
#define om ordered_map
#define vus vector<unordered_set<ll>>
#define str string
#define vs vector<string>

#define rep(i,a,n) for(ll i=a;i<n;i++) 
#define per(i,a,n) for(ll i=n-1;i>=a;i--) 
#define forl for(ll i=0;i<n;i++)
#define forn for(ll i=1;i<=n;i++)
#define for0 for(ll i=n-1;i>=0;i--)
#define for1 for(ll i=n;i>=1;i--)
#define forlr for(ll i=l;i<=r;i++)
#define forrl for(ll i=r;i>=l;i--)

#define endl "\n"
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll mod = 1e9 + 7;

ll power1(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) return (power1((a*a), b/2));
    else return (power1((a*a), b/2) * a);
}

ll power(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) return (power((a*a)%mod, b/2))%mod;
    else return (power((a*a)%mod, b/2) * a)%mod;
}

ll fact(ll n){
    if(n==0) return 1;
    if(n==1) return 1;
    return (fact(n-1)*n)%mod;
}

ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

vector<bool> prime(1e7,true);

void sieve(ll n) {
    for(int p=2;p*p<=n;p++) {
        if(prime[p]) {
            for(int i=p*2;i<=n;i+=p) prime[i] = false;
        }
    }
}

void swap(ll &a, ll &b) {
    ll t = b;
    b = a;
    a = t;
}

//-----------------------------------------------------------------------------

int main(){
    //fastio
    ll t; cin>>t;
    vvi dp(1e3+2, vi (1e3+2, -1));
    dp[0][0]=1, dp[0][1]=0;
    rep(i,1,1e3+2) {
        dp[i][0] = (dp[i-1][0]*i)%mod; 
        dp[i][1] = (dp[i][0]*i)%mod;
    }
    rep(i,1,1e3+2) {
        dp[0][i] = (dp[0][i-1]*i)%mod;
        if(i%2) dp[0][i] = (dp[0][i]-1)%mod;
        else dp[0][i] = (dp[0][i]+1)%mod;
    }
    per(i,1,1e3+1) {
        rep(j,2,1e3+2) {
            dp[i][j] = (i*dp[i][j-1] + (j-1)*dp[i+1][j-2])%mod;
        }
    }
    for(;t>0;t--) {
        ll n;cin>>n;
        vi a(n);
        um<ll,ll> gone;
        rep(i,0,n) {
            cin>>a[i]; 
            if(a[i]) gone[a[i]]++;
        }
        ll free=0, res=0;
        rep(i,0,n) {
            if(a[i]==0) {
                if(gone[i+1]) free++;
                else res++;
            }
        }
        //cout<<free<<res<<endl;
        if(free+res==0) {
            cout<<0<<endl;
            continue;
        }
        cout<<dp[free][res]<<endl;
    }
    return 0;  
}
