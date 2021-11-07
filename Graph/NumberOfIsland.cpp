// Function to find the number of islands.
    void helper(vector<vector<char>>& grid, int i, int j , vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0' || visited[i][j]==1)
            return;
        
        visited[i][j]=1;
        helper(grid, i, j+1 , visited); // right
        helper(grid, i-1, j , visited); // top
        helper(grid, i+1, j , visited); //bottom
        helper(grid, i, j-1 , visited); // left
        
        helper(grid, i-1, j+1 , visited); // right top diagonal
        helper(grid, i+1, j+1 , visited); // right bottom diagonal
        helper(grid, i-1, j-1 , visited); //left top diagonal
        helper(grid, i+1, j-1 , visited); // left bottom diagonal
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n =  grid.size() ;
        int m =  grid[0].size();
        vector<vector<int>> visited( n, vector<int> (m, 0));
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    helper(grid, i, j , visited);
                    count++;
                }  
            }
        }
        return count;
        
    }