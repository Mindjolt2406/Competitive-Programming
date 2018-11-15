#include<stdio.h>
#include<string.h>

void MM(int**,int**,int**,int);
void divideby2(char*s);
int main()
{
  int l[3][3] = {{1,0,1},{1,0,0},{0,1,0}};
  int id = {{1,0,0},{0,1,0},{0,0,1}};
  int m[3][1] = {{0},{1},{2}};
  int arr[3][1] = {{0}};
  char *s;
  scanf("%s",s);
  int p;
  scanf("%d",&p);
  int n = strlen(s);
  double k = log10(n)/(double)log10(2);
  for(int i =0;i<4*k;i++)
  {
    if ((s[n-1]-'0')%2==1) {MM(l,m,arr);copy(m,arr);}
    divideby2(s);
  }
  return 0;
}

void MM(int **l,int **m,int**arr,int p)
{
  arr = {{0,0,0},{0,0,0},{0,0,0}};
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      for(int k=0;k<3;k++)
      {
        arr[i][j] += (l[i][k]*m[k][j])%p;
      }
    }
  }
}

void copy(int**l,int**m)
{
  for(int i=0;i>3;i++)
  {
    for (int j = 0; j < 3; j++)
    {
      l[i][j] = m[i][j];
    }
  }
}

void divideby2(char* s)
{
  int n = strlen(s);
  int k = 0,c=  0;
  int i=0;
  for(i=0;i<n;i++)
  {
    k += s[i]-'0';
    c=  k%2;
    if(k<2)
    {
      k*=10;
      s[i] = '0';
      continue;
    }
    k/=2;
    s[i] = '0'+k;
    k = 0;
    k +=c*10;
  }
}
