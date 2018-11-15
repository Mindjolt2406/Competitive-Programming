#include<iostream>
#include<set>
#define MOD 1000000007
using namespace std;

int main()
{
  int n,m;
  set <char> s;
  cin>>n>>m;
  long long int prod = 1;
  char l[n][m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>l[i][j];
  for(int i=0;i<m;i++)
  {
    s.clear();
    for(int j=0;j<n;j++)
    {
      s.insert(l[j][i]);
    }
    int num = s.size();
    prod*=num;
    prod%=MOD;
  }
  cout<<prod<<endl;
  return 0;
}
