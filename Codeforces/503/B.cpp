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

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) {sc(l[i]);l[i]--;}
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    int a = i;
    // int b = l[i];
    int* visited = (int*)calloc(n,sizeof(int));
    while(visited[a]==0)
    {
      visited[a]++;
      a = l[a];
    }
    v.pu(a);
  }
  for(int i=0;i<n;i++) cout<<v[i]+1<<" ";cout<<endl;
  return 0;
}
