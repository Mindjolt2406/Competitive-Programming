#include<stdio.h>
#include<math.h>
#include<string.h>
void mm(int a[3][3], int b[3][3], int c[3][3],int m);
int main()
{
  int a[3][3],b[3][3],c[3][3];
  int start[3]={2,1,0};
  int matrix[3][3]={{1,0,1},{1,0,0},{0,1,0}};
  int matrix2[3][3]={{1,0,1},{1,0,0},{0,1,0}};
  char n[1000000];
  long nnum=0;
  do{
    scanf("%c",&n[nnum]);
    nnum++;
  }while(n[nnum-1]!='\n');
  n[nnum]='\0';

  int m;
  scanf("%d", &m);

  int plethora[11][3][3]={0};
  plethora[0][0][0]=1;
  plethora[0][0][2]=1;
  plethora[0][1][0]=1;
  plethora[0][2][1]=1;

  int result[3][3]={0};
  for(int i=1;i<11;++i)
  {
    mm(plethora[i-1],plethora[0],result,m);
    for (int j=0;j<3;j++)
    {
      for(int k=0;k<3;++k)
      {
        plethora[i][j][k]=result[j][k];
        result[j][k]=0;
      }
    }
  }
  // printf("\n");
  // for(int i=0;i<10;++i)
  // {
  //   for (int j=0;j<3;j++)
  //   {
  //     for(int k=0;k<3;++k)
  //     {
  //       printf("%d ",plethora[i][j][k]);
  //     }
  //     printf("\n");
  //   }
  //   printf("\n\n");
  // }
  for (int j=0;j<3;j++)
  {
    for(int k=0;k<3;++k)
    {
      result[j][k]=0;
    }
  }

  for(int i=0;i<3;++i)
  {
    for(int j=0;j<3;++j)
    {
      b[i][j]=plethora[0][i][j];
      if(i==j)
      a[i][j]=1;
    }
  }

  long number=strlen(n);
  printf("\nnumber is %ld\n", number);
  long i=0;
  int temp;
  while(i<number-1)
  {
    temp=n[i]-48;
    if(temp!=0)
    {
      while(temp>0)
      {
        mm(a,b,result,m);
        for(int j=0;j<3;++j)
        {
          for(int k=0;k<3;++k)
          {
            a[j][k]=result[j][k];
            result[j][k]=0;
          }
        }
        temp--;
      }
    }
    // if(number==2)
    // {
    //   for(int y=0;y<3;++y)
    //   {
    //     for(int u=0;u<3;++u)
    //     {
    //       b[y][u]=plethora[10][y][u];
    //     }
    //   }
    // }
    // else
    // {
    if(i!=number-2)
    {
      for(int y=0;y<3;++y)
      {
        for(int u=0;u<3;++u)
        {
          c[y][u]=a[y][u];
        }
      }
      for(int q=0;q<9;++q)
      {
        mm(c,a,result,m);
        for(int y=0;y<3;++y)
        {
          for(int u=0;u<3;++u)
          {
            c[y][u]=result[y][u];
            result[y][u]=0;
          }
        }
      }
      for(int y=0;y<3;++y)
      {
        for(int u=0;u<3;++u)
        {
          a[y][u]=c[y][u];
        }
      }
    }
    i++;
  }
  int ans[3];
  ans[0]=a[0][0]*start[0]+a[0][1]*start[1]+a[0][2]*start[2];
  ans[1]=a[1][0]*start[0]+a[1][1]*start[1]+a[1][2]*start[2];
  ans[2]=a[2][0]*start[0]+a[2][1]*start[1]+a[2][2]*start[2];
  printf("\nAnswer is %d\n", ans[2]%m);
  // printf("\nAnswer is %d\n", ans[2]);
  return 0;
}
void mm(int a[3][3], int b[3][3], int c[3][3], int m)
{
  for(int i=0;i<3;++i)
  {
    for(int j=0;j<3;++j)
    {
      for(int k=0;k<3;++k)
      {
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  for(int i=0;i<3;++i)
  {
    for(int j=0;j<3;++j)
    {
      c[i][j]%=m;
    }
  }
}
