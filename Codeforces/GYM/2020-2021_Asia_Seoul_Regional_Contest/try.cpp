#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
const int MOD = 1e9+7;
vector<int> fact(N);

void precompute() {
	fact[0] = 1;
	for(int i=1;i<N;i++) {
		fact[i] =  (1LL * fact[i-1] * i) % MOD;	
	}
}

int main() {
	precompute();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> freq(N);
		for(int i=0;i<n;i++) 
		{
			cin >> v[i];
			if(v[i] < N) freq[v[i]]++;
		}
		
		sort(v.begin(), v.end());
		int mexCounter = 0;
		int ans = 1;
		for(auto it : v) {
			if(it == mexCounter) 
			{
				mexCounter++;	
				ans = (1LL * ans * freq[it]) % MOD;
			}
		}
		
		// if(mexCounter <= 1) cout << fact[n] << endl;
		cout << (1LL * fact[n-mexCounter] * ans) % MOD << endl;
	}
}