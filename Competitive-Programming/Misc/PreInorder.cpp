#include<iostream>
#include<deque>
using namespace std;

int index1 = 0;

struct node
{
  node* left;
  node* right;
  int data;
};

int search(int* in,int key,int n)
{
  for(int i=0;i<n;i++)
  {
    if(in[i]==key) return i;
  }
}

node* newnode()
{
  struct node *n = new node;
  n->left = NULL;
  n->right = NULL;
  n->data = -1;
  return n;
}

node* generate(node* root,int* in,int* pre,int beg,int end,int n)
{
  if(beg>end) return NULL;
  struct node *nodel=newnode(),*noder=newnode();
  int c = search(in,pre[index1],n);
  root->data = pre[index1];
  cout<<"c: "<<c<<" index: "<<index1<<" beg: "<<beg<<" end: "<<end<<endl;
  if(beg==end)return root;
  index1++;
  root->left = generate(nodel,in,pre,beg,c-1,n);
  index1++;
  root->right = generate(noder,in,pre,c+1,end,n);
  return root;
}

void level(node* root)
{
  if(root != NULL){
  deque <node*> q;
  q.push_back(root);
  while(!q.empty())
  {
    node* n = q.front();
    if(n->left)q.push_back(n->left);
    if(n->right)q.push_back(n->right);
    cout<<n->data<<endl;
    q.pop_front();
  }
  cout<<endl;}
}

int main()
{
  int n;
  cin>>n;
  int pre[n];
  int in[n];
  for(int i=0;i<n;i++)cin>>pre[i];
  for(int i=0;i<n;i++)cin>>in[i];
  struct node *tree;
  tree = newnode();
  cout<<tree->data<<endl;
  generate(tree,in,pre,0,n-1,n);
  level(tree);
}
