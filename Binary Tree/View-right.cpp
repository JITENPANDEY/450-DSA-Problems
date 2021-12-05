int maxLevel=-1;
vector<int> ans;
void recur(TreeNode* root, int currLevel){
    if(!root)
        return;
    if(currLevel> maxLevel){
        ans.push_back(root->val);
        maxLevel = currLevel;
    }
    recur(root->right, currLevel+1);
    recur(root->left, currLevel+1);
}
vector<int> rightSideView(TreeNode* root) {
    recur(root, 0);
    return ans;
}