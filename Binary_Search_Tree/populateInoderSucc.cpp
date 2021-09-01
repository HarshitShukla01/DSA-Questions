#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right,*next;
    Node(int value)
    {
        data=value;
        right=left=next=NULL;
    }
};

void  printBST(Node* root)
{
   if(root==NULL) return;
   printBST(root->left);
   cout<<root->data<<" ";
   printBST(root->right);
}

void  printBSTNext(Node* root)
{
   if(root==NULL) return;
   printBSTNext(root->left);
   if(root->next)
   cout<<root->data<<" -> "<<root->next->data<<endl;
   else 
   cout<<root->data<<" -> "<<"-1"<<endl;
   printBSTNext(root->right);
}

void  traverseBST(Node* root,vector<Node*>& arr)
{
   if(root==NULL) return;
   traverseBST(root->left,arr);
   if(root)arr.push_back(root);
   traverseBST(root->right,arr);
}
 
    void populateNext(Node *root)
    {
        if (root == NULL) return;

        vector<Node*>arr;
        traverseBST(root,arr);
       for(int i=0;i<arr.size();i++)
       {
           if(i==arr.size()-1) arr[i]->next=NULL;
           else arr[i]->next=arr[i+1];
       }
       
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
  populateNext(root);
  cout<<"next : "<<endl;
  printBSTNext(root);
}
