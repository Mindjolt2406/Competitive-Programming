// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

lli mod = 1e9 + 7;

lli fast_expo(lli a, lli b){
    if(b == 0){
        return 1;
    }
    lli x = fast_expo(a, b/2);
    x = (x * x) % mod;
    if(b % 2 == 1){
        x = (x * a) % mod;
    }
    return x;
}

lli mod_inv(lli n){
    return fast_expo(n, mod - 2);
}

lli gp_sum(lli a, lli r, lli n){
    if(r == 1){
        return (a * n);
    }
    lli ans = (a * (fast_expo(r, n) - 1 + mod)) % mod;
    ans = (ans * mod_inv(r - 1)) % mod;
    return ans;
}

void solve(){
    lli n, k, m;
    cin >> n >> k >> m;
    if(n == 1){
        cout << "1\n";
        return;
    }
    lli ans;
    if(m == 1){
        ans = mod_inv(n);
    }
    else if(m == 2){
        ans = (((2 * n + k - 1) * mod_inv(n)) % mod) * mod_inv(n + k);
        ans %=  mod;
    }
    else{
        lli base, terms;
        if(m % 2 == 1){
            base = mod_inv(n);
            terms = m/2;
        }
        else{
            base = ((((2 * n + k - 1) * mod_inv(n)) % mod) * mod_inv(n + k)) % mod;
            terms = m/2 - 1;
        }
        ans = gp_sum(1, n - 1, terms);
        lli x = (fast_expo(n - 1, terms) * base) % mod;
        ans = (ans + x) % mod;
        ans = (ans * mod_inv(n)) % mod;
    }
    cout << ans << "\n";
}

int main(){
  _
  int t;
  cin >> t;
  while(t--){
      solve();
  }
  return 0;
}