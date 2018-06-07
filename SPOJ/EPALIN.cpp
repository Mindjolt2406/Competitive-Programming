#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
      int n = s.length();
      int MOD = 4084061;
      int prod=1,k = 26;
      int hashs=0,hasht=0,count=0,max=0;
      for(int i=n-1;i>-1;i--)
      {
        hashs*=k;hashs+=s[i]-97;
        hashs%=MOD;
        hasht+=(s[i]-97)*prod;
        hasht%=MOD;
        if(hashs==hasht)max=n-i;
        prod*=k;prod%=MOD;
      }
      count = max;
      string a,b,c,d;
      a = s.substr(0,n-count);
      b = s.substr(n-count,count+1);
      reverse(a.begin(),a.end());
      c = a;
      reverse(a.begin(),a.end());
      d = a+b+c;
      cout<<d<<endl;
    }
}
