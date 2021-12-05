Node* mirrorHelper(Node *node){
    if(!node) return NULL;
    
    Node* left = mirrorHelper(node->left);
    Node* right = mirrorHelper(node->right);
    
    node->left = right;
    node->right = left;
    return node;
}
void mirror(Node* node) {
    // code here
    mirrorHelper(node);
    
}