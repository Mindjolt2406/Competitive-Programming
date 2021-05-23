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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


typedef struct Point
{
  ld x,y;

  Point(): x(0), y(0) {}
  Point(ld x, ld y): x(x), y(y) {}
  Point(const Point &p): x(p.getX()), y(p.getY()) {}

  ld length() const
  {
    return sqrtl(x*x +  y*y);
  }

  ld length2() const
  {
    return x*x + y*y;
  }

  ld getX() const {return x;}
  ld getY() const {return y;}

  ld cross(Point lhs, Point rhs) 
  {
    return (lhs-*this)*(rhs-*this);
  }

  Point operator + (Point rhs)
  {
    return Point(x+rhs.x, y+rhs.y);
  }

  Point operator - (Point rhs)
  {
    return Point(x-rhs.x, y-rhs.y);
  }

  ld operator * (Point rhs)
  {
    return x*rhs.y - y*rhs.x;
  }

  bool operator == (Point p)
  {
    return (p.getX() == x && p.getY() == y);
  }

  bool operator == (const Point &p) const
  {
    return (p.getX() == x && p.getY() == y);
  }

  bool operator < (const Point p) const
  {
    if(y < p.getY()) return true;
    if(p.getY() == y) return x < p.getX();
    return false;
  }

  void rotate(ld angle)
  {
    if(angle > 0) y *= -1;
    ld s = sin(angle);
    ld c = cos(angle);

    // rotate point
    ld xnew = x * c - y * s;
    ld ynew = x * s + y * c;

    x = xnew;
    y = ynew;

    x = ((ll)(1e6*x))/1e6;
    y = ((ll)(1e6*y))/1e6;
    if(angle < 0) y*= -1;
  }

  std::pair<ld,ld> getPair()
  {
    return std::make_pair(x,y);
  }

  std::pair<ld,ld> getPair() const
  {
    return std::make_pair(x,y);
  }

  std::string to_string()
  {
    // this->rotate(-defaultAngle);
    std::string tempString =  "( " + std::to_string(x) + ", " + std::to_string(y) + " )";
    // this->rotate(defaultAngle);
    return tempString;
  }

} Point;


typedef struct Line
{
  Point u,v;
  ld slope;

  Line() {}
  Line(Point u, Point v): u(u), v(v) 
  {
    computeSlope();
  }
  Line( ld px, ld py, ld qx, ld qy): u(px,py), v(qx,qy) 
  {
    computeSlope();
  }
  Line(const Line &line): u(line.u), v(line.v), slope(line.slope) {}

  void computeSlope()
  {
    if(v.getX() == u.getX()) slope = INF;
    else slope = (v.getY() - u.getY())/((ld)(v.getX() - u.getX()));
  }

  bool isZeroSlope()
  {
    return abs(slope) < EPS;
  }

  void orderLine()
  {
    if(v.getY() > u.getY())
    {
      std::swap(u,v);
    }
    else if(v.getY() == u.getY() && v.getX() > u.getX()) std::swap(u,v);
  }

  Point getU() {return u;}
  Point getV() {return v;}

  // bool isStartPoint(Point p) 
  // {

  // }

  bool operator<(const Line& line) const
  {
    return mp(u.getPair(), v.getPair()) < mp((line.u).getPair(), (line.v).getPair());
  }
  // Problem
  bool on_left(Point p, bool inclusive = false) 
  {
    if(inclusive) return p.cross(u,v) >= 0;
    return p.cross(u,v) > 0;
  }

  bool on_right(Point p, bool inclusive = false) 
  {
    if(inclusive) return p.cross(u,v) <= 0;
    return p.cross(u,v) < 0;
  }

  int getMaxY()
  {
    return (u.getY() > v.getY()) ? u.getY() : v.getY();
  }

  int getMaxX()
  {
    return (u.getX() > v.getX()) ? u.getX() : v.getX();
  }

  int getMinY()
  {
    return (u.getY() < v.getY()) ? u.getY() : v.getY();
  }

  int getMinX()
  {
    return (u.getX() < v.getX()) ? u.getX() : v.getX();
  }

  ld evaluateX(ld y) const
  {
    return ((y - u.getY())/slope) + u.getX();
  }

  ld evaluateY(ld x) const
  {
    return u.getY() + slope * (x - u.getX());
  }

  bool operator ==(const Line& line) const
  {
    return (this->u == line.u) && (this->v == line.v);
  }

  void deRotate(ld angle)
  {
    u.rotate(angle);
    v.rotate(angle);
  }

  std::pair< std::pair<ld,ld>, std::pair<ld,ld> > getPair()
  {
    return mp(mp(u.getX(), u.getY()), mp(v.getX(), v.getY()));
  }

  std::string to_string()
  {
    std::string temp;
    temp += "u: " + u.to_string() + " v: " + v.to_string(); 
    return temp;
  }
} Line;

typedef struct Vertex Vertex;
typedef struct HalfEdge HalfEdge;

typedef struct Face 
{
  HalfEdge *edge;  /* rep->left == this */
  int id;

  void setID(int id) {this->id = id;}
  int getID() {return id;}
} Face;

typedef struct HalfEdge 
{
  HalfEdge *prevEdge;  /* prev->next == this */
  HalfEdge *nextEdge;  /* next->prev == this */
  HalfEdge *twinEdge;  /* twin->twin == this */
  Vertex *origin;     /* twin->next->tail == tail &&
                              prev->twin->tail == tail */
  Face *face;       /* prev->left == left && next->left == left */

  void setTwinEdge(HalfEdge* edge) {twinEdge = edge;}
  
  void setFace(Face* face) {this->face = face;}
  void setPrevEdge(HalfEdge* edge) {prevEdge = edge;}
  void setNextEdge(HalfEdge* edge) {nextEdge = edge;}

  HalfEdge* getPrevEdge() {return prevEdge;}
  HalfEdge* getNextEdge() {return nextEdge;}
  HalfEdge* getTwinEdge() {return twinEdge;}
  Face* getFace() {return face;}

  void setOrigin(Vertex* vertex);
  Vertex* getOrigin();
  bool operator ==(HalfEdge* edge);
  pair<pair<ld,ld> , pair<ld,ld> >  getEdgePair();

} HalfEdge;

typedef struct Vertex {
  Point point;
  HalfEdge *halfEdge;  /* rep->tail == this */
  vector<HalfEdge*> edges;

  public:
  Vertex(Point p): point(p) {}

  void setHalfEdge(HalfEdge* edge) {halfEdge = edge;}

  HalfEdge* getHalfEdge() {return halfEdge;}
  Point getPoint() {return point;}
  pair<ld,ld> getPair() {return point.getPair();}

  void addHalfEdge(HalfEdge* edge) {edges.pu(edge);}

  bool lessPoint(const Point point1, const Point point2) const
  {
    if(point1.getX() - point.getX() >= 0 && point2.getX() - point.getX() < 0) return true;
    if(point1.getX() - point.getX() < 0 && point2.getX() - point.getX() >= 0) return false;
    if(point1.getX() - point.getX() == 0 && point2.getX() - point.getX() == 0)
    {
      if(point1.getY() - point.getY() >= 0  || point2.getY() - point.getY() >= 0) return point1.getY() > point2.getY();
      return point2.getY() > point1.getY();
    }

    ld det = (point1.getX() - point.getX()) * (point2.getY() - point.getY()) - (point2.getX() - point.getX()) * (point1.getY() - point.getY());
    if(det < 0) return true;
    if(det > 0) return false;

    ld d1 = (point1.getX() - point.getX()) * (point1.getX() - point.getX()) + (point1.getY() - point.getY()) * (point1.getY() - point.getY());
    ld d2 = (point2.getX() - point.getX()) * (point2.getX() - point.getX()) + (point2.getY() - point.getY()) * (point2.getY() - point.getY());
    return d1 > d2;
  }



  void sortEdges()
  {
    sort(edges.begin(), edges.end(), [this](HalfEdge* edge1, HalfEdge* edge2){
      bool ans =  this->lessPoint(edge1->getTwinEdge()->getOrigin()->getPoint(),  edge2->getTwinEdge()->getOrigin()->getPoint());
      // cerr << point.getPair() << " " << edge1->getOrigin()->getPoint().getPair() << " " << edge2->getOrigin()->getPoint().getPair() << " " << ans << endl;
      return ans;
    });
  }

  void printEdges()
  {
    cerr << "Original Point: " << point.getPair() << " " << edges.size() << endl;
    for(auto edgePointer : edges)
    {
      cerr << edgePointer->getTwinEdge()->getOrigin()->getPoint().getPair() << endl;
    }
  }

  void assignEdges()
  {
    if(edges.size() == 1) 
    {
      edges[0]->getTwinEdge()->setNextEdge(edges[0]);
      edges[0]->setPrevEdge(edges[0]->getTwinEdge());
    }
    else
    {
      int edgeSize = edges.size();
      for(int i=0;i<edges.size();i++)
      {
        edges[(i-1+edgeSize)%edgeSize]->getTwinEdge()->setNextEdge(edges[i]);
        edges[i]->setPrevEdge(edges[(i-1+edgeSize)%edgeSize]->getTwinEdge());
      }
    }

    setHalfEdge(edges[0]);
  }

  bool operator ==(Vertex* vertex)
  {
    return getPair() == vertex->getPair();
  }


} Vertex;

void HalfEdge::setOrigin(Vertex* vertex) {origin = vertex;}

Vertex* HalfEdge::getOrigin() {return origin;}

bool HalfEdge::operator ==(HalfEdge* edge)
{
  return (edge->origin == origin && edge->twinEdge->origin == twinEdge->origin);
}

pair<pair<ld,ld> , pair<ld,ld> >  HalfEdge::getEdgePair()
{
  return mp(getOrigin()->getPair(), getTwinEdge()->getOrigin()->getPair());
}

bool getIntersection(Line &l1, Line &l2, Point &p) {
  if(l1.slope != l2.slope) {
    if(l1.isZeroSlope()) {
      p.y = l1.u.y;
      p.x = l2.u.x;
      if(p.y < l1.getMinY() || p.y > l1.getMaxY()) return false;
      if(p.x < l2.getMinX() || p.x > l2.getMaxX()) return false;
    } else {
      p.x = l1.u.x;
      p.y = l2.u.y;
      if(p.y < l2.getMinY() || p.y > l2.getMaxY()) return false;
      if(p.x < l1.getMinX() || p.x > l1.getMaxX()) return false;
    } 
    return true;
  }
  return false;
}

bool get_line_intersection(Line &l1, Line &l2, Point &p)
{
    float p0_x = l1.u.x, p0_y = l1.u.y, p1_x = l1.v.x, p1_y = l1.v.y;
    float p2_x = l2.u.x, p2_y = l2.u.y, p3_x = l2.v.x, p3_y = l2.v.y;

    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        p.x = p0_x + (t * s1_x);
        p.y = p0_y + (t * s1_y);
        return true;
    }

    return false;
}

void getIntersectionPoints(vector<Line> &lines, map<Line, vector<Point> > &mapLinePoint, map<pair<ld, ld>, Vertex*> &vertexMap) {
  int n = lines.size();
  vector<Point> points;
  for(auto line : lines) {
    mapLinePoint[line].pu(line.getU());
    mapLinePoint[line].pu(line.getV());
  }

  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      Point point;
      if(get_line_intersection(lines[i], lines[j], point)) 
      {
        points.pu(point);
        vertexMap[point.getPair()] = new Vertex(point);
        mapLinePoint[lines[i]].pu(point);
        mapLinePoint[lines[j]].pu(point);
      }
    }
  }

  for(auto line : lines) {
    sort(mapLinePoint[line].begin(), mapLinePoint[line].end());
  }
}

ll getPerimeter(HalfEdge* startEdge) {
   HalfEdge* tempEdge = startEdge;
  int flag = 0;
  ll perimeter = 0;
  while(true) {
    if(startEdge == tempEdge) {
      flag++;
      if(flag == 2) break;
    }
    auto pairU = tempEdge -> getOrigin() -> getPoint().getPair();
    auto pairV = tempEdge -> getTwinEdge() -> getOrigin() -> getPoint().getPair();
    if(pairU.fi == pairV.fi) {
      perimeter += abs(pairU.se - pairV.se);
    } else {
      perimeter += abs(pairU.fi - pairV.fi);
    }
    tempEdge = tempEdge -> getNextEdge();
  }

  return perimeter;
}

int main()
{
  __;
  int n, t;
  cin >> n >> t;

  vector<Line> lines;
  map<pair<ld, ld>, Vertex*> vertexMap;
  Point startPoint;
  int minVal = 1e9;
  vector<vector<int> > tempPoints;
  for(int i=0;i<n;i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> temp;
    minVal = min(minVal, min(x1, min(x2, min(y1, y2))));
    temp.pu(x1); temp.pu(y1); temp.pu(x2); temp.pu(y2);
    tempPoints.pu(temp);
  }

  for(int i=0;i<n;i++) {
    auto it = tempPoints[i];
    int x1 = it[0], y1 = it[1], x2 = it[2], y2 = it[3];
    x1 -= minVal; y1 -= minVal; x2 -= minVal; y2 -= minVal;
    lines.pu(Line(x1, y1, x2, y2));
    if(i == 0) startPoint = Point(x1, y1);
    vertexMap[mp(x1, y1)] = new Vertex(Point(x1, y1));
    vertexMap[mp(x2, y2)] = new Vertex(Point(x2, y2));
  }

  map<Line, vector<Point> > mapLinePoint;
  getIntersectionPoints(lines, mapLinePoint, vertexMap);

  vector<HalfEdge*> halfEdges;
  for(auto line : lines) {
    vector<Point> points = mapLinePoint[line];
    for(int i=1;i<points.size();i++) {
      HalfEdge* edgeU = new HalfEdge();
      HalfEdge* edgeV = new HalfEdge();

      edgeU -> setOrigin(vertexMap[points[i].getPair()]);
      edgeV -> setOrigin(vertexMap[points[i-1].getPair()]);
      edgeU -> setTwinEdge(edgeV);
      edgeV -> setTwinEdge(edgeU);
      vertexMap[points[i].getPair()] -> addHalfEdge(edgeU);
      vertexMap[points[i-1].getPair()] -> addHalfEdge(edgeV);
    }
  }

  for(auto it : vertexMap) (it.second)->sortEdges();
  for(auto it : vertexMap) (it.second)->assignEdges();

  // for(auto it : vertexMap) (it.second)-> printEdges();


  Vertex * v = vertexMap[startPoint.getPair()];
  HalfEdge* startEdge = v -> edges[0];
  ll perimeter = getPerimeter(startEdge);
  // t(perimeter);
  t %= perimeter; 

  HalfEdge* tempEdge = startEdge;
  int flag = 0;
  while(true) {
    if(startEdge == tempEdge) {
      flag++;
      if(flag == 2) break;
    }
    auto pairU = tempEdge -> getOrigin() -> getPoint().getPair();
    auto pairV = tempEdge -> getTwinEdge() -> getOrigin() -> getPoint().getPair();
    // t(t, pairU, pairV);
    if(pairU.fi == pairV.fi) {
      ll dist = abs(pairU.se - pairV.se);
      if(dist < t) t -= dist;
      else {
        if(pairU.se < pairV.se) {
          cout << (ll)pairU.fi  + minVal<< " " << (ll)pairU.se + t + minVal;
        } else {
          cout << (ll)pairU.fi  + minVal<< " " << (ll)pairU.se - t + minVal;
        }
        cout << endl;
        return 0;
      }
    } else {
      ll dist = abs(pairU.fi - pairV.fi);
      if(dist < t) t -= dist;
      else {
        if(pairU.fi < pairV.fi) {
          cout << (ll)pairU.fi + t + minVal<< " " << (ll)pairU.se + minVal;
        } else {
          cout << (ll)pairU.fi - t + minVal<< " " << (ll)pairU.se + minVal;
        }
        cout << endl;
        return 0;
      }
    }
    tempEdge = tempEdge -> getNextEdge();
  }
  return 0;
}
