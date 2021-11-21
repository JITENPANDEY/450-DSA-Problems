int findHeight(Node *root,int x)
{
    if(!root)
        return 1000000;
    if(root->data==x)
        return 0;
    
    return 1+min(findHeight(root->left, x),findHeight(root->right, x));
}