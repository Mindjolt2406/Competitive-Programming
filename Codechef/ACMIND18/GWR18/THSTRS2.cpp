#include <bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000003
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d", &n);
#define scll(n) scanf("%lld", &n);
#define scld(n) scanf("%Lf", &n);
#define scr(s)             \
    {                      \
        char temp[500010]; \
        scanf("%s", temp); \
        s = temp;          \
    }
#define t1(x) cerr << #x << " : " << x << endl
#define t2(x, y) cerr << #x << " : " << x << " " << #y << " : " << y << endl
#define t3(x, y, z) cerr << #x << " :" << x << " " << #y << " : " << y << " " << #z << " : " << z << endl
#define t4(a, b, c, d) cerr << #a << " : " << a << " " << #b << " : " << b << " " << #c << " : " << c << " " << #d << " : " << d << endl
#define t5(a, b, c, d, e) cerr << #a << " : " << a << " " << #b << " : " << b << " " << #c << " : " << c << " " << #d << " : " << d << " " << #e << " : " << e << endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout << "here" << endl;

using namespace std;

bool compa(string &a, string &c, int x, int y)
{
    if (a.size() - x != y + 1)
        return false;
    bool boo = false;
    int count = 0;
    for (int i = x; i < y; i++)
    {
        if (a[i] != c[count])
            return false;
        count++;
    }
    return true;
}

bool compb(string &a, string &c, int x, int y)
{
  _;
    if (x + 1 != c.size() - y)
        return false;
    bool boo = false;
    int count = y;
    for (int i = 0; i < x; i++)
    {
        if (a[i] != c[count])
            return false;
        count++;
    }
    _;
    return true;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    int t;
    sc(t);
    while (t--)
    {
        string a, b, c;
        scr(a);
        scr(b);
        scr(c);

        vector<vector<int>> hashta(1000010);
        vector<vector<int>> hashtb(1000010);

        int l =-1,r =-1;
        string k1, k2;
        ll hasha = 0, hashb = 0, hashc = 0;
        int na = a.size(), nb = b.size(), nc = c.size();
        for (int i = 0; i < min(c.size(), a.size()); i++)
        {
            // na-i-1;
            ll a1 = power(26, i, MOD);
            a1 *= a[na - i - 1];
            a1 %= MOD;
            hasha += a1;
            hasha %= MOD;
            // t(i,hasha);
            hashta[hasha].pu(na - i - 1);
        }

        set<int> a1, b1;
        _;
        for (int i = 0; i < c.size(); i++)
        {
            hashc *= 26;
            hashc += c[i];
            hashc %= MOD;
            t(i,hashc);
            if (!hashta[hashc].empty())
            {
                for (int j = 0; j < hashta.size(); j++)
                {
                    if (compa(a, c, hashta[hashc][j], i))
                    {
                        l = max({l,i+1});
                        a1.insert(i);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < min(c.size(), b.size()); i++)
        {
            // na-i-1;
            hashb *= 26;
            hashb += b[i];
            hashb %= MOD;
            // t(i,hashb);
            hashtb[hashb].pu(i);
        }

        hashc = 0;
        for (int i = 0; i < c.size(); i++)
        {
            // hashc*=26;
            // hashc+=c[c.size()-i-1]-'a';
            ll a1 = power(26, i, MOD);
            a1 *= c[nc - i - 1];
            a1 %= MOD;
            hashc += a1;
            hashc %= MOD;
            // t(i,hashc);
            if (!hashtb[hashc].empty())
            {
                for (int j = 0; j < hashtb.size(); j++)
                {
                    if (compb(b, c, hashtb[hashc][j], c.size() - i - 1))
                    {
                        r = max({r, i+1});
                                b1.insert(c.size() - i - 1);
                        break;
                    }
                }
            }
        }
        _;
        b1.insert(c.size());
        set<int>::iterator it;
        int min1 = INF;
        a1.insert(-1);
        _;
        // for (it = a1.begin(); it != a1.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout<<endl;
        // for (it = b1.begin(); it != b1.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout<<endl;

        // for (it = a1.begin(); it != a1.end(); it++)
        // {
        //     cout << *it << endl;
        //     int a = *b1.upper_bound(*it);
        //     min1 = min(a - *it - 1, min1);
        //     // t(*it, a,min1);
        // }
        int ans;
        if(l+r<=c.size()) 
        ans = a.size()+b.size()+c.size()-l-r;
        else if(l==c.size()) ans = a.size()+b.size();
        else if(r==c.size())
            ans = a.size() + b.size();
        else if(l>0&&r>0)
        {
            ans = 0;
        }
        else if (l > 0)
            ans = a.size() + b.size() + c.size() - l;
        else if (r > 0)
            ans = a.size() + b.size() + c.size() - r;
        else
            ans = a.size() + b.size() + c.size() ;
        // for(it=b1.begin();it!=b1.end();it++)
        // {
        //   int a = *a1.upper_bound(*it);
        //   min1 = min(abs(a-*it)-1,min1);
        // }

        // cout<<l<<" "<<r<<endl;
        cout<<ans<<endl;
        // if (min1 == INF)
        //     cout << a.size() + b.size() + c.size() << endl;
        // else
        //     cout << min1 + a.size() + b.size() << endl;
    }
    return 0;
}