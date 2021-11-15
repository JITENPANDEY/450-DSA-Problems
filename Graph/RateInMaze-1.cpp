vector<string>ans;
void dfs(vector<vector<int>> &maze, int n, int i, int j, vector<vector<bool>>&visited, string path){
    if(i<0 || i>=n ||j<0 || j>=n || maze[i][j]==0 || visited[i][j]==true)
        return;
    
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    visited[i][j]=true;
    dfs(maze, n, i+1, j, visited, path + 'D');
    dfs(maze, n, i, j-1, visited, path + 'L');
    dfs(maze, n, i, j+1, visited, path + 'R');
    dfs(maze, n, i-1, j, visited, path + 'U');
    visited[i][j]=false;
    
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    string path = "";
    dfs(m, n, 0, 0, visited, path);
    return ans;
    
}