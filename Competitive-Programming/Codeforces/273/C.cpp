// UPSOLVED QUESTION
// The solution is fantastic
// The first observation, which I was able to make, was that sum%3 will be left, and that's the min that can be left
// Which implies that if we're able to make a,b,c from the 2 functions, we're done (sum = 0mod3)
// However, there's a catch
// It's only possible to do so under a certain condition.
// To get this condition, if we take the max, and continously reduce it(reduce 2 from it, and 1 from the other), there are 2 things that can happen
// 1. The other 2 colours become 0. This implies that if we take the colours and sort them, l[0]+l[1]<l[2]
// 2. If it doesn't, one of the other colours has the possibility of taking the max position. Again, this happens iff l[0]+l[1]>=l[2]
// So, if we reduce it to a certain state where after another reduction the max colour changes, we can see that l[2]-max(l[0],l[1])<2
// Or, in other words, max-2ndmax<2
// Now, if we reduce 2 from max and 1 from 2ndmax, or if we reduce 1 from all 3, this invariance is mantained.
// The thing is that the base cases i.e a permutation of 1 1 0, or 1 0 0, or 0 0 0 will be reached.
// Any other possibility like x 0 0 where x>=2 is not going to happen as it doesn't follow the invariant.
// So, in conclusion, this question can be solved while taking the invaraince in mind.
// I feel that it should've been intuitive enough to understand that invariance would be used because stuff was changing,
// and anything could happen. There had to be some order amidst the chaos.
// The first thing was cases. Sometimes stuff was becoming 0, somethimes it was confusion(a.k.a the second case).
// The proof ethod for this was nothing but cases and invaraince, which is again nothing but some form of induction.
// How would I tackle this kind of problem again?
// 
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

ll min(ll x,ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  ll r,g,b;
  scll(r);scll(g);scll(b);
  ll l[3] = {r,g,b};
  sort(l,l+3);
  cout<<min((r+g+b)/3,l[0]+l[1])<<endl;
  return 0;
}
