#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        right=NULL;
        left=NULL;
    }
};

void  printBST(Node* root)
{
   if(root==NULL) return;
   printBST(root->left);
   cout<<root->data<<" ";
   printBST(root->right);
}

void  traverseBST(Node* root,vector<int>& arr)
{
   if(root==NULL) return;
   traverseBST(root->left,arr);
   if(root)arr.push_back(root->data);
   traverseBST(root->right,arr);
}

void  value_change(Node* root,vector<int> arr,int& i)
{
   if(root==NULL) return;
   value_change(root->left,arr,i);
   root->data=arr[i];
   i++;
   value_change(root->right,arr,i);
}

void binary_to_bst(Node *root)
{
    if (root == NULL) return;
    vector<int>arr;
    traverseBST(root,arr);
    sort(arr.begin(),arr.end());
    int i=0;
    value_change(root,arr,i);

    
}



int main()
{

  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  cout<<"before = ";
  printBST(root);
  binary_to_bst(root);
  cout<<endl;
  cout<<"after = ";
  printBST(root);
}
