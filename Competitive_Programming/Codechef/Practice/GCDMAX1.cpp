#include<bits/stdc++.h>
#define pu emplace_back
using namespace std;

void print(vector<int> v)
{
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
  cout<<endl;
}

int max2(int*l, int n)
{
  int max1 = 0;
  for(int i=0;i<n;i++) max1 = max(l[i],max1);
  return max1;
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0 || b == 0)
       return 0;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int gcdarr(int*l,  int n,int k,int val)
{
  if(k==1) return max2(l,n);
  int c = n/k;
  c-=1;
  // cout<<"c: "<<c<<endl;
  int max1 = 0;
  for(int i=0;i<c;i++)
  {
    //Make the reverse prefix gcd array for this segment and a forward prefix gcd array for the next segment
    vector<int> v,w;
    int count = 0;
    for(int j=(i+1)*k-1;j>=(i)*k;j--)
    {
      //V is the reverse gcd array
      if(v.empty()) v.pu(l[j]);
      else {v.pu(gcd(l[j],v[count-1]));}
      // cout<<"i: "<<i<<" v: ";print(v);
      count++;
    }
    // cout<<"v: ";print(v);
    // cout<<"here"<<endl;
    count = 0;
    for(int j=(i+1)*k;j<(i+2)*k -1;j++)
    {
      // cout<<"j: "<<j<<" i: "<<i<<endl;
      if(w.empty()) w.pu(l[j]);
      else w.pu(gcd(l[j],w[count-1]));
      count++;
    }
    reverse(w.begin(),w.end());
    // if(!v.empty())cout<<"v: ";print(v);
    // if(!w.empty())cout<<"w: ";print(w);
    for(int i=0;i<w.size();i++)
    {
      max1 = max(gcd(v[i],w[i]),max1);
    }
    max1 = max(max1,v[k-1]);
  }
  // For the last segment, make it's reverse prefix array, and count. n-k+1 subarrays are possible of lengths k
  // We have covered c*k arrays . Sor for those n-k+1 -c*k, build the forward array for the next incompeete segment
  // Then join
  vector<int> v,w;
  int count = 0;
  for(int i=c*k+k-1;i>=c*k;i--)
  {
    if(v.empty()) v.pu(l[i]);
    else v.pu(gcd(l[i],v[count-1]));
    count++;
  }
  count = 0;
  for(int i=c*k+k;i<n;i++)
  {
    if(w.empty()) w.pu(l[i]);
    else w.pu(gcd(l[i],w[count-1]));
    count++;
  }
  // cout<<"max1: "<<max1<<endl;
  // reverse(w.begin(),w.end());
  // if(!v.empty())cout<<"v: ";print(v);
  // if(!w.empty())cout<<"w: ";print(w);
  count = 0;
  max1 = max(max1,v[k-1]);
  for(int i=k-2;count<w.size();i--)
  {
    // cout<<"gcd: "<<gcd(v[i],w[count])<<" v[i]: "<<v[i]<<" w[count]: "<<w[count]<<endl;
    max1 = max(gcd(v[i],w[count]),max1);
    count++;
  }
  // cout<<"max1: "<<max1<<endl;
  if(max1>=val) return 1;
  else return 0;
}

int main()
{
  int n,k;
  // scanf("%d %d",&n,&k);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin>>n>>k;
  int l[n];
  for(int i=0;i<n;i++) {cin>>l[i];}
  int beg = 1, end = n;
  int max1 = 0;
  int boo = 0;
  while(beg<=end)
  {
    int mid = (beg + end)/2;
    // cout<<"mid: "<<mid<<endl;
    int c = 0;
    c = gcdarr(l,n,mid,k);
    if(c) {beg = mid+1;max1 = max(max1,mid);boo = 1;}
    if(!c) end = mid-1;
  }
  if(boo) cout<<max1<<endl;//printf("%d\n",max1);
  else cout<<0<<endl;//printf("%d\n",0);
  return 0;
}
