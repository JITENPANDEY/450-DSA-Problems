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


#METHOD2
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