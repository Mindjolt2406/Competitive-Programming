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

#define pll pair<ll,ll> 

ll gcd(ll a, ll b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

pll Add(pll A, pll B)
{
    ll num = A.fi * B.se + A.se * B.fi;
    ll den = A.se * B.se;
    ll g = gcd(num,den);
    num /= g;
    den /= g;
    return mp(num,den);
}

pll Mul(pll A, pll B)
{
    ll g1 = gcd(A.fi, B.se);
    ll g2 = gcd(A.se, B.fi);
    A.fi /= g1; B.se /= g1;
    A.se /= g2; B.fi /= g2;
    ll num = A.fi * B.fi;
    ll den = A.se * B.se;
    ll g = gcd(num,den);
    num /= g;
    den /= g;
    return mp(num,den);
}

pll Sub(pll A, pll B)
{
    ll num = A.fi * B.se - A.se * B.fi;
    ll den = A.se * B.se;
    ll g = gcd(num,den);
    num /= g;
    den /= g;
    return mp(num,den);
}

pll Div(pll A, pll B)
{
    return Mul(A, mp(B.se, B.fi));
}

struct compareFrac
{
    bool operator() (const pll &A, const pll &B) const
    {
        return A.fi * B.se < A.se * B.fi;
    }
};

pair<ll,ll> Avg(vector<pair<ll,ll> > &v)
{
    int n = v.size();
    pll temp = mp(0,1);
    for(auto it : v) temp = Add(temp,it);
    temp = Div(temp,mp(n,1));
    return temp;
}

int solve(int A, int B, int C) 
{
    multiset<pll, compareFrac> sMin, s2Max, sMax;
    vector<int> ele;
    
    for(int i=0;i<B;i++)
    {
        pll temp = mp(0,1);
        sMin.insert(temp);
        s2Max.insert(temp);
        sMax.insert(temp);
        ele.pu(0);
    }
    
    for(int i=0;i<A;i++)
    {
        pll temp = mp(1,1);
        sMin.insert(temp);
        s2Max.insert(temp);
        sMax.insert(temp);
        ele.pu(1);
    }
    
    // Get max
    int total = (A+B-1)/(C-1);
    for(int i=0;i<total;i++)
    {
        // Get the first C. 
        vector<pll> temp;
        for(int j=0;j<C;j++)
        {
            temp.pu(*sMax.begin());
            sMax.erase(sMax.begin());
        }
        
        // Get average
        pll avg = Avg(temp);
        
        sMax.insert(avg);
    }
    
    // Get min
    for(int i=0;i<total;i++)
    {
        // Get the first C. 
        vector<pll> temp;
        for(int j=0;j<C;j++)
        {
            temp.pu(*sMin.rbegin());
            sMin.erase(sMin.find(*sMin.rbegin()));
        }
        
        // Get average
        pll avg = Avg(temp);
        
        sMin.insert(avg);
    }
    
    // Get 2max
    int index = C-1;
    t(ele);
    while(ele[index] == 0) index++;
    vector<pll> temp;
    for(int i=0;i<C;i++)
    {
        s2Max.erase(s2Max.find(mp(ele[index-i],1)));
        temp.pu(mp(ele[index-i],1));
    }
    
    pll avg2 = Avg(temp);
    t(avg2);
    s2Max.insert(avg2);
    
    for(int i=0;i<total-1;i++)
    {
        // Get the first C. 
        vector<pll> temp;
        for(int j=0;j<C;j++)
        {
            temp.pu(*s2Max.begin());
            s2Max.erase(s2Max.begin());
        }
        
        // Get average
        pll avg = Avg(temp);
        
        s2Max.insert(avg);
    }
    
    pll X = *sMin.begin(), Y = *s2Max.begin(), Z = *sMax.begin();
    if(X == Z) return 1;
    if(Y == Z) return 2;

    t(X,Y,Z);
    pll smallDiff = Sub(Z,Y);
    pll totalDiff = Sub(Z,X);
    t(smallDiff, totalDiff);
    pll ans = Div(totalDiff,smallDiff);
    
    t(X,Y,Z);
    return ans.fi + 1;
}

int main()
{
  __;
  int A,B,C;
  cin >> A >> B >> C;
  cout << solve(A,B,C) << endl;
  return 0;
}
