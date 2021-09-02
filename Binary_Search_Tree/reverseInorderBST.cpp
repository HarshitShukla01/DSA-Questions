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

void  printReverseBST(Node* root)
{
   if(root==NULL) return;
   printReverseBST(root->right);
   cout<<root->data<<" ";
   printReverseBST(root->left);
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  cout<<"normal = ";
  printBST(root);
  cout<<endl;
  
  cout<<"reverse = ";
  printReverseBST(root);
  cout<<endl;

}
