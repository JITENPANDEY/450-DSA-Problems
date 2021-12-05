vector<int>ans;
int maxCount =0;
unordered_map<int,int>mp;
int postorder(TreeNode* root){
    if(!root) return 0;
    
    int leftSum = postorder(root->left);
    int rightSum = postorder(root->right);
    int sum=root->val + leftSum + rightSum;
    mp[sum]++;
    maxCount = max(maxCount, mp[sum]);
    return sum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    postorder(root);
    for(auto i: mp){
        if(i.second==maxCount)
        ans.push_back(i.first);
    }
    
    return ans;
}