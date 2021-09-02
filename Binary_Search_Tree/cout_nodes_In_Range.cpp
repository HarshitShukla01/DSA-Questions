#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        right=left=NULL;
    }
};

void  printBST(Node* root)
{
   if(root==NULL) return;
   printBST(root->left);
   cout<<root->data<<" ";
   printBST(root->right);
}

void count(Node* root,int l,int h, int& c)
{
  if(root==NULL) return;
   count(root->left,l,h,c);
   if(root->data>=l&&root->data<=h) c++;
   count(root->right,l,h,c);
}

int getCount(Node *root, int l, int h)
{
 
  if(root==NULL) return -1;
  int c=0;
  count(root,l,h,c);
  return c;
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  cout<<"BST : ";
  printBST(root);
  cout<<endl;
  
  int l=2,h=5;
  cout<<"Node in range ("<<l<<" , "<<h<<")  : "<<getCount(root,l,h);

}