#include<stdio.h>
#include<string.h>
int bruteforce(char*,char*,int,int);
void rabinkarp(char*,char*,int,int);

int main()
{
  int n,m;
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  scanf("%d",&m);
  char t[m];
  scanf("%s",t);
  printf("%d\n",bruteforce(s,t,n,m));
  //rabinkarp(s,t,n,m);
  return 0;
}
int bruteforce(char* s,char* t,int n,int m)
{
  int count = 0,j=0;
  for(j=0;j<n-m+1;j++)
  {
    count = 0;
    for(int i=0;i<m;i++)
    {
      if (s[i+j]==t[i]) count++;
      else break;
    }
    if(count==m)return 1;
  }
  return 0;
}

void rabinkarp(char* s,char*t,int n,int m)
{
  int* hash[1000000];
  int d = 26;
  int hasht=0,hashs=0;
  int p=1001;
  int prod=1;
  for(int i=0;i<m;i++)
  {
    hashs+=(s[i]-'0')*prod;
    hasht+=(t[i]-'0')*prod;
    prod*=d;hashs%=p;hasht%=p;prod%=p;
  }
}

typedef struct
{
  char* data;
  s1 *next;
} s1;
