#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    
    vector<int> v;
    
    int cnt = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i] == '.') cnt++;
      if(s[i] == 'P')
      {
        if(!v.empty() || cnt) v.push_back(cnt);
        cnt = 0;
      }
    }
    
    int x = 0;
    int y = 1;
    for(int i=v.size()-1;i>=0;i--) 
    {
      if(y) x ^= (v[i]%3);
      y^=1;
    }
    
    if(x) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
