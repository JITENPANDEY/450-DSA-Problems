void reverse(ListNode **head) 
{
    ListNode * curr =*head;
    ListNode * prev= NULL, *next = NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;

    }
    *head=prev;
}
ListNode * splitLinkedList(ListNode * head, ListNode ** mid_node)
{
    ListNode * slow=head;
    ListNode * fast =head;
    ListNode * SecondHead;
    if(head->next==NULL)
    return head;
    while(1)
    {
        fast=fast->next->next;
        if(fast==NULL)// even
        {
            SecondHead =slow->next;
            *mid_node=NULL;
            break;
        }
        if(fast->next==NULL)// odd length
        {
            SecondHead = slow->next->next;
            *mid_node =slow->next;
            break;
        }

        slow=slow->next;
    }
    slow->next=NULL;
    return SecondHead;
} 
bool compare(ListNode* head1, ListNode * head2)
{
    ListNode* temp1 = head1; 
        ListNode* temp2 = head2; 

        while (temp1 && temp2) { 
            if (temp1->val == temp2->val) { 
                temp1 = temp1->next; 
                temp2 = temp2->next; 
        } 
        else
            return false; 
    } 


    if (temp1 == NULL && temp2 == NULL) 
        return true; 


    return false; 
}
bool isPalindrome(ListNode* head) {
    ListNode * mid_node =NULL;
    if(head == NULL || head->next==NULL) return true;
    ListNode * Head2= splitLinkedList(head,&mid_node);
  reverse(&Head2);

    bool res = compare(head,Head2);
    reverse(&Head2);
    ListNode * temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    if(mid_node !=NULL)
        temp->next=mid_node;
    else
        temp->next=Head2;

    return res;
    
    
}