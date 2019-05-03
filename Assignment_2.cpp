/*
Name:Saumitra Kulkarni
Roll no:222004
Gr No:17u255
Batch:B1
*/

#include<iostream>
using namespace std;

class thread
{
private:
  typedef struct bst
  {
    int lth,rth,data;
    struct bst *left,*right;
  }node;
  node *dummy,*nn,*root,*temp;
public:
  thread()
  {
    root=NULL;
  }
  void create();
  void insert(node *,node *);
  void inorder();
};

void thread::create()
{
  nn=new node;
  nn->lth=0;
  nn->rth=0;
  nn->left=NULL;
  nn->right=NULL;
  cout<<"\nEnter the value:";
  cin>>nn->data;

  if(root==NULL)
  {

    root=nn;
    dummy=new node;
    dummy->lth=0;
    dummy->rth=0;
    dummy->right=NULL;
    dummy->left=root;
    dummy->data=-999;

  }
  else
  {
    insert(root,nn);
  }
}

void thread::insert(node *root,node *nn)
{
  if(nn->data<root->data)
  {
    if(root->lth==0)
    {
      nn->left=root->left;
      nn->right=root;
      root->left=nn;
      root->lth=1;
    }
    else
    {
      insert(root->left,nn);
    }
  }

  else if(nn->data>root->data)
  {
    if(root->rth==0)
    {
      nn->right=root->right;
      nn->left=root;
      root->right=nn;
      root->rth=1;
    }
    else
    {
      insert(root->right,nn);
    }
  }
  else
  {
    cout<<"\nDuplicate value Entered"<<endl;
  }
}

void thread::inorder()
{
  temp=root;
  while(temp!=dummy)
  {
    while(temp->lth==1)
    {
      temp=temp->left;
    }
    cout<<temp->data<<"\t";
    while(temp->rth==0)
    {
      temp=temp->right;
      if(temp==dummy)
      return;
      cout<<temp->data<<"\t";
    }
    temp=temp->right;
  }
}

int main()
{
  cout<<"\n---Threaded Binary Tree---"<<endl;
  int opt;
  char ch;
  thread t;
  do
  {
      cout<<"\n1.Create TBT\n2.Display_inorder\n3.Exit\n";
      cout<<"Your Option:";
      cin>>opt;

      switch(opt)
      {
        case 1:
               do
               {
                t.create();
                cout<<"\nTo enter the more nodes press y or press n to exit"<<endl;
                cin>>ch;
              } while(ch!='n');
              break;
        case 2:t.inorder();
              break;
        case 3:cout<<"\n---Exiting the Program---\n";
               break;
      }
  }
  while(opt!=3);
  return 0;
}
