Node* getMid(Node* head){
    if(!head || !head->next)
        return head;
    
    Node*slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge(Node* head1, Node* head2){
    if(!head1 || !head2) return head1 ? head1:head2;
    
    if(head1->data>head2->data) swap(head1, head2);
    Node* res = head1;
    
    while(head1 && head2){
        Node* temp = head1;
        while(head1 && head1->data<=head2->data){
            temp = head1;
            head1=head1->next;
        }
        temp->next = head2;
        swap(head1, head2);
    }
    return res;
    
}
Node* mergeSort(Node* head) {
    // your code here
    if(!head || !head->next)
        return head;
        
    Node *mid = getMid(head);
    Node* head2 = mid->next;
    mid->next = NULL;
    
    Node *h1 = mergeSort(head);
    Node *h2 = mergeSort(head2);
    
    return merge(h1, h2);
    
}