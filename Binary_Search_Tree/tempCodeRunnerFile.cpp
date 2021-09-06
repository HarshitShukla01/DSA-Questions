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