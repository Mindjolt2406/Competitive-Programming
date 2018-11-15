#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  set <char> se;
  int counta=0,countb=0,countc = 0;
  for(int i=0;i<n;i++)
  {
    int c = se.size();
    se.insert(s[i]);
    int d = se.size();
    if(s[i]=='0'||((s[i]-'0')-3>0))counta++;
    if((s[i]-'0'==8 ||((s[i]-'0')+3)<10)&&s[i]!='0')countb++;
    if((s[i]=='0'||(s[i]+1)%3<s[i]%3||(s[i]-1)%3<0)&&c!=d)countc++;
  }
  cout<<counta<<" "<<countb<<" "<<countc<<" "<<se.size()<<endl;
  if(counta!=n && countb!=n && countc==se.size())cout<<"NO";
  else if(counta!=n && countb!=n)cout<<"YES";
  else if(countc>0)cout<<"NO";
  //else if(countc==0)cout<<"YES";
  else cout<<"NO";
  cout<<endl;
}
