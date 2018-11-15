// #include<iostream>
// #include<tuple>
// #include<list>
// #include<algorithm>
// #include<iterator>
// #include<vector>
#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
#define MOD 1000000007
using namespace std;

// Functor to compare by the Mth element
template<long long int M, template<typename> class F = std::less>
struct TupleCompare
{
    template<typename T>
    bool operator()(T const &t1, T const &t2)
    {
        return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
    }
};

void addEdge(vector < pair <long long int,long long int> > adj[],long long int u,long long int v,long long int key)
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
}

int main()
{
  long long int n;
  long long int q;
  cin>>n;
  q = n-1;
  long long int counter = 0;
  vector < pair <long long int,long long int> > adj[n];
  vector < tuple <long long int,long long int,long long int> > v;
  for(long long int h=0;h<q;h++)
  {
    long long int a,b,key;
    cin>>a>>b>>key;
    a-=1;b-=1;
    // addEdge(a,b,key,adj);
    v.pu(make_tuple(a,b,key));
  }
  sort(begin(v),end(v), TupleCompare<2>());
  long long int colour[n];
  long long int number[n];
  list <long long int> refer[n];
  list <long long int> :: iterator it;
  long long int countcolour = n;
  for(long long int i=0;i<n;i++)
  {
    colour[i] = i;
    number[i] = 1;
    refer[i].pu(i);
  }
  long long int count = 0;
  for(long long int i=0;i<v.size()&& countcolour;i++)
  {
    long long int a = get<0>(v[i]), b = get<1>(v[i]), c = get<2>(v[i]);
    long long int d = colour[a],e = colour[b];
    if(d==e) continue;
    else if(number[d]>number[e])
    {
      // for(long long int j=0;j<number[e];j++) colour[refer[e][j]] = d;
      for(it = refer[e].begin();it!=refer[e].end();it++) colour[*it] = d;
      counter+=(number[e]*number[d]*c)%MOD;
      number[d]+=number[e];
      number[e] = 0;
      count+=c;
      addEdge(adj,a,b,c);
      countcolour--;
      // cout<<c<<endl;
      refer[d].splice(refer[d].end(),refer[e]);
    }
    else
    {
      // for(long long int j=0;j<number[d];j++) colour[refer[d][j]] = e;
      for(it = refer[d].begin();it!=refer[d].end();it++) colour[*it] = e;
      counter+=(number[e]*number[d]*c)%MOD;
      number[e]+=number[d];
      number[d] = 0;
      count+=c;
      addEdge(adj,a,b,c);
      countcolour--;
      // cout<<c<<endl;
      refer[e].splice(refer[e].end(), refer[d]);
    }
  }
  // for(long long int i=0;i<n;i++)
  // {
  //   cout<<i<<": ";
  //   for(long long int j=0;j<adj[i].size();j++) cout<<adj[i][j].first<<" ";
  //   cout<<endl;
  // }
  cout<<"Min Weight: "<<count<<endl;
  cout<<"Max: "<<counter%MOD<<endl;
  return 0;
}
/*
long long int main()
{
    vector<tuple<long long int, string>> v;
    v.push_back(make_tuple(1, "Hello"));
    v.push_back(make_tuple(2, "Aha"));
    a.splice(a.end(), b); // extends the list a by moving the elements from b to the end of a
    std::sort(begin(v), end(v), TupleCompare<0>());
    return 0;
    8 11
1 2 50
2 3 35
3 4 30
3 5 25
2 4 95
0 2 60
2 6 40
0 6 20
0 7 10
6 7 20
4 6 45

Kruskal.cpp87:37
LF
I
UTF-8C++
master104 files

}
*/
