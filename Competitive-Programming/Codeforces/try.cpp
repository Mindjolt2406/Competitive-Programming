#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lli long long int
#define ld long double

#define pi 3.141592653589793238
#define INF 1000000001
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    int ta=0,tb=0;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int kk;
         cin >> kk;
         a.push_back(kk);
     }
    for(int i=0;i<n;i++){
        int kk;
        cin >> kk;
        b.push_back(kk);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";cout<<endl;
    for(int i=0;i<b.size();i++) cout<<b[i]<<" ";cout<<endl;
    for(int i=0;i<2*n;i++){
        if((a.size()>0 && b.size()>0 && a[a.size()-1]>b[b.size()-1] && i%2 == 0)||(b.empty() && !a.empty())){
            cout<<"A ";
            cout<<a[a.size()-1]<<" "<<a.size()<<endl;
            ta+=a[a.size()-1];
            a.pop_back();

        }
        else if(b.size()>0 && i%2 == 0){
            cout<<"B"<<endl;
            cout<<"in: "<<b.size()<<endl;
            b.pop_back();
            cout<<"out: "<<b.size()<<endl;
        }
        else if((b.size()>0 && a.size()>0 && b[b.size()-1]>a[a.size()-1] && i%2 == 1)||(a.empty()&&!b.empty())){
            cout<<"B ";
            cout<<b[b.size()-1]<<" "<<b.size()<<endl;
            tb+=b[b.size()-1];
            b.pop_back();
        }
        else if(a.size()>0  && i%2 == 1)
        {
          cout<<"A"<<endl;
          cout<<"in: "<<a.size()<<endl;
          a.pop_back();
          cout<<"out: "<<a.size()<<endl;
        }
    }
    cout << ta-tb << endl;
}
