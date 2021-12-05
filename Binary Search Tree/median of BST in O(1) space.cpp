int morrisInorder(Node* root){
    int count = 0;
    Node* curr=root;
    while(curr!=NULL){
        
        //if curr->left is null the print and go to right
        if(curr->left==NULL){
            count++;
            curr = curr->right;
        }else{
            //go to the rightmost node of the left subtree
            Node* temp=curr->left;
            while(temp->right && temp->right!=curr){
                temp=temp->right;
            }
            // and make the thread when temp->right is NULL
            if(temp->right==NULL){
                temp->right = curr;
                curr=curr->left;
            }else{ // rightmost node -> right == curr then destry the thread;
                temp->right = NULL;
                count++;
                curr = curr->right;
            }
            
        }
        
    }
    return count;
}
int findKthSmallest(Node* root, int K){
    int count = 0;
    int kthNode;
    Node* curr=root;
    while(curr!=NULL){
        
        //if curr->left is null the print and go to right
        
        if(curr->left==NULL){
            count++;
            if(count==K){
                kthNode = curr->data;
            }
            curr = curr->right;
        }else{
            //go to the rightmost node of the left subtree
            Node* temp=curr->left;
            while(temp->right && temp->right!=curr){
                temp=temp->right;
            }
            // and make the thread when temp->right is NULL
            if(temp->right==NULL){
                temp->right = curr;
                curr=curr->left;
            }else{ // rightmost node -> right == curr then destry the thread;
                temp->right = NULL;
                count++;
                if(count==K){
                    kthNode = curr->data;
                }
                curr = curr->right;
            }
            
        }
        
    }
    return kthNode;
}
float findMedian(struct Node *root)
{
      //Code here
      int numberOfNodes = morrisInorder(root);
      float median = 0.0;
      int mid = numberOfNodes/2+1; // mid in case of odd and mid+1 in case of even
      float median1 = (float) findKthSmallest(root, mid);
      float median2 = (float) findKthSmallest(root, mid-1);
      if(numberOfNodes%2){
           return median1;
      }
      else {
          median = (float(median1) + float(median2))/2.0;
          return median;
          
      }
      
      
      
      
}