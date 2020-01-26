#include <iostream>
#define MOD 1000000007
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  long long int l[n];
	  long long int m[2001] = {0};
	  for(int i=0;i<n;i++){cin>>l[i];l[i]+=1000;}
	  for(int i=0;i<n;i++)m[l[i]]++;
	  long long int count = 0;
	  for(int i=0;i<2001;i++)
	  {
	   // if(t==1&&i==1) cout<<m[i]<<" "<<m[i+1]<<" "<<m[i+2]<<endl;
	    for(int j=i;j<2001;j++)
	    {
	      if(i==j && m[j]>1){count+= ((m[j]*(m[j]-1))/2);}
	      else if((i+j)%2==0 && i!=j && m[(i+j)/2]>0){ count+= (((m[i]*m[j])));}
	    }
	   // if(t==1&&i==1) cout<<"Count: "<<count<<endl;
	   // if(t==1&&i==2) cout<<"Count: "<<count<<endl;
	  }
	  cout<<count<<endl;
	}
	return 0;
}
