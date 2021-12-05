int count=0, ans;
void inorder(Node* root, int k){
    if(root){
        inorder(root->left, k);
        count++;
        if(count==k){
            ans = root->data;
            return;
        }
        inorder(root->right, k);
    }
    
}
int kthLargest(Node *root, int K)
{
    //Your code here
    inorder(root, K);
    //cout<<ans;
    return ans;
}