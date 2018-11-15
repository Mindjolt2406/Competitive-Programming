#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
using namespace std;

int n;
void merger(pair<int,int>*l,int i,int c, int j,int *p, int*boo)
{
  pair<int,int> *m = new pair<int,int>[j-i+1];
  int x = i;
  int y = c+1;
  int k = 0;
  int sum1 = 0,sum2 = 0,count = 0;
  while(k<j-i+1)
  {
    if(y==j+1)
    {
      while(x<=c)
      {
        m[k].first = l[x].first;
        m[k].second = l[x].second;
        count+=(y-c-1);
        int d = y-c-1;
        // p[l[x].second] = max(sum2-l[x].second-1,p[l[x].second]);
        if(sum1!=l[x].first && sum2!=0) p[l[x].second] = sum2-l[x].second-1;
        if(p[l[x].second]>=0 && sum2!=0)boo[l[x].second] =1;
        // boo[l[x].second] = 1;
        // cout<<"l[x].first: "<<l[x].first<<" l[x].second: "<<l[x].second<<" sum2: "<<sum2<<" sum1: "<<sum1<<" p[l[x].second]: "<<p[l[x].second]<<endl;
        x++;
        k++;
      }
      continue;
    }
    else if(x==c+1)
    {
      while(y<=j)
      {
        m[k].first = l[y].first;
        m[k].second = l[y].second;
        y++;
        k++;
      }
      continue;
    }
    else if(l[x].first<=l[y].first)
    {
      m[k].first = l[x].first;
      m[k].second = l[x].second;
      int d = y-c-1;
      // if(l[x].second==0) cout<<"d: "<<d<<" sum2: "<<sum2;
      // p[l[x].second] = max(sum2-l[x].second-1,p[l[x].second]);
      if(sum1!=l[x].first && sum2!=0) p[l[x].second] = sum2-l[x].second-1;
      if(p[l[x].second]>=0 && sum2!=0)boo[l[x].second] =1;
      // cout<<"l[x].first: "<<l[x].first<<" l[x].second: "<<l[x].second<<" sum2: "<<sum2<<" sum1: "<<sum1<<" p[l[x].second]: "<<p[l[x].second]<<endl;
      x++;
    }
    else if(l[y].first<l[x].first)
    {
      m[k].first = l[y].first;
      m[k].second = l[y].second;
      sum2 = max(l[y].second,sum2);
      if(sum2==l[y].second) sum1 = l[y].first;
      // cout<<"l[y].second: "<<l[y].second<<endl;
      y++;
    }
    k++;
  }
  //Copying
  copy(m,m+j-i+1,l+i);
  // cout<<"i: "<<i<<" j: "<<j;
  // cout<<" sum2: "<<sum2<<" count: "<<count<<" p: ";
  // for(int i=0;i<n;i++) cout<<p[i]<<" ";
  // cout<<endl;
  // cout<<"BOO"<<endl;
  // for(int i=0;i<n;i++) cout<<boo[i]<< " ";
  // cout<<endl;
}


void sort1(pair<int,int> *l, int i,int j,int*m,int*boo)
{
  if(i<j)
  {
    int c = (i+j)/2;
    // cout<<"i: "<<i<<" j: "<<j<<" c: "<<c<<endl;
    sort1(l,i,c,m,boo);
    sort1(l,c+1,j,m,boo);
    merger(l,i,c,j,m,boo);
    // cout<<"Indices i: "<<i<<" j: "<<j<<endl;
  }
}

int main()
{
  cin>>n;
  pair<int,int> *l = new pair<int,int>[n];
  int *m=(int*)calloc(n,sizeof(int));
  int *boo=(int*)calloc(n,sizeof(int));
  // for(int i=0;i<n;i++) m[i] = -1;
  int min1 = 1000000001;

  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    l[i] = mp(a,i);
  }
  for(int i=0;i<n;i++) min1 = min(min1,l[i].first);
  vector <int> v;
  for(int i=0;i<n;i++) if(l[i].first==min1) v.pu(i);
  sort1(l,0,n-1,m,boo);
  for(int i=0;i<v.size();i++) m[v[i]] = -1;
  // for(int i=0;i<n;i++) cout<<boo[i]<< " ";
  // cout<<endl;
  for(int i=0;i<n;i++)
  {
    if(m[i]>0)cout<<m[i]<<" ";
    else if(m[i]<=0 && boo[i] && m[i]!=-1) cout<<0<<" ";
    else if(m[i]<=0)cout<<-1<<" ";
  }
  cout<<endl;
  return 0;
}


/*

(10,0) (4,1) (6,2) (3,3) (2,4) (8,5) (18,6)
Step1: (4,1) (10,0) sum =
13
5 7 3 2 1 6 5 2 8 1 7 9 3

*/
