 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        return (p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //basic case for s, we're traversing only the big tree s
        if (root == NULL) {
            return false;
        }
		//check if the 2 trees are the same (if s is given to be the same as t this will stop here)
        if (isSameTree(root, subRoot) == false) {
		//if s is not equal to t we'll assume that s is larger than t and will split the search to it's left node and right node.
            return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);    
        }
        return true;
        
    }
    
    //we will compare both the trees
    //if bot trees are not equal then there is a posibility that the subtree will be same either left subtree              or rightsubtree

    //         else the main tree doesnot contyain the subtree