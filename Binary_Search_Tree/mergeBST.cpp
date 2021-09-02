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

Node* insertBST(Node* root,int k)
{
  if(root == NULL) return new Node(k);

  if(root->data>k)
    root->left = insertBST(root->left,k);
  else
    root->right = insertBST(root->right,k);

  return root;
}

void merge_bst(Node* root1,Node* root2)
{
    if(root1==NULL&&root2==NULL) return;
    if(root1==NULL) {root1=root2; return;}
    if(root2==NULL) return;

    merge_bst(root1,root2->left);
    insertBST(root1,root2->data);
    merge_bst(root1,root2->right);
}

int main()
{

  Node* root1 = new Node(13);
  root1->left = new Node(2);
  root1->right = new Node(18);
  root1->left->left = new Node(1);
  root1->left->right = new Node(6);
  root1->right->right = new Node(19);
  
  Node* root2 = new Node(14);
  root2->left = new Node(11);
  root2->right = new Node(16);
  root2->left->left = new Node(3);
  root2->left->right = new Node(12);
  root2->right->right = new Node(17);

  cout<<"BST - 1 : ";
  printBST(root1);
  cout<<endl;
  cout<<"BST - 2 : ";
  printBST(root2);
  cout<<endl;
  
  merge_bst(root1,root2);
  cout<<"BST - final : ";
  printBST(root1);
  cout<<endl;

}