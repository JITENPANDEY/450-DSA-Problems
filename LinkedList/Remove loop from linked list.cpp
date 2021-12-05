void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    // your code here
    Node *prev = head;//enry point of the loop
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        prev = slow;
        slow = slow -> next;
        fast = fast->next->next;
        
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                prev = fast;
                slow=slow->next;
                fast=fast->next;
            }
            prev ->next = NULL;
        }
    }
}