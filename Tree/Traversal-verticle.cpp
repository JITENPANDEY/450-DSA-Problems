vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // Create a map and store vertical order in
        // map using function getVerticalOrder()
        map<int, vector<int> > m;
        int hd = 0;
     
        // Create queue to do level order traversal.
        // Every item of queue contains node and
        // horizontal distance.
        queue<pair<Node*, int> > que;
        que.push(make_pair(root, hd));
     
        while (!que.empty()) {
            // pop from queue front
            pair<Node*, int> temp = que.front();
            que.pop();
            hd = temp.second;
            Node* node = temp.first;
     
            // insert this node's data in vector of hash
            m[hd].push_back(node->data);
     
            if (node->left != NULL)
                que.push(make_pair(node->left, hd - 1));
            if (node->right != NULL)
                que.push(make_pair(node->right, hd + 1));
        }
 
        // Traverse the map and print nodes at
        // every horizontal distance (hd)
        vector<int>ans;
        map<int, vector<int> >::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            for (int i = 0; i < it->second.size(); ++i)
                ans.push_back(it->second[i]);
        }
        return ans;
        
    }