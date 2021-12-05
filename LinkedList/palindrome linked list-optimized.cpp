ListNode* reverseList(ListNode *head) {
        ListNode* curr = NULL;
        while(head!=NULL){
            ListNode *next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        
        // 1->2->3->2->1  after reversing
        //     1->2->3<-2-<1
        //     h      |    s
        //         NULL
        while(slow != NULL){
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }