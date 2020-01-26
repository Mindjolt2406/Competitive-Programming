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
#define EPS 1e-12
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

template <class T>
intline int sgn(const T&x)
{
  return (x > EPS) - (x< -EPS);
}

template <class T>
struct Point
{
  T x,y;

  Point(): x(0), y(0) {}
  Point(const T &x, const T &y): x(x), y(y) {}

  ld length() const
  {
    return sqrtl(x*x +  y*y);
  }

  ld length2() const
  {
    return x*x + y*y;
  }

  ld distance(const Point & rhs)
  {
    return (rhs - *this).length();
  }

  T cross(const Point &lhs, const Point &rhs)
  {
    return (lhs-*this)*(rhs-*this);
  }

  T dot(const Point &lhs, const Point &rhs)
  {
    return (lhs-*this)&(rhs-*this);
  }

  ld distance_to_line(const Point &p, const Point &q)
  {
    if(p==q) return distance(p);
    else return fabsl(cross(p,q) / p.distance(q));
  }

  ld distance_to_segment(const Point &p, const Point &q)
  {
    if(p==q) return distance(p);
    else if(p.dot(q,*this) < 0) return distance(p);
    else if(q.dot(p,*this) < 0) return distance(q);
    else return distance_to_line(p,q);
  }

  bool on_line(const Point & p, const Point &q,)
  {
    return sgn(cross(p,q)) == 0;
  }

  bool on_halfline(const Point &p, const Point &q,const bool &include = true)
  {
    if(*this == p) return include;
    return on_line(p,q) && sgn(p.dot(q,*this)) >= 0;
  }

  bool on_segment(const Point & p, const Point &q, const bool include)
  {
    if(*this == p || *this == q) return include;
    return on_line(p,q) && sgn(dot(p,q)) <= 0;
  }

  bool in_triangle(const Point &u, const Point &v, const Point &w, const bool &include)
  {
    Point p[3] = {u,v,w};
    if( sgn(u.cross(v,w)) < 0) reverse(p,p+3); // Consider them anticlockwise
    for(int i=0;i<3;i++)
    {
      if(on_segment(p[i],p[(i+1)%3])) return include;
      else if(sgn(cross(p[i],p[(i+1)%3])) < 0) return false;
    }
    return true;
  }

  bool in_angle(const Point &o, const Point &p, const Point &q, const bool &include)
  {
    if(on_halfline(o,p) || on_halfline(o,q)) return include;
    int a = sgn(o.cross(p,q)), b = sgn(o.dot(p,q));

  }



  Point operator + (const Point & rhs)
  {
    return Point(x+rhs.x, y+rhs.y);
  }

  Point operator - (const Point &rhs)
  {
    return Point(x-rhs.x, y-rhs.y);
  }

  T operator * (const Point &rhs)
  {
    return x*rhs.y - y*rhs.x;
  }

  T operator & (const Point &rhs)
  {
    return x*rhs.x + y*rhs.y;
  }

  Point operator * (const T &rhs)
  {
    return Point(x*rhs, y*rhs);
  }

  Point operator / (const T &rhs)
  {
    return Point(x/rhs, y/rhs);
  }

  bool operator == (const Point &rhs)
  {
    return rhs.x == x && rhs.y == y;
  }

  bool operator != (const Point &rhs)
  {
    return rhs.x != x || rhs.y != y;
  }

  // Change numbers if necessary
  inline int quadrant() const
  {
    if(x== 0 && y==0) return -1;
    else if(x>0 && y>0) return 1;
    else if(x<0 && y>0) return 2;
    else if(x<0 && y<0) return 3;
    else if(x>0 && y<0) return 4;
    else if(x==0 && y>0) return 5;
    else if(y==0 && x<0) return 6;
    else if(x==0 && y<0) return 7;
    else return 8;
  }

  // inline int quadrant() const {
	// 	if (x == 0 && y == 0) return -1;
	// 	else if (x < 0 && y < 0) return 0;
	// 	else if (x == 0 && y < 0) return 1;
	// 	else if (x > 0 && y < 0) return 2;
	// 	else if (x > 0 && y == 0) return 3;
	// 	else if (x > 0 && y > 0) return 4;
	// 	else if (x == 0 && y > 0) return 5;
	// 	else if (x < 0 && y > 0) return 6;
	// 	else return 7;
	// }

	// bool operator < (const Point & rhs) const {
	// 	int lq = quadrant(), rq = rhs.quadrant();
	// 	if (lq != rq) {
	// 		return lq < rq;
	// 	} else {
	// 		int s = sgn(*this * rhs);
	// 		return s != 0 ? s > 0 : sgn(length2() - rhs.length2()) < 0;
	// 	}
	// }
} 

template <class T> 
struct Line
{
  Point <T> u,v;

  Line() {}

  Line(const Point<T> &u, const Point<T> &v): u(u), v(v) {}

  Line( const T &px, const T &py, const T &qx, const T &qy): u(px,py), v(qx,qy) {}

  // Cross Product
  T operator * (const Line &rhs) const
  {
    return (v-u)*(rhs.v-rhs.u);
  }

  T operator & (const Line &rhs) const
  {
    return (v-u)&(rhs.v-rhs.u);
  }

  // ISSUES WITH THIS
  bool operator < (const Line &rhs) const 
  {
    int vs = sgn(*this * rhs), ss = sgn(*this & rhs);
    if(vs == 0 && ss > 0) return on_left(rhs.u,false);
    else return v-u < rhs.v - rhs.u
  }

  // Problem
  template < class U> 
  bool on_left(const Point<U> &p, const bool &inclusive = true) const
  {
    return p.cross(u,v) > 0;
  }

  bool on_right(const Point<U> &p, const bool &inclusive = true) const
  {
    return p.cross(u,v) < 0;
  }
}

template <class T> 
Point<T> line_line_intersection(const Line<T> &lhs, const Line<T> &rhs)
{
  return line_line_intersection(lhs.u, lhs.v, rhs.u, rhs.v);
}

// Ampersand not in original code
template <class T>
bool half_plane_intersection(vector<Line<T> > &L, vector<Point<T> > &ans)
{
  const int n = L.size();
  sort(l.begin(),L.end());
  int first = 0, last = 0;
  vector<Point<T> > p(n);
  vector<Line<T> > q(n);

  q[last++] = L[0];

  for(int i=1;i<n;i++)
  {
    for(;first+1 < last && L[i].on_right(p[last-2]); last--);
    for(; first + 1 < last && L[i].on_right(p[first]);first++);
    q[last++] = L[i];

    if(sgn(q[last-2] * q[last-1]) == 0)
    {
      last --;
      if(q[kast - 1].on_left(L[i].u)) q[last-1] = L[i];
    }

    if(first+1<last) p[last-2] = line_line_intersection(q[last-2],q[last-1]);
  }

  for(;first+1<last && q[first].on_right(p[last-2]); last--);
  if (last - first <= 2) return false;
  p[last-1] = line_line_intersection(q[first],q[last-1]);
  ans.clear();
  for(int i = first; i < last; i++) ans.pu(p[i]);
  return true;
}

int main()
{
  __;
  
  return 0;
}

