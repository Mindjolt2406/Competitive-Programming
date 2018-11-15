#include<bits/stdc++.h>
#include<chrono>
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
using namespace std::chrono;

struct node
{
  int colour;
  int direction;
};

ll gcd(ll u, ll v) {
    while ( v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}

ll max(ll a,ll b)
{
  if(a>b) return a;
  return b;
}

ll min(ll a, ll b)
{
  if(a<b) return a;
  return b;
}

int main()
{
  typedef struct node node;
  int n,q;
  sc(n);sc(q);
  int* l = new int[n+1];
  l[0] = 0;
  for(int i=1;i<=n;i++) sc(l[i]);
  node colour[n+1];
  int number[n+1];
  int blocked[n+1];
  int *counter = (int*)calloc(n+1,sizeof(int));
  list <int> refer[n+1];
  list <int> :: iterator it;
  for(int i=1;i<=n;i++)
  {
    colour[i].colour = i;
    colour[i].direction = 0;
    blocked[i] = 0;
    number[i] = 1;
    refer[i].pu(i);
  }
  auto start = high_resolution_clock::now();
  for(int h=0;h<q;h++)
  {
    int a;
    sc(a);
    if(a==1)
    {
      // Just change the teeth
      int b,c;
      sc(b);sc(c);
      l[b] = c;
    }
    else if(a==2)
    {
      // Connect a and b. Remember the clockwise and anticlockwise manipulations
      // Also, If one of them is blocked, mark the other blocked if it already isn't
      int b,c;
      sc(b);sc(c);
      // cout<<b<<" "<<c<<endl;
      if(b==c) continue;
      node d = colour[b], e = colour[c];
      if(d.colour==e.colour)
      {
        if(blocked[d.colour]) continue;
        if(d.direction==e.direction) blocked[d.colour] = 1;
      }
      else
      {
        if(blocked[e.colour] || blocked[d.colour]) {blocked[d.colour] = 1;blocked[e.colour] = 1;continue;}
        if(number[e.colour]>number[d.colour]) swap(d,e);
        int c = (abs(d.direction-e.direction) + 1)%2;
        // cout<<d.colour<<" "<<e.colour<<endl;
        for(it=refer[e.colour].begin();it!=refer[e.colour].end();it++)
        {
          colour[*it].colour = d.colour;
          colour[*it].direction+=c;
          colour[*it].direction%=2;
          counter[*it]++;
        }
        number[d.colour]+=number[e.colour];
        number[e.colour] = 0;
        refer[d.colour].splice(refer[d.colour].end(),refer[e.colour]);
      }
    }
    else
    {
      int b,c;
      ll v;
      sc(b);sc(c);scll(v);
      if(b==c) {printf("%lld\n",v);continue;}
      if(colour[b].colour==colour[c].colour)
      {
        if(blocked[colour[b].colour]) printf("0\n");
        else
        {
          ll x;
          if(colour[b].direction==colour[c].direction) x = 1;
          else x = -1;
          ll y = gcd(max(l[b]*v,l[c]),min(l[b]*v,l[c]));
          x*= v*l[b];
          x/=y;
          printf("%lld/%lld\n",x,l[c]/y);
        }
      }
      else printf("0\n");
      // If b and c are connected
      //   If b or c is blocked, output 0
      //   Else V*l[b]/l[c]
      // Else output 0
    }
    // for(int i=1;i<=n;i++) cout<<i<<" - colour: "<<colour[i].colour<<" direction: "<<colour[i].direction<<" blocked: "<<blocked[colour[i].colour]<<endl;cout<<endl;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  // cout<<duration.count()<<endl;
  return 0;
}

/*
6 10
1 2 3 4 5 6
2 1 2
2 2 3
2 4 5
2 5 6
2 1 4

*/
