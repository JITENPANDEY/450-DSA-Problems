unordered_map<Node*, Node*> map;
    Node* cloneGraph(Node* node) {
        
//BFS - APPROACH
//         if(node==NULL) return NULL;
//         unordered_map<Node*, Node*> map;
//         queue<Node*> q;
//         q.push(node);
//         map[node]= new Node(node->val);
        
//         while(!q.empty()){
//             Node* currNode = q.front();
//             q.pop();
            
//             for(auto n : currNode->neighbors){
//                 if(!map[n]){
//                     map[n] = new Node(n->val);
//                     q.push(n);
//                 }
//                 map[currNode]->neighbors.push_back(map[n]);
//             }
//         }
//         return map[node];
        
//DFS - APPROACH
        if(node==NULL) return NULL;
        if(!map[node]){
            map[node] = new Node(node->val);
            for(auto n : node->neighbors){
                   map[node] -> neighbors.push_back(cloneGraph(n));
                }
            }
        
        return map[node];
    }