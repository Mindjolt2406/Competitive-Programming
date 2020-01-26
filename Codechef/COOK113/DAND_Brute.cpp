#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve2(ll pl, ll cp, ll sl, ll cs, ll ct, ll k, int i) {
	//cout << "s2 " << pl << " " << cp << " " << sl << " " << cs << " " << ct << " " << i << endl;
	//the interval [0, 2^i) and [2^i, 2^(i+1))
	if(!i) {
		k-=pl>0?cp:0;
		k-=cs;
		k-=ct;
		return k<=0?1:0;
	}
	ll k2=k;
	//use only the ones with ith bit
	k2-=max(pl-(1ll<<i)+1, 0ll)*cp;
	k2-=min((1ll<<i+1)-sl, 1ll<<i)*cs;
	k2-=ct<<i;
	if(k2<=0) {
		//use ith bit
		return 1ll<<i|solve2(max(pl-(1ll<<i), -1ll), cp, sl<1ll<<i?0:sl^1ll<<i, cs, ct, k, i-1);
	} else {
		//no ith bit
		return solve2(pl>=1ll<<i?pl^1ll<<i:pl, cp, sl<1ll<<i?sl:sl^1ll<<i, cs, 2*ct+(sl<1ll<<i?cs:0)+(pl>=1ll<<i?cp:0), k, i-1);
	}
}

ll solve1(ll l, ll r, ll k, int i) {
	//cout << "s1 " << l << " " << r << " " << i << endl;
	//the interval [0, 2^i) and [2^i, 2^(i+1))
	if(!i) {
		return k>1||!r?0:1;
	}
	if(r-(1ll<<i)+1>=k)
		l=max(l, 1ll<<i);
	//is contained in [0, 2^i)
	if(r<1ll<<i)
		return solve1(l, r, k, i-1);
	//is contained in [2^i, 2^(i+1))
	if(l>=1ll<<i)
		return 1ll<<i|solve1(l^1ll<<i, r^1ll<<i, k, i-1);
	return solve2(r^1ll<<i, 1, l, 1, 0, k, i-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		ll l, r, k;
		cin >> l >> r >> k;
		cout << solve1(l, r, k, 59) << "\n";
	}
}
