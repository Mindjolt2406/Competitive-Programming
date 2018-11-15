/*
Mr. G. works as a tourist guide. His current assignment is to take some tourists from one city to another. Some two-way roads connect the cities. For each pair of neighboring cities there is a bus service that runs only between those two cities and uses the road that directly connects them. Each bus service has a limit on the maximum number of passengers it can carry. Mr. G. has a map showing the cities and the roads connecting them. He also has the information regarding each bus service. He understands that it may not always be possible for him to take all the tourists to the destination city in a single trip. For example, consider the following road map of 7 cities. The edges connecting the cities represent the roads and the number written on each edge indicates the passenger limit of the bus service that runs on that road.
Now, if he wants to take 99 tourists from city 1 to city 7, he will require at least 5 trips and the routeheshouldtakeis: 1-2-4-7.
But, Mr. G. finds it difficult to find the best route all by himself so that he may be able to take all the tourists to the destination city in minimum number of trips. So, he seeks your help.
Input
The input will contain one or more test cases. The first line of each test case will contain two integers: N (N ≤ 100) and R representing respectively the number of cities and the number of road segments. Then R lines will follow each containing three integers: C1, C2 and P. C1 and C2 are the city numbers and P (P > 1) is the limit on the maximum number of passengers to be carried by the bus service between the two cities. City numbers are positive integers ranging from 1 to N. The (R + 1)-th line will contain three integers: S, D and T representing respectively the starting city, the destination city and the number of tourists to be guided.
The input will end with two zeroes for N and R. Output
For each test case in the input first output the scenario number. Then output the minimum number of trips required for this case on a separate line. Print a blank line after the output of each test case.
Sample Input
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
3 6 20
4 7 35
5 7 20
6 7 30
1 7 99
0 0

Sample Output
Scenario #1
Minimum Number of Trips = 5
*/
#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
#define pu push_back
#define m make_pair
using namespace std;

long long int min1 = 1000000000;
long long int max1 = 0;
vector < pair <long long int,long long int> > visited;

void addEdge(long long int u,long long int v, long long int key,vector< pair <long long int,long long int> >adj[])
{
  adj[u].pu(m(v,key));
  adj[v].pu(m(u,key));
  // cout<<adj[u].back().first<<" "<<adj[u].back().second<<endl;
}

pair <long long int,long long int> dfs(vector < pair <long long int,long long int> > adj[],long long int u,long long int key)
{
  if(u==key) return m(1,0);
  // cout<<"size: "<<visited.size()<<endl;
  // cout<<"Hey there!"<<u<<endl;
  cout<<u<<" ";
  if(visited[u].first==-1) return m(0,0);
  if(visited[u].first==1) return m(1,0);
  // cout<<"HI"<<endl;
  visited[u].first = 1;
  // cout<<"HI"<<endl;
  cout<<u<<" ";
  int boo = 0;
  vector<long long int> v;
  pair <long long int,long long int>  c;
  for(int i=1;i<adj[u].size();i++)
  {
    c = dfs(adj,adj[u][i].first,key);
    if(c.first == 1 && visited[u].second>adj[u][i].second)
    {
      visited[u].second = adj[u][i].second;
      boo = 1;
      v.pu(visited[u].second);
      visited[i].first = 1;
    }
    else visited[i].first = -1;
  }
  // cout<<"HELLO: "<<u<<endl;
  if(!v.empty() && max1<=*max_element(v.begin(),v.end())) {max1 = *max_element(v.begin(),v.end()); c.second = max1;}
  // cout<<"BYE: "<<u<<endl;
  if(boo) return c;
  visited[u].first = -1;
  return m(0,0);
}

int main()
{
  long long int n,r;
  cin>>n>>r;
  long long int count = 1;
  while(n!=0 && r!=0)
  {
    min1 = 1000000000;
    max1 = 0;
    vector < pair <long long int,long long int> > adj[n+1];
    for(int h=0;h<r;h++)
    {
      long long int a,b,key;
      cin>>a>>b>>key;
      addEdge(a,b,key,adj);
    }
    long long int beg,end,number;
    cin>>beg>>end>>number;
    for(int i=0;i<n+1;i++) visited.pu(m(0,1000000000));
    // cout<<"HELLO"<<visited.size()<<endl;
    pair <long long int,long long int> p = dfs(adj,beg,end);
    // cout<<"BYE"<<endl;
    for(int i=0;i<visited.size();i++) cout<<visited[i].first<<" "<<visited[i].second<<endl;
    cout<<"max1: "<<max1<<" second: "<<p.second<<endl;
    max1 = p.second;
    cout<<"Scenario #"<<count<<endl;
    cout<<"Minimum Number of Trips = "<<ceil((number)/(double long)(max1-1))<<endl;
    cin>>n>>r;
    count++;
  }
}
