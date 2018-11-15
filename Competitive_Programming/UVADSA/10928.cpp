#include<bits/stdc++.h>
#define pu push_back
using namespace std;

vector <int> *adj;

void addEdge(int u,int v)
{
  adj[u].pu(v);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    adj = new vector <int>[n];
    cout<<"n: "<<n<<endl;
    for(int i=0;i<n;i++)
    {
      string s;
      getline(cin,s);
      cout<<"s: "<<s<<endl;
      istringstream buf(s);
      istream_iterator<string> beg(buf),end;
      vector<string> tokens(beg,end);
      for(int j=0;j<tokens.size();j++)
      {
        addEdge(i,stoi(tokens[j])-1);
      }
    }
    int min1 = 1001;
    for(int i=0;i<n;i++)
    {
      if(adj[i].size()<min1) min1 = adj[i].size();
    }
    vector<int> v;
    for(int i=0;i<n;i++)
    {
      if(adj[i].size()==min1)v.pu(i);
    }
    for(int i=0;i<v.size()-1;i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1];
    if(t!=1)cout<<endl;
  }
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

int main()
{
    std::string str = "This is a string";
    std::istringstream buf(str);
    std::istream_iterator<std::string> beg(buf), end;

    std::vector<std::string> tokens(beg, end); // done!

    for(auto& s: tokens)
        std::cout << '"' << s << '"' << '\n';
}
*/
