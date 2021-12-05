bool helper(TreeNode *left, TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        if(left==NULL || right==NULL)
            return false;
        
        if(left->val!=right->val)
            return false;
        
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || helper(root->left, root->right);
    }

    // Iterative solution
    
    bool isSymmetric(TreeNode* root) {
        TreeNode *left, *right;
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            left=q.front();
            q.pop();
            right=q.front();
            q.pop();
            if(left==NULL && right==NULL)
                continue;
            if(left==NULL || right==NULL)
                return false;
            if(left->val!=right->val)
                return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }