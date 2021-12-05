Node* merge(Node* head1, Node* head2){
        Node* temp = new Node(0);
        Node* res = temp;
        while(head1 && head2){
            if(head1->data < head2->data){
                temp->bottom = head1;
                temp = temp->bottom;
                head1=head1->bottom;
            }else{
                temp->bottom = head2;
                temp = temp->bottom;
                head2=head2->bottom;
            }
        }
        if(head1) temp->bottom = head1;
        else temp->bottom = head2;
        
        return res->bottom;
    }
    Node *flatten(Node *root)
    {
       // Your code here
       if(!root || !root->next)
        return root;
    
        root->next = flatten(root->next);
        
        root = merge(root, root->next);
        
        return root;
    }