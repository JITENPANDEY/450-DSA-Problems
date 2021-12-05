void dfs(vector<int>adj[], vector<bool>& visited, int &countNodes, int src){
        visited[src] = true;
        
        for(auto &neigh : adj[src]){
            if(!visited[neigh]){
                countNodes++;
                dfs(adj, visited, countNodes, neigh);
            }
            
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool>visited(V, false);
	    int countNodes = 1;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(adj, visited, countNodes, i);
	            if(countNodes==V)
	                return i;
	        }
	    }
	    return -1;
	}