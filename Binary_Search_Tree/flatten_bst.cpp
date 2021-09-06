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
void inorder(Node* curr, Node*& prev)
{
    if (curr == NULL) return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

Node* flatten_bst(Node* root)
{
   Node* prev  = new Node(-1);
   Node* point = prev;
   inorder(root,prev);

   point=point->right;
   point->left = NULL;  
   return point;

}


int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  Node* amt = flatten_bst(root);
  printBST(amt);
}
