#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)

#define FOR(i,a,b)      for(int i=(a);i<(b);i++)
#define RFOR(i,a,b)     for(int i=(b)-1;i>=(a);i--)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007
#define EPS       1E-10
#define ELR       2.71828182845904523536
#define PI        acos(-1)

#define CASE(x)   cout << "Case #" << x << ": "

int poss(int a,int b,int c,int d)
{
      if(a >= 0 && a< c && b >=0 && b < d) return 1;
      else return 0;
}

int main()
{
      inp_s;
      DRT()
      {
            int n,m;
            cin >> n >> m;
            vector<string> arr(n);
            FOR(i,0,n) cin >> arr[i];

            deque< PII > bfs;
            int visited[n][m];
            FOR(i,0,n) FOR(j,0,m) visited[i][j] = INT_MAX;
            visited[0][0] = 1;
            bfs.push_front(mp(0,0));

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            while(!bfs.empty())
            {
                  PII node = bfs.front();
                  bfs.pop_front();

                  if(node.first == n-1 && node.second == m-1) break;

                  FOR(i,0,4)
                  {
                        int x = node.first + dx[i];
                        int y = node.second + dy[i];

                        if(poss(x,y,n,m))
                        {
                              if(arr[x][y] == arr[node.first][node.second] && visited[x][y] > visited[node.first][node.second])
                              {
                                    visited[x][y] = visited[node.first][node.second];
                                    bfs.push_front(mp(x,y));
                              }
                              else if(visited[x][y] > visited[node.first][node.second] + 1)
                              {
                                    visited[x][y] = visited[node.first][node.second] + 1;
                                    bfs.push_back(mp(x,y));
                              }
                        }
                  }
            }
            cout << visited[n-1][m-1] - 1 << endl;
      }
      return 0;
}
