#include<bits/stdc++.h>
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


int main() {
    long long int t;
    cin >> t;
    cout << "t:" << t << endl;
    // string prnt = "";
    for (long long int x = 0; x < t; x++) 
    {
        long long int n;
        cin >> n;
        cout << "n:" << n << endl;
        long long int maxi = -1, curr = -1, ans = 0;
        vector<long long int> arr(n,0);
        for (long long int i = 0; i < n; i++) 
        {
            long long int ele;
            // cin >> ele;
            scanf("%lld", &ele);
            arr.push_back(ele);
            // if ((ele > maxi) && (i == (n-1) || (curr > ele))) {
            //     ans += 1;
            // }
            // curr = ele;
            // maxi = max(maxi, curr);
            // // arr.push_back(ele);
        }
        for (long long int i = 0; i < (n-1); i++) {
            cout << "Ele:" << arr[i] << "maxi:" << maxi << endl;
            if ((arr[i] > maxi) && (i == (n-1) || arr[i] > arr[i+1])) {
                ans += 1;
            }
            maxi = max(maxi, arr[i]);
        }
        // prnt = "Case #" + str(x+1) + ": " + str(ans);
        printf("Case #%lld: %lld\n", (x+1), ans);
    }
}
