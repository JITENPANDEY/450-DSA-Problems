struct comp {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for( auto &l : lists) if(l!=NULL) pq.push(l);
        ListNode* dummy = new ListNode();
        ListNode *prev = dummy;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            
            prev->next = node;
            prev = node;
            node = node->next;
            
            if(node) pq.push(node);
            
        }
        return dummy->next;
        
    }