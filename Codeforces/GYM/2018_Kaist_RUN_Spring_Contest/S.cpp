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
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define pii pair<int, int>
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template <typename T>
ostream &operator<<(ostream &out, set<T> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << (*i) << ' ';
    return out;
}
template <typename T, typename V>
ostream &operator<<(ostream &out, map<T, V> const &v) {
    for (auto i = v.begin(); i != v.end(); i++)
        out << "\n" << (i->first) <<  ":"  << (i->second);
    return out;
}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll


string arr[5][5] = {
    {"New Customer", "Promising", "About to Sleep", "Lost", "Lost"},
    {"Potential Loyalist", "Potential Loyalist", "About to Sleep", "Hibernating", "Lost"}, 
    {"Potential Loyalist", "Potential Loyalist", "Need Attention", "About to Leave", "About to Leave"},
    {"Loyal Customer", "Loyal Customer", "Loyal Customer", "About to Leave", "About to Leave"},
    {"Champion", "Loyal Customer", "Loyal Customer", "About to Leave", "Can't Lose Them"}
};

int r[5];
int f[5];

int solve() {

    for (int i = 1; i <= 4; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= 4; i++) {
        cin >> f[i];
    }

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int n;
    cin >> n;
    map<string, pii> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 2) {
            string s;
            cin >> s;
            if (!m.count(s)) {
                cout << "None\n";
                continue;
            }
            auto q = m[s];
            // tr(s, q, i);
            int rt = (i - q.fi);
            int ft = q.se;
            int p = 0, o = 0;
            for (int j = 1; j <= 4; j++) {
                if (rt > r[j]) o = j;
            }
            for (int j = 1; j <= 4; j++) {
                if (ft > f[j]) p = j;
            }
            // tr(p, o);
            cout << arr[p][o] << endl;
        } else {
            string s;
            cin >> s;
            if (!m.count(s)) {
                m[s] = {i, 1};
            } else {
                auto q = m[s];
                m[s] = {i, q.se + 1};
            }
        }
    }
    return 0;
}

int32_t main(){ _
    int t;
    // cin >> t;
    t = 1;
    while (t--) solve();
}
