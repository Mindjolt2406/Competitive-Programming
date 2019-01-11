void sort(int* ,int,int);
void merge(int* ,int,int,int);
long long int count = 0;

// sort(array, beg,end);
void sort(int *l,int i,int j)
{
  if(i<j)
  {
    int c = (i+j)/2;
    sort(l,i,c);
    sort(l,c+1,j);
    merge(l,i,c,j);
  }
}

void merge(int*l,int i,int c,int j)
{
  int*m = (int*)calloc((j-i+1),sizeof(int));
  int x=i,y=c+1;
  int k=0;
  while(k<j-i+1)
  {
    if(y==j+1)
    {
      while(x<=c)
      {
        m[k] = l[x];
        count+=(y-c-1);
        x++;
        k++;
      }
      continue;
    }
    else if(x==c+1)
    {
      while(y<=j)
      {
        m[k] = l[y];
        y++;
        k++;
      }
      continue;
    }
    else if(l[x]<l[y])
    {
      m[k] = l[x];
      count+=(y-c-1);
      x++;
    }
    else if(l[y]<=l[x])
    {
      m[k] = l[y];
      y++;
    }
    k++;
  }
  //Copying
  for(int k=0;k<j-i+1;k++)
  {
    l[k+i] = m[k];
  }
}
