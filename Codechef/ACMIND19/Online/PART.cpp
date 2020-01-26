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
using namespace std;

#define ll long long int
#define ld long double
#define v vector
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

const ll mod = 1e9 + 7;
const ld PI = acos(-1.0);
const ll maxN = (1 << 20);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll T;
    cin >> T;
    while(T --) {
        ll k, n;
        cin >> n >> k;
        v<ll> a(n), pref(n+1, 0);
        for(ll i = 0; i < n; i ++) {
            cin >> a[i];
            pref[i+1] = pref[i] + a[i];
        }
        v<ll> idx, posPref, dp, prev;
        posPref.push_back(0);
        idx.push_back(0);
        dp.push_back(0);
        prev.push_back(-1);
        for(ll i = 1; i <= n; i ++) {
            if(pref[i] > 0) {
                idx.push_back(i);
                posPref.push_back(pref[i]);
                dp.push_back(0);
                prev.push_back(-1);
            }
        }
        if(pref[n] <= 0) {
            cout << "NO" << endl;
            continue;
        }
        ll N = posPref.size();
        dp[0] = 0;
        prev[0] = -1;
        ll maxTill = 0;
        set<pair<pair<ll, ll> , ll>> rightnow;
        rightnow.insert({{0, 0}, 0}); // num, len, idx;
        for(ll i = 1; i < N; i ++) {
            auto idx1 = rightnow.upper_bound({{posPref[i], -1}, -1});
            auto idx2 = idx1;
            idx2 --;
            dp[i] = (*idx2).fi.se + 1;
            prev[i] = (*idx2).se;
            v<pair<pair<ll, ll>, ll>> toDelete;
            while((idx1 != rightnow.end()) && ((*idx1).fi.fi >= posPref[i]) && ((*idx1).fi.se <= dp[i])) {
                toDelete.push_back(*idx1);
                idx1 ++;
            } 
            for(auto i : toDelete) {
                rightnow.erase(i);
            }
            rightnow.insert({{posPref[i], dp[i]}, i});
        }
        if(dp[N-1] < k) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            v<ll> ans;
            ll idx1 = N-1;
            for(ll i = 0; i < k; i ++) {
                ans.push_back(idx[idx1]);
                idx1 = prev[idx1];
            }
            ans.push_back(0);
            reverse(ALL(ans));
            for(ll i = 1; i <= k; i ++) {
                cout << ans[i] - ans[i-1] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}