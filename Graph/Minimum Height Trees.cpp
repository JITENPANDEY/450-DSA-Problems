vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1) return {0};
    vector<int> graph[n];
    vector<int>degrees(n,0);
    for(auto &edge : edges){
        int a = edge[0], b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        degrees[a]++;
        degrees[b]++;
    }
    queue<int> q; // containes all the leaf node
    for(int i=0;i<n;i++){
        if(degrees[i]==1){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.clear();
        int size = q.size();
        for(int i=0;i<size;i++){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto &neigh : graph[node]){
                degrees[neigh]--;
                if(degrees[neigh]==1)
                    q.push(neigh);
            }
        }
        
    }
    
    return ans;
}