#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

// Function to compare by the Mth element
template<int M, template<typename> class F = std::less>
struct TupleCompare
{
    template<typename T>
    bool operator()(T const &t1, T const &t2)
    {
        return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
    }
};

void addEdge(vector < pair <int,int> > adj[],int u,int v,int key)
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
}

int main()
{
  int n;
  int q;
  cin>>n>>q;
  vector < pair <int,int> > adj[n];
  vector < tuple <int,int,int> > v;
  for(int h=0;h<q;h++)
  {
    int a,b,key;
    cin>>a>>b>>key;
    a-=1;b-=1;
    // addEdge(a,b,key,adj);
    v.pu(make_tuple(a,b,key));
  }
  sort(begin(v),end(v), TupleCompare<2>());
  int colour[n];
  int number[n];
  list <int> refer[n];
  list <int> :: iterator it;
  int countcolour = n;
  for(int i=0;i<n;i++)
  {
    colour[i] = i;
    number[i] = 1;
    refer[i].pu(i);
  }
  int count = 0;
  for(int i=0;i<v.size()&& countcolour;i++)
  {
    int a = get<0>(v[i]), b = get<1>(v[i]), c = get<2>(v[i]);
    int d = colour[a],e = colour[b];
    if(d==e) continue;
    else if(number[d]>number[e])
    {
      // for(int j=0;j<number[e];j++) colour[refer[e][j]] = d;
      for(it = refer[e].begin();it!=refer[e].end();it++) colour[*it] = d;
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
      // for(int j=0;j<number[d];j++) colour[refer[d][j]] = e;
      for(it = refer[d].begin();it!=refer[d].end();it++) colour[*it] = e;
      number[e]+=number[d];
      number[d] = 0;
      count+=c;
      addEdge(adj,a,b,c);
      countcolour--;
      // cout<<c<<endl;
      refer[e].splice(refer[e].end(), refer[d]);
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<i<<": ";
    for(int j=0;j<adj[i].size();j++) cout<<adj[i][j].first<<" ";
    cout<<endl;
  }
  cout<<"Min Weight: "<<count<<endl;
  return 0;
}