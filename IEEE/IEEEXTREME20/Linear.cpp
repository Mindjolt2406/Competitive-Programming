#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
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

/*
This code is described in "Computational Geometry in C" (Second Edition),
Chapter 7.  It is not written to be comprehensible without the
explanation in that book.

Written by Joseph O'Rourke.
Last modified: December 1997
Questions to orourke@cs.smith.edu.
--------------------------------------------------------------------
This code is Copyright 1997 by Joseph O'Rourke.  It may be freely
redistributed in its entirety provided that this copyright notice is
not removed.
--------------------------------------------------------------------
*/
#include        <stdio.h>
#include        <math.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define X       0
#define Y       1
// typedef enum { false, true } bool;
typedef enum { Pin, Qin, Unknown } tInFlag;

#define DIM     2               /* Dimension of points */
typedef int     tPointi[DIM];   /* type integer point */
typedef double  tPointd[DIM];   /* type double point */
#define PMAX    100002           /* Max # of pts in polygon */

typedef tPointi tPolygoni[PMAX];/* type integer polygon */

/*---------------------------------------------------------------------
Function prototypes.
---------------------------------------------------------------------*/

const long double eps = 1e-12;
const long double infl = 1e20;

template <class T>
inline int sgn(const T & x) {
	return (x > eps) - (x < -eps);
}

template <class T>
struct Point {
 	T x, y;

	Point() : x(0), y(0) {

	}

	Point(const T & x, const T & y) : x(x), y(y) {

	}

	long double length() const {
		return sqrtl(x * x + y * y);
	}

	T length2() const {
		return x * x + y * y;
	}

	long double distance(const Point & rhs) const {
		return (rhs - *this).length();
	}

 	T cross(const Point & lhs, const Point & rhs) const {
		return (lhs - *this) * (rhs - *this);
	}

	T dot(const Point & lhs, const Point & rhs) const {
		return (lhs - *this) & (rhs - *this);
	}

	long double distance_to_line(const Point & p, const Point & q) const {
		if (p == q) return distance(p);
		else return fabsl(cross(p, q) / p.distance(q));
	}

	long double distance_to_segment(const Point & p, const Point & q) const {
		if (p == q) return distance(p);
		else if (p.dot(q, *this) < 0) return distance(p);
		else if (q.dot(p, *this) < 0) return distance(q);
		else return distance_to_line(p, q);
	}

	bool on_line(const Point & p, const Point & q) const {
		return sgn(cross(p, q)) == 0;
	}

	bool on_halfline(const Point & p, const Point & q, const bool & inclusive = true) const {
		if (*this == p) return inclusive;
		else return on_line(p, q) && sgn(p.dot(q, *this)) >= 0;
	}

	bool on_segment(const Point & p, const Point & q, const bool & inclusive = true) const {
		if (*this == p || *this == q) return inclusive;
		else return on_line(p, q) && sgn(dot(p, q)) <= 0;
	}

	bool in_triangle(const Point & u, const Point & v, const Point & w, const bool & inclusive = true) const {
		Point p[3] = {u, v, w};
		if (sgn(u.cross(v, w)) < 0) reverse(p, p + 3);
		for (int i = 0; i < 3; i++) {
			if (on_segment(p[i], p[(i + 1) % 3])) return inclusive;
			else if (sgn(cross(p[i], p[(i + 1) % 3])) < 0) return false;
		}
		return true;
	}

	bool in_angle(const Point & o, const Point & p, const Point & q, const bool & inclusive = true) const {
		if (on_halfline(o, p) || on_halfline(o, q)) return inclusive;
		int vs = sgn(o.cross(p, q)), ss = sgn(o.dot(p, q));
		if (vs == 0 && ss > 0) return false;
		int vp = sgn(o.cross(p, *this)), vq = sgn(o.cross(*this, q));
		if (sgn(o.cross(p, q)) >= 0) return vp > 0 && vq > 0;
		else return vp > 0 || vq > 0;
	}

	Point operator + (const Point & rhs) const {// returns a+b(vector addition)
		return Point(x + rhs.x, y + rhs.y);
	}

	Point operator - (const Point & rhs) const {// Returns a-b(vector subtraction)
		return Point(x - rhs.x, y - rhs.y);
	}

	T operator * (const Point & rhs) const { 	// cross product
		return x * rhs.y - y * rhs.x;
	}

	T operator & (const Point & rhs) const { 	// dot product
		return x * rhs.x + y * rhs.y;
	}

	Point operator * (const T & rhs) const {	// multiplication with constant
		return Point(x * rhs, y * rhs);
	}

	Point operator / (const T & rhs) const {	// division with constant
		return Point(x / rhs, y / rhs);
	}

	bool operator == (const Point & rhs) const {// returns true if points are located at the same point.
		return x == rhs.x && y == rhs.y;
	}

	bool operator != (const Point & rhs) const {// returns true if points are not located at same point.
		return x != rhs.x || y != rhs.y;
	}

	inline int quadrant() const {				// returns quadrant defined from 0 to 7 (-1 if origin). Used in operator <
		if (x == 0 && y == 0) return -1;
		else if (x < 0 && y < 0) return 0;
		else if (x == 0 && y < 0) return 1;
		else if (x > 0 && y < 0) return 2;
		else if (x > 0 && y == 0) return 3;
		else if (x > 0 && y > 0) return 4;
		else if (x == 0 && y > 0) return 5;
		else if (x < 0 && y > 0) return 6;
		else return 7;
	}

	bool operator < (const Point & rhs) const {	//used for sorting the points in counter clockwise order.
		int lq = quadrant(), rq = rhs.quadrant();
		if (lq != rq) {
			return lq < rq;
		} else {
			int s = sgn(*this * rhs);
			return s != 0 ? s > 0 : sgn(length2() - rhs.length2()) < 0;
		}
	}
};

template <class T>
inline bool xycmp(const Point<T> & lhs, const Point<T> & rhs) {
	if (lhs.x != rhs.x) return lhs.x < rhs.x;
	else return lhs.y < rhs.y;
}

template <class T>
void convex_hull(vector<Point<T> > p, vector<Point<T> > & ans)  // ans[0] is the leftmost and downmost point, order is ACW.
{
	const int n = p.size();
	Point<T> o = *min_element(p.begin(), p.end(), xycmp<T>);
	for(int i = 0; i < n; i++) p[i] = p[i] - o;
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) p[i] = o + p[i];
	ans.resize(n);
	int sz = 0;
	ans[sz++] = p[0];
	for(int i = 1; i < n; i++) {
		for(; sz > 1 && sgn(ans[sz - 2].cross(ans[sz - 1], p[i])) <= 0; sz--);
		ans[sz++] = p[i];
	}
	ans.resize(sz);
}

template <class T>
bool point_in_convex_polygon(const vector<Point<T> > & p, const Point<T> & q, const bool & inclusive = true) 
{
	const int n = p.size();
	if (n == 1) {
		return inclusive && p[0] == q;
	} else if (n == 2) {
		return inclusive && q.on_segment(p[0], p[1]);
	} else if (!q.in_angle(p[0], p[1], p[n - 1])) {
		return false;
	} else if (q.on_line(p[0], p[1]) || q.on_line(p[0], p[n - 1])) {
		return inclusive && (q.on_segment(p[0], p[1]) || q.on_segment(p[0], p[n - 1]));
	} else {
		int low = 1, high = n - 1;
		for (; low < high - 1; ) {
			int mid = low + (high - low) / 2;
			(sgn(q.cross(p[0], p[mid])) < 0 ? high : low) = mid;
		}
		if (q.on_segment(p[low], p[high])) {
			return inclusive;
		} else {
			return q.in_triangle(p[0], p[low], p[high]);
		}
	}
}

template <class T, class U>
inline T & minimize(T & a, const U & b) {
	if (b < a) a = b;
	return a;
}

template <class T>
Point<T> line_line_intersection(const Point<T> & p1, const Point<T> & p2, const Point<T> & q1, const Point<T> & q2) {
	T pv1 = p1.cross(p2, q1), pv2 = p1.cross(p2, q2);
	return q1 * (-pv2 / (pv1 - pv2)) + q2 * (pv1 / (pv1 - pv2));
}

template <class T>
struct Line {
	Point<T> u, v;

	Line() {

	}

	Line(const Point<T> & u, const Point<T> & v) : u(u), v(v) {

	}

	Line(const T & px, const T & py, const T & qx, const T & qy) : u(px, py), v(qx, qy) {

	}

	T operator * (const Line & rhs) const {
		return (v - u) * (rhs.v - rhs.u);
	}

	T operator & (const Line & rhs) const {
		return (v - u) & (rhs.v - rhs.u);
	}

	bool operator < (const Line & rhs) const {
		int vs = sgn((v - u) * (rhs.v - rhs.u)), ss = sgn((v - u) & (rhs.v - rhs.u));
		if (vs == 0 && ss > 0) return on_left(rhs.u, false);
		else return v - u < rhs.v - rhs.u;
	}

	template <class U>
	bool on_left(const Point<U> & p, const bool & inclusive = true) const {
		return p.cross(u, v) > 0;
	}

	template <class U>
	bool on_right(const Point<U> & p, const bool & inclusive = true) const {
		return p.cross(u, v) < 0;
	}
};

typedef vector<Point<ld>> Polygon;
long double signed_area(Polygon p)
{
	long double area=0;
	for(int i=0;i<p.size();i++)
	{
		int j=i+1;
		j%=p.size();
		area+=p[i].x*p[j].y-p[j].x*p[i].y;
	}
	return area/2.0;
}
long double area(const Polygon &p)
{
	return fabsl(signed_area(p));
}

template <class T>
Point<T> line_line_intersection(const Line<T> & lhs, const Line<T> & rhs) {
	return line_line_intersection(lhs.u, lhs.v, rhs.u, rhs.v);
}

template <class T>
bool half_plane_intersection(vector<Line<T> > L, vector<Point<T> > & ans) {
	const int n = L.size();
	sort(L.begin(), L.end());
	int first = 0, last = 0;
	vector<Point<T> > p(n);
	vector<Line<T> > q(n);
	q[last++] = L[0];
	for (int i = 1; i < n; i++) {
		for (; first + 1 < last && L[i].on_right(p[last - 2]); last--);
		for (; first + 1 < last && L[i].on_right(p[first]); first++);
		q[last++] = L[i];
		if (sgn(q[last - 2] * q[last - 1]) == 0) {
			last--;
			if (q[last - 1].on_left(L[i].u)) q[last - 1] = L[i];
		}
		if (first + 1 < last) p[last - 2] = line_line_intersection(q[last - 2], q[last - 1]);
	}
	for (; first + 1 < last && q[first].on_right(p[last - 2]); last--);
	if (last - first <= 2) return false;
	p[last - 1] = line_line_intersection(q[first], q[last - 1]);
	ans.clear();
	for (int i = first; i < last; i++) ans.push_back(p[i]);
	return true;
}

template <class T>
long double distance_between_convex_polygons(const vector<Point<T> > & p, const vector<Point<T> > & q) {
	const int n = p.size();
	const int m = q.size();

	long double ans = p[0].distance(q[0]);

	for (int i = 0, k; i < n; i++) {
		if (i == 0) {
			k = -1;
			long long vmx;
			for (int j = 0; j < m; j++) {
				long long v = q[j].cross(p[0], p[1]);
				if (k == -1 || vmx < v) {
					k = j;
					vmx = v;
				}
			}
		} else {
			for (; q[k].cross(p[i], p[(i + 1) % n]) < q[(k + 1) % m].cross(p[i], p[(i + 1) % n]); k = (k + 1) % m);
		}
		minimize(ans, q[k].distance_to_segment(p[i], p[(i + 1) % n]));
		if (q[k].cross(p[i], p[(i + 1) % n]) == q[(k + m - 1) % m].cross(p[i], p[(i + 1) % n])) {
			minimize(ans, q[(k + m - 1) % m].distance_to_segment(p[i], p[(i + 1) % n]));
		}
		if (q[k].cross(p[i], p[(i + 1) % n]) == q[(k + 1) % m].cross(p[i], p[(i + 1) % n])) {
			minimize(ans, q[(k + 1) % m].distance_to_segment(p[i], p[(i + 1) % n]));
		}
	}

	for (int i = 0, k; i < m; i++) {
		if (i == 0) {
			k = -1;
			long long vmx;
			for (int j = 0; j < n; j++) {
				long long v = p[j].cross(q[0], q[1]);
				if (k == -1 || vmx < v){
					k = j;
					vmx = v;
				}
			}
		} else {
			for (; p[k].cross(q[i], q[(i + 1) % m]) < p[(k + 1) % n].cross(q[i], q[(i + 1) % m]); k = (k + 1) % n);
		}
		minimize(ans, p[k].distance_to_segment(q[i], q[(i + 1) % m]));
		if (p[k].cross(q[i], q[(i + 1) % m]) == p[(k + n - 1) % n].cross(q[i], q[(i + 1) % m])) {
			minimize(ans, p[(k + n - 1) % n].distance_to_segment(q[i], q[(i + 1) % m]));
		}
		if (p[k].cross(q[i], q[(i + 1) % m]) == p[(k + 1) % n].cross(q[i], q[(i + 1) % m])) {
			minimize(ans, p[(k + 1) % n].distance_to_segment(q[i], q[(i + 1) % m]));
		}
	}

	return ans;
}

void    ClosePostscript( void );
void	PrintSharedSeg( tPointd p, tPointd q );
double  Dot( tPointi a, tPointi b );
int	AreaSign( tPointi a, tPointi b, tPointi c );
char    SegSegInt( tPointi a, tPointi b, tPointi c, tPointi d, tPointd p, tPointd q );
char    ParallelInt( tPointi a, tPointi b, tPointi c, tPointi d, tPointd p, tPointd q );
bool    Between( tPointi a, tPointi b, tPointi c );
void    Assigndi( tPointd p, tPointi a );
void    SubVec( tPointi a, tPointi b, tPointi c );
bool    LeftOn( tPointi a, tPointi b, tPointi c );
bool    Left( tPointi a, tPointi b, tPointi c );
void    PrintPoly( int n, tPolygoni P );
bool    ConvexIntersect( tPolygoni P, tPolygoni Q, int n, int m );
tInFlag InOut( tPointd p, tInFlag inflag, int aHB, int bHA );
int     Advance( int a, int *aa, int n, bool inside, tPointi v );
void	OutputPolygons( void );
/*-------------------------------------------------------------------*/

/* Global variables */
int     	n, m;
tPolygoni	P, Q;

/*---------------------------------------------------------------------
---------------------------------------------------------------------*/
bool    ConvexIntersect( tPolygoni P, tPolygoni Q, int n, int m )
                           /* P has n vertices, Q has m vertices. */
{
   int     a, b;           /* indices on P and Q (resp.) */
   int     a1, b1;         /* a-1, b-1 (resp.) */
   tPointi A, B;           /* directed edges on P and Q (resp.) */
   int     cross;          /* sign of z-component of A x B */
   int     bHA, aHB;       /* b in H(A); a in H(b). */
   tPointi Origin = {0,0}; /* (0,0) */
   tPointd p;              /* double point of intersection */
   tPointd q;              /* second point of intersection */
   tInFlag inflag;         /* {Pin, Qin, Unknown}: which inside */
   int     aa, ba;         /* # advances on a & b indices (after 1st inter.) */
   bool    FirstPoint;     /* Is this the first point? (used to initialize).*/
   tPointd p0;             /* The first point. */
   int     code;           /* SegSegInt return code. */ 

   /* Initialize variables. */
   a = 0; b = 0; aa = 0; ba = 0;
   inflag = Unknown; FirstPoint = true;

   do {
      /*printf("%%Before Advances:a=%d, b=%d; aa=%d, ba=%d; inflag=%d\n", a, b, aa, ba, inflag);*/
      /* Computations of key variables. */
      a1 = (a + n - 1) % n;
      b1 = (b + m - 1) % m;

      SubVec( P[a], P[a1], A );
      SubVec( Q[b], Q[b1], B );

      cross = AreaSign( Origin, A, B );
      aHB   = AreaSign( Q[b1], Q[b], P[a] );
      bHA   = AreaSign( P[a1], P[a], Q[b] );
      // printf("%%cross=%d, aHB=%d, bHA=%d\n", cross, aHB, bHA );

      /* If A & B intersect, update inflag. */
      code = SegSegInt( P[a1], P[a], Q[b1], Q[b], p, q );
      // printf("%%SegSegInt: code = %c\n", code );
      if ( code == '1' || code == 'v' ) {
         if ( inflag == Unknown && FirstPoint ) {
            aa = ba = 0;
            FirstPoint = false;
            p0[X] = p[X]; p0[Y] = p[Y];
            // printf("%8.2lf %8.2lf moveto\n", p0[X], p0[Y] );
         }
         inflag = InOut( p, inflag, aHB, bHA );
        //  printf("%%InOut sets inflag=%d\n", inflag);
      }

      /*-----Advance rules-----*/

      /* Special case: A & B overlap and oppositely oriented. */
      if ( ( code == 'e' ) && (Dot( A, B ) < 0) )
            PrintSharedSeg( p, q ), exit(EXIT_SUCCESS);

      /* Special case: A & B parallel and separated. */
      if ( (cross == 0) && ( aHB < 0) && ( bHA < 0 ) )
            return true;
            // printf("%%P and Q are disjoint.\n"), exit(EXIT_SUCCESS);

      /* Special case: A & B collinear. */
      else if ( (cross == 0) && ( aHB == 0) && ( bHA == 0 ) ) {
            /* Advance but do not output point. */
            if ( inflag == Pin )
               b = Advance( b, &ba, m, inflag == Qin, Q[b] );
            else
               a = Advance( a, &aa, n, inflag == Pin, P[a] );
         }

      /* Generic cases. */
      else if ( cross >= 0 ) {
         if ( bHA > 0)
            a = Advance( a, &aa, n, inflag == Pin, P[a] );
         else
            b = Advance( b, &ba, m, inflag == Qin, Q[b] );
      }
      else /* if ( cross < 0 ) */{
         if ( aHB > 0)
            b = Advance( b, &ba, m, inflag == Qin, Q[b] );
         else
            a = Advance( a, &aa, n, inflag == Pin, P[a] );
      }
      // printf("%%After advances:a=%d, b=%d; aa=%d, ba=%d; inflag=%d\n", a, b, aa, ba, inflag);

   /* Quit when both adv. indices have cycled, or one has cycled twice. */
   } while ( ((aa < n) || (ba < m)) && (aa < 2*n) && (ba < 2*m) );

  //  if ( !FirstPoint ) /* If at least one point output, close up. */
  //           printf("%8.2lf %8.2lf lineto\n", p0[X], p0[Y] );

   /* Deal with special cases: not implemented. */
   if ( inflag == Unknown) 
      // printf("%%The boundaries of P and Q do not cross.\n");
      return true;
  return false;
}

/*---------------------------------------------------------------------
Prints out the double point of intersection, and toggles in/out flag.
---------------------------------------------------------------------*/
tInFlag InOut( tPointd p, tInFlag inflag, int aHB, int bHA )
{
  //  printf("%8.2lf %8.2lf lineto\n", p[X], p[Y] );

   /* Update inflag. */
   if      ( aHB > 0)
      return Pin;
   else if ( bHA > 0)
      return Qin;
   else    /* Keep status quo. */
      return inflag;
}
/*---------------------------------------------------------------------
   Advances and prints out an inside vertex if appropriate.
---------------------------------------------------------------------*/
int     Advance( int a, int *aa, int n, bool inside, tPointi v )
{
  //  if ( inside )
  //     printf("%5d    %5d    lineto\n", v[X], v[Y] );
   (*aa)++;
   return  (a+1) % n;
}

/*
   Reads in the coordinates of the vertices of a polygon from stdin,
   puts them into P, and returns n, the number of vertices.
   Formatting conventions: etc.
*/
int   ReadPoly( tPolygoni P, vector<Point<int> > &hull )
{
   int   n = hull.size();

   /*printf("%%Polygon:\n");
   printf("%%  i   x   y\n");*/

   for(int i=0;i<n;i++)
   {
     P[i][0] = hull[i].x, P[i][1] = hull[i].y;
    //  printf("%%%3d%4d%4d\n", n, P[i][0], P[i][1]);
   }
  //  printf("\n");
  //  while ( (n < nin) && (scanf("%d %d",&P[n][0],&P[n][1]) != EOF) ) {
  //     /*printf("%%%3d%4d%4d\n", n, P[n][0], P[n][1]);*/
  //     ++n;
  //  }
/*
   if (n < PMAX)
      printf("%%n = %3d vertices read\n",n);
   else   printf("Error in read_poly:  too many points; max is %d\n", PMAX);
   putchar('\n');
*/

   return   n;
}

// void   PrintPoly( int n, tPolygoni P )
// {
//    int   i;

//    printf("Polygon:\n");
//    printf("  i   l   x   y\n");
//    for( i = 0; i < n; i++ )
//       printf("%3d%4d%4d%4d\n", i, P[i][0], P[i][1]);
// }

/*
   Returns true iff c is strictly to the left of the directed
   line through a to b.
*/
bool    Left( tPointi a, tPointi b, tPointi c )
{
        return  AreaSign( a, b, c ) > 0;
}

bool    LeftOn( tPointi a, tPointi b, tPointi c )
{
        return  AreaSign( a, b, c ) >= 0;
}

bool    Collinear( tPointi a, tPointi b, tPointi c )
{
        return  AreaSign( a, b, c ) == 0;
}
/*---------------------------------------------------------------------
a - b ==> c.
---------------------------------------------------------------------*/
void    SubVec( tPointi a, tPointi b, tPointi c )
{
   int i;

   for( i = 0; i < DIM; i++ )
      c[i] = a[i] - b[i];
}


int	AreaSign( tPointi a, tPointi b, tPointi c )
{
    double area2;

    area2 = ( b[0] - a[0] ) * (double)( c[1] - a[1] ) -
            ( c[0] - a[0] ) * (double)( b[1] - a[1] );

    /* The area should be an integer. */
    if      ( area2 >  0.5 ) return  1;
    else if ( area2 < -0.5 ) return -1;
    else                     return  0;
}

/*---------------------------------------------------------------------
SegSegInt: Finds the point of intersection p between two closed
segments ab and cd.  Returns p and a char with the following meaning:
   'e': The segments collinearly overlap, sharing a point.
   'v': An endpoint (vertex) of one segment is on the other segment,
        but 'e' doesn't hold.
   '1': The segments intersect properly (i.e., they share a point and
        neither 'v' nor 'e' holds).
   '0': The segments do not intersect (i.e., they share no points).
Note that two collinear segments that share just one point, an endpoint
of each, returns 'e' rather than 'v' as one might expect.
---------------------------------------------------------------------*/
char	SegSegInt( tPointi a, tPointi b, tPointi c, tPointi d, tPointd p, tPointd q )
{
   double  s, t;       /* The two parameters of the parametric eqns. */
   double num, denom;  /* Numerator and denoninator of equations. */
   char code = '?';    /* Return char characterizing intersection. */

   /*printf("%%SegSegInt: a,b,c,d: (%d,%d), (%d,%d), (%d,%d), (%d,%d)\n",
	a[X],a[Y], b[X],b[Y], c[X],c[Y], d[X],d[Y]);*/

   denom = a[X] * (double)( d[Y] - c[Y] ) +
           b[X] * (double)( c[Y] - d[Y] ) +
           d[X] * (double)( b[Y] - a[Y] ) +
           c[X] * (double)( a[Y] - b[Y] );

   /* If denom is zero, then segments are parallel: handle separately. */
   if (denom == 0.0)
      return  ParallelInt(a, b, c, d, p, q);

   num =    a[X] * (double)( d[Y] - c[Y] ) +
            c[X] * (double)( a[Y] - d[Y] ) +
            d[X] * (double)( c[Y] - a[Y] );
   if ( (num == 0.0) || (num == denom) ) code = 'v';
   s = num / denom;
   /*printf("num=%lf, denom=%lf, s=%lf\n", num, denom, s);*/

   num = -( a[X] * (double)( c[Y] - b[Y] ) +
            b[X] * (double)( a[Y] - c[Y] ) +
            c[X] * (double)( b[Y] - a[Y] ) );
   if ( (num == 0.0) || (num == denom) ) code = 'v';
   t = num / denom;
   /*printf("num=%lf, denom=%lf, t=%lf\n", num, denom, t);*/

   if      ( (0.0 < s) && (s < 1.0) &&
             (0.0 < t) && (t < 1.0) )
     code = '1';
   else if ( (0.0 > s) || (s > 1.0) ||
             (0.0 > t) || (t > 1.0) )
     code = '0';

   p[X] = a[X] + s * ( b[X] - a[X] );
   p[Y] = a[Y] + s * ( b[Y] - a[Y] );

   return code;
}
char   ParallelInt( tPointi a, tPointi b, tPointi c, tPointi d, tPointd p, tPointd q )
{
/*   
   printf("ParallelInt: a,b,c,d: (%d,%d), (%d,%d), (%d,%d), (%d,%d)\n",
	a[X],a[Y], b[X],b[Y], c[X],c[Y], d[X],d[Y]);
*/

   if ( !Collinear( a, b, c) )
      return '0';

   if ( Between( a, b, c ) && Between( a, b, d ) ) {
      Assigndi( p, c );
      Assigndi( q, d );
      return 'e';
   }
   if ( Between( c, d, a ) && Between( c, d, b ) ) {
      Assigndi( p, a );
      Assigndi( q, b );
      return 'e';
   }
   if ( Between( a, b, c ) && Between( c, d, b ) ) {
      Assigndi( p, c );
      Assigndi( q, b );
      return 'e';
   }
   if ( Between( a, b, c ) && Between( c, d, a ) ) {
      Assigndi( p, c );
      Assigndi( q, a );
      return 'e';
   }
   if ( Between( a, b, d ) && Between( c, d, b ) ) {
      Assigndi( p, d );
      Assigndi( q, b );
      return 'e';
   }
   if ( Between( a, b, d ) && Between( c, d, a ) ) {
      Assigndi( p, d );
      Assigndi( q, a );
      return 'e';
   }
   return '0';
}
void	Assigndi( tPointd p, tPointi a )
{
   int i;
   for ( i = 0; i < DIM; i++ )
      p[i] = a[i];
}
/*---------------------------------------------------------------------
Returns true iff point c lies on the closed segement ab.
Assumes it is already known that abc are collinear.
---------------------------------------------------------------------*/
bool    Between( tPointi a, tPointi b, tPointi c )
{
   tPointi      ba, ca;

   /* If ab not vertical, check betweenness on x; else on y. */
   if ( a[X] != b[X] )
      return ((a[X] <= c[X]) && (c[X] <= b[X])) ||
             ((a[X] >= c[X]) && (c[X] >= b[X]));
   else
      return ((a[Y] <= c[Y]) && (c[Y] <= b[Y])) ||
             ((a[Y] >= c[Y]) && (c[Y] >= b[Y]));
}

void   OutputPolygons( void )
{
   int i;
   int xmin, ymin, xmax, ymax;

   /* Compute Bounding Box for Postscript header. */
   xmin = xmax = P[0][X];
   ymin = ymax = P[0][Y];
   for (i = 1; i < n; i++) {
      if      ( P[i][X] > xmax ) xmax = P[i][X];
      else if ( P[i][X] < xmin ) xmin = P[i][X];
      if      ( P[i][Y] > ymax ) ymax = P[i][Y];
      else if ( P[i][Y] < ymin ) ymin = P[i][Y];
   }
   for (i = 0; i < m; i++) {
      if      ( Q[i][X] > xmax ) xmax = Q[i][X];
      else if ( Q[i][X] < xmin ) xmin = Q[i][X];
      if      ( Q[i][Y] > ymax ) ymax = Q[i][Y];
      else if ( Q[i][Y] < ymin ) ymin = Q[i][Y];
   }


   /* PostScript header */
  //  printf("%%!PS\n");
  //  printf("%%%%Creator: convconv.c (Joseph O'Rourke)\n");
  //  printf("%%%%BoundingBox: %d %d %d %d\n",
  //     xmin, ymin, xmax, ymax);
  //  printf("%%%%EndComments\n");
  //  printf(".00 .00 setlinewidth\n");
  //  printf("%d %d translate\n", -xmin+100, -ymin+100 );
  //  /* The +100 shifts the figure from the lower left corner. */

  //  printf("\n%%Polygon P:\n");
  //  printf("newpath\n");
  //  printf("%d\t%d\tmoveto\n", P[0][X], P[0][Y]);
  //  for( i = 1; i <= n; i++ )
  //     printf("%d\t%d\tlineto\n", P[i%n][X], P[i%n][Y]);
  //  printf("closepath stroke\n");

  //  printf("\n%%Polygon Q:\n");
  //  printf("newpath\n");
  //  printf("%d\t%d\tmoveto\n", Q[0][X], Q[0][Y]);
  //  for( i = 1; i <= m; i++ )
  //     printf("%d\t%d\tlineto\n", Q[i%m][X], Q[i%m][Y]);
  //  printf("closepath stroke\n");

  //  printf("2 2 setlinewidth\n");
  //  printf("newpath\n");
 }
/*---------------------------------------------------------------------
Returns the dot product of the two input vectors.
---------------------------------------------------------------------*/
double  Dot( tPointi a, tPointi b )
{
    int i;
    double sum = 0.0;

    for( i = 0; i < DIM; i++ )
       sum += a[i] * b[i];

    return  sum;
}

void	PrintSharedSeg( tPointd p, tPointd q )
{
  //  printf("%%A int B:\n");
  //  printf("%8.2lf %8.2lf moveto\n", p[X], p[Y] );
  //  printf("%8.2lf %8.2lf lineto\n", q[X], q[Y] );
   ClosePostscript();
}

void   ClosePostscript( void )
{
  //  printf("closepath stroke\n");
  //  printf("showpage\n%%%%EOF\n");
}

bool isBetween(Point<int> a, Point<int> b, Point<int> c)
{
  ld crossproduct = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);

  if (abs(crossproduct) > 1e-6)
      return false;

  ld dotproduct = (c.x - a.x) * (b.x - a.x) + (c.y - a.y)*(b.y - a.y);
  if(dotproduct < 0)
      return false;

  ld squaredlengthba = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
  if (dotproduct > squaredlengthba)
      return false;

  return true;
} 

int main()
{
  int t;
  cin >> t;
  while(t--)  
  {
    int n;
    cin >> n;

    vector<Point<int> > posPoint, negPoint;
    for(int i=0;i<n;i++)
    {
      double x,y,k;
      cin >> x >> y >> k;
      x *= 100;
      y *= 100;
      Point<int> p(x,y);
    
      if(k == -1) negPoint.pu(p);
      else posPoint.pu(p);
    }//

    if(posPoint.size() == 0 || negPoint.size() == 0) 
    {
      cout << "YES" << endl;
      continue;
    }

    vector<Point<int> > posHull, negHull; 
    convex_hull(posPoint,posHull);
    convex_hull(negPoint,negHull);

    if(posHull.size() > negHull.size()) swap(posHull,negHull);

    {
      if(posHull.size() == 1 && negHull.size() == 1 && posHull[0] == negHull[0]) 
      {//
        cout << "NO" << endl;
        continue;
      }
      else if(posHull.size() == 1 && negHull.size() == 1) 
      {
        cout << "YES" << endl;
        continue;
      }
      else if(posHull.size() == 1 && negHull.size() == 2)
      {
        cout << (isBetween(negHull[0], negHull[1], posHull[0]) ? "NO" : "YES") << endl;
        continue;
      }
      else if(posHull.size() == 1)
      {
        if(point_in_convex_polygon(negHull, posHull[0], false)) cout << "NO" << endl;
        else cout << "YES" << endl;
        continue;
      }
      else if(posHull.size() == 2)
      {
        
      }
    }

    ReadPoly(P, posHull);
    ReadPoly(Q, negHull);

    if(!ConvexIntersect( P, Q, posHull.size(), negHull.size()))
    {
      // cout << "YES" << endl;
      cout << "NO" << endl;
    }
    else
    {
      bool posInNeg = true, negInPos = true;
      for(auto point : posHull)
      {
        if(!point_in_convex_polygon(negHull,point,false))
        {
          posInNeg = false;
          break;
        }
      }
//
      for(auto point : negHull)
      {
        if(!point_in_convex_polygon(posHull,point,false))
        {
          negInPos = false;
          break;
        }
      }

      // cout << "YES" << endl;
      if(posInNeg || negInPos) cout << "NO" << endl;
      else cout << "YES" << endl;
    }

  }

  return 0;
}

// int main()
// {
//    n = ReadPoly( P );
//    m = ReadPoly( Q );
//   //  OutputPolygons();
//    cout << ConvexIntersect( P, Q, n, m ) << endl;

//   //  ClosePostscript();
//    return 0;
// }



/*
2
7
2 2 1
2 -2 1
-2 2 1
-2 -2 1
0 0 -1
0 1 -1
1 0 -1
6
1 0 1
0 2 1
2 2 1
1 3 -1
0 1 -1
2 1 -1

*/