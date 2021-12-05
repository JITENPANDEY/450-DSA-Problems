 ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        if(k==0)
            return head;
        
        ListNode * curr = head;
        int len =0;
        while(curr->next !=NULL){
            len++;
            curr= curr->next;
        }
        len++;
        k%=len;
        curr->next = head;
        curr = head;
        
       for(int i=0;i<len-k-1;i++){
            curr=curr->next;
        }
        head = curr->next;
        curr->next =NULL;
        
        return head;
        
    }