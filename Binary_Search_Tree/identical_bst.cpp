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

bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL&&root2==NULL) return true;
    if(root1!=NULL&&root2==NULL) return false;
    if(root1==NULL&&root2!=NULL) return false;

    bool leftTree = isIdentical(root1->left,root2->left);
    bool rightTree = isIdentical(root1->right,root2->right);
    bool dataTree = root1->data==root2->data?true:false;

    if(leftTree&&rightTree&&dataTree) return true;
    else return false;
}

int main()
{

  Node* root1 = new Node(4);
  root1->left = new Node(2);
  root1->right = new Node(5);
  root1->left->left = new Node(1);
  root1->left->right = new Node(3);
  root1->right->right = new Node(6);
  
  Node* root2 = new Node(4);
  root2->left = new Node(9);
  root2->right = new Node(5);
  root2->left->left = new Node(1);
  root2->left->right = new Node(3);
  root2->right->right = new Node(6);

  if(isIdentical(root1,root2)) cout<<"yes";
  else cout<<"NO";

}