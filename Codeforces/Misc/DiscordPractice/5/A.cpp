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

void print1(string &s) {
    cout << s.size() << endl;
    for(auto it : s) cout << it << " "; cout << endl;
}

int main() {
    __;
    map<char, int> d;
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(auto it : s) d[it]++;

    int cntOdd = 0;
    for(auto it : d) if(it.se & 1) cntOdd++;

    if(cntOdd == 0) {
        string ans;
        cout << 1 << endl;
        for(auto it : d) {
            string temp;
            for(int i = 0; i < it.se/2; i++) {
                temp += it.fi;
            }
            ans += temp;
        }

        string revAns = ans;
        reverse(revAns.begin(), revAns.end());
        ans += revAns;
        cout << ans << endl;
    } else {
        int cntEven = 0;
        for(; cntOdd + cntEven <= n; cntEven +=2) {
            // t(n, cntOdd, cntEven);
            if(n % (cntOdd + cntEven) != 0 || (n/(cntOdd + cntEven) - 1) % 2 != 0) continue;
            else {
                // t(cntEven);
                vector<string> finalAns;
                for(auto it : d) {
                    if(it.se %2 == 1) {
                        d[it.fi]--;
                        string temp;
                        temp += it.fi;
                        finalAns.pu(temp);
                    }
                }

                // t(finalAns);
                // Make cntEven = 0
                int tempCntEven = cntEven;
                for(auto it : d) {
                    while(d[it.fi] && tempCntEven) {
                        d[it.fi] --;
                        tempCntEven --;
                        string temp;
                        temp += it.fi;
                        finalAns.pu(temp);
                    }
                }

                // t(finalAns);
                
                for(auto it : d) {
                  d[it.fi] /= 2;
                }

                vector<string> tempAns(finalAns.size());
                int totalSz = (n/(cntOdd + cntEven) - 1)/2;
                int i = 0, tempSz = totalSz;
                // t(tempSz);
                for(auto it : d) {
                    // t(it);
                    while(d[it.fi]) {
                        // t(d[it.fi], i);
                        d[it.fi]--;
                        tempAns[i] += it.fi;
                        tempSz--;

                        if(tempSz == 0) {
                            tempSz = totalSz;
                            i++;
                        }
                    }

                }

                for(int i = 0; i < finalAns.size(); i++) {
                    string tempRev = tempAns[i];
                    reverse(tempRev.begin(), tempRev.end());
                    finalAns[i] = tempAns[i] + finalAns[i] + tempRev;
                }

                cout << finalAns.size() << endl;
                for(auto it : finalAns) cout << it << " "; cout << endl;
                return 0;
            }

        }
        print1(s);
    }
    return 0;
}
