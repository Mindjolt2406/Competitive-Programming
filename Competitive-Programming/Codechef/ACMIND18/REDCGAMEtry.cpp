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

int func(int countmax1,int countmax2,int max1,int max2,int cost)
{
  // cout<<countmax1<<" "<<countmax2<<" "<<max1<<" "<<max2<<" "<<cost<<endl;
  if(countmax1==1)
  {
    return max1-cost;
  }
  
  if(countmax1%2 == countmax2%2)
  {
    return countmax1%2;
  }
  else
  {
    int a = max1%2,b = max2%2,c = countmax1%2,d= countmax2%2;
    if(!a && b && !c && d) return 1;
    else if(a && !b && c && !d) return 1;
    else if(a && !b && !c && d) return 0;
    else if(!a && b && c && !d) return 0;
    else return 0;
  }
}

int distance(vector<int> v)
{
  if(v.size()==0) return 0;
  set<int> s;
  set<int> :: iterator it;
  vector<int> vdis;
  map<int,int> d; // d is the counter
  int countmax1 = 0,countmax2 =0;
  int left=0,right=v.size()-1,leftd =0,rightd=0;
  for(int i=0;i<v.size();i++) 
  {
    s.insert(v[i]);
    if(d.find(v[i])!=d.end()) d[v[i]] ++;
    else d[v[i]] = 1;
  }
  for(it=s.begin();it!=s.end();it++) vdis.pu(*it);
  leftd = 0,rightd = vdis.size()-1;
  countmax1+=d[v[rightd]];
  int max1 = vdis[rightd],max2 = vdis[rightd-1];
  int cost = (max1-max2)*(countmax1-countmax2);
  if(rightd==0) return func(countmax1,0,max1,max1-1,0);

  int c = v[left];
  while(left<=right)
  {
    // cout<<"leftd: "<<leftd<<" rightd: "<<rightd<<" left: "<<left<<" right: "<<right<<endl;
    if(c>=cost)
    {
      d[c]--;
      c-=cost;
      d[c]++;
      d[max2]+=d[max1];
      rightd--;
      // Change max1 and max2
      max1 = max2;
      countmax1 += d[max1];
      if(rightd>0) 
      {
        max2 = vdis[rightd-1];
        countmax2 = d[max2];
        cost = (max1-max2)*(countmax1-countmax2);
      }
      else return func(countmax1,0,max1,max1-1,0);
    }
    else if(leftd>=rightd)
    {
      d[c]--;
      int a = d[max1];
      // cout<<"a: "<<a<<" c: "<<c<<endl;
      int b1 = c/a, b2 = c%a;
      max1-=b1;
      if(max1<=0) return b2;
      return func(d[max1]-b2,b2,max1,max1-1,c);
    }
    else
    {
      d[c]--;
      cost-=c;
      left++;
      c = v[left];
    }
    if(v[left]!=vdis[leftd]) leftd++;

  }
}


int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    int*l = new int[n];
    ll count = 0;
    for(int i=0;i<n;i++) sc(l[i]);
    sort(l,l+n);
    vector<int> v;
    ll sum1 = 0;
    for(int i=0;i<n-1;i++) 
    {
      if(l[i]>=k) {v.pu(l[i]);sum1+=k;}
      else sum1+=l[i];
    }
    int c = distance(v);
    sum1+=l[n-1]-c;
    cout<<sum1<<endl;
  }
  // }
  // int n;
  // sc(n);
  // vector<int> v;
  // for(int i=0;i<n;i++) {int a;sc(a);v.pu(a);}
  // cout<<distance(v)<<endl;
  return 0;
}

