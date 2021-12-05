ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;
            prev = curr;
            curr= curr->next;
            
        }
        return dummy->next;
    }