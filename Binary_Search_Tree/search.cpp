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


Node* search(Node* root,int k)
{
  if(root==NULL) return NULL;
  if(root->data == k) return root;
  if(root->data>k) return search(root->left,k); 
  return search(root->right,k);
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

int main()
{

  Node* root = NULL;
  root = insertBST(root,5);
  insertBST(root,1);
  insertBST(root,3);
  insertBST(root,4);
  insertBST(root,2);
  insertBST(root,7);

  printBST(root);
  cout<<endl;

  int k;
  cin>>k;

  Node* srch = search(root,k);
  if(srch) cout<<"found";
  else cout<<"not found";
 

}
