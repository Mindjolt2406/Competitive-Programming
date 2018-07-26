#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  // ----------
  // This is for cases when the testcases are separated by blank lines and inpu thas to be taken until EOF
  // Input here
  string s1,s2,s;
  getline(cin,s1);
  getline(cin,s2);
  while(1)
  {
    /*
      Code here
    */
    if(getline(cin,s)) // Blank line
    {
      // Input again
      getline(cin,s1);
      getline(cin,s2);
    }
    else break;
  }
  // --------
  
  return 0;
}
