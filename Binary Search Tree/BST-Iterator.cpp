class BSTIterator {
private :
    stack<TreeNode*> s;
    
    void push(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode* next = s.top();
        s.pop();
        
        if(next->right)
            push(next->right);
        return next->val;
        
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

SC = O(H)