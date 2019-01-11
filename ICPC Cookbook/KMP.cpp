// Make the preix table first

int main()
{
  // Find a pattern in a string
  int test;
  sc(test);
  while(test--)
  {
    string s,t;
    scr(s);scr(t);
    int n = s.size(), m = t.size();
    s = t+"$"+s;
    vector<int> p(n+m+1); // the pi array (dp array)
    // t(s,m);
    for(int i=1;i<n+m+1;i++)
    {
      int c = p[i-1];
      while(c>0 && s[c]!=s[i]) c = p[c-1];
      if(s[c]==s[i]) c++;
      p[i] = c;
    }

    // Indices of substrings
    vi v;
    for(int i=m+1;i<n+m+1;i++)
    {
      if(p[i]==m) v.pu(i-m-m+1);
    }

    if(v.size()==0) printf("Not Found\n");
    else
    {
      printf("%d\n",(int) v.size());
      for(int i=0;i<v.size();i++) printf("%d ",v[i]);printf("\n");
    }

    printf("\n");
  }
  return 0;
}

