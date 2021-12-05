Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(!head || !head->next) return head;
 Node* curr = head;
 Node *next_next;
 
 while(curr->next){
     // if two values are equal
     if(curr->data == curr->next->data){
         next_next = curr->next->next;
         delete curr->next;
         curr->next  = next_next;
     }else{
         curr= curr->next;
     }
 }
 return head;
}

// second aproach
Node *removeDuplicates(Node *head)
{
 Node*prev = head, *temp = head;
    while(temp){
        if(prev->data == temp->data){
            temp = temp->next;
        }else{
            prev->next = temp;
            prev = temp;
        }
    }
    // if the last element is more than once
    if(prev!=temp) // it means we have more occurannce of last element
        prev->next = NULL;
    
    return head;
}

// hashing method
void removeDuplicates(Node* head)
{
    unordered_map<int, bool> track;
    Node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
}
