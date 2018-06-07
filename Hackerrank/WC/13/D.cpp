#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

// Complete the fewestOperationsToBalance function below.
int fewestOperationsToBalance(string s)
{
    // Return the minimum number of steps to make s balanced.
  stack<char> s1;
  for(int i=0;i<s.size();i++)
  {
    if(!s1.empty() && s[i]==')' && s1.top()=='(') s1.pop();
    else s1.push(s[i]);
  }
  set<int> s2;
  while(!s1.empty())
  {
    char c = s1.top();
    s2.insert(c);
    s1.pop();
  }
  return s2.size();
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    int result = fewestOperationsToBalance(s);
    cout << result << "\n";
    return 0;
}
