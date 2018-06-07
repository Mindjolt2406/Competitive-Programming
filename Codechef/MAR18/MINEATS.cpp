#include <iostream>
#include<algorithm>
using namespace std;

int calck(int*,int,int);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  int n,h;
	  cin>>n>>h;
	  int l[n];
	  for(int i=0;i<n;i++)cin>>l[i];
    sort(l,l+n);
	  int beg = 1;
	  int end = l[n-1];
	  int min = l[n-1];
	  while(beg<=end)
	  {
	    int mid = (beg+end)/2;
      //cout<<mid<<" "<<min<<endl;
	    int c = calck(l,mid,n);
	    if(c<=h) {end = mid-1;if(mid<min)min = mid;}
	    else {beg = mid+1;}
	  }
	  cout<<min<<endl;
	}
	return 0;
}

int calck(int* l, int k,int n)
{
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(l[i]%k==0)count+=l[i]/k;
    else count+=l[i]/k +1;
  }
  return count;
}
