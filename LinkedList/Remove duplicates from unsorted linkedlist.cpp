Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_set<int> visited;
        Node*curr=head;
        Node*prev = NULL;
        while(curr!=NULL){
            if(visited.find(curr->data)!=visited.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                visited.insert(curr->data);
                prev = curr;
                curr=curr->next;
            }
        }
        return head;
    }