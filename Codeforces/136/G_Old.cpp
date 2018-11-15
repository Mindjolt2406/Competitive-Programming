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


void update(int* bit,int* l,int index,int value,int n,int c)
{
  while(index<=n)
  {
    if(l[index-1]<=value) bit[index]+=c;
    index += index&(-1*index);
  }
}

ll get(int* bit,int index)
{
  ll sum1 = 0;
  while(index>0)
  {
    sum1+=bit[index];
    index-= index&(-1*index);
  }
  return sum1;
}

ll getInv(int* bit1,int* bit2,int left,int right)
{
  if(left==right) return 0;
  ll sum1 = 0;
  sum1+=left - get(bit1,left);
  sum1+=get(bit2,right);
  return sum1;
}

int main()
{
  int n;ll k;
  sc(n);scll(k);
  int* bit1 = new int[n+1];
  int* bit2 = new int[n+1];
  int* l = new int[n];
  int* m = new int[n];
  int count = 1;
  for(int i=0;i<n;i++) {sc(l[i]);}
  for(int i=0;i<=n;i++){bit1[i] = 0;bit2[i] = 0;}
  map<int,int> d;
  set<int> s;
  set<int> :: iterator it;
  for(int i=0;i<n;i++) s.insert(l[i]);
  for(it = s.begin();it!=s.end();it++) {d[*it] = count;count++;}
  for(int i=0;i<n;i++) m[i] = d[l[i]];
  for(int i=0;i<n;i++) cout<<m[i]<<" ";cout<<endl;
  int left = 1,right = 2;
  ll counter = 0;
  update(bit1,m,left,m[left],n,1);
  for(int i=n;i>1;i--) update(bit2,m,right,m[right],n,1);
  for(int i=1;i<=n;i++) cout<<bit1[i]<<" ";cout<<endl;
  for(int i=1;i<=n;i++) cout<<bit2[i]<<" ";cout<<endl;
  while(right<n)
  {
    // Get inversions
    while(right<n && getInv(bit1,bit2,left,right)<k)
    {
      // Delete the element
      cout<<"left: "<<left<<" right: "<<right<<getInv(bit1,bit2,left,right)<<endl;;
      update(bit2,m,right,m[right],n,-1);
      right++;
    }
    counter+=n-right;
    left++;
    update(bit1,m,left,m[left],n,1);
  }
  printf("%lld\n",counter);
  return 0;
}
