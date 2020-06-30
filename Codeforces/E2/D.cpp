#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define PI acos(-1)
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

ld dist2(ld x1,ld y1,ld x2,ld y2)
{
  return abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2);
}

ld heron(ld a,ld b,ld c)
{
  ld s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

ld min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

ld max(ld x, ld y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  ld x1,y1,r1,x2,y2,r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  ld dist = dist2(x1,y1,x2,y2);
  // t(dist);
  cout << fixed << setprecision(12);

  if(r1 + r2 < sqrt(dist)) 
  {
    cout << 0 << endl;
    return 0;
  }
  else if(min(r1,r2) + sqrt(dist) <= max(r1,r2))
  {
    cout << PI*min(r1,r2)*min(r1,r2) << endl;
    return 0;
  }

  ld cos_theta1 = (r1*r1 + dist - r2*r2)/(2*r1*sqrt(dist));
  ld cos_theta2 = (r2*r2 + dist - r1*r1)/(2*r2*sqrt(dist));

  ld theta1 = acos(cos_theta1);
  ld theta2 = acos(cos_theta2);

  // t(theta1,theta2);

  theta1 *= 2;
  theta2 *= 2;


  ld area1 = PI*r1*r1;
  ld area2 = PI*r2*r2;

  // t(area1,area2);

  ld area_triangle = heron(r1,r2,sqrt(dist));

  // cout << area1 + area2 - ((area1*(2*PI - theta1) + area2*(2*PI-theta2))/(2*PI) + 2*area_triangle) << endl;
  // t(area1*theta1,0.5*r1*r1*sin(theta1));
  cout << (area1*theta1+area2*theta2)/(2*PI) - (0.5*r1*r1*sin(theta1)) - (0.5*r2*r2*sin(theta2)) << endl;
  return 0;
}
