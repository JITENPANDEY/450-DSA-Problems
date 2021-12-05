// hashing method
// go through all the nodes and mark as visited if we encounter with a visisted node in our path we find the loop
// TC, SC = O(N)


// Floyd’s Cycle-Finding Algorithm 
// Approach: This is the fastest method and has been described below:  

// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.

bool detectLoop(Node* head)
    {
        // your code here
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
            
            if(slow==fast)
                return true;
        }
        return false;
        
    }