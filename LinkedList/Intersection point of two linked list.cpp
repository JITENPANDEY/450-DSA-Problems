ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL ||headB==NULL) return NULL;
        
        ListNode *dummy1=headA;
        ListNode *dummy2=headB;
        while(dummy1!=dummy2)
        {
            dummy1= dummy1==NULL?headB:dummy1=dummy1->next;
            dummy2= dummy2==NULL?headA:dummy2=dummy2->next;
        }
        return dummy1;
    }