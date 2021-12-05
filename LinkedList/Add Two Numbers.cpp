ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode();
        ListNode * node = dummy;
        int carry =0;
        while(l1 || l2){
            int sum = carry;
            
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            node->next = new ListNode(sum%10);
            carry = sum/10;
            node = node->next;
            
        }
        if(carry){
             node->next = new ListNode(carry);
        }
        return dummy->next;
    }