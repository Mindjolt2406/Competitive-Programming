#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

typedef struct node
{
  struct node* left;
  struct node* right;
  int height;
  int data;
  int number;
}node;

node* generate(int key,int height1)
{
  node* n = new node;
  n->left = NULL;
  n->right = NULL;
  // if(p!=NULL)n->parent = p;
  // else n->parent = NULL;
  n->height = height1;
  n->data = key;
  n->number = 1;
  return n;
}

int height(node* root)
{

  if(root==NULL) {return -1;}
  else {return root->height;}
}

int number(node* root)
{
  if(root==NULL) return 0;
  else return root->number;
}

void level(node* root)
{
  if(root != NULL)
  {
    deque< node* > q;
    q.push_back(root);
    // q.push_back(NULL);
    while(!q.empty())
    {
      node* n = q.front();
      if(n!=NULL)
      {
        if(n->left)q.push_back(n->left);
        if(n->right)q.push_back(n->right);
        cout<<n->data<<" "<<n->number<<endl;
        q.pop_front();
      }
      else
      {
        cout<<endl;
        q.pop_front();
        if(q.front()!=NULL) q.push_back(NULL);
      }

    }
  }
}

void inorder(node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}

void preorder(node* root)
{
  if(root!=NULL)
  {
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}

int computeHeight(node* root)
{
  if(root!=NULL)
  {
    root->height = max(computeHeight(root->left),computeHeight(root->right))+1;
    return root->height;;
  }
  else return -1;
}

node* zigzig(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  z->left = t1;z->right = t2;
  y->left = z; y->right = x;
  x->left = t3; x->right = t4;
  z->height-=2;
  x->number = number(x->left)+number(x->right)+1;
  z->number = number(z->left)+number(z->right)+1;
  y->number = number(y->left)+number(y->right)+1;
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return y;
}

node* zigzag(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = z;  x-> right = y;
  z->left = t1; z->right = t2;
  y->left = t3; y->right = t4;
  x->height+=1;
  y->height-=1;
  z->height-=2;
  y->number = number(y->left)+number(y->right)+1;
  z->number = number(z->left)+number(z->right)+1;
  x->number = number(x->left)+number(x->right)+1;
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return x;
}

node* zagzag(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = t1;x->right = t2;
  y->left = x; y->right = z;
  z->left = t3; z->right = t4;
  z->height-=2;
  x->number = number(x->left)+number(x->right)+1;
  z->number = number(z->left)+number(z->right)+1;
  y->number = number(y->left)+number(y->right)+1;
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return y;
}

node* zagzig(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = y;  x-> right = z;
  y->left = t1; y->right = t2;
  z->left = t3; z->right = t4;
  y->height-=1;
  z->height-=2;
  x->height+=1;
  y->number = number(y->left)+number(y->right)+1;
  z->number = number(z->left)+number(z->right)+1;
  x->number = number(x->left)+number(x->right)+1;
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return x;
}

node* decide(node* z)
{
  node* y = new node;
  node* x = new node;
  if(height(z->right) > height(z->left))
  {
    y = z->right;
    if(height(y->right) > height(y->left)) {x = y->right; z = zigzig(z,y,x,z->left,y->left,x->left,x->right);} //The parameters are z,y,x,t1,t2,t3,t4
    else {x = y->left; z = zigzag(z,y,x,z->left,x->left,x->right,y->right);}
  }
  else
  {
    y = z->left;
    if(height(y->right) > height(y->left)) {x = y->right; z = zagzig(z,y,x,y->left,x->left,x->right,z->right);}
    else {x = y->left; z = zagzag(z,y,x,x->left,x->right,y->right,z->right);}
  }
  return z;
}

node* insert(node* root,int key)
{
  if(root!=NULL)
  {
    if(key==root->data) return root; // No duplicates
    else if(key > root->data) root->right = insert(root->right,key);
    else root->left = insert(root->left,key);
    root->height = max(height(root->right),height(root->left))+1;
    // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
    if(abs(height(root->left) - height(root->right)) > 1)
    {
      // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
      root = decide(root);
    }
    root->number = number(root->left)+number(root->right) +1;
    return root;
  }
  else
  {
    return generate(key,0);
  }
}

node* inorderSuccesor(node* root)
{
  while(root->left!=NULL)
  {
    root->height = max(height(root->left) -1,height(root->right)) +1;
    root->number -=1;
    root = root->left;
  }
  return root;
}

node* delete1(node* root,int key)
{
  if(root == NULL) return NULL;
  if(key< root->data) root->left = delete1(root->left,key);
  else if(key>root->data) root->right = delete1(root->right,key);
  else
  {
    int children = 2;
    if(root->left == NULL) children-=1;
    if(root->right== NULL) children-=1;
    if(children == 0) {root = NULL;return NULL;}
    else if(children == 1)
    {
      node* child;
      if(root->left!=NULL) child = root->left;
      else child = root->right;
      child->height = max(height(child->left),height(child->right)) +1;
      child->number = number(child->left) + number(child->right) +1;
      return child;
    }
    else //Children ==2
    {
      node* child = inorderSuccesor(root->right);
      root->data = child->data;
      root->right = delete1(root->right,child->data);
      root->height = max(height(root->left),height(root->right)) +1;
      root->number = number(root->left) + number(root->right) +1;
      if(abs(height(root->left) - height(root->right)) > 1) root = decide(root);
      return root;
    }
  }
  if(abs(height(root->left) - height(root->right)) > 1)
  {
    // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
    root = decide(root);
  }
  root->height = max(height(root->left),height(root->right)) +1;
  root->number = number(root->left)+number(root->right) +1;
  return root;
}

int findrank(node* root,int key)
{
  int count = 0;
  while(root&& root->data!=key)
  {
    if(key > root->data) {count+= number(root->left) +1; root = root->right;}
    else root = root->left;
  }
  if(root)count+=number(root->left);
  return count;
}

int kthsmallest(node* root,int k)
{
  int count = 0;
  while(root && number(root->left)+count!=k-1)
  {
    if(number(root->left)+count+1>k) root = root->left;
    else if(number(root->left)+count+1<k) {count+= number(root->left)+1;root = root->right;}
  }
  if(root==NULL) return -1;
  return root->data;
}

int main()
{
  int q;
  cin>>q;
  node* root = NULL;
  for(int h=0;h<q;h++)
  {
    char a;
    cin>>a;
    if(a=='I')//Insert value
    {
      int key;
      cin>>key;
      root = insert(root,key);
      // cout<<"Level Order"<<endl;
      // level(root);
      // cout<<"Inorder"<<endl;
      // inorder(root);
      // cout<<endl;
      // cout<<"Preorder"<<endl;
      // preorder(root);
      // cout<<endl;
    }
    else if(a=='D') //Delete value
    {
      int key;
      cin>>key;
      root = delete1(root,key);
      // level(root);
      // cout<<endl;
      // cout<<"Inorder"<<endl;
      // inorder(root);
      // cout<<endl;
      // cout<<"Preorder"<<endl;
      // preorder(root);
      // cout<<endl;
    }
    else if(a=='K')
    {
      int k;
      cin>>k;
      int n = kthsmallest(root,k);
      // cout<<"Level Order"<<endl;
      // level(root);
      if(root==NULL || k>root->number) cout<<"invalid"<<endl;
      else cout<<n<<endl;
    }
    else if(a=='C')
    {
      int x;
      cin>>x;
      cout<<findrank(root,x)<<endl;
    }
  }
}
/*
8
4 7 10 11 6 2 3 1
8
1 0 1 -1 1 -2 2 2
*/
