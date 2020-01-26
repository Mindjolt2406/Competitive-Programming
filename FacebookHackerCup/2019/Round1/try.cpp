// g++ -std=c++14
#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

// #define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define int ll

const int MOD = 1e9 + 7;

int power(int x, int t){
    int ans = 1;
    while(t > 0) {
        if(t & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        t >>= 1;
    }
    return ans;
}


int solve(int test){
    int n, k;
    cin >> n >> k;
    // cerr<<"n: "<<n<<" k: "<<k<<endl;
    string s;
    cin >> s;
    int diff = 0;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        // cerr<<"i: "<<i<<endl;
        if(s[i] == 'A'){
            diff--;
            diff = max(0LL, diff);
        }
        else{
            diff++;
            if(diff == k + 1){
                ans = (ans + power(2, i + 1)) % MOD;
                diff--;
                diff--;
            }

        }
    }
    cout << "Case #" << test << ": " << ans % MOD << endl;
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        // cerr<<"i: "<<i<<endl;
        solve(i);
    }
    return 0;
}
