string serializer(TreeNode* root, unordered_map<string, int>&mp, vector<TreeNode*>&ans){
        if(root==NULL) return "X";
        
        string leftSubtree = serializer(root->left, mp,ans);
        string rightSubtree = serializer(root->right, mp,ans);
        
        string s = to_string(root->val) +","+ leftSubtree +","+ rightSubtree;
        if(mp[s]++ == 1)
            ans.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        cout<<serializer(root, mp,ans);
        return ans;
    }