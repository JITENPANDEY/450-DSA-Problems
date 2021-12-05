int length(ListNode* head){
    int n = 0;
    while(head){
        n++;
        head=head->next;
    }
    return n;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    
    ListNode *oh = NULL; // original head
    ListNode *ot = NULL; // original tail
    ListNode *th = NULL; // temp head
    ListNode *tt = NULL; // temp tail
    
    if(!head || !head->next || k<=1) return head;
    
    int len = length(head);
    ListNode *curr = head;
    while(len>=k){
        //reverse in grp of size k
        for(int i=0;i<k;i++){
            ListNode* next = curr->next;
            curr->next = NULL;
            
            //addFisrtMethod
            if(th==NULL){
                th = curr;
                tt = curr;
            }else{
                curr->next = th;
                th = curr;
            }
            curr = next;
        }
        
        if(oh==NULL){
            oh = th;
            ot = tt;
        }else{
            ot->next = th;
            ot = tt;
        }
        
        th = NULL;
        tt = NULL;
        len -=k;
    }
    
    if(curr)
        ot->next = curr;
    return oh;
    

}