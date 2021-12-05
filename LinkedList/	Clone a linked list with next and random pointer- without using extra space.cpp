// without using extra space
    Node* copyRandomList(Node* head) {
        // First round: make copy of each node,
        // and link them together side-by-side in a single list
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            Node* curr_next = curr->next;
            curr->next = node;
            node->next = curr_next;
            
            curr = curr_next;
        }
        
        // Second round: assign random pointers for the copy nodes.
        curr = head;
        while(curr){
            Node* random = curr->random;
            if(random)
            curr->next->random = random->next;
            
            curr = curr->next->next;
        }
        
        // Third round: restore the original list, and extract the copy list.
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        curr = head;
        while(curr){
            Node* next_next = curr->next->next;

            // extract the copy
            prev->next = curr->next;

            // restore the original list
            curr->next = next_next;
              
            prev = prev -> next; 
            curr = next_next;  
        }
        return dummy->next;
        
    }