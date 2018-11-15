#include<bits/stdc++.h>
using namespace std;

int main()
{
  int ns = 0,nm = 0,l = 0,xl = 0,xxl = 0;
  cin>>ns>>nm>>l>>xl>>xxl;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    if(s=="S")
    {
      if(ns){ns-=1;cout<<"S"<<endl;}
      else if(nm){nm-=1;cout<<"M"<<endl;}
      else if(l){l-=1;cout<<"L"<<endl;}
      else if(xl){xl-=1;cout<<"XL"<<endl;}
      else if(xxl){xxl-=1;cout<<"XXL"<<endl;}
    }
    else if(s=="M")
    {
      if(nm){nm-=1;cout<<"M"<<endl;}
      else if(l){l-=1;cout<<"L"<<endl;}
      else if(ns){ns-=1;cout<<"S"<<endl;}
      else if(xl){xl-=1;cout<<"XL"<<endl;}
      else if(xxl){xxl-=1;cout<<"XXL"<<endl;}
    }
    else if(s=="L")
    {
      if(l){l-=1;cout<<"L"<<endl;}
      else if(xl){xl-=1;cout<<"XL"<<endl;}
      else if(nm){nm-=1;cout<<"M"<<endl;}
      else if(xxl){xxl-=1;cout<<"XXL"<<endl;}
      else if(ns){ns-=1;cout<<"S"<<endl;}
    }
    else if(s=="XL")
    {
      if(xl){xl-=1;cout<<"XL"<<endl;}
      else if(xxl){xxl-=1;cout<<"XXL"<<endl;}
      else if(l){l-=1;cout<<"L"<<endl;}
      else if(nm){nm-=1;cout<<"M"<<endl;}
      else if(ns){ns-=1;cout<<"S"<<endl;}
    }
    else if(s=="XXL")
    {
      if(xxl){xxl-=1;cout<<"XXL"<<endl;}
      else if(xl){xl-=1;cout<<"XL"<<endl;}
      else if(l){l-=1;cout<<"L"<<endl;}
      else if(nm){nm-=1;cout<<"M"<<endl;}
      else if(ns){ns-=1;cout<<"S"<<endl;}
    }
  }
  return 0;
}
