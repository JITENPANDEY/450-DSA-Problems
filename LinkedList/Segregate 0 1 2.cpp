Node* segregate(Node *head) {
        
        // Add code here
        Node* dummyZero = new Node(0);
        Node* dummyOne = new Node(0);
        Node* dummyTwo = new Node(0);
        
        Node* zero = dummyZero;
        Node* one = dummyOne;
        Node* two = dummyTwo;
        
        Node*curr= head;
        while(curr){
            if(curr->data==0){
                zero->next = curr;
                zero = zero->next;
            }else if(curr->data==1){
                one->next = curr;
                one = one->next;
            }else{
                two->next = curr;
                two = two->next;
            }
            curr=curr->next;
        }
        
        zero->next = dummyOne->next?dummyOne->next: dummyTwo->next;
        one->next = dummyTwo->next;
        two->next = NULL;
        
        return dummyZero->next;
        
        
    }