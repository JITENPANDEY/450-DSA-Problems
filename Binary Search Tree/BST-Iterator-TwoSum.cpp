class BSTIterator {
private :
    stack<TreeNode*> s;
    bool forward;
    
    // if forward = true means find next()
    // if forward = false means find before()
    
    void push(TreeNode* root){
        while(root){
            s.push(root);
            if(forward)
                root=root->left;
            else
                root=root->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool forward) {
        this->forward = forward;
        push(root);
    }
    
    int next() {
        TreeNode* tempNode = s.top();
        s.pop();
        if(forward==true){
            if(tempNode->right)
            push(tempNode->right);
        }else{
            if(tempNode->left)
            push(tempNode->left);
        }
        
        return tempNode->val;
        
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator leftPointer(root, true); // go next
        BSTIterator rightPointer(root, false); // go before
        
        int i = leftPointer.next(); // it wiil give me the next number in forward direction
        int j = rightPointer.next(); // it wiil give me the before number in backward direction
        
        while(i<j){
            if(i+j == k) return true;
            if(i+j>k) j = rightPointer.next();
            else i= leftPointer.next();
        }
        return false;
    }
};