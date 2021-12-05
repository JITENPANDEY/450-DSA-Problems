Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        Node* curr = head;
        unordered_map<Node*, Node*> mp;
        
        while(curr){
            Node* node = new Node(curr->val);
            mp[curr] = node;
            temp->next = node;
            temp=temp->next;
            curr=curr->next;
        }
        
        Node * c1 = head;
        Node* c2 = dummy->next;
        while(c1){
            c2->random = (c1->random)?mp[c1->random]: NULL;
            c1 = c1->next;
            c2 = c2->next;
        }
        return dummy->next;
        
    }