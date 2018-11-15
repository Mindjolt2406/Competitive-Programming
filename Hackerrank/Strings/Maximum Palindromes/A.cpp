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

int getSum(int*l,int a,int b)
{
  if(a>0) return l[b]-l[a-1];
  return l[b];
}

int main()
{
  string s;
  scr(s);
  int n = s.size();
  int**l = new int*[26];
  for(int i=0;i<26;i++) l[i] = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    l[s[i]-'a'][i]++;
  }

  for(int i=0;i<26;i++) for(int j=1;j<n;j++) l[i][j]+=l[i][j-1];
  int q;
  sc(q);
  while(q--)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    int count = 0;
    for(int i=0;i<26;i++)
    {
      int c = getSum(l[i],a,b);
      if(c%2==1) count++;
    }
    if(count==0 && (b-a)>1) count++;
    cout<<count<<endl;
  }
  return 0;
}
