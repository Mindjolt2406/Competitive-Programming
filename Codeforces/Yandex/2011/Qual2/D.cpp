// I really like this question. Took me wayy longer than needed to implement though ( Total time - 3 hours)
// The main craux of this question lies in the fact that the subproblem is that once you've chosen your two elements, 
// you get an array for whom you have to choose two elements again. This is the recursive subproblem
// So, the subproblem is that an array repeats. How is that even helpful? It is, because you can represent the array with very 
// less data. Try seeing why
// The observation here is that once you remove 2 elements, the array is of the form i,j,j+1,j+2,..., n-1, n
// So, the dp state will just be dp[i][j] where i and j are the smallest 2 indices left in the array
// From here you could relate it to removing two elements and relate it to other states like dp[j+1][j+2]
// I got heavily confused in the backtracking part. Backtracking is literally inverse of everything
// I've elaborated below

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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int n;
  sc(n);
  int*l = new int[n+1];
  l[0] = 0;
  for(int i=1;i<=n;i++) sc(l[i]); 
  int **dp = new int*[n+2];
  for(int i=0;i<=n+1;i++) dp[i] = new int[n+2];
  for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dp[i][j] = INF;

  // Different base cases for even and odd 
  if(n%2==1)
  {
    for(int i=1;i<=n;i++) dp[i][n+1] = l[i];
  }
  else
  {
    for(int i=1;i<n;i++) dp[i][n] = max(l[i],l[n]);
  }

  for(int i=n;i>=1;i--)
  {
    for(int j=n;j>=1;j--)
    {
      // The recursive relation
      if(i==j) continue; // Calling the same person in the queue isn't a valid move
      int a = INF,b = INF,c = INF; 
      if(j+2>n+1) continue;
      // These !=INF conditions are just there just so that INF doesn't change. Or else your INF starts looking weird
      if(dp[j+1][j+2]!=INF) a = dp[j+1][j+2] + max(l[i],l[j]);
      if(dp[j][j+2]!=INF) b = dp[j][j+2] + max(l[i],l[j+1]);
      if(dp[i][j+2]!=INF) c = dp[i][j+2] + max(l[j],l[j+1]);
      // There are 3 possible paths you could go from. These have been computed before. Just take the best and move on
      dp[i][j] = min(min(a,b),c);
    }
  }

  // Since the array starts from the 1st and 2nd index, this is where the final answer lies
  cout<<dp[1][2]<<endl;


  vector<pair<int,int> > v,w;
  v.pu(mp(1,2)); // Starting from here
  int a1 = 1, b1 = 2;
  while(true)
  {
    // In a convoluted way, I'm computing which was the best path which led me to a certain state. w holds the 2 numbers getting
    // deleted and v holds the state
    if(v[v.size()-1].se >= n) { w.pu(mp(v[v.size()-1].fi,v[v.size()-1].se));}
    pair<int,int> p = v[v.size()-1];
    int i = p.fi,j = p.se;
    int a1 = -1, b1 = -1;

    if(j+2>n+1) break;
    
    int a = dp[j+1][j+2] + max(l[i],l[j]), b = dp[j][j+2] + max(l[i],l[j+1]), c = dp[i][j+2] + max(l[j],l[j+1]);

    if(c<a) 
    {
      a1 = i, b1 = j+2;
    }
    else 
    {
      a1 = j+1, b1 = j+2;
    }
    if(b < min(a,c)) 
    {
      a1 = j, b1 = j+2;
    }

    if(a1==j+1 && b1==j+2) w.pu(mp(i,j));
    else if(a1==j && b1==j+2) w.pu(mp(i,j+1));
    else if(a1==i && b1==j+2) w.pu(mp(j,j+1));
    v.pu(mp(a1,b1)); 
  }

  for(int i=0;i<w.size();i++)
  {
    if(w[i].se<n+1 )cout<<w[i].fi<<" "<<w[i].se<<endl; // For odd cases, I've paired up the alone guys with n+1
    else cout<<w[i].fi<<endl;
  }
  return 0;
}

