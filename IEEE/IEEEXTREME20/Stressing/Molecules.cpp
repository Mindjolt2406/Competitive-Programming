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
template <typename T>
ostream &operator<<(ostream &out, multiset<T> const &v) {
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

int solve() {
    int c, h, o;
    cin >> c >> h >> o;
    int ans = c + h + o;
    for (int z = 0; z < 1e5 + 10; z++) {
        int temp = (24 * z) -(min(c, 6 * z) + min(h, 12*z) + min(o, 6 * z));
        // tr(temp);
        int uc, uh, uo;
        uc = min(c, z * 6);
        uh = min(h, 12 * z);
        uo = min(o, 6 * z);

        int rc = c - uc;
        int rh = h - uh;
        int ro = o - uo;

        // tr(rc, rh, ro);

        if (ro == 0) {
            temp += rc;
            temp += ((rh + 1) / 2);
        } else {
            int consumed_water = min(ro, rh/2);

            int nxt_rem_h = rh - 2*consumed_water;


            int nxt_rem_o = ro - consumed_water;
            
            if (nxt_rem_h > 0 && nxt_rem_o > 0) {
                temp++;
                nxt_rem_h--;
                nxt_rem_o--;
            }

            // tr(consumed_water, nxt_rem_o, temp, nxt_rem_h);

            
            int consumed_co2 = min(rc, nxt_rem_o/2);
            

            int nxt_nxt_rem_o = nxt_rem_o - (consumed_co2*2);

            int nxt_rem_c = rc - consumed_co2;

            if (nxt_rem_c > 0 && nxt_nxt_rem_o > 0) {
                nxt_nxt_rem_o = 0;
                nxt_rem_c--;
                temp++;
            }

            // tr(consumed_co2, nxt_nxt_rem_o, nxt_rem_c, temp);

            temp += nxt_rem_c;

            temp += ((nxt_nxt_rem_o + 1) / 2);

        }

        // tr(z, temp);
        ans = min(ans, temp);


    }   
    cout << ans << endl;
    return 0;
}

int32_t main(){ _
    int t;
    cin >> t;
    // t = 1;
    while (t--) solve();
    return EXIT_SUCCESS;	
}