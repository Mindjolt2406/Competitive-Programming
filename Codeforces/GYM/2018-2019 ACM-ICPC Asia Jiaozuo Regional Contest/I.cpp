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
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    // vi v(1000001);
    vi v;
    v.pu(0);
    int count = 0;
    // v[0]= 1;
    for(int i=0;i<n-1;i++)
    {
      int a;
      sc(a);
      count+=a;
      v.pu(count);
    }
    // for(int i=0;i<=10;i++) cout<<v[i]<<" ";cout<<endl;
    int left = -1,right = v.size();
    int number = 0,prev = -1;
    ll total = 0,sum = 0;
    while(left<=right)
    {
      // Move left pointer to the right
      left++;
      if(left==right) break;
      number++;
      if(number%2==1)
      {
        total+=sum;
        prev = v[left];
      }
      else
      {
        total+=sum+prev-v[left];
        sum+=prev-v[left];
      }
      if(number!=n) cout<<total<<" ";
      else  cout<<total;
      // Move right pointer to the left
      right--;
      if(left==right) break;
      number++;
      if(number%2==1)
      {
        total+=sum;
        prev = v[right];
      }
      else
      {
        total+=sum+v[right]-prev;
        sum+=v[right]-prev;
      }
      if(number!=n) cout<<total<<" ";
      else  cout<<total;
    }
    cout<<endl;
  }
  return 0;
}

