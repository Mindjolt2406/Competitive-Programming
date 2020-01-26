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
#define EPS 1e-5
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


typedef struct node
{
  ld r,g,b;
  int left_r, left_g, left_b;
  int right_r,right_g,right_b;
  int idx;
  bool ansr,ansg,ansb;
} node;

map<int,node*> d;
map<int,int> e;
map<int,int> freqr,freqg,freqb;

ld ans(ld a, ld b, ld c)
{
  ld cnt = 0;
  if(a!=b)
  {
    if(a<b) cnt += b-a;
    else cnt += 360-a+b;
  }

  if(b!=c)
  {
    if(b<c) cnt += c-b;
    else cnt += 360-b+c;
  }

  // t(a,b,c,cnt,360-cnt);
  // if(cnt < 1) return 0;
  
  return cnt;
}

// template<node*>
bool comp(node* n1, node* n2)
{
  ld cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
  if(freqr[n1->r]<=1) n1->ansr = false;
  if(freqg[n1->g]<=1) n1->ansg = false;
  if(freqb[n1->b]<=1) n1->ansb = false;

  if(freqr[n2->r]<=1) n2->ansr = false;
  if(freqg[n2->g]<=1) n2->ansg = false;
  if(freqb[n2->b]<=1) n2->ansb = false;

  cnt1 = n1->ansr ? 0 : ans(d[n1->left_r]->r,n1->r,d[n1->right_r]->r);
  cnt2 = n1->ansg ? 0 : ans(d[n1->left_g]->g,n1->g,d[n1->right_g]->g);
  cnt3 = n1->ansb ? 0 : ans(d[n1->left_b]->b,n1->b,d[n1->right_b]->b);

  cnt4 = n2->ansr ? 0 : ans(d[n2->left_r]->r,n2->r,d[n2->right_r]->r);
  cnt5 = n2->ansg ? 0 : ans(d[n2->left_g]->g,n2->g,d[n2->right_g]->g);
  cnt6 = n2->ansb ? 0 : ans(d[n2->left_b]->b,n2->b,d[n2->right_b]->b);

  // t(n1->idx,cnt1,cnt2,cnt3);
  // t(d[n1->left_r]->r,n1->r,d[n1->right_r]->r);
  // t(d[n1->left_g]->g,n1->g,d[n1->right_g]->g);
  // t(d[n1->left_b]->b,n1->b,d[n1->right_b]->b);
  // t(n2->idx,cnt4+cnt5+cnt6);
  ll sum1 = round(cnt1+cnt2+cnt3);
  ll sum2 = round(cnt4+cnt5+cnt6);

  if(sum1 != sum2) return sum1 < sum2;
  return e[n1->idx] > e[n2->idx];
}

int main()
{
  __;
  int n;
  cin >> n;
  set<node*,decltype(&comp)> s(&comp);
  vector<pair<ld,int> > vr,vg,vb;

  for(int i=0;i<=360;i++) freqr[i] = freqg[i] = freqb[i] = 0;

  for(int i=0;i<n;i++)
  {
    ld r,g,b;
    int index;
    cin >> r >> g >> b;
    cin >> index;
    vr.pu(mp(r,i));
    vg.pu(mp(g,i));
    vb.pu(mp(b,i));
    e[i] = index;
  }  

  sort(vr.begin(),vr.end());
  sort(vg.begin(),vg.end());
  sort(vb.begin(),vb.end());

  for(int i=0;i<n;i++)
  {
    node *a = new node;
    int index = vr[i].se;
    a->r = vr[i].fi;
    if(freqr[a->r]>1) a->ansr = true;
    a->right_r = vr[(i+1)%n].se;
    a->left_r = vr[(i-1+n)%n].se;
    a->idx = i;
    d[index] = a;
  }

  for(int i=0;i<n;i++)
  {
    int index = vg[i].se;
    node *a = d[index];
    a->g = vg[i].fi;
    if(freqg[a->g]>1) 
    {
      a->ansg =true;
    }
    a->right_g = vg[(i+1)%n].se;
    a->left_g = vg[(i-1+n)%n].se;
    d[index] = a;
  }

  for(int i=0;i<n;i++)
  {
    int index = vb[i].se;
    node *a = d[index];
    a->b = vb[i].fi;
    if(freqb[a->b]>1) a->ansb = true;
    a->right_b = vb[(i+1)%n].se;
    a->left_b = vb[(i-1+n)%n].se;
    d[index] = a;
  }

  for(auto it : d) s.insert(it.se);

  cerr<<fixed<<setprecision(5);

  for(auto it : d)
  { 
    node* a = it.se;
    ld cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
    cnt1 = ans(d[a->left_r]->r,a->r,d[a->right_r]->r);
    cnt2 = ans(d[a->left_g]->g,a->g,d[a->right_g]->g);
    cnt3 = ans(d[a->left_b]->b,a->b,d[a->right_b]->b);
    ld sum1 = cnt1+cnt2+cnt3;
    // t(a->r, a->g, a->b, a->left_r, a->left_g, a->left_b);
    // t(a->right_r,a->right_g,a->right_b,a->idx);
    t(a->idx,round(sum1),e[a->idx],cnt1,cnt2,cnt3);
    // t(d[a->left_r]->r,a->r,d[a->right_r]->r);
    // t(d[a->left_g]->g,a->g,d[a->right_g]->g);
    // t(d[a->left_b]->b,a->b,d[a->right_b]->b);
  }

  while(!s.empty())
  {
    node *a = *s.begin();

    s.erase(a);
    // cout << a->r + a->g + a-> b << endl;
    cout << e[a -> idx] << endl;

    vector<int> idx = {a->left_r, a->right_r, a->left_g, a->right_g, a->left_b, a->right_b};
    vector<node*> w;
    for(int i=0;i<6;i++) w.pu(d[idx[i]]);

    w[0]->right_r = w[1]->idx;
    w[1]->left_r = w[0]->idx;

    w[2]->right_g = w[3]->idx;
    w[3]->left_g = w[2]->idx;

    w[4]->right_b = w[5]->idx;
    w[5]->left_b = w[4]->idx;

    for(int i=0;i<6;i++) d[idx[i]] = w[i];
  }


  return 0;
}

/*
3
42 1 1 1
90 1 1 2
110 1 1 3


4
0 0 0 0
120 120 120 120
240 240 240 240
0 120 240 2017

*/