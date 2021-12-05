ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        while(curr){
            while(curr->next && curr->val==curr->next->val)
                curr=curr->next;
            
            if(pre->next == curr) // this means there is no adjacent duplicate
                pre=pre->next;
            else
                pre->next=curr->next;
            curr=curr->next;
        }
        return dummy->next;
    }