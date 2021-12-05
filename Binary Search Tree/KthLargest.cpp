int count=0, ans;
    void inorder(Node* root, int k){
        if(root){
            inorder(root->right, k);
            count++;
            if(count==k){
                ans = root->data;
                return;
            }
            inorder(root->left, k);
        }
        
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        inorder(root, K);
        //cout<<ans;
        return ans;
    }