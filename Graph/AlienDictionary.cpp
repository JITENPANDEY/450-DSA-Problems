string ans ="";
void dfs(int source, vector<bool>&visited, vector<int>adj[]){
    visited[source]=true;
    for( auto i : adj[source]){
        if(!visited[i]){
            dfs(i, visited, adj);
        }
    }
    char ch = source +'a';
    ans = ch + ans;
}
string findOrder(string dict[], int n, int K) {
    //code here
    vector<int>graph[K];
    //create the graph
    for(int i=0;i<n-1;i++){
        int minlen = min(dict[i].size(),dict[i+1].size());
        
        for(int j=0;j<minlen;j++){
              if(dict[i][j] != dict[i+1][j]){
                graph[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                break;
            }
        }
    }
    
    //apply topo sort by suing dfs
    vector<bool>visited(K, false);
    for(int i=0;i<K;i++){
        if(!visited[i])
            dfs(i, visited, graph);
    }
    //cout<<ans<<endl;
    return ans;
}