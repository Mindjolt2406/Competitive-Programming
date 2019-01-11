// Only ll
typedef struct BIT //ll
{
  vector<ll> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  ll sum(int i)
  {
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<ll> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;