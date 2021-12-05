Node* lowestCommonAncestor(Node* root, int p, int q) {
        if(root==NULL || root->data==p || root->data==q)
            return root;
        Node *left = lowestCommonAncestor(root->left,p,q);
        Node *right = lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL)
            return root;
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        return NULL;
    }
    //optimized the calls
    int findHeight(Node *root,int x)
    {
        if(!root)
            return 1000000;
        if(root->data==x)
            return 0;
        int lh = findHeight(root->left, x);
        if(lh<1000000)
        return lh+1;
        
        int rh = findHeight(root->right, x);
        
        return 1+min(lh,rh);
    }

    int findHeight(Node *root,int x)
    {
        if(!root)
            return 1000000;
        if(root->data==x)
            return 0;
        
        return 1+min(findHeight(root->left, x),findHeight(root->right, x));
    }

    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* LCA = lowestCommonAncestor(root, a, b);
        int x=findHeight(LCA,a);
        int y=findHeight(LCA,b);
        //cout<<x;
        return x+y;
    }