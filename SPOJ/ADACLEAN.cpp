/*Optimizations that were needed
1. CRAZY testcases!!!!
2. You have to check for collisions
3. C++ algo for equating strings is better than running a loop.
I made a mistake in a typo, switched i and j, and was wondering why i was getting incremented unnecessarily*/
#include <iostream>
#include<map>
#include<string>
#define  MOD 4084061

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int h=0;h<t;h++)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int hash = 0;
		int prod = 1;
		int d = 26;
		int* l=(int*)calloc(MOD,sizeof(int));
		for(int i=0;i<k;i++)
		{
			hash*=d;
			hash+=s[i];
			hash%=MOD;
			if(i!=k-1){prod*=d;prod%=MOD;}
		}
		int count = 0;
		for(int i=0;i<n-k+1;i++)
		{
      //cout<<"hash: "<<hash<<" "<<s.substr(i,2)<<endl;
			if(l[hash]==0)
      {
        l[hash]=i+1;
        count+=1;
        string t = s.substr(i,2);
      //  cout<<i<<" "<<t<<endl;
      }
      else
      {
        if(s.substr(i,k)!=s.substr(l[hash]-1,k))count+=1;;
        /*int boo = 1;
        for(int j=0;j<k;j++)
        {
          //cout<<s.substr(i+j,1)<<" "<<s.substr(l[hash]-1+j,1)<<endl;
          if(s[i+j]==s[l[hash]-1+j]) continue;
          else {boo = 0;break;}
        }
        if(boo==0){count+=1;boo=1;}*/
      }
			hash-=s[i]*prod;hash = ((hash%MOD)+MOD)%MOD;
      hash*=d;
			if(i<n-k)hash+=s[i+k];
			hash%=MOD;
		}
		cout<<count<<endl;
	}
	return 0;
}
