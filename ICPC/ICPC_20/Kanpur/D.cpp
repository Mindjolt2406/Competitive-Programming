#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_set<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_multiset<T> & vec);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p);
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::unordered_map<T1,T2> & p);
template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::set<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_set<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::multiset<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template <typename T>
std::ostream & operator << (std::ostream & os, const std::unordered_multiset<T> & vec){
    os<<"{";
    for(auto elem : vec)
        os<<elem<<",";
    os<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::pair<T1,T2> & p){
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::map<T1,T2> & p){
    os<<"{";
    for(auto x: p)
        os<<x.first<<"->"<<x.second<<", ";
    os<<"}";
    return os;
}
template<typename T1, typename T2>
std::ostream & operator << (std::ostream & os, const std::unordered_map<T1,T2> & p){
    os<<"{";
    for(auto x: p)
        os<<x.first<<"->"<<x.second<<", ";
    os<<"}";
    return os;
}
#define t1(x)             cerr<<#x<<"="<<x<<endl
#define t2(x, y)          cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define t3(x, y, z)       cerr<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define t4(a,b,c,d)       cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define t5(a,b,c,d,e)     cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define t6(a,b,c,d,e,f)   cerr<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define tr(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define fastio() ios::sync_with_stdio(0);cin.tie(0)
#define MEMS(x,t) memset(x,t,sizeof(x));
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-------------------------------------------------------------------------------------------------------------------------------------*/
#define MOD 1000000000
#define endl "\n"
#define int long long
#define inf 1e18
#define ld long double
/*-------------------------------------------------------------------------------------------------------------------------------------*/

long long poww(long long a, long long n, long long m)
{
        long long ans = 1;
        long long mul = a;
        while (n != 0)
        {
                if (n % 2)
                {
                        ans = (ans * mul) % m;
                }
                mul = (mul * mul) % m;
                n /= 2;
        }
        return ans;
}
/* 
1) (a/b)%mod= (a*(poww(b,phi(mod)-1,mod)))%mod iff a%b==0
2) (a^b)%mod= (a^(b%(mod-1)))%mod iff mod is prime
3) Fermat's little theorem: 
        a^(phi(n))=1 mod(n)  when a and n are relatively prime.
*/


int phi(int n) 
{
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

signed main()
{
    fastio();
    int t;
    cin>>t;
    while(t--)
    {
        int k,d;
        cin>>k>>d;

        int ans=k;
        int ans3=(k*k)/2LL;
        ans3%=MOD;

        int phin=phi(MOD);
        
        int ans2 = poww(k,d-1,MOD);
        ans2-=1;
        if(ans2<0)  
            ans2+=MOD;
        
        ans2*=poww(k-1,phin-1,MOD);
        ans2%=MOD;

        ans+=(ans2*ans3)%MOD;


        if(ans>=MOD)
            ans-=MOD;
        cout<<ans<<endl;
    }
}