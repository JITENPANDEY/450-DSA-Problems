class Node{
public:
    int min, max, sum;
    bool isBST;
    Node(int min, int max, int sum, bool isBST){
        this->min = min;
        this->max = max;
        this->sum = sum;
        this->isBST = isBST;
    }
};
class Solution {
public:
    Node postorder(TreeNode*root, int &res){
        if(root==NULL) // sum  =0, min = INTMAX, max = INTMIN
            return Node(INT_MAX, INT_MIN, 0,true);
        
        Node left = postorder(root->left, res);
        Node right = postorder(root->right, res);
        
        bool isBST = (left.isBST and right.isBST and left.max < root->val and root->val < right.min);
        int sum = root -> val + left.sum + right.sum;
        //cout<<isBST<<endl;
        if(isBST) res = max(res, sum);
        return Node(min(root -> val, left.min), max(root -> val, right.max) , sum, isBST);
        
    }
    int maxSumBST(TreeNode* root) {
        int res= 0;
        Node ans = postorder(root, res);
        return res;
    }
};