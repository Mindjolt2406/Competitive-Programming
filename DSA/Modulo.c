int findmod(char*,int);
int findmod(char* s, int p)
{
  // (int)log10(double) returns
  int k = (int)log10((double) p);
  int n =0;
  int i=0;
  while(i<k)
  {
    n*=10;
    n +=s[i++]-'0';
  }
  n%=p;
  for(i = k;i<strlen(s);i++)
  {
    n*=10;
    n+=s[i]-'0';
    n%=p;
  }
  return n;
}
