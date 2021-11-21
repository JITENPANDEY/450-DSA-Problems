int checkTree(Node *root,bool &flag){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        int lsum = checkTree(root->left,flag);
        int rsum = checkTree(root->right,flag);
        int sum = lsum+rsum;
        if(root->data != sum){
            flag = false;
        }
        return sum+(root->data);
    }
    bool isSumTree(Node* root)
    {
        bool flag = true;
        checkTree(root,flag);
        return flag;
    }