#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sl(a) scanf("%lld",&a);
#define rep(n) for(int i=0;i<n;i++)
#define prarr(a,n) rep(n) cout<<a[i]<<" ";cout<<endl;
#define vi vector<int>
#define ff first
#define ss second
#define N 100010

bitset<10000010> bs;
vi primes;
ll _sieve_size;
map<int,int> powers={};//stores powers of primes in primefac of mod
map<ll,ll> tot={{1000000007ll,1000000006ll}};// stores toitent value
ll fac[N];//factorial without prime factors of mod 
ll ifac[N];//invfac without prime factors of mod
ll power(ll x, ll y, ll p)
{
ll res = 1;
// Initialize result
x = x % p; // Update x if it is more
while (y > 0)
{
if (y & 1)
res = (res*x) % p;
y = y>>1; // y = y/2
x = (x*x) % p;
}
return res;
}
void sieve(ll n)
{
  _sieve_size=n+1;
  bs.reset();bs.flip();
  bs.set(0,false);bs.set(1,false);
  for(ll i=2;i<_sieve_size;i++)
  {
    if(bs.test(i))
    {
      for(ll j=i*i;j<_sieve_size;j+=i)
      bs.set(j,false);
    primes.push_back((int)i);
    }
  }
}
vi prfac(int n)
{
  vi ret={};
  if(n<0) ret.push_back(-1);
  n=abs(n);
  int l=0;
while(n&& n%primes[l]==0) {ret.push_back(primes[l]);n/=2;}
  l++;
  for(ll j=primes[l];j<=sqrt(n);)
  {
    while(n&& n%j==0) {ret.push_back(j);n/=j;}
    l++;
    j=primes[l];
  }
  if(n!=1)
  ret.push_back(n);
return ret;
}
ll toitent(ll m)
{
	if(tot.find(m)!=tot.end()) return tot[m];
	if(primes.size()==0) sieve(sqrt(m)+2);
	vi fac = prfac(m);
	ll tmp  = m;
	for(auto i : fac)
	{
		int cnt = 0;
		while(m%i==0) {m=m/i;cnt++;}
		powers[i] = cnt;
	}
	ll phi  = 1;
	for(auto p : powers) phi*=power(p.ff,p.ss-1,(ll)(1e9)+7ll)*(p.ff-1);
	tot[tmp] = phi;
	return phi;
}
ll modinv(ll a,ll mod)
{
	return power(a,toitent(mod)-1,mod);
}
void setfacnp(int n,ll mod)
{
	if(tot.find(mod)==tot.end()) toitent(mod);
	int cnt=1;
	for(int i = 1;i<=n;i++,cnt++)
	{
		for(auto p : powers) while(i%p.ff==0) i/=p.ff;
		fac[cnt] = i;
		ifac[cnt] = modinv(i,mod);
		i = cnt;
	}
	fac[0] = 1;
	ifac[0] = 1;
	for(int i = 1;i<=n;i++)
	{
		fac[i] = (fac[i-1]*fac[i])%mod;
		ifac[i] = (ifac[i-1]*ifac[i])%mod;
	}

}
ll C(int n,int r,ll mod)
{
	setfacnp(n,mod);
	ll ret = 1;
	ret = (fac[n]*ifac[n-r])%mod;
	ret=(ret*ifac[r])%mod;
	map<int,int> m={}; vi v = {n,n-r,r};
	int i = n,cnt = 0,pi;;
	//now take the prime factors of mod and find their exponents in nCr and store in ans
	for(auto p : powers) {cnt=0;pi=p.ff; while(i/pi) {cnt+=i/pi;pi*=p.ff;}m[p.ff]+=cnt;}
	i = n-r;	
	for(auto p : powers) {cnt=0;pi=p.ff; while(i/pi) {cnt+=i/pi;pi*=p.ff;}m[p.ff]-=cnt;}
	i = r;	
	for(auto p : powers) {cnt=0;pi=p.ff; while(i/pi) {cnt+=i/pi;pi*=p.ff;}m[p.ff]-=cnt;}
	ll ans = 1;	
	for(auto p :m){
		ans = ans*(power(p.ff,p.ss,mod));ans%=mod;
	}
	ret*=ans;
	ret%=mod;
	return ret;
}
int main(int argc, char const *argv[])
{
	
	int t,n =15,r = 4,mod = 1800000092;
	cout<<C(n,r,mod)<<endl;
	return 0;
	cin>>t;
	while(t--)
	{
		// cin>>n>>r>>mod;
	}
	return 0;
}