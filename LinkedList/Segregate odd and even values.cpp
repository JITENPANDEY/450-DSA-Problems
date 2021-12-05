 Node* divide(int N, Node *head){
        Node * oddhead =NULL;
        Node * evenhead = NULL;
        Node * lastodd = NULL;
        Node * lasteven =NULL;
        
        Node*curr = *head;
        // if(*head == NULL || *head->next ==NULL)
        // return;
        
        while(curr!=NULL){
            //even case
            if(curr->data%2==0){
                if(evenhead==NULL){
                    evenhead = curr;
                    lasteven = evenhead;
                    curr=curr->next;
                }
                else{
                    lasteven->next = curr;
                    lasteven = curr;
                    curr=curr->next;
                }
            }
            //odd case
            else{
                if(oddhead==NULL){
                    oddhead = curr;
                    lastodd = oddhead;
                    curr=curr->next;
                }
                else{
                    lastodd->next = curr;
                    lastodd = curr;
                    curr=curr->next;
                }
                
            }
        }
        if(evenhead==NULL){
            *head = oddhead;
        }
        else if(oddhead == NULL){
            *head = evenhead;
        }
        else{
            lasteven->next=oddhead;
            lastodd->next=NULL;
            *head = evenhead;
        }
    }