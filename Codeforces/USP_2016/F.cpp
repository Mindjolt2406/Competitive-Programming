// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define endl "\n"
#define fi first
#define se second
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define pii pair<int, int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

// #define tr(...) cout<<_FUNCTION<<' '<<LINE<<" = ";trace(#VA_ARGS, __VA_ARGS_)
// template<typename S, typename T>
// ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

// template<typename T>
// ostream& operator<<(ostream& out,vector<T> const& v){
// ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

// template <typename T>
// ostream &operator<<(ostream &out, set<T> const &v) {
//     for (auto i = v.begin(); i != v.end(); i++)
//         out << (*i) << ' ';
//     return out;
// }
// template <typename T>
// ostream &operator<<(ostream &out, multiset<T> const &v) {
//     for (auto i = v.begin(); i != v.end(); i++)
//         out << (*i) << ' ';
//     return out;
// }
// template <typename T, typename V>
// ostream &operator<<(ostream &out, map<T, V> const &v) {
//     for (auto i = v.begin(); i != v.end(); i++)
//         out << "\n" << (i->first) <<  ":"  << (i->second);
//     return out;
// }

// template<typename T>
// void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

// template<typename T, typename... Args>
// void trace(const char* names, T&& arg1, Args&&... args){
// const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll
const int LOG = 30;
int solve() {
    int n, pos;
    cin >> n >> pos;
    int temp = pos;
    int round;
    int ans = 0;
    for (int i = 0; i < LOG; i++) {
        if (temp & (1LL << i)) {
            temp = temp >> i;
            ans += (temp + 1) / 2;
            cout << ans << endl;
            // break;
            return 0;
        } else {
            ans += (n + 1) / 2;
            n -= ((n + 1) / 2);
        }
    }
    return 0;

}

int32_t main(){ _
    int t;
    cin >> t;
    // t = 1;
    while (t--) solve();
}