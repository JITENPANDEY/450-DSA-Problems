TreeNode* getSuccessor(TreeNode* node){
        while(node->left)
            node=node->left;
        return node;
    }
    TreeNode* deleteNodeHelper(TreeNode* root){
        //if left is NULL then return right and vice versa
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        
        //attch left child to the successor of the given node and return right child of the given node
        TreeNode* leftChild = root->left;
        TreeNode* successor = getSuccessor(root->right);
        successor->left = leftChild;
        TreeNode*rightChild = root->right;
        delete root;
        return rightChild;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL) return NULL;
        
        if(root->val==key)
            return deleteNodeHelper(root);
        
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left && root->left->val==key){
                    root->left = deleteNodeHelper(root->left);
                    break;
                }else{
                    root= root->left;
                }
            }else{
                if(root->right && root->right->val==key){
                    root->right = deleteNodeHelper(root->right);
                    break;
                }else{
                    root= root->right;
                }
            }
        }
        return dummy;      
    }