int Ceil(node* root, int input)
{
    // Base case
    if (root == NULL)
        return -1;
 
    // We found equal key
    if (root->key == input)
        return root->key;
 
    // If root's key is smaller, ceil must be in right subtree
    if (root->key < input)
        return Ceil(root->right, input);
 
    // Else, either left subtree or root has the ceil value
    int ceil = Ceil(root->left, input);
    return (ceil >= input) ? ceil : root->key;
}
vector<int> Ceil(node* root, int key)
{ 
  int floor =-1, ceil =-1;
  while (root) {
 
        if (root->data == key) {
            ceil = root->data;
            floor = root->data;
            return;
        }
 
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return {ceil, floor};
}