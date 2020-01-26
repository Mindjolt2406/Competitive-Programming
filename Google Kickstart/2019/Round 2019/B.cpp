/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

const int N = 255;
vector<vector<int> > vis1(N,vector<int>(N)), vis2(N,vector<int>(N)), v(N,vector<int> (N));


bool find(int k,int n,int m)
{
  // Alternate formulation of abs(x1-x2) + abs(y1-y2) is max( abs(x2-y2-(x1-y1)), abs(x2+y2-(x1+y1)) )

  // Compute min and max of x2-y2 and x2+y2 where x2 and y2 are points whose distances are greater than k
  // Then for each point, compare these 4 things and get the max distances for each point. Once you get them, then 
  // return true if your max is <=k. Else return false

  int min1 = INF,max1 = -1,min2 = INF,max2 = -1;
  int flag = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(vis1[i][j]>k)
      {
        min1 = min(min1,j-i);
        max1 = max(max1,j-i);
        min2 = min(min2,i+j);
        max2 = max(max2,i+j);
        flag = 1;
      }
    }
  }

  if(flag==0) return true;

  int dist = INF;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int distmax = -1;
      // Calculate the distances for each point
      distmax = max(distmax,max(abs(min1-(j-i)),abs(min2-(i+j))));
      distmax = max(distmax,max(abs(min1-(j-i)),abs(max2-(i+j))));
      distmax = max(distmax,max(abs(max1-(j-i)),abs(min2-(i+j))));
      distmax = max(distmax,max(abs(max1-(j-i)),abs(max2-(i+j))));
      dist = min(dist,distmax);

      // t(i,j,distmax,abs(min1-(j-i)));
      // t(min1,max1,min2,max2,i,j);
      // dist = max(dist,max(min1-(i-j),min2-(i+j)));
      // dist = max(dist,max(min1-(i-j),max2-(i+j)));
      // dist = max(dist,max(max1-(i-j),min2-(i+j)));
      // dist = max(dist,max(max1-(i-j),max2-(i+j)));
    }
  }

  // t(k,dist);
  if(dist<=k) return true;
  return false;
}

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    queue<pair<int,int> > q1,q2;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      for(int j=0;j<m;j++) 
      {
        v[i][j] = s[j]-'0';
        vis1[i][j] = vis2[i][j] = -1;
        if(v[i][j]) {q1.push(mp(i,j)); q2.push(mp(i,j));vis1[i][j] = vis2[i][j] = 0;}
      }
    }

    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
    q1.push(mp(-1,-1));
    int counter = 0;
    while(!q1.empty())
    { 
      pair<int,int> p = q1.front();
      q1.pop();
      
      if(p==mp(-1,-1))
      {
        counter++;
        if(q1.front()==p || q1.empty()) break;
        else q1.push(p);
        continue;
      }
      int a = p.fi, b = p.se;
      // t(a,b,counter);
      // if(!v[a][b]) {vis1[a][b]++;t(a,b,v[a][b]);}
      for(int i=0;i<4;i++)
      {
        int c = a+dx[i], d = b+dy[i];
        if(c<0 || c>=n || d<0 || d>=m) continue;
        if(vis1[c][d]!=-1) continue;
        vis1[c][d] = vis1[a][b]+1;
        // t(a,b,c,d,vis1[c][d]);
        q1.push(mp(c,d));
      }
    }

    int max1 = -1;
    for(int i=0;i<n;i++) 
    {
      for(int j=0;j<m;j++) 
      {
        max1 = max(max1,vis1[i][j]);
      }
    }

    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<m;j++)
    //   {
    //     cout<<vis1[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    int beg = 0, end = max1,ans = 0;
    while(beg<=end)
    {
      int mid = (beg+end)>>1;
      if(find(mid,n,m)) {end = mid-1;ans = mid;}
      else beg = mid+1;
    }
    cout<<"Case #"<<h<<": "<<ans<<endl; 
  } 
  return 0;
}

/*
 
*/