// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

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

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

// #define int ll

const int N = 5e5 + 100;
const int L = 30;
int n, arr[N], k;

int try_pos(int start, int msk) {
    int curr = 0;
    int cnt = 0;
    for (int i = start; i < start + n; i++) {
        int ind = i % n;
        curr |= arr[ind];
        if ((curr & msk) == msk) {
            cnt++;
            curr = 0;
        }
    }
    return (cnt >= k);
}

vector<int> poss;
int possible(int msk) {
    for (auto &i : poss) {
        if (try_pos(i, msk)) {
            return 1;
        }
    }
    return 0;
}

void pre() {
    set<int> s;
    int curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = L; j >= 0; j--) {
            if (((curr & (1 << j)) == 0) && (arr[i] & (1 << j))) {
                s.insert(i);
                curr |= (1 << j);
            }
        }
    }
    for (auto i : s) {
        poss.pb(i);
    }
}

int32_t main(){ _
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pre();
    int curr = 0;
    for (int i = L; i >= 0; i--) {
        if (possible(curr | (1 << i))) {
            curr |= (1 << i);
        }
    }
    cout << curr << endl;
}