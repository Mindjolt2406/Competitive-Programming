#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

int main()
{
  int l[4] = {2,3,5,7};
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    if(n==1) {printf("1\n");continue;}
    int i = 0;
    int m[4] = {0};
    while(n && i<4)
    {
      if(n%l[i]==0)
      {
        while(n%l[i]==0)
        {
          m[i]++;
          n/=l[i];
        }
      }
      i++;
    }
    // for(int i=0;i<4;i++) cout<<m[i]<<" ";cout<<endl;
    // cout<<n<<endl;
    if(n>1) printf("-1\n");
    else
    {
      vector<int> v;
      int count8 = m[0]/3;
      int count9 = m[1]/2;
      int count6 = 0,count3 = 0, count4 = 0,count2 = 0;
      if(m[0]%3 && m[1]%2)
      {
        count6++;
      }
      else if(m[0]%3)
      {
        if(m[0]%3==2) count4++;
        else count2++;
      }
      else if(m[1]%2) count3++;
      for(int i=0;i<count8;i++) v.pu(8);
      for(int i=0;i<count9;i++) v.pu(9);
      if(count6) v.pu(6);
      if(count4) v.pu(4);
      if(count2) v.pu(2);
      if(count3) v.pu(3);
      for(int i=0;i<m[2];i++) v.pu(5);
      for(int i=0;i<m[3];i++) v.pu(7);
      sort(v.begin(),v.end());
      // cout<<"here"<<endl;
      for(int i=0;i<v.size();i++) printf("%d",v[i]);printf("\n");
    }
  }
  return 0;
}
