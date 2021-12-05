    int sumTree(Node *root){
        if(!root) return 0;
        
        int l = sumTree(root->left);
        int r = sumTree(root->right);
        //ifleaf node
        if(!root->left && !root->right){
            int sum = root->data;
            root->data = 0;
            return sum;
        }else{
            int sum = l + r + root->data;
            root->data = l+r;
            return sum;
        }
        
    }
    void toSumTree(Node *node)
    {
        sumTree(node);
    }