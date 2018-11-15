#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

//
// For any question, if you figure out the stuff you need to store in the nodes, you have to change/update the
// code in the following places
// 1. struct node
// 2. generate
// 3. Insert
// 4. Delete - children 1,2, outside
// 5. zigzags and zigzigs
// 6. Make a function like height() or number() if you want to
// 7. In the inorderSuccesor
// 8. Make different functions for what you want

int count1 = 0;
struct node
{
  node* left;
  node* right;
  int height;
  int data;
};

node* generate(int key,int height1)
{
  node* n = new node;
  n->left = NULL;
  n->right = NULL;
  // if(p!=NULL)n->parent = p;
  // else n->parent = NULL;
  n->height = height1;
  n->data = key;
  return n;
}

int height(node* root)
{

  if(root==NULL) {return -1;}
  else {return root->height;}
}

void level(node* root)
{
  if(root != NULL)
  {
    deque< node* > q;
    q.push_back(root);
    q.push_back(NULL);
    while(!q.empty())
    {
      node* n = q.front();
      if(n!=NULL)
      {
        if(n->left)q.push_back(n->left);
        if(n->right)q.push_back(n->right);
        cout<<n->data<<" ";
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

// void level(node* root)
// {
//   if(root != NULL)
//   {
//     deque< node* > q;
//     q.push_back(root);
//     // q.push_back(NULL);
//     while(!q.empty())
//     {
//       node* n = q.front();
//       if(n!=NULL)
//       {
//         if(n->left)q.push_back(n->left);
//         if(n->right)q.push_back(n->right);
//         cout<<n->data<<" "<<n->height<<endl;
//         q.pop_front();
//       }
//       else
//       {
//         cout<<endl;
//         q.pop_front();
//         if(q.front()!=NULL) q.push_back(NULL);
//       }
//
//     }
//   }
// }

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
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return y;
}

node* zigzag(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = z;  x-> right = y;
  z->left = t1; z->right = t2;
  y->left = t3; y->right = t4;
  x->height+=1;
  y->height-=1;
  z->height-=2;
  cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return x;
}

node* zagzag(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = t1;x->right = t2;
  y->left = x; y->right = z;
  z->left = t3; z->right = t4;
  z->height-=2;
  // cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return y;
}

node* zagzig(node* z,node* y,node* x,node* t1,node* t2,node* t3,node* t4)
{
  cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  x->left = y;  x-> right = z;
  y->left = t1; y->right = t2;
  z->left = t3; z->right = t4;
  y->height-=1;
  z->height-=2;
  x->height+=1;
  cout<<"data: "<<z->data<<" height "<<z->height<<" data: "<<y->data<<" height "<<y->height<<" data: "<<x->data<<" height "<<x->height<<endl;
  return x;
}

node* decide(node* z)
{
  count1++;
  node* y = new node;
  node* x = new node;
  // cout<<"z data left: "<<z->left->data<<" height: "<<z->left->height<<" z data right: "<<z->right->data<<" height: "<<z->right->height<<endl;
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
  // cout<<"z data left: "<<z->left->data<<" height: "<<z->left->height<<" z data right: "<<z->right->data<<" height: "<<z->right->height<<endl;
  return z;
}

node* insert(node* root,int key)
{
  if(root!=NULL)
  {
    if(key > root->data) root->right = insert(root->right,key);
    else root->left = insert(root->left,key);
    root->height = max(height(root->right),height(root->left))+1;
    // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
    if(abs(height(root->left) - height(root->right)) > 1)
    {
      // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
      root = decide(root);
    }
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
    root = root->left;
  }
  return root;
}

node* delete1(node* root,int key)
{
  // cout<<"data: "<<root->data<<endl;
  if(key< root->data) {root->left = delete1(root->left,key);if(root->left) cout<<"root left: "<<root->left->data<<" "<<root->data<<endl;}
  else if(key>root->data) {root->right = delete1(root->right,key);if(root->right) cout<<"root right: "<<root->right->data<<" "<<root->data<<endl;}
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
      return child;
    }
    else //Children ==2
    {
      node* child = inorderSuccesor(root->right);
      root->data = child->data;
      root->right = delete1(root->right,child->data);
      // cout<<"root data: "<<root->right->data<<endl;
      root->height = max(height(root->left),height(root->right)) +1;
      if(abs(height(root->left) - height(root->right)) > 1) root = decide(root);
      return root;
    }
  }
  if(abs(height(root->left) - height(root->right)) > 1)
  {
    // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
    root = decide(root);
    // cout<<"data: "<<root->data<<" left: "<<height(root->left)<<" right: "<<height(root->right)<<endl;
  }
  root->height = max(height(root->left),height(root->right)) +1;
  // cout<<"root height: "<<root->height<<endl;
  return root;
}

int main()
{
  //typedef struct node node;
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  node* root = NULL;
  node *p = root;
  root = insert(root,l[0]);
  for(int i=1;i<n;i++) root = insert(root,l[i]);
  level(root);
  cout<<"Inorder"<<endl;
  inorder(root);
  cout<<endl;
  cout<<"Preorder"<<endl;
  preorder(root);
  cout<<endl;
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a;
    cin>>a;
    if(a==1)//Insert value
    {
      int key;
      cin>>key;
      root = insert(root,key);
      level(root);
      cout<<"Inorder"<<endl;
      inorder(root);
      cout<<endl;
      cout<<"Preorder"<<endl;
      preorder(root);
      cout<<endl;
    }
    else if(a==2) //Delete value
    {
      int key;
      cin>>key;
      root = delete1(root,key);
      cout<<"Level order"<<endl;
      level(root);
      cout<<"Inorder"<<endl;
      inorder(root);
      cout<<endl;
      cout<<"Preorder"<<endl;
      preorder(root);
      cout<<endl;
      cout<<"Count: "<<count1<<endl;
    }
  }
}
/*
8
4 7 10 11 6 2 3 1
8
1 0 1 -1 1 -2 2 2
*/
/*
8
10 7 12 3 9 11 17 8
2 2 10 2 11

*/
