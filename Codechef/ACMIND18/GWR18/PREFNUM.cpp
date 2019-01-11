#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(n) for (int i = 0; i < n; i += 1)
#define prarr(a, n)             \
    rep(n) printf("%d ", a[i]); \
    printf("%s\n", " ");
#define sc(a) scanf("%d", &a);
#define scl(a) scanf("%lld", &a);
#define scf(a) ascanf("%f", &a);
#define ff first
#define ss second
#define pu push_back

int main()
{
    int t;
    ll x,y;
    sc(t);
    while(t--)
    {
        ll mp[20];
        ll tmp = 1;
        scl(x);scl(y);
        rep(20)
        {
            mp[i] = tmp%y;
            tmp = mp[i]*10;
        }
        ll ans = 0;
        int i =0;
        for(i=0;i<19;i++)
        {
            // cout << y - (x * mp[i]) % y<<" i "<<i <<endl;
            if ((y - (x * mp[i]) % y)%y >= (ll)pow(10, i)) continue;

            else
            {
                break;
            }
        }

            ans = 0;
            if (pow(10, i)>1e18/x)
            {
                cout<<-1<<endl;
                continue;
            }
                ans += x * (ll)pow(10, i);
            ans += (y - (x * mp[i]) % y)%y;
            // cerr<<i<<endl;
            // cerr<<ans<<endl;
        if(i==19||ans>(ll)1e18||ans<0)
        ans = -1;
        printf("%lld\n",ans);
    }
    // int ans = 0;
    // printf("%lld\n", ans);
    return 0;
}