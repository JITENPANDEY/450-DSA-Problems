int height(Node* root){
    return (!root)?0: 1+max(height(root->left), height(root->right));
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
        return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    
    return false;
    
    
}