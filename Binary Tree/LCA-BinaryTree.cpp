 //1. if root is null or my curr node is either p or q then return root.
    //2. go to the left and find for p or q
    //3. go to left find for p and q
    //4. if at any current node get both p and q then that node will be the LCA
    //5. if from any node if u get null from left and not null from right then return right
    //6. if from any node if u get null from right and not null from left then return left
    // if both left and right are NULL return null
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL)
            return root;
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return NULL;
    }