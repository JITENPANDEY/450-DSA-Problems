//recursion
void recur(TreeNode* root, vector<int>&ans){
  if(root){
      ans.push_back(root->val);
      recur(root->left, ans);
      recur(root->right,ans);
  }
}
//using two stack
void withoutRecur1(TreeNode* root, vector<int>&ans){
  stack<TreeNode*>s;
  stack<TreeNode*>ansStack;
    
  if(root)
  s.push(root);
  while( !s.empty()){
        TreeNode* curr=s.top(); s.pop();
        ansStack.push(curr);
        if(curr->left){
          s.push(curr->left);
        }
        if(curr->right){
          s.push(curr->right);
        }
        
  }
  while(!ansStack.empty()){
    ans.push_back(ansStack.top()->val);
    ansStack.pop();
  }
}

//using one stack
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