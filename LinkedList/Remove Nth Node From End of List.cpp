ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow= head;
        ListNode* fast = head;
        while(n--){
            fast=fast->next;
        }
        
        if (!fast) return head->next;
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* deletedNode = slow->next;
        slow->next = slow->next->next;
        delete deletedNode;
        return head;
    }