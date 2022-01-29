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

int fun(string s)
{
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=i;j<n;j++)
        {   
            cnt += (s[j] == 'r');
            if(cnt%2 == 1)
                ans ++;
        }
    }
    return ans;
}


void brute_force(string base, int n, int cnt = 100) {
    int N = base.size() + n;
    string baseSS(N, 'r');
    int baseNum = fun(baseSS);

    for (int mask = 0; mask < (1LL << min(25, n)); ++mask) {
        string s = "";
        for(int i=n-1;i>=0;i--)
        {
            if(mask&(1LL<<i))
                s+='r';
            else 
                s+='b';
        }
        string currString = base + s;
        if (fun(currString) == baseNum) {
            cout << currString << endl;
            cnt--;
            if (cnt == 0)
                return ;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ll max_pairs=(n+1)/2;
    if((n+1)%2==0){
        max_pairs=max_pairs*((n+1)/2);
    }
    else{
        max_pairs=max_pairs*(((n+1)/2)+1);
    }

    cout << max_pairs << endl;

    if (n <= 30) {
        brute_force("", n);
        return ;
    } else {
        vector<string> ans;
        // print first.
        string s(n, 'b');
        s[n/ 2] = 'r';
        cout << s << endl;
        int cnt = 99;
        {
            string firstHalf(n / 2, 'b');
            firstHalf[n/2 - 1] = 'r';
            int secondSize = (n - n/2);
            for (int i = secondSize - (n & 1); i >= 0; i--) {
                string secondHalf((n - n/2), 'b');
                if (i < secondSize)
                    secondHalf[i] = 'r';
                if (i + 1 < secondSize)
                    secondHalf[i + 1] = 'r';
                
                cout << firstHalf + secondHalf << endl;
                cnt--;
                if (cnt == 0)
                    break;
            }
        }

        if (cnt == 0)
            return ;
        
        {
            string firstHalf(n/2 - 1, 'b');
            firstHalf[n/2 - 2] = 'r';
            brute_force(firstHalf, (n - (n/2 - 1)), cnt);
        }
    }
}

int main() {
    __;
    solve();
    return 0;
}
