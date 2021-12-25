// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1e18
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

class Point {
  public:
    ll x, y, z;
    Point(ll x, ll y, ll z) : x(x), y(y), z(z) {}

    bool operator==(const Point &other) {
        return other.x == x && other.y == y && other.z == z;
    }

    ll distance2(const Point &other) {
        ll diffX = labs(other.x - x), diffY = labs(other.y - y),
           diffZ = labs(other.z - z);

        return diffX * diffX + diffY * diffY + diffZ * diffZ;
    }
};

ostream &operator<<(ostream &os, const Point &point) {
    os << point.x << " " << point.y << " " << point.z << endl;
    return os;
}

Point operator+(const Point &curr, const Point &other) {
    return Point(other.x + curr.x, other.y + curr.y, other.z + curr.z);
}

Point operator-(const Point &curr, const Point &other) {
    return Point(curr.x - other.x, curr.y - other.y, curr.z - other.z);
}

ll min(ll x, ll y) { return x < y ? x : y; }

Point extrapolatePoint(const Point &x, const Point &o, const Point &y) {
    // o is the centre one.
    return x + (y - o);
}

bool checkCube(vector<Point> &points) {
    if (points.size() != 8)
        return false;

    Point ref = points.front();
    ll minDistance = INF;
    for (int i = 1; i < 8; i++) {
        minDistance = min(minDistance, ref.distance2(points[i]));
    }

    if (minDistance == 0)
        return false;

    vector<Point> closePoints;
    for (int i = 1; i < 8; i++) {
        if (ref.distance2(points[i]) == minDistance)
            closePoints.push_back(points[i]);
    }

    if (closePoints.size() != 3)
        return false;

    vector<Point> farPoints;
    for (int i = 0; i < 3; i++) {
        Point currPoint = closePoints[i], nextPoint = closePoints[(i + 1) % 3];
        farPoints.push_back(extrapolatePoint(currPoint, ref, nextPoint));
        if (count(points.begin(), points.end(), farPoints.back()) == 0)
            return false;
    }

    Point lastPoint =
        extrapolatePoint(farPoints[0], closePoints[0], farPoints[2]);

    if (count(points.begin(), points.end(), lastPoint) == 0)
        return false;

    return true;
}

pair<bool, vector<Point>> recur(vector<Point> &original, vector<Point> points,
                                int index) {
    if (index == 8) {
        // t(points);
        if (checkCube(points))
            return {true, points};
        return {false, {}};
    }

    int arr[3] = {0, 1, 2};
    Point currPoint = original[index];
    vector<ll> currPointCoord = {currPoint.x, currPoint.y, currPoint.z};
    do {
        int x = currPointCoord[arr[0]];
        int y = currPointCoord[arr[1]];
        int z = currPointCoord[arr[2]];
        Point p(x, y, z);
        vector<Point> tempPoints = points;
        tempPoints.push_back(p);
        auto result = recur(original, tempPoints, index + 1);
        if (result.first)
            return result;
    } while (next_permutation(arr, arr + 3));

    return {false, {}};
}

void solve() {
    vector<Point> points;
    for (int i = 0; i < 8; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Point p(x, y, z);
        points.push_back(p);
    }

    auto result = recur(points, {}, 0);
    if (result.first) {
        cout << "YES\n";
        for (auto point : result.second)
            cout << point;
    } else {
        cout << "NO\n";
    }
}

int main() {
    __;
    solve();
    return 0;
}
