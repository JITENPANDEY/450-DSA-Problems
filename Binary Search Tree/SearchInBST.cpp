Node* search(Node*root, int target){
  if(root == NULL || root->key == key) return root;
  if(target<root->val)
    return search(root->left, target);

  return search(root->right, target); 
}