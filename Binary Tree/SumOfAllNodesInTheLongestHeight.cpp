int maxSum = 0, maxHeight = 0;
void solve(Node* root, int sum, int height){
    if(!root)
        return;
    sum +=root->data;
    if(height>=maxHeight){
        maxSum = max(sum, maxSum);
        maxHeight = height;
    }
    solve(root->left, sum, height+1);
    solve(root->right, sum, height+1);
}
int sumOfLongRootToLeafPath(Node *root)
{
    //code here
    if(!root) return 0;
    
    solve(root, 0, 0);
    return maxSum;
}