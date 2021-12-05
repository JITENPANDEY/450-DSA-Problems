int dp[201][201]={0};
    int dfs(vector<vector<int>>& matrix, int i, int j, int row, int col){
        if(dp[i][j]!=0)
            return dp[i][j];
        int ans = 0;
        if(i+1<row && matrix[i][j]<matrix[i+1][j]) ans = max(ans, dfs(matrix, i+1, j, row, col));
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j]) ans = max(ans, dfs(matrix, i-1, j, row, col));
        if(j+1<col && matrix[i][j]<matrix[i][j+1]) ans = max(ans, dfs(matrix, i, j+1, row, col));
        if(j-1>=0 && matrix[i][j]<matrix[i][j-1]) ans = max(ans, dfs(matrix, i, j-1, row, col));

        return dp[i][j] = 1 + ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans, dfs(matrix, i, j, matrix.size(), matrix[i].size()));
            }
        }
        return ans;
    }