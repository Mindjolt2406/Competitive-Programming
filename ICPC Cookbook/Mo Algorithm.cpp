int block;

typedef struct node
{
  int first,second,i;
}node;

bool sorter(const node &a, const node &b) 
{ 
  if(a.fi/block < b.fi/block) return true;
  else if(a.fi/block> b.fi/block) return false;
  else
  {
    if(a.se<b.se) return true;
    return false;
  }
} 

int add(int*counter,int*l,int pos)
{
  int count = 0;
  counter[l[pos]]++;
  if(counter[l[pos]]==1) count++;
  return count;
}

int remove(int*counter,int*l,int pos)
{
  int count =0 ;
  counter[l[pos]]--;
  if(counter[l[pos]]==0) count--;
  return count;
}

int main()
{
  // ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  sc(n);
  int*l = new int[n];
  int*counter = (int*)calloc(1000001,sizeof(int));
  for(int i=0;i<n;i++) sc(l[i]);
  int q;
  sc(q);
  int ans[q];
  node *arr = new node[q];
  for(int i=0;i<q;i++)
  {
    sc(arr[i].fi);
    sc(arr[i].se);
    arr[i].fi--;arr[i].se--;
    arr[i].i = i;
  }

  block = int(sqrt(n));
  sort(arr,arr+q,sorter);
  
  int left = -1,right = -1,count = 0;
  for(int i=0;i<q;i++)
  {
    node p = arr[i];
    int a = p.fi,b = p.se;
    while(left>a)
    {
      left--;
      count+=add(counter,l,left);
    }
    while(left<a)
    {
      if(left==-1) {left++;continue;}
      count+=remove(counter,l,left);
      left++;
    }
    while(right<b)
    {
      right++;
      count+=add(counter,l,right);
    }
    while(right>b)
    {
      count+=remove(counter,l,right);
      right--;
    }
    ans[p.i] = count;
  }

  for(int i=0;i<q;i++)
  {
    printf("%d\n",ans[i]);
  }  
  return 0;
}

