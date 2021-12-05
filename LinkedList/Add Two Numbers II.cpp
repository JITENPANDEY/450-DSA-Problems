ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode * node = new ListNode();
        int sum = 0;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
           if (!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            node->val = sum%10;
            ListNode* head = new ListNode(sum/10); // node with carry value
            head->next = node;
            node = head;
            sum/=10;
            
        }
        
        return node->val==0? node->next: node;
    }