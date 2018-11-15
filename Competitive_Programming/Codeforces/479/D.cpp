#include<bits/stdc++.h>
#define pu push_back
using namespace std;


long long int bsearch(long long int l[],long long int n,long long int key)
{
  long long int beg = 0, end = n-1;
  while(beg<=end)
  {
    long long int mid = (beg+end)/2;
    if (l[mid]==key) return 1;
    else if (key>l[mid]) beg = mid+1;
    else end = mid-1;
  }
  return 0;
}

struct node
{
  node* left;
  node* right;
  long long int data;
};

node* generate(long long int key)
{
  node* n = new node;
  n->left = NULL;
  n->right = NULL;
  n->data = key;
  return n;
}


int main()
{
  typedef struct node node;
  long long int n;
  cin>>n;
  long long int l[n];
  map <long long int,node*> d;
  map <long long int,node*> :: iterator it;
  for(long long int i=0;i<n;i++) {cin>>l[i];}
  sort(l,l+n);
  // for(long long int i=0;i<n;i++) d[l[i]] = i;
  for(long long int i=0;i<n;i++)
  {
    node* p;
    if(d.find(l[i])==d.end()) {p = generate(l[i]); d[l[i]] = p;}
    else p = d[l[i]];
    // Right
    if(bsearch(l,n,l[i]*2)==1)
    {
      if(d.find(l[i]*2) == d.end()){node* p = generate(l[i]*2);d[l[i]*2] = p;}
      p->right = d[l[i]*2];
      d[l[i]*2]->left = p;
    }
    else if(l[i]%3==0 && bsearch(l,n,l[i]/3))
    {
      if(d.find(l[i]/3) == d.end()){node* p = generate(l[i]/3);d[l[i]/3] = p;}
      p->right = d[l[i]/3];
      d[l[i]/3]->left = p;
    }
    else p->right = NULL;
  }
  node* p;
  for(it=d.begin();it!=d.end();it++)
  {
    if(it->second->left==NULL) p = it->second;
  }
  while(p)
  {
    cout<<p->data<<" ";
    p = p->right;
  }
  cout<<endl;
  return 0;
}
