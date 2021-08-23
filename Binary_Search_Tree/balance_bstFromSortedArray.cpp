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

Node* createBST( int arr[],int st,int end)
{
   if(st>end) return NULL;

    int mid=(end+st)/2;
    Node* temp = new Node(arr[mid]);
    temp->left = createBST(arr,st,mid-1);
    temp->right = createBST(arr,mid+1,end);
    return temp;
}

int main()
{
  
  int arr[] = {1,2,3,4,5,6};
  int n=6;
  Node* root = createBST(arr,0,n-1);

  printBST(root);

}
