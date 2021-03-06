//recursion
void recur(TreeNode* root, vector<int>&ans){
    if(root){
        ans.push_back(root->val);
        recur(root->left, ans);
        recur(root->right,ans);
    }
}
//without recursion
void withoutRecur(TreeNode* root, vector<int>&ans){
    stack<TreeNode*>s;
    TreeNode* curr=root;
    while( !s.empty()  or curr!=NULL){
        //if root is not NULL-> push it and go to left
        if(curr!=NULL){
            s.push(curr);
            ans.push_back(curr->val);
            curr=curr->left;
        }
        //if root is NULL->means left is NULL-> then pop, go to right
        else{
            curr = s.top();
            s.pop();
            curr=curr->right;
            
        }
    }
}

//without stack
    void morrisInorder(TreeNode* root, vector<int>&ans){
        TreeNode* curr=root;
        while(curr!=NULL){
            
            //if curr->left is null the print and go to right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                //go to the rightmost node of the left subtree
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr){
                    temp=temp->right;
                }
                // and make the thread when temp->right is NULL
                if(temp->right==NULL){
                    temp->right = curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }else{
                    temp->right = NULL;
                    curr = curr->right;
                }
                
            }
            
        }

    }