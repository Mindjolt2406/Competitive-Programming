#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
  srand(time(NULL));
  FILE *fp;
  fp=fopen("input.txt","w");
  long i;
  for(int i=0;i<100;++i)
  {
    for(int j=0;j<100;++j)
    {
      fprintf(fp,"%d ",rand()%100000);
    }
  }
  fclose(fp);
  return 0;
}
