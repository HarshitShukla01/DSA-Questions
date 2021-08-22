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
Node* preToBST(int pre[],int n)
{
  Node* rt = NULL;
  rt= insertBST(rt,pre[0]);
  for(int i=1;i<n;i++)
  {
      insertBST(rt,pre[i]);
  } 
  return rt;
}
int main()
{

  Node* root = NULL;
  int pre[] = { 10, 5, 1, 7, 40, 50 };
  int n = sizeof(pre) / sizeof(pre[0]);
  root= preToBST(pre,n);
  printBST(root);

}
