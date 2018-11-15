// #include<iostream>
// #include<tuple>
// #include<list>
// #include<algorithm>
// #include<iterator>
// #include<vector>
#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

// Global variables
int n;
vector < pair <int,int> > *adj;

void addEdge(int u,int v,int key)
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
}

// Function to compare tuples wrt the Mth element
template<int M, template<typename> class F = std::less>
struct TupleCompare
{
    template<typename T>
    bool operator()(T const &t1, T const &t2)
    {
        return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
    }
};

tuple<double,double,long long int> Kruskal(vector < tuple <int,int,double> > v,int n,double r)
{
  sort(begin(v),end(v), TupleCompare<2>());
  long long int states = 1;
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
  double count1=0,count2 = 0;
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
      if(c<=r) count1+=c;
      else {count2+=c;states++;}
      addEdge(a,b,c);
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
      if(c<=r) count1+=c;
      else {count2+=c;states++;}
      addEdge(a,b,c);
      countcolour--;
      // cout<<c<<endl;
      refer[e].splice(refer[e].end(), refer[d]);
    }
  }
  return make_tuple(count1,count2,states);
}

int main()
{
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int r;
    cin>>n>>r;
    adj = new vector < pair <int,int> >[n];
    vector < pair <int,int> > v;
    vector < tuple <int,int,double> > v1;
    // x,y coordinates for all points
    for(int i=0;i<n;i++)
    {
      int a,b;
      cin>>a>>b;
      v.pu(m(a,b));
    }
    // dding all edges into the adjacency list
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        double c = sqrt(pow((double)v[i].first-v[j].first,2)+pow((double)v[i].second-v[j].second,2));
        // cout<<v[i].first<<" "<<v[j].first<<" "<<v[i].second<<" "<<v[j].second<<" "<<c<<endl;
        v1.pu(make_tuple(i,j,c));
      }
    }
    // for(int i=0;i<v1.size();i++) cout<<get<0>(v1[i])<<" "<<get<1>(v1[i])<<" "<<get<2>(v1[i])<<endl;
    // vector < pair <int,int> > *ptr;
    // ptr=&adj;
    tuple <double,double,long long int> p = Kruskal(v1,n,r);
    // long long int states = bfs(r);
    // for(int i=0;i<n;i++)
    // {
    //   cout<<i<<": "<<endl;
    //   for(int j=0;j<adj[i].size();j++) cout<<adj[i][j].first<<" "<<adj[i][j].second<<" "<<endl;
    // }
    cout<<"Case #"<<h<<": "<<get<2>(p)<<" "<<(long long int)round(get<0>(p))<<" "<<(long long int)round(get<1>(p))<<endl;
    // cout<<"Count1: "<<p.first<<" Count2: "<<p.second<<" States: "<<states<<endl;
  }
  return 0;
}

/*
3
3 100
0 0
1 0
2 0
3 1
0 0
100 0
200 0
4 20
0 0
40 30
30 30
10 10

vector < pair <int,int> > adj[],
*/
