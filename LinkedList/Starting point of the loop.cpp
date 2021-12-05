ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *entry = head; //enry point of the loop
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast->next->next;
            
            if(slow==fast){
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }