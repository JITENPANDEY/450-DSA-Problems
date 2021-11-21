vector<int> diagonal(Node *root)
{
    vector <int> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        while(curr != NULL) // pick the curr elemet and print all the right nodes of curr, if there exist left child then push it into the stack for next iteration
        {
            ans.push_back(curr->data);
            if(curr->left)
                q.push(curr->left);

            curr = curr->right;
        }
    }
    return ans;
  
}