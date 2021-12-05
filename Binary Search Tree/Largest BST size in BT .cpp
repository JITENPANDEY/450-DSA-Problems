class TreeNode{
    public:
    int min, max, size;
    bool isBST;
    TreeNode(int min, int max, int size, bool isBST){
        this->min = min;
        this->max= max;
        this->size = size;
        this->isBST = isBST;
    }
};
class Solution{
    public:
    TreeNode postorder(Node* root, int &ans){
        if(root==NULL)
            return TreeNode(INT_MAX, INT_MIN, 0, true);
            
        TreeNode leftNode = postorder(root->left, ans);
        TreeNode rightNode = postorder(root->right, ans);
        
        bool isBST = (leftNode.isBST && rightNode.isBST 
        && leftNode.max <root->data && root->data < rightNode.min);
        int size = 1+leftNode.size +rightNode.size;
        if(isBST) ans = max(ans, size);
        return TreeNode(min(root->data, leftNode.min), max(root->data, rightNode.max), size, isBST);
        
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = 0;
    	postorder(root, ans);
    	return ans;
    }
};