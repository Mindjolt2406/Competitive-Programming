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
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

vector<pair<int,int> > ans;

// Median Algorithm in O(n)
int getNumber(vector<int> &v,int k)
{
  if(v.size()<=5)
  {
    vector<int>w = v;
    sort(w.begin(),w.end()); 
    return w[k];
  }

  // Find median of medians
  vector<vector<int> > w;
  for(int i=0;i<v.size();i+=5)
  {
    vector<int> x;
    for(int j=0;j<=min(4,(int)v.size()-1);j++)
    {
      x.pu(v[i+j]);
    }
    sort(x.begin(),x.end()); // Takes constant time
    w.pu(x);
  }

  // vector of the middles
  vector<int> middle;
  for(int i=0;i<w.size();i++)
  {
    if(i==w.size()-1) middle.pu(w[i][w.size()/2]);
    else middle.pu(w[i][2]); 
  }

  int pivot = getNumber(middle,middle.size()/2);

  vector<int> a,b;
  int countPivot = 0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]<pivot) a.pu(v[i]);
    else if(v[i]==pivot) countPivot++;
    else b.pu(v[i]);
  }

  if(a.size()>k) return getNumber(a,k);
  else if(countPivot+a.size()>k) return pivot;
  else return getNumber(b,k-a.size()-countPivot);
}

// Use a stack to make the chords
void getChords(vector<bool> &w)
{
  stack<pair<bool,int> >s;
  bool boo = w[0];
  for(int i=0;i<w.size();i++)
  {
    if(s.empty()) s.push(mp(w[i],i));
    else if(s.top().fi==w[i]) s.push(mp(w[i],i));
    else
    {
      pair<int,int> a = s.top();
      s.pop();
      ans.pu(mp(a.se,i));
    }
  }
} 

int main()
{
  __;
  // auto start = chrono::steady_clock::now();
  int n;
  cin>>n;
  vector<int> v(2*n);
  for(int i=0;i<2*n;i++) cin>>v[i];

  // Get median
  int splitter = getNumber(v,v.size()/2);

  // Colour black and white
  vector<bool> w(2*n);
  int count = 0;
  for(int i=0;i<2*n && count<n;i++) if(splitter<v[i]) {w[i] = true;count++;}

  if(count<n) // To ensure than only n elements are filled
  {
    for(int i=0;i<2*n && count<n;i++) 
    {
      if(splitter==v[i]) 
      {
        w[i] = true;
        count++;
      }
    }
  } 

  getChords(w);

  count = 0;

  for(int i=0;i<ans.size();i++)
  {
    count+=abs(v[ans[i].fi] - v[ans[i].se]);
    // cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
  }

  cout<<count<<endl;
  // auto end = chrono::steady_clock::now();
  // auto diff = end - start;
  // cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
  return 0;
}

/*
4
2 8 6 3 5 9 6 5

*/
