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
//
/*
int catlan(int n)
{
    if(n<=1) return 1;
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=res+(catlan(i)*catlan(n-i-1));
    }

    return res;

}
*/

//n^2
unsigned long int catlan(unsigned int n)
{
    unsigned long int catl[n + 1];
    catl[0] = catl[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        catl[i] = 0;
        for (int j = 0; j < i; j++)
            catl[i] += catl[j] * catl[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];

}
int main()
{
  
for(unsigned int i=0;i<11;i++)
cout<<catlan(i)<<endl;

}
