/*
This is a sneaky problem.
To solve this, let's try solving an easier question where we remove the number in query and only consider the string
In that way, we can just take every prefix, put it in a map, and for every time we encounter the prefix we update it's
key to be the lexicographically smallest string it has come from.
This seems easy enough.
Now, since the queries always ask to look at strings from 1 to k, we sort all the queries based on k,
do the same stuff as above and keep adding more and more strings to the map as k increases.
We save the answers for each query in another map, and pull it out when we have to print them out.
Pretty nice q

The main observations were that the string length was length than 10. That implied that we could store every prefix
encountered.
The next observation (for sorting) came from the fishy fact that every query was of the form [1,k]
*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
using namespace std;


int main()
{
  int n;
  cin>>n;
  vector<string> v1,shortest;
  for(int i=0;i<n;i++)
  {
    string s;
    char temp[10];
    scanf("%s",temp);
    s = temp;
    v1.pu(s);
  }
  // Making a vector of the shortest strings seen so far for the cases when the prefix isn't found
  string min1 = "zzzzzzzzzzz";
  for(int i=0;i<v1.size();i++)
  {
    if(v1[i]<min1) {min1 = v1[i];}
    shortest.pu(min1);
  }
  int q;
  cin>>q;
  vector<tuple<int,string,int> >v;
  map<int,string> d;
  for(int i=0;i<q;i++)
  {
    int k;
    string s;
    char temp[10];
    scanf("%d %10s",&k,temp);
    s = temp;
    // cin>>k>>s;
    v.pu(mt(k,s,i));
  }
  sort(v.begin(),v.end());
  map<string,string> e;
  int i=0,j=0; // i is the iterator for the original string array and j is the iterator for the sorted vector of tuples
  for(int j=0;j<v.size();j++)
  {
    int c = get<0>(v[j]);
    if(i!=c)
    {
      while(i<c)
      {
        string k;
        string s = v1[i];
        for(int h=0;h<s.size();h++)
        {
          k+=s[h];
          if(e.find(k)!=e.end())
          {
            if(e[k]>s)e[k] = s;
          }
          else e[k] = s;
        }
        i++;
      }
    }
    string k;
    string s = get<1>(v[j]);
    string temp;
    for(int h=0;h<s.size();h++)
    {
      k+=s[h];
      if(e.find(k)!=e.end())
      {
        temp =  e[k];
      }
      else break;
    }
    if(temp.empty()) temp = shortest[c-1];
    d[get<2>(v[j])] = temp;
  }
  for(int i=0;i<q;i++)
  {
    printf("%s\n",d[i].c_str());
  }
  return 0;
}
/*
4
abcd
abce
abcdex
abcde
1
3 abcy

*/
