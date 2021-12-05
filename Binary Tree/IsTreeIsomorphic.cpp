bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
if(root1==nullptr and root2==nullptr) 
        return true;
    if(root1==nullptr or root2==nullptr) 
        return false;
    if(root1->data!=root2->data)
        return false;
    
    return 
        (isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right))
        or
        (isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left));
}