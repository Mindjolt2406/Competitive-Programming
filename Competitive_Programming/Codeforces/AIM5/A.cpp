  #include<bits/stdc++.h>
  #define mt make_tuple
  #define mp make_pair
  #define pu push_back
  #define INF 1000000001
  #define MOD 1000000007
  #define ll long long int
  #define ld long double
  #define vi vector<int>
  #define vll vector<long long int>
  #define sc(n) scanf("%d",&n);
  #define scll(n) scanf("%lld",&n);
  #define scld(n) scanf("%Lf",&n);
  #define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

  using namespace std;

  int main()
  {
    int n,m;
    sc(n);sc(m);
    string *l = new string[n];
    for(int i=0;i<n;i++) scr(l[i]);
    int c1=  -1,c2 = -1,c3 = -1;
    for(int i=0;i<n;i++)
    {
      int count = 0;
      for(int j=0;j<m;j++)
      {
        // cout<<"j: "<<j<<endl;
        if(l[i][j]=='B') count++;
        if(count==1 && l[i][j]=='B') c2 = j;
        // cout<<"count: "<<count<<endl;
        if(count>=1 && l[i][j]=='W') break;
      }
      if(count) {c1 = i;c3 = count;break;}
    }
    // cout<<"c2: "<<c2<<endl;
    cout<<(c1+(c1+c3-1))/2 +1<<" "<<(c2 + (c2+c3-1))/2 +1<<endl;
    return 0;
  }
