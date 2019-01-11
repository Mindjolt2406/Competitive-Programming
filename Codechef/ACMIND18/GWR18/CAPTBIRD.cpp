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
ld dis(pii a,pii b)
{
    return (ld)sqrt((ld)((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss)));
}
int main()
{
    int t;
    int n,p,q;
    sc(t);
    while(t--)
    {
        ld ans = 0.0;
        sc(n);
        vector<int> x(n);
        rep(n) sc(x[i]);
        sort(x.begin(),x.end());
        sc(p);sc(q);
        ld a,b,c;
        int l = 0,r= n-1;
        while(l<r)    
        {
            a = dis({p, q}, { x[l],0});
            b = dis({x[l],0}, {x[r],0});
            c = dis({p, q}, { x[r],0});
            // cout<<a<<" "<<b<<" "<<c<<endl;
            // ans = max({acos((a*a+c*c-b*b)/(2*a*c)),ans});
            ans += acos((a*a+c*c-b*b)/(2*a*c));
            l++;r--;
        }
        printf("%0.12LF\n",ans);
    }
    return 0;
}