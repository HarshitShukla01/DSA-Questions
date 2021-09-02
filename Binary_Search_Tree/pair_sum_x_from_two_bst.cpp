#include<bits/stdc++.h>
using namespace std;

#define ump unordered_map<int,int>

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

void traverse_bst(Node*  root,ump& mp)
{
   if(root==NULL) return;
   traverse_bst(root->left,mp);
   mp[root->data]=1;
   traverse_bst(root->right,mp);
}

void find_all(Node*  root,ump& mp,int x)
{
   if(root==NULL) return;
   find_all(root->left,mp,x);
   if(mp[x-root->data]) mp[x-root->data]++;
   find_all(root->right,mp,x);
}

int pair_find(Node* root1,Node* root2,int x)
{
    ump mp;
    traverse_bst(root2,mp);
    find_all(root1,mp,x);
    
    int count=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>1) count++;
    }

    return count;

}

int main()
{

  Node* root1 = new Node(13);
  root1->left = new Node(2);
  root1->right = new Node(18);
  root1->left->left = new Node(1);
  root1->left->right = new Node(6);
  root1->right->right = new Node(19);
  
  Node* root2 = new Node(14);
  root2->left = new Node(11);
  root2->right = new Node(16);
  root2->left->left = new Node(3);
  root2->left->right = new Node(12);
  root2->right->right = new Node(17);

  cout<<"BST - 1 : ";
  printBST(root1);
  cout<<endl;
  cout<<"BST - 2 : ";
  printBST(root2);
  cout<<endl;
  
  int x;
  cout<<"enter x = ";
  cin>>x;
  cout<<"no of pairs = "<<pair_find(root1,root2,x);

}