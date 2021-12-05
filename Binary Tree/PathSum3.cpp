/* TC = O(N^2)
    int helperSum(TreeNode* root, int targetSum){
        if(!root) return 0;
        return (targetSum==root->val) + helperSum(root->left, targetSum-root->val) + helperSum(root->right, targetSum-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return helperSum(root, targetSum) + pathSum(root->left, targetSum) +pathSum(root->right, targetSum);
    }
    */
    // TC = O(N)
    unordered_map<int, int> map;
    int count = 0;
    
    void countPathSum(TreeNode* root, int target, int sum){
        if(!root)
            return;
        sum += root->val;        //Path sum from root
        if(sum == target)
            count++;
        if(map.find(sum - target) != map.end()) //checking whether any target sum path present in the path from root to the current node
            count += map[sum - target];
        map[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        map[sum]--;      //After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPathSum(root, targetSum, 0);
        return count;
    }