void dfs(vector<int>adj[], vector<bool>&visited, int s){
    visited[s]=true;
    for(auto i : adj[s]){
        if(!visited[i])
            dfs(adj, visited, i);
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    //1. if there are les than n-1 connection cable its not possible to connect all the computer.
    //2. using fs find the number of connected components
    //3. required number of operation would be the number of connected components-1;
    
    if(connections.size()<n-1)
        return -1;
    vector<int>adj[n];
    vector<bool>visited(n, false);
    
    for(auto i : connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    int component=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj, visited, i);
            component++;
        }
    }
    return component-1;
    
}