int length(struct node *head){
        int n = 0;
        while(head){
            n++;
            head=head->next;
        }
        return n;
    }
    struct node *reverse (struct node *head, int k)
    { 
        node *oh = NULL; // original head
        node *ot = NULL; // original tail
        node *th = NULL; // temp head
        node *tt = NULL; // temp tail
        
        if(!head || !head->next || k<=1) return head;
    
        int len = length(head);
        node *curr = head;
        while(len>0){  // see the changes in while loop
            //reverse in grp of size k
            for(int i=0;i<min(len, k);i++){
                node* next = curr->next;
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
            len-=k;
        }
        
        if(curr)
            ot->next = curr;
        return oh;
    }