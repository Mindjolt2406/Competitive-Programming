#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const double EPS = 1e-15;
 
struct Point
{
	double x, y;
 
	Point() 
	{
		x = 0, y = 0;
	}
 
	Point(double _x, double _y)
	{
		x = _x, y = _y;
	}
 	
 	bool between(Point &P, Point &Q)
 	{
 		bool checkX = x < max(P.x, Q.x) + EPS && x + EPS > min(P.x, Q.x);
 		bool checkY = y < max(P.y, Q.y) + EPS && y + EPS > min(P.y, Q.y);
 		return checkX && checkY;
 	}

	Point operator+ (const Point& P) const
	{
		return Point(x + P.x, y + P.y);
	}
 
	Point operator- (const Point& P) const
	{
		return Point(x - P.x, y - P.y);
	}

	bool operator< (Point &o)
	{
		if(abs(x - o.x) > EPS)
			return x < o.x;
		return y < o.y;
	}
};

struct Line
{
	double a, b, c;

	Line(Point P, Point Q)
	{
		if(abs(P.x - Q.x) < EPS)
		{
			a = 1;
			b = 0;
			c = -P.x;
		}
		else
		{
			a = (P.y - Q.y) / (Q.x - P.x);
			b = 1.0;
			c = -(a * P.x + P.y);
		}
	}

	bool parallel(Line l)
	{
		return abs(a - l.a) < EPS && abs(b - l.b) < EPS;
	}

	Point intersect(Line l)
	{
		if(parallel(l))
			return Point();	
		double x = (b * l.c - c * l.b) / (a * l.b - b * l.a);
		double y;
		if(abs(b) < EPS)
			y = -l.a * x - l.c;
		else
			y = -a * x - c;
    return Point(x,y);
	}
};


struct Segment
{
	Point P, Q;
	int idx;
 
	Segment()
	{
		idx = -1;
	}
 
	Segment(double x1, double y1, double x2, double y2, int _idx)
	{
		P = Point(x1, y1);
		Q = Point(x2, y2);
		idx = _idx;
	}
 
	Segment(Point _P, Point _Q, int _idx)
	{
		P = _P, Q = _Q, idx = _idx;
	}
 	
 	Point intersect(Segment ls)
 	{	
 		Line l1 = Line(P, Q);
 		Line l2 = Line(ls.P, ls.Q);
 		if(l1.parallel(l2))
 			return Point();
 		Point c = l1.intersect(l2);
 		return c.between(P, Q) && c.between(ls.P, ls.Q) ? c : Point();
 	}

	double get_y(double &x) const
	{
		if(abs(P.x - Q.x)<EPS)
			return P.y;
		return P.y + (Q.y - P.y) * (x - P.x) / (Q.x - P.x);
	}
};
 
struct Event
{
	double x;
	int type, idx; //type - 1: Add, -1: Remove
 
	Event() {}
 
	Event(double x, int type, int idx) : x(x), type(type), idx(idx) {}
 
	bool operator< (const Event &e) const
	{
		if(abs(x - e.x) > EPS)
			return x < e.x;
		if(type != e.type)
			return type > e.type;
		return idx < e.idx;
	}
};
 
int vec(const Point &a, const Point &b, const Point &c)
{
	double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if(abs(s) < EPS)
		return 0;
	return s > 0 ? 1 : -1;
}
 
bool intersect1D(double l1, double r1, double l2, double r2)
{
	if(l1 > r1)
		swap(l1, r1);
	if(l2 > r2)
		swap(l2, r2);
	return max(l1, l2) <= min(r1, r2) + EPS;
}
 
bool intersect(const Segment &a, const Segment &b)
{
	return 	intersect1D(a.P.x, a.Q.x, b.P.x, b.Q.x) &&
			intersect1D(a.P.y, a.Q.y, b.P.y, b.Q.y) &&
			vec(a.P, a.Q, b.P) * vec(a.P, a.Q, b.Q) <= 0 &&
			vec(b.P, b.Q, a.P) * vec(b.P, b.Q, a.Q) <=0;
}
 
bool operator<(const Segment& a, const Segment& b)
{
	double x = max(min(a.P.x, a.Q.x), min(b.P.x, b.Q.x));
	return a.get_y(x) < b.get_y(x) - EPS;
}
 
set<Segment> s;
vector<set<Segment>::iterator > where;
 
set<Segment>::iterator prev(set<Segment>::iterator it) 
{
	return it == s.begin() ? s.end() : --it;
}
 
set<Segment>::iterator next(set<Segment>::iterator it) 
{
	return ++it;
}
 
pair<int, int> solve(const vector<Segment> &v)
{
	int n = v.size();
	set<Event> events;
	for(int i=0;i<n;i++)
	{
		events.insert(Event(min(v[i].P.x, v[i].Q.x), +1, i));
		events.insert(Event(max(v[i].P.x, v[i].Q.x), -1, i));
	}
	s.clear();
	where.resize(n);
	while(events.size())
	{
		auto E = *events.begin();
		events.erase(E);
		int idx = E.idx;
		if(E.type == +1)
		{
			set<Segment>::iterator nxt = s.lower_bound(v[idx]), prv = prev(nxt);
			if(nxt != s.end() && intersect(*nxt, v[idx]))
				return make_pair(nxt->idx, v[idx].idx);
			if(prv != s.end() && intersect(*prv, v[idx]))
				return make_pair(prv->idx, v[idx].idx);
			where[idx] = s.insert(nxt, v[idx]);
		}
		else
		{
			set<Segment>::iterator nxt = next(where[idx]), prv = prev(where[idx]);
			if(nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
				return make_pair(prv->idx, nxt->idx);
			s.erase(where[idx]);
		}
	}
	return make_pair(-1, -1);
}

struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

int main()
{
  int t;
  cin >> t;
  while(t--)  
  {
    int n;
    cin >> n;

    vector<pt> posPoint, negPoint;
    for(int i=0;i<n;i++)
    {
      double x,y,k;
      cin >> x >> y >> k;
      pt p;
      p.x = x, p.y = y;

      if(k == -1) negPoint.pu(p);
      else posPoint.pu(p);
    }

    if(posPoint.size() == 0 || negPoint.size() == 0) 
    {
      cout << "YES" << endl;
      continue;
    } 

    convex_hull(posPoint);
    convex_hull(negPoint);

    int posSize = posPoint.size(), negSize = negPoint.size();

    vector<pair<pt,pt> > pointPairs;
    for(int i=0;i<posSize;i++)
    {
      pointPairs.pu(mp(posPoint[i], posPoint[(i+1)%posSize]));
    }

    for(int i=0;i<posSize;i++)
    {
      pointPairs.pu(mp(negPoint[i], negPoint[(i+1)%negSize]));
    }

    vector<Segment> segments;
    for(int i=0;i<pointPairs.size();i++)
    {
      pair<pt,pt> p = pointPairs[i];

      Segment s(p.fi.x, p.fi.y, p.se.x*0.99 + p.fi.x*0.01, p.se.y*0.99+p.fi.y*0.01,i);
      segments.pu(s);
    }

    pair<int,int> p = solve(segments);
    if(p == mp(-1,-1)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }


  return 0;
}
