ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
// SC-O(N+M)
//         ListNode ans(0);
//         ListNode*res = &ans;
        
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                 res->next = l1;
//                 l1 = l1->next;
//             } else {
//                 res->next = l2;
//                 l2 = l2->next;
//             }
//             res = res->next;
//         }

//         res->next = l1 ? l1 : l2;
//         return ans.next;
        
 // SC-O(1)
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val > l2->val) swap(l1,l2);
        ListNode*ans=l1;
        while(l1 && l2){
            ListNode *temp = l1;
            while(l1 && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return ans;

    }