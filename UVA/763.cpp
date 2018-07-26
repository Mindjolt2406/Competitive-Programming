#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

void recur(int* a)
{
  queue<int> q;
  int i=0;
  for(int i=0;i<200;i++) if(a[i]) q.push(i);
  while(!q.empty())
  {
    int i = q.front();
    q.pop();
    if(a[i]==1)
    {
      if(a[i+1])
      {
        a[i+1]--;
        a[i] = 0;
        a[i+2]++;
        q.push(i+1);
      }
    }
    else if(a[i]==2)
    {
      a[i] = 0;
      a[i+1] += 1;
      if(i-2>=0){a[i-2]++;q.push(i-2);q.push(i+1);}
      else if(i==1){a[0]++;q.push(i-1);q.push(i+1);}
    }
    else if(a[i]==3)
    {
      a[i] = 0;
      a[i+2] +=2;
      if(i-2>=0){a[i-2]++;q.push(i-2);q.push(i+2);}
      else if(i==1){a[0]++;q.push(0);q.push(i+2);}
    }
    else if(a[i]==4)
    {
      a[i] = 1;
      a[i+2] +=2;
      if(i-2>=0){a[i-2]++;q.push(i-2);q.push(i+2);}
      else if(i==1){a[0]++;q.push(0);q.push(i+2);}
    }
  }
  // else if(a[i]==5)
  // {
  //
  // }
}

int main()
{
  string s,s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  while(1)
  {
    int* a = (int*)calloc(200,sizeof(int));
    int* b = (int*)calloc(200,sizeof(int));
    reverse(s1.begin(),s1.end());reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++) a[i] = s1[i]-'0';
    for(int i=0;i<s2.size();i++) b[i] = s2[i]-'0';
    for(int i=0;i<200;i++) a[i]+=b[i];
    recur(a);
    int max1 = -1;
    string k;
    for(int i=0;i<200;i++) if(a[i]==1) max1 = i;
    for(int i=0;i<=max1;i++)
    {
      k+=a[i]+'0';
    }
    reverse(k.begin(),k.end());
    printf("%s\n\n",k.c_str());
    if(getline(cin,s))
    {
      getline(cin,s1);
      getline(cin,s2);
      // cout<<"s1: "<<s1<<endl;
      // cout<<"s2: "<<s2<<endl;
    }
    else break;
  }
  return 0;
}

/*
10010
1

10000
1000

10000
10000

*/
