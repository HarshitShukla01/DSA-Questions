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

Node* inorderPredecessor(Node* root)
{
  Node* curr =root;
  while(curr&&curr->right)
  {
    curr = curr->right;
  }
  return curr;
}

Node* inorderSucessor(Node* root)
{
  Node* curr =root;
  while(curr&&curr->left)
  {
    curr = curr->left;
  }
  return curr;
}

void findBST(Node* root,int k,Node*& pre, Node*& suc)
{
  if (root == NULL) return;

   if(root->data<k) findBST(root->right,k,pre,suc);
   else if(root->data>k) findBST(root->left,k,pre,suc);
   else
   {
     pre = inorderPredecessor(root->left);
     suc = inorderSucessor(root->right);
   }
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);
  cout<<"before = ";
  printBST(root);
  cout<<endl;
  int k;
  cout<<"enter number =  ";
  cin>>k;
  Node* pre = NULL;
  Node* suc = NULL;
  findBST(root,k,pre,suc);
  int f1 = pre!=NULL ? pre->data:-1;
  int f2 = suc!=NULL? suc->data:-1;
  cout<<"Inorder Predecessor = "<<f1<<endl;
  cout<<"Inorder Successor = "<<f2<<endl;


}
