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


bool chk_bst(Node* root,int l,int h)
{
    if(root ==NULL) return false;
    if(l>=h) return true;
    bool b1 = chk_bst(root->left,l,root->data-1);
    bool b2 = chk_bst(root->right,root->data+1,h);

    if(b1||b2) return true;
    else return false;
}


bool find_deadEnd(Node* root)
{

   return chk_bst(root,1,INT_MAX);
}


int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  cout<<find_deadEnd(root);

}
