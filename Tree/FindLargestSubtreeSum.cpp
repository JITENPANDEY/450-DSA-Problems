int ans = INT_MIN;
int postorder(TreeNode* root){
    if(!root) return 0;
    
    int leftSum = postorder(root->left);
    int rightSum = postorder(root->right);
    int sum=root->val + leftSum + rightSum;
    ans = max(ans, sum);
    
    return sum;
}
int findFrequentTreeSum(TreeNode* root) {
    postorder(root);
    return ans;
}