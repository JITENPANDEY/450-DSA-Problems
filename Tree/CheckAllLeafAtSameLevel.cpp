 bool flag = true;
    int findHeight(Node*root){
      if(root==NULL)
        return 0;
        
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        
        if(lh!=rh && root->left && root->right)
        flag = false;
        
        return 1+max(lh, rh);
    }
    /*You are required to complete this method*/

    bool check(Node *root)
    {
        //Your code her
        findHeight(root);
        return flag;
        
    }