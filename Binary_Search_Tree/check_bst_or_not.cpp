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

int maxL(Node* root)
{
  if(root==NULL) return INT_MIN;
  return max(root->data,max(maxL(root->left),maxL(root->right)));

}
int minR(Node* root)
{
  if(root==NULL) return INT_MAX;
  return min(root->data,min(minR(root->left),minR(root->right)));
}

bool isBST(Node* root)
{
    if(root==NULL) return true;
    bool l = (root->left==NULL||maxL(root->left)<root->data) ? true:false;
    bool r = (root->right==NULL||minR(root->right)>root->data) ? true:false;
    
    bool chkL = isBST(root->left);
    bool chkR = isBST(root->right);

    if(l&&r&&chkL&&chkR) return true;
    else return false;
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(1);
  root->right = new Node(5);
  root->left->left = new Node(2);
  root->left->right = new Node(3);
  root->right->right = new Node(6);
  printBST(root);
  cout<<endl;
  
  if(isBST(root)) cout<<"yes";
  else cout<<"no";

  

}
