void recur(set<int> s, vector<int> v,int n)
{
  if(s.empty())
  {
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    return;
  }

  for(int i=1;i<=n;i++)
  {
    if(s.find(i)!=s.end())
    {
      v.pu(i);
      s.erase(i);
      recur(s,v,n);
      v.pop_back();
      s.insert(i);
    }
  }
}
// recur(set,vector,n)