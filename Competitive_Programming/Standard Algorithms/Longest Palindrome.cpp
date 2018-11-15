#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int rollinghash(int,string,int);
int bsearch(int,string);
int main()
{
  string s;
  cin>>s;
  int n = s.length();
  int left=0,right=n;
  int a = bsearch(1,s);
  int b = bsearch(0,s);
  cout<<a<<" "<<b<<endl;
  cout<<max(a,b)<<endl;
  return 0;
}

int rollinghash(int size,string s,int max) //This commputes if a palindrome of given size exists or not.
{
  //int l[4084061];
  cout<<"size: "<<size<<endl;
  int MOD = 4084061;
  //fill(array, array+4084061, -1);
  int n = s.length();
  long long int hash=0,hashr = 0;
  long long int k = 27,prod=1;
  reverse(s.begin(),s.end());
  string t = s;
  reverse(s.begin(),s.end());
  int boo=-1;
  for(int i=0;i<size;i++)
  {
    hash*=k;
    hash+=(s[i]);hash%=MOD;
    hashr*=k;
    hashr+=(t[i]);hashr%=MOD;
    if(i<size-1)prod*=k;prod%=MOD;
  }
  cout<<prod<<endl;
  int* l = (int*)calloc(n-size+1,sizeof(int));
  for(int i=0;i<n-size+1;i++)
  {
    l[i] = hashr;
    hashr-=t[i]*prod;
    hashr = ((hashr%MOD)+MOD)%MOD;
    hashr*=k;
    hashr%=MOD;
    if(i<n-size)hashr+=t[i+size];
    hashr%=MOD;
  }
  for(int i=0;i<n-size+1;i++)cout<<l[i]<<" ";
  cout<<endl<<hash<<endl;
  for(int i=0;i<n-size+1;i++)
  {
    cout<<hash<<" "<<l[n-i-size]<<endl;
    if(hash==l[n-i-size]) {boo = i;cout<<"boo";break;}
    hash-=s[i]*prod;
    hash = ((hash%MOD)+MOD)%MOD;hash*=k;
    if(i<n-size)hash+=s[i+size];
    hash%=MOD;
  }
  cout<<hash<<" "<<l[boo]<<" ash "<<boo<<endl;
  if(boo!=-1) {max = size;cout<<hash<<" "<<hashr<<" ash "<<boo<<endl;return max;}
  return 0;
}

int bsearch(int c,string s)
{
  int max = 0;
  int left = 0,right = s.length();
  int mid = (left+right)/2;
  while(left<=right&&mid<right)
  {
    cout<<mid<<" "<<c<<" "<<left<<" "<<right<<endl;
    if(mid%2==c)mid+=1;
    cout<<mid<<" "<<c<<" "<<left<<" "<<right<<endl;
    int k = rollinghash(mid,s,0);
    cout<<k<<endl;
    if(k!=0) {if(k>max)max = k;left = mid+1;}
    else right = mid-1;
    mid = (left+right)/2;
  }
  return max;
}
