 //Recursion
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *curr = reverseList(head->next);
        head->next->next = head;
        head->next=NULL;
        return curr;
        
    }
    //Using Add first method
    //addFirstMethod
    
    ListNode*reverseList(ListNode*head){
        ListNode*next;
        ListNode*tempHead = NULL;
        ListNode * curr = head;
        while(curr){
            next = curr->next;
            curr->next = NULL;
            
            // addFirstMethod
            if(tempHead==NULL){
                tempHead = curr;
            }else{
                curr->next = tempHead;
                tempHead = curr;
            }
            
            curr = next;
            
        }
        return tempHead;
    }

    // // Iteration with less variable
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
    
    //Iteration
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode*next = curr;
        ListNode* prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }