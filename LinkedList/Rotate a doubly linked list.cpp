void rotateByN(Node *&head, int pos)
{
    if (pos == 0)
        return;
 
    Node *curr = head;
 
    while (pos)
    {
        curr = curr->next;
        pos--;
    }
 
    Node *tail = curr->pre;
    Node *NewHead = curr;
    tail->next = NULL;
    curr->pre = NULL;
 
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
     
    curr->next = head;
    head->pre = curr;
    head = NewHead;
}