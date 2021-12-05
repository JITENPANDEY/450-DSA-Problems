// store the subtree size of all the nodes and res for the root node
// res[node] += res[childnode] + subtreesize[childnode]
void preprocessing(int src, int par,vector<int> graph[],vector<int>&subtreeSize,vector<int>&subtreeAns){
    for (int child : graph[src]) {
        if (child != par) {
            preprocessing(child, src, graph, subtreeSize, subtreeAns);
            subtreeSize[src] += subtreeSize[child];
            subtreeAns[src] += subtreeAns[child] + subtreeSize[child];
        }
    }
}
// res[child] = res[root] - count of closer nodes + count of farther nodes
// res[child] = res[root] - subtreeSize[child] + (N - subtreeSize[child])  
void solve(int src, int par, int N,vector<int>graph[] ,vector<int>&subtreeSize,vector<int>&subtreeAns){
    for (int child : graph[src]) {
        if (child != par) {
            subtreeAns[child] = subtreeAns[src] - subtreeSize[child] + N - subtreeSize[child];
            solve(child, src, N, graph, subtreeSize, subtreeAns);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> graph[n];
    vector<int>subtreeSize(n);
    vector<int>subtreeAns(n);
    
    fill(subtreeSize.begin(),subtreeSize.end(),1);
    
    
    for(auto v:edges){
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    preprocessing(0,-1,graph,subtreeSize, subtreeAns);
    for(auto &i: subtreeSize) cout<<i<<" ";
    cout<<endl;
    for(auto &i: subtreeAns) cout<<i<<" ";
    solve(0,-1,n,graph,subtreeSize, subtreeAns);
    return subtreeAns;
}