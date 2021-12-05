ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        k--;
        while(k--){
            fast = fast->next;
        }
        ListNode *Kth = fast;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        swap(Kth->val, slow->val);
        return head;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count =1;
        ListNode*curr = head;
        while(curr){
            if(count<k) fast = fast->next;
            if(count>k) slow = slow->next;
            curr=curr->next;
            count++;
        }
        swap(slow->val, fast->val);
        return head;
    }