#include<iostream>
#include<vector>
#include<map>
using namespace std;

map <long long int,long long int> m;
map <long long int,long long int> ::iterator it;
int count1 = 0;

void bottomupheapify(vector <long long int> &l,long long int n,long long int index)
{
  m[l[index]] = index;
  if(index==0)count1 ++;
  while(index>0 && l[(index-1)/2]>l[index])
  {
    m[l[index]] = (index-1)/2;
    m[l[(index-1)/2]] = index;
    long long int k = l[index];
    l[index] = l[(index-1)/2];
    l[(index-1)/2] = k;
    index = (index-1)/2;
  }
}

void topdownheapify(vector <long long int> &l,long long int n,long long int index)
{
  while(2*index+1<n)
  {
    long long int left = 2*index+1,right = 2*index+2,c;
    if(right<n)
    {
      cout<<c<<endl;
      if(l[left]<l[index] && l[left]<l[right]) c = left;
      else if(l[right]<l[index]) c = right;
      else break;
      cout<<c<<endl;
    }
    else if(right>=n)
    {
      if(l[left]<l[index]) c = left;
      else break;
    }
    else break;
    long long int k = l[index];
    l[index] = l[c];
    l[c] = k;
    m[l[index]] = index;
    index = c;
    m[l[index]] = index;
  }
}

void insert(vector <long long int> &l,long long int n,long long int key)
{
  l.push_back(key);
  bottomupheapify(l,n,n-1);
}

void deletemin(vector <long long int> &l, long long int n)
{
  long long int k = l[0];
  l[0] = l[n-1];
  l[n-1] = k;
  m[l[0]] = 0;
  m[l[n-1]] = n-1;
  l.pop_back();
  m.erase(l[n-1]);
  topdownheapify(l,n-1,0);
}

void delete1(vector<long long int> &l,long long int n,long long int key)
{
  long long int index = m[key];
  l[index] = l[0]-1;
  bottomupheapify(l,n,index);
  deletemin(l,n);
}

void decreasekey(vector <long long int> &l,long long int n, long long int key,long long int value) // Decreases key TO value
{
  int index = d[key];
  l[index] = value;
  bottomupheapify(l,n,index);
}

void increasekey(vector <long long int> &l,long long int n, long long int key,long long int value)
{
  int index = d[key];
  l[index] = value;
  topdownheapify(l,n,index);
}


int main()
{
  vector<long long int> v;
  long long int q;
  cin>>q;
  long long int n=0;
  for(long long int h=0;h<q;h++)
  {
    long long int a;
    cin>>a;
    if(a==1)
    {
      long long int b;
      cin>>b;
      n++;
      insert(v,n,b);
    }
    else if(a==2)
    {
      long long int b;
      cin>>b;
      delete1(v,n,b);
      n--;
    }
    else if(a==3)
    {
      cout<<v[0]<<endl;
    }
  }
  return 0;
}

/*
18
1 1
1 10 1 2
1 11 1 12 1 3 1 4
1 13 1 14 1 15 1 16 1 5 1 6 1 7 1 8

*/
