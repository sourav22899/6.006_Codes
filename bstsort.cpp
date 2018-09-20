#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a>=b?a:b
#define min(a,b) a>=b?b:a
#define F first
#define S second
#define N 1000000007
struct node
{
  ll key;
  ll height;
  struct node* left;
  struct node* right;
  struct node* parent;
};
struct node* newnode(ll x)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> key = x;
  temp -> left = NULL;
  temp -> right = NULL;
  temp -> parent = NULL;
  temp -> height = 1;
  return temp;
}
void inorder(struct node* current)
{
  if(current -> left != NULL) inorder(current -> left);
  cout<<current -> key<<endl;
  if(current -> right != NULL) inorder(current -> right);
}
/*struct node* insert(struct node* node, ll x)
{
  if(node == NULL) return newnode(x);
  if(x < node -> key) 
  {
    node -> left = insert(node -> left,x);
  }
  else 
  {
    node -> right = insert(node -> right,x);
  }
  return node;
}*/
ll height(struct node* node)
{
  if (node == NULL) return 0;
  else return node -> height;
}
ll update_height(struct node* node)
{
  ll ht = max(height(node -> left),height(node -> right)) + 1;
  return ht;
}
void left_rotate(struct node* x) 
{
  struct node* y = x -> right;
  y -> parent = x -> parent;
  if(x -> parent)
  {
    if ((x -> parent) -> left == x) (x -> parent) -> left = y;
    else if ((x -> parent) -> right == x) (x -> parent) -> right = y;
  }
  x -> right = y -> left;
  if(y -> left) (y -> left) -> parent = x;
  y -> left = x;
  x -> parent = y;
  update_height(x);
  update_height(y);
}
void right_rotate(struct node* x) 
{
  struct node* y = x -> left;
  y -> parent = x -> parent;
  if(x -> parent)
  {
    if ((x -> parent) -> left == x) (x -> parent) -> left = y;
    else if((x -> parent) -> right == x) (x -> parent) -> right = y; 
  }
  x -> left = y -> right;
  if(y -> right) (y -> right) -> parent = x;
  y -> right = x;
  x -> parent = y;
  update_height(x);
  update_height(y);
}
void rebalance(struct node* node) 
{
  while(node)
  {
    update_height(node);
    if (height(node -> left) >= height(node -> right) + 2)
    {
      if(height(((node) -> left) -> left) >= height(((node) -> left) -> right)) right_rotate(node);
      else
      {
        left_rotate(node -> left);
        right_rotate(node);
      }
    }
    else if(height((node) -> right) >= height((node) -> left) + 2)
    {
      if(height(((node) -> right) -> right) >= height(((node) -> right) -> left)) left_rotate(node);
      else
      {
        right_rotate(node -> right);
        left_rotate(node);
      }
    }
    node = node -> parent;
  }
}
void insert(struct node* node, ll x) 
{
  struct node* New = newnode(x); 
  if(node == NULL) 
  {
    node = New;
  }
  else if(New -> key < node -> key)
  {
    if(node -> left == NULL)
    {
      node -> left = New;
      New -> parent = node;
    }
    else insert(node -> left, New -> key);
  }
  else 
  {
    if(node -> right == NULL)
    {
      node -> right = New;
      New -> parent = node;
    }
    else insert(node -> right, New -> key);
  } 
}
struct node* search(struct node* node, ll x)
{
  if(node == NULL || node -> key == x) return node;
  if(x < node -> key) return search(node -> left,x);
  return search(node -> right,x);
}
struct node* maximum(struct node* node)
{
  if(node == NULL) return NULL;
  else
  {
    while(node -> right != NULL)
    {
      node = node -> right;
    }
    return node;
  }
}
struct node* minimum(struct node* node)
{
  if(node == NULL) return NULL;
  else
  {
    while(node -> left != NULL)
    {
      node = node -> left;
    }
    return node;
  }
}
struct node* next_larger(struct node* root,ll x)
{
  struct node* node = search(root,x);
  if(node == NULL) return NULL;
  if(node -> right != NULL) return minimum(node -> right);
  else
  {
    struct node* p = node -> parent;
    while(node -> parent != NULL && p -> right == node)
    {
      node = p;
      p = p -> parent;
    }
    return p;
  }
}
struct node* next_smaller(struct node* root,ll x)
{
  struct node* node = search(root,x);
  if(node == NULL) return NULL;
  if(node -> left != NULL) return maximum(node -> left);
  else
  {
    struct node* p = node -> parent;
    while (node -> parent != NULL && p -> left == node)
    {
      node = p;
      p = p -> parent;
    }
    return p;
  }
}
void del(struct node* root,ll x)
{
  struct node* node = search(root,x);
  if(node)
  {
    if(node -> left == NULL || node -> right == NULL)
    {
      if(node == ((node -> parent) -> left))
      {
        if(node -> right) (node -> parent) -> left = node -> right;
        else (node -> parent) -> left = node -> left;
        if ((node -> parent) -> left) 
        {
          ((node -> parent) -> left) -> parent = node -> parent;
        } 
      }
      else
      {
        if(node -> right) (node -> parent) -> right = node -> right;
        else (node -> parent) -> right = node -> left;
        if ((node -> parent) -> right) 
        {
          ((node -> parent) -> right) -> parent = node -> parent;
        }
      }  
    }
    else
    {
      struct node* next = next_larger(root,node -> key);
      ll temp = 0;
      temp = next -> key;
      next -> key = node -> key;
      node -> key = temp;
    //cout<<node -> key<<endl;
      del(next,next -> key);
    }
  }
}
///////left rotate///////////right rotate///////rebalance

int main()
{
  struct node* root = NULL;
  root = newnode(13);
  insert(root,20);
  insert(root,17);
  insert(root,14);
  insert(root,19);
  insert(root,35);
  insert(root,9);
  insert(root,12);
  insert(root,26);
  insert(root,16);
  inorder(root);
  /*
  ll x,y;cin>>x>>y;
  //cout<<search(root,1)<<endl;
  cout<<endl;
  cout<<maximum(root) -> key<<endl;
  cout<<minimum(root) -> key<<endl;
  if(next_larger(root,x)) cout<<next_larger(root,x) -> key<<endl;
  else cout<<"There is no larger value."<<endl;
  if(next_smaller(root,y)) cout<<next_smaller(root,y) -> key<<endl;
  else cout<<"There is no smaller value."<<endl;
  */
  cout<<endl;
  //del(root,13);
  ll a[]={13,20,17,14,19,35,9,12,26,16};
  //if(search(root,17) -> left)cout<<(search(root,17) -> left) -> key<<endl;
  //inorder(root);
  rep(x,0,10)
  {
    if(search(root,a[x]))cout<<height(search(root,a[x]))<<endl;
    else cout<<"It is a root"<<endl;
  }
  /*ll x;cin>>x;
  del(root,x);
  inorder(root);*/
  //if(search(root,x) && search(root,x) -> parent)cout<<(search(root,x) -> parent) -> key<<endl;
  return 0;
}
