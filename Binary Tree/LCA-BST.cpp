// TC = O(LogN)
/*Let large = max(p.val, q.val), small = min(p.val, q.val).
    We keep iterate root in our BST:
        If root.val > large then both node p and q belong to the left subtree, go to left by root = root.left.
        If root.val < small then both node p and q belong to the right subtree, go to right by root = root.right.
        Now, small <= root.val <= large the current root is the LCA between q and p.
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small = min(p->val, q->val);
        int large = max(p->val, q->val);
        while (root != NULL) {
            if (root->val > large) // p, q belong to the left subtree
                root = root->left;
            else if (root->val < small) // p, q belong to the right subtree
                root = root->right;
            else // Now, small <= root.val <= large -> This root is the LCA between p and q
                return root;
        }
        return NULL;

    }