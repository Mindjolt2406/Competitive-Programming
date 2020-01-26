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


int main()
{
  __;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int a2 = a,b2 = b,c2 =c ,d2 = d;
  vector<int> v(4), w(4);

  while(a2%3==0) {a2/=3;a2 *= 2; w[0]++;}
  while(a2%2==0) {a2/=2; v[0]++;}

  while(b2%3==0) {b2/=3;b2 *= 2; w[1]++;}
  while(b2%2==0) {b2/=2;v[1]++;}

  while(c2%3==0) {c2/=3;c2 *= 2; w[2]++;}
  while(c2%2==0) {c2/=2;v[2]++;}

  while(d2%3==0) {d2/=3;d2 *= 2; w[3]++;}
  while(d2%2==0) {d2/=2;v[3]++;}

  int cnt1 = INF, cnt2 = INF;
  vector<pair<int,int> > temp1(2), temp2(2);

  if(a2==c2 && b2==d2)
  {
    cnt1 = 0;
    cnt1 += abs(w[2]-w[0]);
    cnt1 += abs(v[2]-v[0]);

    cnt1 += abs(w[3]-w[1]);
    cnt1 += abs(v[3]-v[1]);

    int tempa = a, tempb = b, tempc = c, tempd = d;
    
    if(w[2]-w[0]>0)
    {
      tempc /= pow(3,w[2]-w[0]);
      tempc *= pow(2,w[2]-w[0]);
    }
    else
    {
      tempa /= pow(3,w[0]-w[2]);
      tempa *= pow(2,w[0]-w[2]);
    }

    if(v[2]-v[0]>0) tempc /= pow(2,v[2]-v[0]);
    else tempa /= pow(2,v[0]-v[2]);

    if(w[3]-w[1]>0)
    {
      tempd /= pow(3,w[3]-w[1]);
      tempd *= pow(2,w[3]-w[1]);
    }
    else
    {
      tempb /= pow(3,w[1]-w[3]);
      tempb *= pow(2,w[1]-w[3]);
    }

    if(v[3]-v[1] > 0) tempd /= pow(2,v[3]-v[1]);
    else tempb /= pow(2,v[1]-v[3]);

    temp1 = {mp(tempa,tempb),mp(tempc,tempd)};
  }
  if(a2==d2 && b2==c2)
  {
    int tempa = a, tempb = b, tempc = c, tempd = d;

    cnt2 = 0;
    cnt2 += abs(w[1] - w[2]);
    cnt2 += abs(v[1] - v[2]);

    cnt2 += abs(w[0] - w[3]);
    cnt2 += abs(v[0] - v[3]);

    if(w[2] > w[1])
    {
      tempc /= pow(3,w[2]-w[1]);
      tempc *= pow(2,w[2]-w[1]);
    }
    else
    {
      tempb /= pow(3,w[1]-w[2]);
      tempb *= pow(2,w[1]-w[2]);
    }

    if(v[2] > v[1]) tempc /= pow(2,v[2]-v[1]);
    else tempb /= pow(2,v[2]-v[1]);

    if(w[3]>w[0])
    {
      tempd /= pow(3,w[3]-w[0]);
      tempd *= pow(2,w[3]-w[0]);
    }
    else
    {
      tempa /= pow(3,w[0]-w[3]);
      tempa *= pow(2,w[0]-w[3]);
    }

    if(v[3] > v[0]) tempd /= pow(2,v[3]-v[0]);
    else tempa /= pow(2,v[0]-v[3]);

    temp2 = {mp(tempa,tempb),mp(tempc,tempd)};
  }

  if(cnt1==INF && cnt2 == INF) cout<<-1<<endl;
  else 
  {
    vector< pair<int,int> > x = cnt1 <= cnt2 ? temp1 : temp2;

    cout<<min(cnt1,cnt2)<<endl;
    cout<<x[0].fi<<" "<<x[0].se<<endl;
    cout<<x[1].fi<<" "<<x[1].se<<endl;
  }
  return 0;
}

