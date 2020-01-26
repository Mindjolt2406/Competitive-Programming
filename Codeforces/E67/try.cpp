#include <bits/stdc++.h>

#define ll long long int
#define v vector
#define inparr(arr); for(ll i=0;i<arr.size();i++) cin >> arr[i];
#define inpmat(mat); for(ll i=0;i<mat.size();i++) for(ll j=0;j<mat[i].size();j++) cin >> mat[i][j];
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define mp make_pair
#define fi first
#define se second

#define M 1000000007
#define N 998244353
#define PI 3.14159265358979323

using namespace std;

int main() {
    fast;
    ll n, m;
    bool pos = true;
    cin >> n >> m;
    v<ll> ans(n, 0);
    v<ll> vis(n, 0);
    v<pair<ll, ll>> sorted, unsorted;
    for(ll i=0; i<m; i++) {
        ll t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if(t == 1) sorted.push_back(mp(l, r));
        else unsorted.push_back(mp(l, r));
    }

    for(ll i=0; i<sorted.size(); i++) {
        ll num = ans[sorted[i].fi];
        for(ll j=sorted[i].fi; j<=sorted[i].se; j++) {
            vis[j] = 1;
            ans[j] = num;
            num ++;
        }
    }
    for(ll i=0; i<n-1; i++) {
        if(ans[i] > ans[i+1])
            ans[i] = 1000000;
    }

    for(ll i=0; i<n; i++) {
        if(vis[i] == 0 && i > 0) {
            ans[i] = ans[i-1] - 1;
        }   
        if(vis[i] == 0 && i == 0) {
            ans[i] = 1000000;
            vis[i] = 1;
        }
    }

    for(ll i=0; i<unsorted.size(); i++) {
        ll f = 0;
        for(ll j=unsorted[i].fi; j<=unsorted[i].se-1; j++) {
            if(ans[j] > ans[j+1]) f = 1;
        }
        if(f == 0) {
            pos = false;
            break;
        }
    }

    ll mini = 1e10;
    for(ll i=0; i<n; i++) {
        mini = min(mini, ans[i]);
    }

    ll add = 1 - mini;
    for(ll i=0; i<n; i++) ans[i] += add;
    if(pos) {
        cout << "YES" << endl;
        for(auto i : ans) cout << i << " ";
        cout << endl;
    }
    else cout << "NO" << endl;

    return 0;
}