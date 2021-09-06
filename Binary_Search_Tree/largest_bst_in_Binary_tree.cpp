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


vector<int> chk_bst(Node* root)
{
    if(root ==NULL) return {1,0,INT_MAX,INT_MIN};
    if(root->left==NULL&&root->right==NULL) return{1,1,root->data,root->data};

    vector<int> l = chk_bst(root->left);
    vector<int> r = chk_bst(root->right);
    
    if(l[0]==1&&r[0]==1)
    {
        if(root->data>l[3]&&root->data<r[2])
        {
            int x = l[2]==INT_MAX ? root->data:l[2];
            int y = r[3]==INT_MIN ? root->data:r[3];

            return {1,l[1]+r[1]+1,x,y};
        }
    }

    return {0,max(l[1],r[1]),0,0};
}


int largest_bst(Node* root)
{
   vector<int> arr =  chk_bst(root);
   return arr[1];
}


int main()
{

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  cout<<largest_bst(root);

}
