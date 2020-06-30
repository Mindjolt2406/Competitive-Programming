ll power(ll x, ll y, ll p)
{
	ll res = 1;      // Initialize result
	x = x % p;  // Update x if it is more than or
	while (y > 0)
	{
			if (y & 1)
					res = (res*x) % p;
			y = y>>1; // y = y/2
			x = (x*x) % p;
	}
	return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= power (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}