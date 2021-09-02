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

Node* find_Succ(Node* root,int k,Node*& succ)
{
    if(root==NULL) return new Node(k);

    if(root->data>k){
        succ=root;
        root->left=find_Succ(root->left,k,succ);
    }
    else if(root->data<k){
        root->right=find_Succ(root->right,k,succ);
    }

    return root;
}


void replace(int arr[],int n)
{
  Node* root=NULL;
  for(int i=n-1;i>=0;i--)
  {
      Node* succ=NULL;
      
      root=find_Succ(root,arr[i],succ);

      if(succ) arr[i]=succ->data;
      else arr[i]=-1;
  }
}

int main()
{
  int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
  int n=sizeof(arr)/sizeof(arr[0]);
  
  cout<<"before  : ";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";

  cout<<endl;
  
  replace(arr,n);
  
  cout<<"after  : ";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}