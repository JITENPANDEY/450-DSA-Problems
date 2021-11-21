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
void withoutRecur2(TreeNode* root, vector<int>&ans){
    stack<TreeNode*>s;
    TreeNode* curr=root;
    TreeNode* prev=NULL;
    while( !s.empty()  or curr!=NULL){
        //if root is not NULL-> push it and go to left
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        //if root is NULL->means left is NULL->
        //and check if prev is right child of top element
        else{
            curr = s.top();
            if(curr->right==NULL or curr->right==prev){
                s.pop();
                ans.push_back(curr->val);
                prev=curr;
                curr=NULL;
            }
            else
                curr=curr->right; 

        }
    }
}