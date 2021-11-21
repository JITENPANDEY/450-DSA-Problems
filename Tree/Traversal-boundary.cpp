/* 
We break the problem in 3 parts: 
  1. Print the left boundary in top-down manner. 
  2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
  …..2.1 Print all leaf nodes of left sub-tree from left to right. 
  …..2.2 Print all leaf nodes of right subtree from left to right. 
  3. Print the right boundary in bottom-up manner.
*/

void printLeaves(Node *root, vector<int> &ans){
        if(root){
            printLeaves(root->left, ans);
            if(!root->left && !root->right){
                ans.push_back(root->data);
            }
            printLeaves(root->right, ans);
        }
        
    }
    void printRightBoundary(Node *root, vector<int> &ans){
        if(!root)
            return;
        if(root->right){
            printRightBoundary(root->right, ans);
            ans.push_back(root->data);
            
        }else if(root->left){
            printRightBoundary(root->left, ans);
            ans.push_back(root->data);
        }
            
    }
    void printLeftBoundary(Node *root, vector<int> &ans){
        if(!root)
            return;
        if(root->left){
            ans.push_back(root->data);
            printLeftBoundary(root->left, ans);
        }else if(root->right){
            ans.push_back(root->data);
            printLeftBoundary(root->right, ans);
        }
            
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root)
        ans.push_back(root->data);
        //print left boundary
        printLeftBoundary(root->left, ans);
        
        //print leaves of left subtree
        printLeaves(root->left, ans);
        
        //print leaves of right subtree
        printLeaves(root->right, ans);
        
        //print right boundary
        printRightBoundary(root->right, ans);
        return ans;
    }
