int rollinghash(int size,string s,int max) //This commputes if a palindrome of given size exists or not.
{
  int MOD = 4084061;
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
  for(int i=0;i<n-size+1;i++)
  {
    if(hash==l[n-i-size]) {boo = i;break;}
    hash-=s[i]*prod;
    hash = ((hash%MOD)+MOD)%MOD;hash*=k;
    if(i<n-size)hash+=s[i+size];
    hash%=MOD;
  }
  if(boo!=-1) {max = size;return max;}
  return 0;
}

int bsearch(int c,string s)
{
  int max = 0;
  int left = 0,right = s.length();
  int mid = (left+right)/2;
  while(left<=right&&mid<right)
  {
    if(mid%2==c)mid+=1;
    int k = rollinghash(mid,s,0);
    if(k!=0) {if(k>max)max = k;left = mid+1;}
    else right = mid-1;
    mid = (left+right)/2;
  }
  return max;
}
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


