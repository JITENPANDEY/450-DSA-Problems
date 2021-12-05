//recursion
 int getMaxSum(Node *root) 
{
    // Add your code here
    if(!root) return 0;
    
    int include = root->data;
    if(root->left) include += getMaxSum(root->left->left) + getMaxSum(root->left->right);
    if(root->right) include += getMaxSum(root->right->left) + getMaxSum(root->right->right);
    
    int exclude = 0;
    exclude += getMaxSum(root->left) + getMaxSum(root->right);

    return max(include, exclude);
}

//memoization
unordered_map<Node*, int> dp;
int getMaxSum(Node *root) 
{
    // Add your code here
    if(!root) return 0;
    if(dp[root]) return dp[root];
    
    int include = root->data;
    if(root->left) include += getMaxSum(root->left->left) + getMaxSum(root->left->right);
    if(root->right) include += getMaxSum(root->right->left) + getMaxSum(root->right->right);
    
    int exclude = 0;
    exclude += getMaxSum(root->left) + getMaxSum(root->right);

    return dp[root] = max(include, exclude);
}