//Given an array find s%p, where s is the string of the number and p is the number for which s is being modded with
#include<stdio.h>
#include<math.h>
#include<string.h>
//#include<"~/IIITB/DSA/Questions/Modulo.c">

int findmod(char*,int);
int main()
{
  char *s;
  scanf("%s",s);
  int n;
  int p;
  //scanf("%d",&n);
  scanf("%d",&p);
  int a= 0,b = 1;
  int c,k;
  for(int i=0;i<6*p;i++)
  {
    c = (a+b)%p;
    a = b;
    b = c;
    if (a==0 && b==1)
    {
      k = i;
      break;
    }
    //printf("%d %d\n",a,b);
  }
  printf("%d\n",k+1);
  k+=1;
  n = findmod(s,k);
  n-=1;
  n+=k;
  n%=k;
  a = 0;b = 1;
  for(int i=0;i<n;i++)
  {
    c=  (a+b)%p;
    a = b;
    b = c;
  }
  printf("The %sth fibonacci number mod %d is %d\n",s,p,a%p);
  return 0;
}

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
