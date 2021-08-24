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

//using extra space
/*
void  printZigZag(Node* root)
{
   vector<int> arr;
   if(root==NULL) return ;

   queue<Node*> curr;
   curr.push(root);
   bool ltr = true;
 
   while(!curr.empty())
   {
       int n= curr.size();
       int m= arr.size();
       for(int i=0;i<n;i++)
       {
           Node* t= curr.front();
           curr.pop();
           arr.push_back(t->data);
          if(t->left) curr.push(t->left);
          if(t->right) curr.push(t->right);
       }
       if(!ltr) reverse(arr.begin()+m,arr.end());

       ltr=!ltr;
   }
   
   for(int i=0;i<arr.size();i++)
   cout<<arr[i]<<" ";
}
*/

void  printZigZag(Node* root)
{
   if(root==NULL) return ;

   stack<Node*> curr;
   stack<Node*> next;
   bool ltr = true;
   curr.push(root);
 
   while(!curr.empty())
   {
       Node* t= curr.top();
       curr.pop();

       if(t)
       {
        cout<<t->data<<" ";
        if(ltr)
        {
          if(t->left) next.push(t->left);
          if(t->right) next.push(t->right);
        }
        else{
         if(t->right) next.push(t->right);
         if(t->left) next.push(t->left);
        }
      }
       
     if(curr.empty()){
         ltr=!ltr;
         swap(curr,next);
     }
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
  
  printZigZag(root);

}
