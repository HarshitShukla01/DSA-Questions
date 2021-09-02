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


void smallest_kth(Node* root,int& i ,int k,int& sml)
{
   if(root==NULL) return;

   smallest_kth(root->left,i,k,sml);

   if(i==k) {sml = root->data; i++; return;}
   i++;

   smallest_kth(root->right,i,k,sml);
}

void largest_kth(Node* root,int& i ,int k,int& lrg)
{
   if(root==NULL) return;
   
   largest_kth(root->right,i , k, lrg);

   if(i==k) {lrg = root->data; i++; return;}
   i++;
   
   largest_kth(root->left,i , k, lrg);
   
}

void  traverseBST(Node* root,vector<Node*>& arr)
{
   if(root==NULL) return;
   traverseBST(root->left,arr);
   if(root)arr.push_back(root);
   traverseBST(root->right,arr);
}
 
void kth_smallest_and_largest(Node* root,int& lrg,int& sml,int k)
{
    if (root == NULL) return;
    
    int i=1;
    smallest_kth(root,i,k,sml);
    i=1;
    largest_kth(root,i,k,lrg);
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
  
  int lrg=0,sml=0,k=1;
  kth_smallest_and_largest(root,lrg,sml,k);
  cout<<"k = "<<k<<endl;
  cout<<"small = "<<sml<<endl;
  cout<<"large = "<<lrg<<endl;

}
