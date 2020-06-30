#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

int a[N*2], l[N*2], r[N*2], b0[N], b1[N], n;

void add(int c0, int c1, int l, int r) {
	if(r >= n) r = n;
	if(l > r) return;
	b0[l] += c0, b0[r+1] -= c0;
	b1[l] += c1, b1[r+1] -= c1;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i], a[i+n] = a[i];
		for(int i=1;i<=n*2;i++) {
			l[i] = i - 1;
			while(l[i] && a[l[i]] <= a[i]) l[i] = l[l[i]];
		}
		memset(b0, 0, sizeof b0);
		memset(b1, 0, sizeof b1);
		for(int i=2*n;i>=1;i--) {
			r[i] = i + 1;
			while(r[i] <= 2*n && a[r[i]] < a[i])
				r[i] = r[r[i]];
			if(i <= n) {
				int d1 = n+i-l[n+i]-1, d2 = r[i] - i-1;
				if(d1 > d2) swap(d1, d2);
				add(-1*a[i], (d1+d2+2)*a[i], d2+1, d1+d2+1);				
				add(0, (d1+1)*a[i], d1+1, d2);
				add(a[i], 0, 1, d1);
			}
		}
		for(int i=1;i<=n;i++) {
			b0[i] += b0[i-1];
			b1[i] += b1[i-1];
			cout << b0[i]*i + b1[i] << " ";
		}
		cout << endl;
	}
	
}



