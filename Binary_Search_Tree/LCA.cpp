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

Node* LCA(Node *root, int n1, int n2)
{
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
 
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
 
    return root;
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
  Node* lca = LCA(root,2,5);
  cout<<"LCA of 2 & 5 = "<<lca->data;
}
