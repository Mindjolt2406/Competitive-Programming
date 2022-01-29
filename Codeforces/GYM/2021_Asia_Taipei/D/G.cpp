// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

typedef struct state {
    int i;
    int j;
    int time;
} state;

void solve() {
    int n, m;
    cin >> n >> m;
    swap(n, m);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    int startX, startY;
    cin >> startY >> startX;

    int guards;
    cin >> guards;
    vector<vector<vector<pair<int, int>>>> squareGuards(n, vector<vector<pair<int, int>>>(m));
    int K = 1;

    for (int i = 0; i < guards; ++i) {
        int m;
        cin >> m;
        K = (K * m) / __gcd(K, m);
        // t(currLcm, m);
        for (int g = 0; g < m; ++g) {
            int x, y;
            cin >> y >> x;
            squareGuards[x][y].push_back(mp(g, m));
        }
    }
    
    // bfs
    // t(v);
    queue<pair<state, int>> states;
    vector<vector<vector<int>>> stateTaken(n, vector<vector<int>>(m, vector<int>(K, -1)));
    states.push({{startX, startY, 0}, 0});
    bool isPossible = false;
    int ans = -1;
    while (!states.empty()) {
        auto stateDist = states.front();
        states.pop();
        auto currState = stateDist.fi;
        int currDist = stateDist.se;
        int i = currState.i, j = currState.j, time = currState.time;
        // t(i, j, time);
        if (v[i][j] == 0) {
            isPossible = true;
            ans = currDist;
            break;
        }

        int dx[5] = {1, -1, 0, 0, 0};
        int dy[5] = {0, 0, 1, -1, 0};
        for (int k = 0; k < 5; ++k) {
            int nextTime = time + 1;
            {
                if (nextTime >= K)
                    nextTime -= K;
            }

            int x = dx[k] + i, y = dy[k] + j;
            auto check = [&](int x, int y){
                if (x < 0 || y < 0 || x >= n || y >= m)
                    return false;
                return true;
            };

            auto noGuards = [&](int x, int y, int time) {
                for (auto it : squareGuards[x][y]) {
                    if (time % it.se == it.fi || (time + 1) % it.se == it.fi)
                        return false;
                }
                return true;
            };

            auto altitudeCheck = [&](int x, int y) {
                return v[i][j] >= v[x][y];
            };

            if (check(x, y) && (stateTaken[x][y][nextTime] == -1) && noGuards(x, y, time) && altitudeCheck(x, y)) {
                stateTaken[x][y][nextTime] = currDist + 1;
                // t(x, y, nextTime);
                states.push({{x, y, nextTime}, currDist + 1});
            }
        }
    }

    cout << ans << endl;
}

int main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
2 3
1 2
1 2
0 0
0 0
1
3 0 1 1 1 1 1

*/
