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

void traverse_bst(Node* root,int &n)
{
   if(root==NULL) return;
   traverse_bst(root->left,n);
   n++;
   traverse_bst(root->right,n);
}

void odd_find(Node* root,int i,int& j,int& med)
{
   if(root==NULL) return;
   odd_find(root->left,i,j,med);
   if(i==j) {med=root->data; return;}
   j++;
   odd_find(root->right,i,j,med);
}

void even_find(Node* root,int i,int& j,int& med)
{
   if(root==NULL) return;
   even_find(root->left,i,j,med);
   if(i==j) {med=root->data;}
   if(i+1==j) {med=(med+root->data)/2; return;}
   j++;
   even_find(root->right,i,j,med);
}

int find_median(Node* root)
{
    if(root==NULL) return -1;
    int n=0;
    traverse_bst(root,n);
    int i=n/2,j=0;
    if(n/2==0) even_find(root,i,j,med);
    else odd_find(root,i,j,med);

    return med;
}

int main()
{

  Node* root = new Node(4);
  root->left = new Node(1);
  root->right = new Node(5);
  root->left->left = new Node(2);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  cout<<"BST : ";
  printBST(root);
  cout<<endl;
  

  cout<<"median  : "<<find_median(root);

}
