// Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans ="";
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node==NULL) ans+="X,";
            else{
                ans+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }        
        }
        //cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            //read next character one by one for left and right child
            getline(s, str, ',');
            if(str=="X")
                node->left = NULL;
            else{
                TreeNode *left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }
            
            getline(s, str, ',');
            if(str=="X")
                node->right = NULL;
            else{
                TreeNode *right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }  
        }
        return root;
    }